#include "Facade.h"
#include <iostream>
using namespace std;
int main()
{
	Facade* f = new Facade();
	f->OperationWrapper();
	system("pause");
	return 0;
}