#include "FlyweightFactory.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

FlyweightFactory::FlyweightFactory()
{}
FlyweightFactory::~FlyweightFactory()
{}
Flyweight* FlyweightFactory::GetFlyweight(const string& key)
{
	vector<Flyweight*>::iterator it = _fly.begin();
	vector<Flyweight*>::iterator ie = _fly.end();
	for (; it != ie; ++it)
	{
		if ((*it)->GetIntrinsicState() == key)
		{
			cout << "already created by user..." << endl;
		}
		return (*it);
	}

	Flyweight* fn = new ConcreteFlyweight(key);
	_fly.push_back(fn);
	return fn;
}