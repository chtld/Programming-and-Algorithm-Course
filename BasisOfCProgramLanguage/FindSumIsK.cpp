#include <iostream>

int main(){
  int n = 0, k = 0, a[1000] = {0};
  std::cin >> n >> k;
  for (int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  bool flag = false;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (flag = (a[i] + a[j] == k)){
        break;
      }
    }
    if(flag) break;
  }
  if (flag){
    std::cout << "yes" << std::endl;
  } else {
    std::cout << "no" << std::endl;
  }
  return 0;
}
