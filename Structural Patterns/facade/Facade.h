#ifndef _FACADE_H_
#define _FACADE_H_
class SubSystem1
{
public:
	SubSystem1();
	~SubSystem1();
	void Operation();
protected:
private:
};
class SubSystem2
{
public:
	SubSystem2();
	~SubSystem2();
	void Operation();
protected:
private:
};
class Facade
{
public:
	Facade();
	~Facade();
	void OperationWrapper();
protected:
private:
	SubSystem1* _subs1;
	SubSystem2* _subs2;
};
#endif