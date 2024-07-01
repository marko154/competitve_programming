#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;

struct FW {
  vii tree;
  int n;
  vii grid;
  FW(vii &_grid) {
    n = _grid.size();
    grid = _grid;

    tree = vii(n + 1, vi(n + 1, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        update(i + 1, j + 1, grid[i][j]);
  }

  int get(int t, int l, int b, int r) {
    return get(b, r) - get(b, l - 1) - get(t - 1, r) + get(t - 1, l - 1);
  }

  int get(int r, int c) {
    int s = 0;
    while (r > 0) {
      int cc = c;
      while (cc > 0) {
        s += tree[r][cc];
        cc -= cc & (-cc);
      }
      r -= r & (-r);
    }
    return s;
  }

  void update(int r, int c, int new_val) {
    while (r <= n) {
      int cc = c;
      while (cc <= n) {
        tree[r][cc] += new_val;
        cc += cc & (-cc);
      }
      r += r & (-r);
    }
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  vii grid(n, vi(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      grid[i][j] = c == '*' ? 1 : 0;
    }
  }
  FW tree(grid);

  for (int i = 0; i < q; i++) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int r, c;
      cin >> r >> c;
      r--;
      c--;
      int new_val = grid[r][c] == 1 ? -1 : 1;
      grid[r][c] += new_val;
      tree.update(r + 1, c + 1, new_val);
    } else {
      int r1, c1, r2, c2;
      cin >> r1 >> c1 >> r2 >> c2;
      cout << tree.get(r1, c1, r2, c2) << endl;
    }
  }

  return 0;
}
