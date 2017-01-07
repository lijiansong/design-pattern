#include <iostream>
using namespace std;

#define SAFE_DELETE(p) if (p) { delete p; p = NULL;}

class CSubject
{
public:
	CSubject(){};
	virtual ~CSubject(){}

	virtual void Request() = 0;
};

class CRealSubject : public CSubject
{
public:
	CRealSubject(){}
	~CRealSubject(){}

	void Request()
	{
		cout<<"CRealSubject Request"<<endl;
	}
};

class CProxy : public CSubject
{
public:
	CProxy() : m_pRealSubject(NULL){}
	~CProxy()
	{
		SAFE_DELETE(m_pRealSubject);
	}

	void Request()
	{
		if (NULL == m_pRealSubject)
		{
			m_pRealSubject = new CRealSubject();
		}
		cout<<"CProxy Request"<<endl;
		m_pRealSubject->Request();
	}

private:
	CRealSubject *m_pRealSubject;
};

int main()
{
	CSubject *pSubject = new CProxy();
	pSubject->Request();
	SAFE_DELETE(pSubject);
}
