class  CType{
public:
	int num;
	CType(){}
	CType(int n):num(n){}
	void setvalue(int n){
		num = n;
	}
	CType operator++(int){
		int temp = num;
		num = num * num;
		return CType(temp);
	}
	friend ostream& operator<<(ostream& os, CType temp);
};
ostream& operator <<(ostream& os, const CType temp){
	os << temp.num;
	return os;
}
