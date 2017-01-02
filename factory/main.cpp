#include "Product.h"
#include "Factory.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Factory* factory = new ConcreteFactory();
	Product* product = factory->CreateProduct();
	//system("pause");
	return 0;
}
