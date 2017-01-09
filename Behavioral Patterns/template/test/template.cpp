#include <iostream>
using namespace std;

class AbstractClass
{
public:
     void TemplateMethod()
     {
          PrimitiveOperation1();
          cout<<"TemplateMethod"<<endl;
          PrimitiveOperation2();
     }

protected:
     virtual void PrimitiveOperation1()
     {
          cout<<"Default Operation1"<<endl;
     }

     virtual void PrimitiveOperation2()
     {
          cout<<"Default Operation2"<<endl;
     }
};

class ConcreteClassA : public AbstractClass
{
protected:
          virtual void PrimitiveOperation1()
     {
          cout<<"ConcreteA Operation1"<<endl;
     }

     virtual void PrimitiveOperation2()
     {
          cout<<"ConcreteA Operation2"<<endl;
     }
};

class ConcreteClassB : public AbstractClass
{
protected:
          virtual void PrimitiveOperation1()
     {
          cout<<"ConcreteB Operation1"<<endl;
     }

     virtual void PrimitiveOperation2()
     {
          cout<<"ConcreteB Operation2"<<endl;
     }
};

int main()
{
     AbstractClass *pAbstractA = new ConcreteClassA;
     pAbstractA->TemplateMethod();

     AbstractClass *pAbstractB = new ConcreteClassB;
     pAbstractB->TemplateMethod();

     if (pAbstractA) delete pAbstractA;
     if (pAbstractB) delete pAbstractB;
}
