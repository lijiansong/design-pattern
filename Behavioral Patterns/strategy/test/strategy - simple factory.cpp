#include <iostream>
using namespace std;

// Define the strategy type
typedef enum StrategyType
{
	StrategyA,
	StrategyB,
	StrategyC
}STRATEGYTYPE;

// The abstract strategy
class Strategy
{
public:
	virtual void AlgorithmInterface() = 0;
	virtual ~Strategy() = 0; // 谢谢hellowei提出的bug，具体可以参见评论
};

Strategy::~Strategy()
{}

class ConcreteStrategyA : public Strategy
{
public:
	void AlgorithmInterface()
	{
		cout << "I am from ConcreteStrategyA." << endl;
	}

	~ConcreteStrategyA(){}
};

class ConcreteStrategyB : public Strategy
{
public:
	void AlgorithmInterface()
	{
		cout << "I am from ConcreteStrategyB." << endl;
	}

	~ConcreteStrategyB(){}
};

class ConcreteStrategyC : public Strategy
{
public:
	void AlgorithmInterface()
	{
		cout << "I am from ConcreteStrategyC." << endl;
	}

	~ConcreteStrategyC(){}
};

class Context
{
public:
	Context(STRATEGYTYPE strategyType)
	{
		switch (strategyType)
		{
		case StrategyA:
			pStrategy = new ConcreteStrategyA;
			break;

		case StrategyB:
			pStrategy = new ConcreteStrategyB;
			break;

		case StrategyC:
			pStrategy = new ConcreteStrategyC;
			break;

		default:
			break;
		}
	}

	~Context()
	{
		if (pStrategy) delete pStrategy;
	}

	void ContextInterface()
	{
		if (pStrategy)
			pStrategy->AlgorithmInterface();
	}

private:
	Strategy *pStrategy;
};

int main()
{
	Context *pContext = new Context(StrategyA);
	pContext->ContextInterface();

	if (pContext) delete pContext;
}
