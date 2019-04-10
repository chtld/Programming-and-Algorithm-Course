#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
	Complex & operator=(const char *s){
		const char *ptr = strchr(s, '+');
		int pos = ptr - s;
		char s1[20];
		for (int i = 0; i < pos; i++) {
			s1[i] = s[i];
		}
		s1[pos] = '\0';
		r = atof(s1);
		int j = 0;
		for (int i = pos + 1; s[i] != 'i'; i++) {
			s1[j] = s[i];
			j++;
		}
		s1[j] = '\0';
		i = atof(s1);
	}
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}