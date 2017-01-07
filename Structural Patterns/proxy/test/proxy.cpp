#include <iostream>
#include <windows.h>
using namespace std;

#define SAFE_DELETE(p) if (p) { delete p; p = NULL; }

class KRefCount
{
public:
    KRefCount():m_nCount(0){}

public:
	unsigned AddRef(){ return InterlockedIncrement(&m_nCount); }
	unsigned Release(){ return InterlockedDecrement(&m_nCount); }
    void Reset(){ m_nCount = 0; }

private:
    unsigned long m_nCount;
};

template <typename T>
class SmartPtr
{
public:
    SmartPtr(void)
        : m_pData(NULL)
    {
        m_pReference = new KRefCount();
        m_pReference->AddRef();
    }

    SmartPtr(T* pValue)
        : m_pData(pValue)
    {
        m_pReference = new KRefCount();
        m_pReference->AddRef();
    }

    SmartPtr(const SmartPtr<T>& sp)
        : m_pData(sp.m_pData)
        , m_pReference(sp.m_pReference)
    {
        m_pReference->AddRef();
    }

    ~SmartPtr(void)
    {
        if (m_pReference && m_pReference->Release() == 0)
        {
            SAFE_DELETE(m_pData);
            SAFE_DELETE(m_pReference);
        }
    }

    inline T& operator*()
    {
        return *m_pData;
    }

    inline T* operator->()
    {
        return m_pData;
    }

    SmartPtr<T>& operator=(const SmartPtr<T>& sp)
    {
        if (this != &sp)
        {
            if (m_pReference && m_pReference->Release() == 0)
            {
                SAFE_DELETE(m_pData);
                SAFE_DELETE(m_pReference);
            }

            m_pData = sp.m_pData;
            m_pReference = sp.m_pReference;
			m_pReference->AddRef();
        }

        return *this;
    }

    SmartPtr<T>& operator=(T* pValue)
    {
        if (m_pReference && m_pReference->Release() == 0)
        {
            SAFE_DELETE(m_pData);
            SAFE_DELETE(m_pReference);
        }

        m_pData = pValue;
        m_pReference = new KRefCount;
		m_pReference->AddRef();
        return *this;
    }

    T* Get()
    {
        T* ptr = NULL;        
        ptr = m_pData;

        return ptr;
    }

    void Attach(T* pObject)
    {
        if (m_pReference->Release() == 0)
        {
            SAFE_DELETE(m_pData);
            SAFE_DELETE(m_pReference);
        }

        m_pData = pObject;
        m_pReference = new KRefCount;
        m_pReference->AddRef();
    }

    T* Detach()
    {
        T* ptr = NULL;

        if (m_pData)
        {           
            ptr = m_pData;
            m_pData = NULL;
            m_pReference->Reset();
        }
        return ptr;
    }

private:
    KRefCount* m_pReference;
    T* m_pData;
};

class CTest
{
public:
	CTest(int b) : a(b) {}
private:
	int a;
};

int main()
{
	SmartPtr<CTest> pSmartPtr1(new CTest(10));
	SmartPtr<CTest> pSmartPtr2(new CTest(20));

	pSmartPtr1 = pSmartPtr2;
}
