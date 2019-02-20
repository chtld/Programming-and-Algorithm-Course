#include<iostream>

int m = 0, n = 0;
int Find (char a[][100], int x, int y){
  int top = 0, bottom = 0, left = 0, right = 0;
  if (a[x][y] == 'T') {
    return 1;
  } else if (a[x][y] == '#') {
    return 100000;
  }
  if (x - 1 >= 0 && a[x - 1][y] == '.') top = 1 + Find(a, x - 1, y);
  if (x + 1 < n && a[x + 1][y] == '.') bottom = 1 + Find(a, x + 1, y);
  if (y - 1 >= 0 && a[x][y - 1] == '.') left = 1 + Find(a, x, y - 1);
  if (y + 1 < m && a[x][y + 1] == '.') right = 1 + Find(a, x, y + 1);
  int result = 100000;
  if (result > bottom && bottom > 0) result = bottom;
  else if (top < result && top > 0) result = top;
  else if (result > left && left > 0) result = left;
  else if (result > right && right > 0) result = right;
  return result;
}

int main(){
  char a[100][100] = {'\0'};
  int x = 0, y = 0;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
      if (a[i][j] = 'S') {
        x = i; y = j;
      }
    }
  }
  int result = Find(a, x, y);
  std::cout << result << std::endl;
  return 0;
}
