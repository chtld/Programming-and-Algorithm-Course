#include <iostream>
using namespace std;
//静态成员函数不能使用非静态成员函数和变量
class CRectangle{
	private:
		int w, h;
		static int nTotalArea;
		static int nTotalNumner;
	
	public:
		CRectangle(int w_, int h_);
		CRectangle(CRectangle &r);
		~CRectangle();
		static void PrintTotal();
};

CRectangle::CRectangle(CRectangle &r){
	w = r.w;
	h = r.h;
	nTotalNumner++;
	nTotalArea += w * h;
}

CRectangle::CRectangle(int w_, int h_){
	w = w_;
	h = h_;
	nTotalNumner++;
	nTotalArea += w * h;
}

CRectangle::~CRectangle(){
	nTotalNumner--;
	nTotalArea -= w*h;
}

void CRectangle::PrintTotal(){
	cout << nTotalNumner << "," << nTotalArea << endl;
}

int CRectangle::nTotalArea = 0;
int CRectangle::nTotalNumner = 0;


int main(){
	CRectangle r1(3, 3), r2(2, 2);
	CRectangle::PrintTotal();
	r1.PrintTotal();
	return 0;
}