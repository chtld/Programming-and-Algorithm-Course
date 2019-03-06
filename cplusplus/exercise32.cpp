#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }
	Sample(Sample &tmp){
		v = 2*tmp.v;
	}
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}