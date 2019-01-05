#include <iostream>

int main(){
  int N = 0, a[100] = {0};
  std::cin >> N;
  for(int i = 0; i < N; i++){
    int b = 0, nOne = 0;
    std::cin >> b;
    while(b){
      if(b%2 == 1){
        nOne++;
      }
      b = b/2;
    }
    a[i] = nOne;
  }
  for(int i = 0; i < N; i++){
    std::cout << a[i] << std::endl;
  }
  return 0;
}
