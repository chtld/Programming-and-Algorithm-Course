#include <iostream>
#include <cstring>
using namespace std;

char map[101][101];
int done[101][101];
int n, m;
int minstep;

void path(int inx, int iny, int outx, int outy) {
  int count = done[inx][iny];
  if (inx == outx && iny == outy) {
    minstep = count;
  }
  count++;
  if (inx > 0 && map[inx - 1][iny] != '#' && done[inx - 1][iny] > count) {
    done[inx - 1][iny] = count;
    path(inx- 1, iny, outx, outy);
  }
  if (inx < n - 1 && map[inx + 1][iny] != '#' && done[inx + 1][iny] > count) {
    done[inx + 1][iny] = count;
    path(inx + 1, iny, outx, outy);
  }
  if (iny > 0 && map[inx][iny - 1] != '#' && done[inx][iny - 1] > count) {
    done[inx][iny - 1] = count;
    path(inx, iny - 1, outx, outy);
  }
  if (iny < n - 1 && map[inx][iny + 1] != '#' && done[inx][iny + 1] > count) {
    done[inx][iny + 1] = count;
    path(inx, iny + 1, outx, outy);
  }
}

int main(){
  int inx, iny, outx, outy;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
      if (map[i][j] == 'S') {
        inx = i;
        iny = j;
      }
      if (map[i][j] == 'T') {
        outx = i;
        outy = j;
      }
    }
  }
  memset(done, 2, sizeof(done));
  done[inx][iny] = 0;
  path(inx, iny, outx, outy);
  cout << minstep << endl;
  return 0;
}
