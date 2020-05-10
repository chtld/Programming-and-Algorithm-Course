#include<iostream>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main(){
    int M, N;
    while (cin >> M >> N) {
        cout << gcd(M, N) << endl;
    }
    return 0;
}