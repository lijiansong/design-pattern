#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton *GetInstance()
	{
		return const_cast <Singleton *>(m_Instance);
	}

	static void DestoryInstance()
	{
		if (m_Instance != NULL )
		{
			delete m_Instance;
			m_Instance = NULL ;
		}
	}

	int GetTest()
	{
		return m_Test;
	}

private:
	Singleton(){ m_Test = 10; }
	static const Singleton *m_Instance;
	int m_Test;
};

const Singleton *Singleton ::m_Instance = new Singleton();

int main(int argc , char *argv [])
{
	Singleton *singletonObj = Singleton ::GetInstance();
	cout<<singletonObj->GetTest()<<endl;
	Singleton ::DestoryInstance();
}
