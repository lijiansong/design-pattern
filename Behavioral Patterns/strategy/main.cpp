#include "strategy.h"
#include "Context.h"
#include <iostream>
using namespace std;
int main()
{
	Strategy* ps = new ConcreteStrategyA();
	Context* pc = new Context(ps);
	pc->DoAction();
	if (NULL != pc)
		delete pc;
	system("pause");
	return 0;
}