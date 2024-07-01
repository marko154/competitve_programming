#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

struct Node {
  ll pref, suff, ans, sum;
};

struct FW {
  vector<Node> tree;
  int n;
  FW(int n) : n(n), tree(vector<Node>(4 * n, {0, 0, 0, 0})) {}

  void update(int pos, ll val) { _update(1, 0, n - 1, pos, val); }
  void _update(int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) {
      tree[v] = {val, val, val, val};
      return;
    }
    int mid = (tl + tr) / 2;
    if (pos <= mid)
      _update(2 * v, tl, mid, pos, val);
    else
      _update(2 * v + 1, mid + 1, tr, pos, val);
    tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
  }
  Node combine(Node l, Node r) {
    return {max(l.sum + r.pref, l.pref), max(r.sum + l.suff, r.suff),
            max(max(r.ans, max(l.suff + r.pref, l.ans)), (ll)0), l.sum + r.sum};
  }

  ll query() { return tree[1].ans; }
};

int main() {
  int n, m;
  cin >> n >> m;

  FW tree(n);
  int t;

  for (int i = 0; i < n; i++) {
    cin >> t;
    tree.update(i, t);
  }
  int k, x;
  for (int i = 0; i < m; i++) {
    cin >> k >> x;
    tree.update(k - 1, x);
    cout << max(tree.query(), (ll)0) << endl;
  }

  return 0;
}
