
#include <bits/stdc++.h>
using namespace std;

int find(int x, int k, vector<vector<int>> up) {
  int i = 0;
  while (k != 0 && x != 0) {
    if (k & 1)
      x = up[i][x];
    k = k >> 1;
    i++;
  }

  if (x == 0)
    return -1;
  return x;
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> up(18, vector<int>(2 * 1e5 + 10, 0));
  up[0][1] = 0;
  for (int i = 2; i <= n; i++) {
    cin >> up[0][i];
  }

  for (int i = 1; i < 18; i++) {
    for (int j = 2; j <= n; j++) {
      up[i][j] = up[i - 1][up[i - 1][j]];
    }
  }

  for (int i = 0; i < q; i++) {
    int x, k;
    cin >> x >> k;
    cout << find(x, k, up) << endl;
  }

  return 0;
}
