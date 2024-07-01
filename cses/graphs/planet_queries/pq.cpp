#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;

#define endl '\n'

int find(int x, int k, vector<vector<int>> &up) {
  int i = 0;
  while (k) {
    if (k & 1)
      x = up[i][x];
    i++;
    k = k >> 1;
  }
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;
  vector<vector<int>> up(31, vector<int>(n));
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    up[0][i] = temp - 1;
  }
  for (int i = 1; i < 31; i++) {
    for (int j = 0; j < n; j++) {
      up[i][j] = up[i - 1][up[i - 1][j]];
    }
  }

  for (int i = 0; i < q; i++) {
    int x, k;
    cin >> x >> k;
    cout << find(x - 1, k, up) + 1 << endl;
  }

  return 0;
}
