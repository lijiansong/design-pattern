#include "Decorator.h"
#include <iostream>
using namespace std;
int main()
{
	Component* com = new ConcreteComponent();
	Decorator* dec = new ConcreteDecorator(com);
	dec->Operation();
	delete dec;
	system("pause");
	return 0;
}