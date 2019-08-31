#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int GetMaxEnergy(int reactorCap, int numberOfRadLiquid
                , int crticalMass, int volumes[], int masses[], int energies[]) {
    int ans = 0;
    struct  Bottole
    {
        int vol;
        int mass;
        int energies;
        double density;
        bool operator<(const Bottole &a) {
            return density > a.density;
        }
    } bottole[35];
    for (int i = 0; i < numberOfRadLiquid; ++ i) {
        bottole[i].vol = volumes[i];
        bottole[i].mass = masses[i];
        bottole[i].energies = energies[i];
        bottole[i].density = (double)(energies[i])/(double)(volumes[i]);
    }
}
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