#include "Iterator.h"
#include "Aggregate.h"
#include <iostream> 
using namespace std;
int main()
{
	Aggregate* ag = new ConcreteAggregate();
	Iterator* it = new ConcreteIterator(ag);
	for (; !(it->IsDone()); it->Next())
	{ 
		cout << it->CurrentItem() << endl;
	}
	system("pause");
	return 0;
}