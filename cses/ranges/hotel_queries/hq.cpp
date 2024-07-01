
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct SegTree {
  vector<int> tree;
  int n;
  SegTree(int n) : n(n), tree(vector<int>(4 * n, 0)) {}

  void update(int pos, int val) { _update(1, 0, n - 1, pos, val); }

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
    tree[v] = max(tree[2 * v], tree[2 * v + 1]);
  }
  pair<int, int> query(int val) {
    // pos, val
    return _query(1, 0, n - 1, val);
  }
  pair<int, int> _query(int v, int tl, int tr, int val) {
    if (tree[v] < val)
      return {-1, -1};
    if (tl == tr) {
      return {tl, tree[v]};
    }
    int mid = (tl + tr) / 2;
    if (tree[2 * v] >= val) {
      return _query(2 * v, tl, mid, val);
    }
    return _query(2 * v + 1, mid + 1, tr, val);
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  SegTree tree(n);

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    tree.update(i, t);
  }
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    auto [pos, val] = tree.query(t);
    if (pos == -1) {
      cout << 0 << endl;
    } else {
      cout << pos + 1 << endl;
      tree.update(pos, val - t);
    }
  }

  return 0;
}
