struct CMy_add{
	int* p;
	CMy_add(int & sum){p = &sum;};
	void operator()(int s){
		s = 0x00000007 & s;
		(*p) += s;
	}
};