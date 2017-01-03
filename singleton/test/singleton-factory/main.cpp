#include <iostream>
#include "Constant.h"
#include "SingletonFactory.h"

using namespace std;

int main(int argc, char *argv[])
{
	SingletonFactory *factoryA = SingletonFactory::GetInstance(kFactory_A);
	factoryA->Operation();
}
