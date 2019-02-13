#include <iostream>

int main(){
  int n = 0;
  std::cin >> n;
  for(int i = 10; i < n + 1; i++){
    int x = i, m = 0;
    while(x){
      m += x%10;
      x /= 10;
    }
    if(i%m == 0){
      std::cout << i << std::endl;
    }
  }
  return 0;
}
