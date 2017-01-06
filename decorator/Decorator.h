class Component
{
public:
	virtual ~Component();
	virtual void Operation();
protected:
	Component();
private:
};
class ConcreteComponent:public Component
{
public:
	ConcreteComponent();
	~ConcreteComponent();
	void Operation();
protected:
private:
};

class Decorator:public Component
{
public:
	Decorator(Component* com);
	virtual ~Decorator();
	void Operation();
protected:
private:
	Component* _com;
};

class ConcreteDecorator:public Decorator
{
public:
	ConcreteDecorator(Component* com);
	~ConcreteDecorator();
	void Operation();
	void AddedBehavior();
protected:
private:
	Component* _com;
};