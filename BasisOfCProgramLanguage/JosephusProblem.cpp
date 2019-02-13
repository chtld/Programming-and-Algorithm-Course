#include <iostream>

int main(){
  int n = 0, m = 0;
  while(true){
    std::cin >> n >> m;
    if(n == 0){
      break;
    }
    int precedent[300] = {0}, succedent[300] = {0};
    for(int i = 0; i < n; i++){
      precedent[i] = i - 1;
      succedent[i] = i + 1;
    }
    precedent[0] = n - 1;
    succedent[n-1] = 0;
    int current = 0, pre = precedent[0], suc = succedent[0];
    while(true){
      if(pre == suc){
        std::cout << current + 1 << std::endl;
        break;
      }
      for(int i = 0; i < m - 1; i++){
        current = succedent[current];
      }
      pre = precedent[current];
      suc = succedent[current];
      succedent[pre] = suc;
      precedent[suc] = pre;
      current = suc;
    }
  }
  return 0;
}
