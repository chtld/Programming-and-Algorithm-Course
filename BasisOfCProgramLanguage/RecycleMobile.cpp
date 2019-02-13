#include<iostream>

int main(){
  int m = 0, n = 0, a[100] = {0};
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    int temp = a[n-1];
    for (int j = n-1; j > 0; j--) {
      a[j] = a[j-1];
    }
    a[0] = temp;
  }
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " ";
  }
  return 0;
}
