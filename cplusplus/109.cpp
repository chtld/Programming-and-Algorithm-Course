class A{
public:
	int num;
	A(int k):num(k){};
	virtual void print() const{
		cout << "A" << " " << num <<endl;
	}
};
class B:public A{
public:
	B(int k):A(k){};
	virtual void print() const{
		cout << "B" << " " << num <<endl;
	}
};


struct Comp{
	bool operator()(const A * a, const A * b){
		return a->num < b->num;
	}
};
void Print(const A* p){
	p->print();
}