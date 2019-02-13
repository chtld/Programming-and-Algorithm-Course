#include<iostream>

int days = 0;
int getDayOfWeek();
int getYear();
int getMonth(bool isLeapYear);

int main(){
  int year = 0, month = 0, dayOfWeek = 0;
  bool isLeapYear = true;
  char week[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday",
                      "Wednesday", "Thursday", "Friday"};
  while ((std::cin >> days) && days != -1) {
    dayOfWeek = getDayOfWeek();
    year = getYear();
    isLeapYear = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
    month = getMonth(isLeapYear);
    std::cout << year << "-" << month << "-" << ++days
              << " " << week[dayOfWeek] << std::endl;
  }
  return 0;
}

int getDayOfWeek(){
  int dayOfWeek = 0;
  dayOfWeek = days % 7;
  return dayOfWeek;
}

int getYear(){
  int i = 2000;
  bool isLeapYear = true;
  while (true) {
    isLeapYear = (i % 4 == 0 && i % 100 != 0 || i % 400 == 0);
    if (isLeapYear && days >= 366) {
      days -= 366;
      i++;
    } else if (!isLeapYear && days >= 365) {
      days -= 365;
      i++;
    } else {
      break;
    }
  }
  return i;
}

int getMonth(bool isLeapYear){
  int pmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int rmonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int month = 0;
  while (true) {
    if (isLeapYear && days >= rmonth[month]) {
      days = days - rmonth[month];
      month++;
    } else if (!isLeapYear && days >= pmonth[month]) {
      days = days - pmonth[month];
      month++;
    } else {
      break;
    }
  }
  return ++month;
}
