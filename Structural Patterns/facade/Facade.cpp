#include "Facade.h"
#include <iostream>
using namespace std;
SubSystem1::SubSystem1()
{}
SubSystem1::~SubSystem1()
{}
void SubSystem1::Operation()
{
	cout << "SubSystem1::Operation...." << endl;
}

SubSystem2::SubSystem2()
{}
SubSystem2::~SubSystem2()
{}
void SubSystem2::Operation()
{
	cout << "SubSystem2::Operation...." << endl;
}

Facade::Facade()
{
	this->_subs1 = new SubSystem1();
	this->_subs2 = new SubSystem2();
}
Facade::~Facade()
{
	delete _subs1, _subs2;
}
void Facade::OperationWrapper()
{
	_subs1->Operation();
	_subs2->Operation();
}