#include<iostream>

using namespace std;

int main(){
    int p, count = 0;
    cin >> p;
    if (p < 12) {
        count = 0;
    } else {
        for (int a = 3; a < p/3; ++ a) {
            double b = p - (double) p * p /(2 * p - 2 * a);
            if (a < b && b - (int) b < 1e-5) {
                count ++;
            }
        }
    }
    cout << count << endl;
    return 0;
}