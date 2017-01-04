#include <iostream>
#include <vector>
using namespace std;

class Builder;

// Product
class Product
{
public:
	void AddPart(const char *info) { m_PartInfoVec.push_back(info); }
	void ShowProduct()
	{
		for (std::vector<const char *>::iterator item = m_PartInfoVec.begin(); 
			item != m_PartInfoVec.end(); ++item)
		{
			cout<<*item<<endl;
		}
	}

private:
	std::vector<const char *> m_PartInfoVec;
};

// Builder
class Builder
{
public:
	virtual void BuildPartA() {}
	virtual void BuildPartB() {}
	virtual Product *GetProduct() { return NULL; }
};

// ConcreteBuilder
class ConcreteBuilder : public Builder
{
public:
	ConcreteBuilder() { m_Product = new Product(); }
	void BuildPartA()
	{
		m_Product->AddPart("PartA completed");
	}

	void BuildPartB()
	{
		m_Product->AddPart("PartB completed");
	}

	Product *GetProduct() { return m_Product; }

private:
	Product *m_Product;
};

// Director
class Director
{
public:
	Director(Builder *builder) { m_Builder = builder; }
	void CreateProduct()
	{
		m_Builder->BuildPartA();
		m_Builder->BuildPartB();
	}

private:
	Builder *m_Builder;
};

// main
int main()
{
	Builder *builderObj = new ConcreteBuilder();
	Director directorObj(builderObj);
	directorObj.CreateProduct();
	Product *productObj = builderObj->GetProduct();
	if (productObj == NULL)
	{
		return 0;
	}
	productObj->ShowProduct();

        delete productObj;
        productObj = NULL;
	delete builderObj;
	builderObj = NULL;
}
