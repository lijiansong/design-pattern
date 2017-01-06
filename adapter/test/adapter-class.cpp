#include <iostream>
using namespace std;

// Targets
class Target
{
public:
	virtual void Request()
	{
		cout<<"Target::Request"<<endl;
	}
};

// Adaptee
class Adaptee
{
public:
	void SpecificRequest()
	{
		cout<<"Adaptee::SpecificRequest"<<endl;
	}
};

// Adapter
class Adapter : public Target, Adaptee
{
public:
	void Request()
	{
		Adaptee::SpecificRequest();
	}
};

// Client
int main(int argc, char *argv[])
{
	Target *targetObj = new Adapter();
	targetObj->Request();

	delete targetObj;
	targetObj = NULL;

	return 0;
}
