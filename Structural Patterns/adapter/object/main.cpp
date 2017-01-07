#include "Adapter.h"
#include <iostream>
using namespace std;
int main()
{
	Adaptee* ade = new Adaptee;
	Target* adt = new Adapter(ade);
	adt->Request();
	system("pause");
	return 0;
}