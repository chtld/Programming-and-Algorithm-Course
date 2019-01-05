#include <iostream>

int main(){
  int n = 0;
  int array[1000] = {0};
  std::cin >> n;
  for(int i = 0; i < n; i++){
    std::cin >> array[i];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n - i - 1; j++){
      if(array[j] > array[j+1]){
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
  for(int i = 0; i < n; i++){
    std::cout << array[i] << std::endl;
  }
  return 0;
}
