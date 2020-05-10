#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int indegree[110];
vector<int> edge[110];
bool visited[110];
int v, e;

struct cmp{
	bool operator()(const int& a, const int& b) {
		return a > b;
	}
};

void topologysort() {
    priority_queue<int, vector<int>, cmp> pq;
    for (int i = 1; i <= v; ++i) {
        if (indegree[i] == 0) {
            pq.push(i);
            visited[i] = true;
        }
    }
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        cout << "v" << cur << " ";
        for (int i = 0; i < edge[cur].size(); ++ i) {
            indegree[edge[cur][i]]--;
        }
        for (int i = 1; i <= v; ++ i) {
            if (visited[i] == false && indegree[i] == 0) {
                visited[i] = true;
                pq.push(i);
            }
        }
    }
    cout << endl;
}


int main(){
    cin >> v >> e;
    memset(indegree, 0, sizeof(indegree));
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < e; ++ i) {
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
        indegree[to]++;
    }
    topologysort();
    return 0;
}