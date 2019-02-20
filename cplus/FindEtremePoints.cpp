#include <iostream>
#include <algorithm>

struct point{
  int x = 0,y = 0;
};

bool cmp(point a, point b){
  if (a.x != b.x) {
    return a.x < b.x;
  } else {
    return a.y < b.y;
  }
}

int main(){
  int n = 0;
  std::cin >> n;
  point a[100];
  bool b[100] = {false};
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].x >> a[i].y;
  }
  std::sort(&a[0], &a[n], cmp);
  int maxy = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i].y > maxy) {
      b[i] = true;
      maxy = a[i].y;
    }
  }
  bool flag = true;
  for (int i = 0; i < n; i++){
    if (b[i]) {
      if (flag) {
        std::cout << "(" << a[i].x << "," << a[i].y << ")";
        flag = false;
      }
      else std::cout << "," << "(" << a[i].x << "," << a[i].y << ")";
    }
  } 
  return 0;
}
