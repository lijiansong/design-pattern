#include "Component.h"
#include "Composite.h"
#include "Leaf.h"
#include <iostream>
using namespace std;

int main()
{
	Leaf* leaf = new Leaf();
	leaf->Operation();
	Composite* com = new Composite();
	com->Add(leaf);
	com->Operation();

	Component* ll = com->GetChild(0);
	ll->Operation();

	system("pause");
	return 0;
}