#include <iostream>

int main(){
  int row = 0, column = 0, array[100][100] = {0};
  std::cin >> row >> column;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      std::cin >> *(*(array + i) + j);
    }
  }
  for (int j = 0; j < column; j++) {
    int x = 0, y = j;
    while (y >= 0 && x < row) {
      std::cout << array[x][y] << std::endl;
      x++;
      y--;
    }
  }
  for (int i = 1; i < row; i++) {
    int x = i, y = column - 1;
    while (x < row && y >= 0){
      std::cout << array[x][y] << std::endl;
      x++;
      y--;
    }
  }
  return 0;
}
