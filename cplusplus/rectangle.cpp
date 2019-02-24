#include <iostream>
using namespace std;


class rectangle{
	public:
	int w, h;
	void Init(int w_, int h_){
		w = w_;
		h = h_;
	}
	int Area(){
		return w * h;
	}
	int Perimenter(){
		return 2*(w + h);
	}
};


int main(){
	int w, h;
	rectangle r;
	cin >> w >> h;
	r.Init(w, h);
	cout << r.Area() << endl << r.Perimenter() << endl;
	return 0;
}