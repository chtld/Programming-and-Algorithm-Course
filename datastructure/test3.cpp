#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
void SalarySort(int num, int salaries[], int result[]);
int main(){
    int result[100005];
    int num = 19;
    int salries[] = {10000,20000,40000,30000,30000,30000,40000,20000,50000,50000,50000,50000,60000,60000,60000,70000,80000,90000,100000};
    SalarySort(num, salries, result);
    for (int i = 0; i < num; ++ i) {
        cout << result[i] << " ";
    }
    return 0;
}


void SalarySort(int num, int salaries[], int result[]) {
    //int result[100005];
    struct Salary
    {
        int times;
        int salary;
        bool operator<(const Salary &b) {
            return times > b.times;
        }
    } salar[100005];
    bool flag = false;
    int numb = 0;
    for (int i = 0; i < num; ++ i) {
        flag = false;
        for (int j = 0; j < numb; ++ j) {
            if (salar[j].salary ==  salaries[i]) {
                salar[j].times++;
                flag = true;
                break;
            }
        }
        if (!flag) {
            salar[numb].salary = salaries[i];
            salar[numb].times = 1;
            numb++;
        }
    }
    sort(salar, salar + numb);
    int index = 0;
    for (int i = 0; i < numb; ++ i) {
        for (int j = 0; j < salar[i].times; ++ j) {
            result[index] = salar[i].salary;
            index++;
        }
    }
    return;
}