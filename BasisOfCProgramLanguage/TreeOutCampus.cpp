#include <iostream>

int main(){
  int L = 0, M = 0;
  int a[10001] = {0};
  std::cin >> L >> M;
  for (int i = 0; i < M; i++) {
    int start = 0, end = 0;
    std::cin >> start >> end;
    for (int j = start; j <= end; j++) {
      a[j] = 1;
    }
  }
  int num = 0;
  for (int i = 0; i <= L; i++) {
    if(a[i] == 0) num++;
  }
  std::cout << num << std::endl;
  return 0;
}
