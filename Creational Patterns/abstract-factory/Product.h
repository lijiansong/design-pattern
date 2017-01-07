class AbstractProductA
{
public:
	virtual ~AbstractProductA();

protected:
	AbstractProductA();

private:

};


class AbstractProductB
{
public:
	virtual ~AbstractProductB();

protected:
	AbstractProductB();

private:

};

class ProductA1:public AbstractProductA
{
public:
	ProductA1();
	~ProductA1();

private:
};

class ProductA2:public AbstractProductA
{
public:
	ProductA2();
	~ProductA2();

private:

};
class ProductB1:public AbstractProductB
{
public:
	ProductB1();
	~ProductB1();

private:

};

class ProductB2:public AbstractProductB
{
public:
	ProductB2();
	~ProductB2();

private:

};

