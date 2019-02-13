#include <iostream>

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int Part(int *arr, int start, int end){
  int left = start;
  int right = end;
  int key = arr[end];
  while (left < right) {
    while (left < right && arr[left] <= key) {
      left++;
    }
    while (left < right && arr[right] >= key) {
      right--;
    }
    if (left < right) {
      swap(arr[left], arr[right]);
    }
  }
  swap(arr[right], arr[end]);
  return left;
}

int getMidNum(int *arr, int size){
  int left = 0;
  int right = size - 1;
  int mid = (size - 1) / 2;
  int div = Part(arr, left, right);
  while (div != mid) {
    if (mid < div) {
      div = Part(arr, left, div - 1);
    } else {
      div = Part(arr, div + 1, right);
    }
  }
  return (size & 0x1) ? arr[mid] : (arr[mid] + arr[mid+1])/2;
}


int main(){
  int N = 0, a[15000] = {0};
  while (true) {
    std::cin >> N;
    if (N == 0) break;
    for (int i = 0; i < N; i++) {
      std::cin >> a[i];
    }
    int median = getMidNum(a, N);
    std::cout << median << std::endl;
  }
  return 0;
}
