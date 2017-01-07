#include <iostream>
using namespace std;

// 语法分析子系统
class CSyntaxParser
{
public:
     void SyntaxParser()
     {
          cout<<"Syntax Parser"<<endl;
     }
};

// 生成中间代码子系统
class CGenMidCode
{
public:
     void GenMidCode()
     {
          cout<<"Generate middle code"<<endl;
     }
};

// 生成汇编代码子系统
class CGenAssemblyCode
{
public:
     void GenAssemblyCode()
     {
          cout<<"Generate assembly code"<<endl;
     }
};

// 链接生成可执行应用程序或库子系统
class CLinkSystem
{
public:
     void LinkSystem()
     {
          cout<<"Link System"<<endl;
     }
};

class Facade
{
public:
     void Compile()
     {
          CSyntaxParser syntaxParser;
          CGenMidCode genMidCode;
          CGenAssemblyCode genAssemblyCode;
          CLinkSystem linkSystem;
          syntaxParser.SyntaxParser();
          genMidCode.GenMidCode();
          genAssemblyCode.GenAssemblyCode();
          linkSystem.LinkSystem();
     }
};

// 客户端
int main()
{
     Facade facade;
     facade.Compile();
}
