#include <iostream>

int main(){
  int m = 0, n = 0;
  std::cin >> m >> n;
  int sum  = 0;
  for(int i = m; i <= n; i++){
    if(i%2 == 1){
      sum += i;
    }
  }
  std::cout << sum << std::endl;
  return 0;
}
