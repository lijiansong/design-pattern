class Builder;
class Director
{
public:
	Director(Builder* bld);
	~Director();
	void Construct();
protected:
private:
	Builder* _bld;
};