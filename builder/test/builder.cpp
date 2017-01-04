#include <iostream>
using namespace std;

typedef enum MANTYPETag
{
	kFatMan,
	kThinMan,
	kNormal
}MANTYPE;

class Man
{
public:
	void SetHead(MANTYPE type){ m_Type = type; }
	void SetBody(MANTYPE type){ m_Type = type; }
	void SetLeftHand(MANTYPE type){ m_Type = type; }
	void SetRightHand(MANTYPE type){ m_Type = type; }
	void SetLeftFoot(MANTYPE type){ m_Type = type; }
	void SetRightFoot(MANTYPE type){ m_Type = type; }
	void ShowMan()
	{
		switch (m_Type)
		{
		case kFatMan:
			cout<<"I'm a fat man"<<endl;
			return;

		case kThinMan:
			cout<<"I'm a thin man"<<endl;
			return;

		default:
			cout<<"I'm a normal man"<<endl;
			return;
		}
	}

private:
	MANTYPE m_Type;
};

// Builder
class Builder
{
public:
	virtual void BuildHead(){}
	virtual void BuildBody(){}
	virtual void BuildLeftHand(){}
	virtual void BuildRightHand(){}
	virtual void BuildLeftFoot(){}
	virtual void BuildRightFoot(){}
	virtual Man *GetMan(){ return NULL; }
};

// FatManBuilder
class FatManBuilder : public Builder
{
public:
	FatManBuilder(){ m_FatMan = new Man(); }
	void BuildHead(){ m_FatMan->SetHead(kFatMan); }
	void BuildBody(){ m_FatMan->SetBody(kFatMan); }
	void BuildLeftHand(){ m_FatMan->SetLeftHand(kFatMan); }
	void BuildRightHand(){ m_FatMan->SetRightHand(kFatMan); }
	void BuildLeftFoot(){ m_FatMan->SetLeftFoot(kFatMan); }
	void BuildRightFoot(){ m_FatMan->SetRightFoot(kFatMan); }
	Man *GetMan(){ return m_FatMan; }

private:
	Man *m_FatMan;
};

// ThisManBuilder
class ThinManBuilder : public Builder
{
public:
	ThinManBuilder(){ m_ThinMan = new Man(); }
	void BuildHead(){ m_ThinMan->SetHead(kThinMan); }
	void BuildBody(){ m_ThinMan->SetBody(kThinMan); }
	void BuildLeftHand(){ m_ThinMan->SetLeftHand(kThinMan); }
	void BuildRightHand(){ m_ThinMan->SetRightHand(kThinMan); }
	void BuildLeftFoot(){ m_ThinMan->SetLeftFoot(kThinMan); }
	void BuildRightFoot(){ m_ThinMan->SetRightFoot(kThinMan); }
	Man *GetMan(){ return m_ThinMan; }

private:
	Man *m_ThinMan;
};

// Director
class Director
{
public:
	Director(Builder *builder) { m_Builder = builder; }
	void CreateMan();

private:
	Builder *m_Builder;
};

void Director::CreateMan()
{
	m_Builder->BuildHead();
	m_Builder->BuildBody();
	m_Builder->BuildLeftHand();
	m_Builder->BuildRightHand();
	m_Builder->BuildLeftHand();
	m_Builder->BuildRightHand();
}

int main(int argc, char *argv[])
{
	Builder *builderObj = new FatManBuilder();
	Director directorObj(builderObj);
	directorObj.CreateMan();
	Man *manObj = builderObj->GetMan();
	if (manObj == NULL)
		return 0;

	manObj->ShowMan();

	delete manObj;
	manObj = NULL;

	delete builderObj;
	builderObj = NULL;

	return 0;
};
