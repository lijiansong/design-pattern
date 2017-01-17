#include "Context.h"
#include "State.h"
#include <iostream>
using namespace std;
int main()
{
	State* st = new ConcreteStateA();
	Context* con = new Context(st);
	con->OperationChangState();
	con->OperationChangState();
	con->OperationChangState();
	if (NULL != con)
		delete con;
	if (NULL != st)
		st = NULL;
	system("pause");
	return 0;
}