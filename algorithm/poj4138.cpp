#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

bool isPrime(int x) {
    if (x == 2)
        return true;
    for (int i = 2; i <= floor(sqrt(x)) + 1; ++ i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main(){
    int s, rlt = 0;
    scanf("%d", &s);
    for (int i =2; i <= s; ++ i) {
        if (isPrime(i)) {
            if (isPrime(s-i) && i*(s-i) > rlt) {
                rlt = i*(s-i);
            }
        }
    }
    printf("%d\n", rlt);
    return 0;
}