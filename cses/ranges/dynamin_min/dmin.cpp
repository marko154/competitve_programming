#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct FW {
  vector<int> tree;
  int n;

  FW(int n) : n(n), tree(vector<int>(4 * n, 1e9)) {}

  void update(int i, int val) { _update(1, 0, n - 1, i, val); }
  void _update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
      tree[v] = val;
      return;
    }

    int mid = (tl + tr) / 2;
    if (pos <= mid)
      _update(2 * v, tl, mid, pos, val);
    else
      _update(2 * v + 1, mid + 1, tr, pos, val);
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
  }

  int get(int l, int r) { return _get(1, l, r, 0, n - 1); }
  int _get(int v, int l, int r, int tl, int tr) {
    if (l <= tl && tr <= r)
      return tree[v];
    if (r < tl || l > tr)
      return 1e9;
    int mid = (tl + tr) / 2;
    return min(_get(2 * v, l, r, tl, mid), _get(2 * v + 1, l, r, mid + 1, tr));
  }
};

int main() {
  ios::sync_with_stdio();
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  FW tree(n);

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    tree.update(i, t);
  }

  for (int i = 0; i < q; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 1)
      tree.update(b - 1, c);
    else
      cout << tree.get(b - 1, c - 1) << endl;
  }

  return 0;
}
