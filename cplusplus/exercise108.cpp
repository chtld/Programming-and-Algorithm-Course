#include <iostream>
#include <bitset>
using namespace std;

int main(){
	int t = 0;
	cin >> t;
	while (t--) {
		int n, i, j;
		cin >> n >> i >> j;
		bitset<32> bstn(n);
		bitset<32> bstk(0);
		bstk[i] = bstn[i];
		bstk[j] = bstn[j];
		bstk.flip(j);
		for (int m = i + 1; m < j; ++ m) {
			bstk.set(m);
		}
		int k = bstk.to_ulong();
		cout << hex << k << endl;
	}
	return 0;
}