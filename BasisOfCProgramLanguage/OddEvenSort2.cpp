#include <iostream>

int main(){
  int a[10] = {0}, n = 10;
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n-i-1; j++){
      bool leftIsEven = (a[j]%2 == 0);
      bool rightIsEven = (a[j+1]%2 == 0);
      if((leftIsEven && !rightIsEven)||
         (leftIsEven == rightIsEven) && (a[j] > a[j+1])){
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
  for(int i = 0; i < n; i++){
    std::cout << a[i] << ' ';
  }
  return 0;
}
