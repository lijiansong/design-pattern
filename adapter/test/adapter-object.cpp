#include <iostream>
using namespace std;

class Target
{
public:
	Target(){}
	virtual ~Target(){}
	virtual void Request()
	{
		cout<<"Target::Request"<<endl;
	}
};

class Adaptee
{
public:
	void SpecificRequest()
	{
		cout<<"Adaptee::SpecificRequest"<<endl;
	}
};

class Adapter : public Target
{
public:
	Adapter() : m_Adaptee(new Adaptee) {}

	~Adapter()
	{
		if (m_Adaptee != NULL)
		{
			delete m_Adaptee;
			m_Adaptee = NULL;
		}
	}

	void Request()
	{
		m_Adaptee->SpecificRequest();
	}

private:
	Adaptee *m_Adaptee;
};

int main(int argc, char *argv[])
{
	Target *targetObj = new Adapter();
	targetObj->Request();

	delete targetObj;
	targetObj = NULL;

	return 0;
}
