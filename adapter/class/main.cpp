#include "Adapter.h"
#include <iostream>
using namespace std;
int main()
{
	Target* adt = new Adapter();
	adt->Request();
	system("pause");
	return 0;
}