#include "Builder.h"
#include "Director.h"
#include "Product.h"
#include <iostream>
using namespace std;
int main()
{
	Director* director = new Director(new ConcreteBuilder());
	director->Construct();
	system("pause");
	return 0;
}