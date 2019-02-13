#include<iostream>

int main(){
  for (int i = 1; i < 5; i++) { //鄱阳
    for (int j = 1; j < 5; j ++) { //洞庭
      for (int k = 1; k < 5; k++) { //太湖
        for (int l = 1; l < 5; l++){ //洪泽
          if (i != j && i != k && i != l && j != k && j !=l && k!=l) {
            int A = (j == 1) + (l == 4) + (i == 3);
            int B = (l == 1) + (j == 4) + (i == 2) + (k == 3);
            int C = (l == 4) + (j == 3);
            int D = (i == 1) + (k == 4) + (l == 2) + (j == 3);
            if(A == 1 && B == 1 && C == 1 && D == 1) {
              std::cout << i << std::endl
                        << j << std::endl
                        << k << std::endl
                        << l << std::endl;
              return 0;
            }
          }
        }
      }
    }
  }
  return 0;
}
