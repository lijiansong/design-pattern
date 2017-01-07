#include <iostream>
using namespace std;
class Implementor
{
public:
     virtual void OperationImpl() = 0;
};
class ConcreteImpementor : public Implementor
{
public:
     void OperationImpl()
     {
          cout<<"OperationImpl"<<endl;
     }
};
class Abstraction
{
public:
     Abstraction(Implementor *pImpl) : m_pImpl(pImpl){}
     virtual void Operation() = 0;
protected:
     Implementor *m_pImpl;
};
class RedfinedAbstraction : public Abstraction
{
public:
     RedfinedAbstraction(Implementor *pImpl) : Abstraction(pImpl){}
     void Operation()
     {
          m_pImpl->OperationImpl();
     }
};
int main(int argc, char *argv[])
{
     Implementor *pImplObj = new ConcreteImpementor();
     Abstraction *pAbsObj = new RedfinedAbstraction(pImplObj);
     pAbsObj->Operation();
     delete pImplObj;
     pImplObj = NULL;
     delete pAbsObj;
     pAbsObj = NULL;
     return 0;
}
