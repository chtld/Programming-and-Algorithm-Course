#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int count = 0;
    for (int i = 0; i < c/a + 1; ++ i) {
        for (int j = 0; j < c/b + 1; ++ j) {
            if (a*i + b*j == c) {
                count ++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}