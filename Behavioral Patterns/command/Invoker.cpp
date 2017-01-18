#include "Invoker.h"
#include "Command.h"
#include <iostream>
using namespace std;
Invoker::Invoker(Command* cmd)
{
	_cmd = cmd;
}
Invoker::~Invoker()
{
	delete _cmd;
}
void Invoker::Invoke()
{
	_cmd->Excute();
}
