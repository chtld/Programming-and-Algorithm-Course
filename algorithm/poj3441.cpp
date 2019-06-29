#include<iostream>
#include<algorithm>
using namespace std;

int BinarySearch(int sum[], int left, int right, int target) {
    int mid, count = 0;
    int bd = right;
    while(left < right) {
        mid = left + (right - left) / 2;
        if (target <= sum[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    while (sum[left] == target && left < bd) {
        count++;
        left++;
    }
    return count;
}


int main(){
    int a[4000], b[4000], c[4000], d[4000];
    int sum1[16000000], sum2[16000000];
    int n;
    int num = 0;
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++ j) {
            sum1 [num] = a[i] + b[j];
            sum2 [num] = c[i] + d[j];
            num ++;
        }
    }
    sort(sum1, sum1 + num);
    sort(sum2, sum2 + num);
    for (int i = 0; i < num; ++ i) {
        count += BinarySearch(sum2, 0, num, -sum1[i]);
    }
    cout << count << endl;
    return 0;
}