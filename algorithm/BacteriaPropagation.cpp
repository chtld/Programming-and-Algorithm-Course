#include <iostream>

using namespace std;

int getdays(int mon1, int day1, int mon2, int day2){
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (mon1 == mon2) return day2 - day1;
	int days = month[mon1 - 1]- day1;
	for (int i = mon1 + 1; i < mon2; ++ i) {
		days += month[i - 1];
	}
	days += day2;
	return days;
}


int main(){
	int n = 0;
	cin >> n;
	while (n--) {
		int mon1, day1, mon2, day2;
		int num;
		cin >> mon1 >> day1 >> num >> mon2 >> day2;
		int days = getdays(mon1, day1, mon2, day2);
		//cout << days << endl;
		for (int i = 0; i < days; ++ i) {
			num <<= 1;
		}
		cout << num << endl;
	}
	return 0;
}