#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

struct CmpByValue {
  bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs) {
    return lhs.second > rhs.second;
  }
};

int main(){
	int N = 0;
	cin >> N;
	int a[1000] = {0};
	for(int i = 0; i < N; ++ i) cin >> a[i];
	map <int, int> mymap;
	for (int i = 0; i < N; ++ i) {
		for (int j = i + 1; j < N; ++ j) {
			mymap[(a[i]+a[j])]++;
		}
	}
	vector<pair<int,int>> name_score_vec(mymap.begin(), mymap.end());  
    sort(name_score_vec.begin(), name_score_vec.end(), CmpByValue());
	cout<<name_score_vec[0].first<<endl;
	for (int i = 1; i < name_score_vec.size(); ++ i) {
		if (name_score_vec[i].second >= name_score_vec[0].second){
			cout<<name_score_vec[i].first<<endl;
		}
		else break;
	}
	return 0;
}