//Factory Pattern
#ifndef _PRODUCT_H_
#define _PRODUCT_H_

class Product
{
public:
	virtual ~Product() = 0;

protected:
	Product();

private:

};

class ConcreteProduct :public Product
{
public:
	ConcreteProduct();
	~ConcreteProduct();

};

#endif