#include <iostream>
#include <cstdio>

int main(){
  int year = 0, month = 0, day = 0;
  scanf("%d-%d-%d", &year, &month, &day);
  int pmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int rmonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  bool isLeapYear = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
  int monthDays = 0;
  if (isLeapYear) {
    monthDays = rmonth[month - 1];
  } else {
    monthDays = pmonth[month - 1];
  }
  if (day + 1 > monthDays) {
    day = day + 1 - monthDays;
    if (month + 1 > 12) {
      year += 1;
    }
    month = (month + 1) % 12;
  } else {
    day += 1;
  }
  printf("%d-%02d-%02d\n", year, month, day);
  return 0;
}
