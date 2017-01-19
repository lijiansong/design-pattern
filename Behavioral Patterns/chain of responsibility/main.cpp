#include "Handle.h"
#include <iostream>
using namespace std;
int main()
{
	Handle* ha = new ConcreteHandleA();
	Handle* hb = new ConcreteHandleB();
	ha->SetSuccessor(hb);
	ha->HandleRequest();
	system("pause");
	return 0;
}