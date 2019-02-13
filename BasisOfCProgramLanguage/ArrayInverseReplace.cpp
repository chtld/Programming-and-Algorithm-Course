#include <iostream>

int main(){
  int n = 0, a[100] = {0};
  std::cin >> n;
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  int left = 0, right = n-1;
  while(left < right){
    int temp = a[left];
    a[left] = a[right];
    a[right] = temp;
    left++;
    right--;
  }
  for(int i = 0; i < n; i++){
    std::cout << a[i] << " ";
  }
  return 0;
}
