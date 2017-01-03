#include "Singleton.h"
#include <iostream>
using namespace std;
int main()
{
	Singleton* sgn = Singleton::Instance();
	system("pause");
	return 0;
}