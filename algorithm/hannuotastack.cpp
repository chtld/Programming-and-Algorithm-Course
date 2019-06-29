#include <iostream>
#include <stack>
using namespace std;

struct problem
{
    int n;
    char cur, mid, dest;
    problem(int _n, char _cur, char _mid, char _dest):
    n(_n), cur(_cur), mid(_mid), dest(_dest)
    {}
};

int main(){
    int n;
    cin >> n;
    stack<problem> hanoi;
    hanoi.push(problem(n, 'A', 'B', 'C'));
    while(!hanoi.empty()) {
        problem temp = hanoi.top();
        hanoi.pop();
        if (temp.n == 1) {
            cout << temp.cur << "->" << temp.dest << endl;
        } else {
            hanoi.push(problem(temp.n-1, temp.mid, temp.cur, temp.dest));
            hanoi.push(problem(1, temp.cur, temp.mid, temp.dest));
            hanoi.push(problem(temp.n-1, temp.cur, temp.dest, temp.mid));
        }
    }
    return 0;
}