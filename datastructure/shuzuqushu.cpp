#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n, t;
    vector<int> arr;
    cin >> n >> t;
    if (t < 0) t = t * (-1);
    int val;
    for (int i = 0; i < n; ++ i) {
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());
    int left = 0, right = left + 1;
    int count = 0;
    while (left < n && right < n) {
        if (left >= right) right++;
        if (left > 0 && right > 0) {
            while (arr[left] == arr[left - 1] ) left++;
            while (arr[right] == arr[right - 1] ) right++;
            if (left >= n || right >= n)
                break;
        }
        if (arr[right] - arr[left] > t) {
            left++;
        } else if (arr[right] - arr[left] < t) {
            right++;
        } else {
            count++;
            left++;
            right++;
        }
    }
    cout << count << endl;
    return 0;
}