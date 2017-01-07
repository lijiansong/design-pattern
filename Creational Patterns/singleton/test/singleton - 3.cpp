#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton *GetInstance()
	{
		static Singleton m_Instance;
		return &m_Instance;
	}

	int GetTest()
	{
		return m_Test++;
	}

private:
	Singleton(){ m_Test = 10; };
	int m_Test;
};

int main(int argc , char *argv [])
{
	Singleton *singletonObj = Singleton ::GetInstance();
	cout<<singletonObj->GetTest()<<endl;

	singletonObj = Singleton ::GetInstance();
	cout<<singletonObj->GetTest()<<endl;
}
