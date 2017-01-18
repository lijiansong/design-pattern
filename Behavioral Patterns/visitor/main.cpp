#include "Element.h"
#include "Visitor.h" 
#include <iostream>
using namespace std;
int main()
{
	Visitor* vis = new ConcreteVisitorA();
	Element* elm = new ConcreteElementA();
	elm->Accept(vis);
	system("pause");
	return 0;
}