#include<iostream>
#include<algorithm>

using namespace std;

class DNA{
public:
    string str;
    int i;
    int inverse;
    DNA(){}
};
struct cmp{
    bool operator()(DNA d1, DNA d2){
        if (d1.inverse < d2.inverse) {
            return true;
        } else if (d1.inverse > d2.inverse) {
            return false;
        } else {
            return d1.i < d2.i;
        }
    }
};

DNA dna[105];

int inv(string str){
    int res = 0;
    for (int i = 0; i < str.size(); ++ i) {
        for (int j = i + 1; j < str.size(); ++ j) {
            if (str[j] < str[i]) {
                res++;
            }
        }
    }
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++ i) {
        cin >> dna[i].str;
        dna[i].i = i;
        dna[i].inverse = inv(dna[i].str);
    }
    sort(dna, dna + m, cmp());
    for (int i = 0; i < m; ++ i) {
        cout << dna[i].str << endl;
    }
    return 0;
}