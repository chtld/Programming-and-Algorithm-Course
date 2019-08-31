#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int temp) {
    if (temp < 2) {
        return false;
    } else if (temp == 2) {
        return true;
    }
    for (int i = 2; i < temp; ++ i) {
        if (temp % i == 0)
            return false;
    }
    return true;
}

int main () {
    int low, high;
    int sum1 = 0, sum2 = 0;
    int ans;
    cin >> low >> high;
    for (int i = low; i < high; ++ i) {
        int temp = i;
        if (isPrime(temp)) {
            sum1 += temp % 10;
            temp = temp / 10;
            sum2 += temp % 10;
        }
    }
    ans = (sum1 < sum2) ? sum1 : sum2;
    cout << ans << endl;
    return 0;
}