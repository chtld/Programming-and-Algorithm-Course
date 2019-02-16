#include <iostream>
#include <iomanip>

int main(){
  double personSum[3] = {0}, typeSum[3] = {0};
  for (int i = 0; i < 3; i++) {
    int id = 0, num = 0;
    std::cin >> id >> num;
    for (int j = 0; j < num; j++){
      char type = '\0';
      double money = 0.0;
      std::cin >> type >> money;
      personSum[id - 1] += money;
      typeSum[type - 'A'] += money;
    }
  }
  for (int i = 0; i < 3; i++) {
    std::cout << i + 1 << ' ' << std::fixed
              << std::setprecision(2) << personSum[i] << std::endl;
  }
  for (int i = 0; i < 3; i++) {
    std::cout << (char)(i + 'A') << ' ' << std::fixed
              << std::setprecision(2) << typeSum[i] << std::endl;
  }
  return 0;
}
