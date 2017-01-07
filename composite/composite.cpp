#include "Composite.h"
#include "Component.h"
Composite::Composite() {}
Composite::~Composite(){}
void Composite::Operation()
{
	vector<Component*>::iterator comIter = comVec.begin();
	vector<Component*>::iterator comIE = comVec.end();
	for (; comIter != comIE; ++comIter)
	{
		(*comIter)->Operation();
	}
}
void Composite::Add(Component* com)
{
	comVec.push_back(com);
}
void Composite::Remove(Component* com)
{
	auto it = find(comVec.begin(), comVec.end(), com);
	if (it!=comVec.end())
	{
		comVec.erase(it);
	}
}

Component* Composite::GetChild(int index)
{
	return comVec[index];
}