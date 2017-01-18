#include "Command.h"
#include "Invoker.h"
#include "Reciever.h"
#include <iostream>
using namespace std;
int main()
{
	Reciever* rev = new Reciever();
	Command* cmd = new ConcreteCommand(rev);
	Invoker* inv = new Invoker(cmd);
	inv->Invoke();
	system("pause");
	return 0;
}