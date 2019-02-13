#include <iostream>

int main(){
  int n = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++){
    int x = 0;
    double tRide = 0.0, tWalk = 0.0;
    std::cin >> x;
    tWalk = x/1.2;
    tRide = 27.0 + 23.0 + x/3.0;
    if (tWalk > tRide) {
      std::cout << "Bike" << std::endl;
    } else if (tWalk == tRide) {
      std::cout << "All" << std::endl;
    } else {
      std::cout << "Walk" << std::endl;
    }
  }
  return 0;
}
