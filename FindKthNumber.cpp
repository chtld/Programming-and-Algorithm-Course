#include <iostream>

int partition(int a[], int left, int right);
int FindKthNumber(int a[], int k, int left, int right);

int main(){
  int n = 0, k = 0, a[10000] = {0};
  std::cin >> n >> k;
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  int left = 0, right = n - 1;
  int number = FindKthNumber(a, k, left, right);
  std::cout << number << std::endl;
  return 0;
}

int FindKthNumber(int a[], int k, int left, int right){
  int index = partition(a, left, right);
  if(index == k - 1) return a[index];
  else if(index < k - 1){
    return FindKthNumber(a, k, index + 1, right);
  } else {
    return FindKthNumber(a, k, left, index -1);
  }
}

int partition(int a[], int left, int right){
  int temp = a[left];
  while(left < right){
    while(a[right] <= temp && left < right){
      right--;
    }
    a[left] = a[right];
    while(a[left] >= temp && left < right){
      left++;
    }
    a[right] = a[left];
  }
  a[left] = temp;
  return left;
}
