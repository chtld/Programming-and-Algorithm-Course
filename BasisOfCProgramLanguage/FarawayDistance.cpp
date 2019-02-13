#include <iostream>
#include <cmath>
#include <iomanip>

double distance(double x, double y, double x0, double y0){
  return sqrt(pow(x - x0, 2) + pow(y - y0, 2));
}

int main(){
  double dist = 0.0, a[100][2] = {0};
  int n = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i][0] >> a[i][1];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j++) {
      double dist1 = distance(a[i][0], a[i][1], a[j][0], a[j][1]);
      dist = (dist1 > dist) ? dist1 : dist;
    }
  }
  std::cout << std::fixed << std::setprecision(4) << dist << std::endl;
  return 0;
}
