#include <iostream>

int main(){
  int a[10] = {0}, n = 10;
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  int left = 0, right = n-1;
  while(left < right){
    while(a[left]%2 == 1){
      left++;
    }
    while(a[right]%2 == 0){
      right--;
    }
    if(left < right){
      int temp = a[left];
      a[left] = a[right];
      a[right] = temp;
    } else {
      break;
    }
  }
  for(int i = 0; i < left; i++){
    for(int j = 0; j < left - i - 1; j++){
      if(a[j] > a[j+1]){
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
  for(int i = left; i < n; i++){
    for(int j = left; j < n-i-1+left; j++){
      if(a[j] > a[j+1]){
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      } 
    }
  }
  for(int i = 0; i < n; i++){
    std::cout << a[i] <<" ";
  }
  return 0;
}
