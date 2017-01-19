#include "Context.h"
#include "Interpret.h" 
#include <iostream> 
using namespace std;
int main()
{
	Context* c = new Context();
	AbstractExpression* te = new TerminalExpression("hello");
	AbstractExpression* nte = new NonterminalExpression(te, 2);
	nte->Interpret(*c);
	system("pause");
	return 0;
}