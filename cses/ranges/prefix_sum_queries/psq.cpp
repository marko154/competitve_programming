#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

struct Node {
  ll sum = 0;
  ll pref = 0;
};

struct FW {
  vector<Node> tree;
  ll n;
  FW(ll n) : n(n), tree(vector<Node>(4 * n)) {}

  void update(ll pos, ll val) { _update(1, 0, n - 1, pos, val); }
  void _update(ll v, ll tl, ll tr, ll pos, ll val) {
    if (tl == tr) {
      tree[v] = {val, max((ll)0, val)};
      return;
    }
    ll mid = (tl + tr) / 2;

    if (pos <= mid)
      _update(2 * v, tl, mid, pos, val);
    else
      _update(2 * v + 1, mid + 1, tr, pos, val);
    tree[v] = {tree[2 * v].sum + tree[2 * v + 1].sum,
               max(tree[2 * v].pref, tree[2 * v].sum + tree[2 * v + 1].pref)};
  }

  ll get(ll l, ll r) { return _get(1, 0, n - 1, l, r).pref; }

  Node _get(ll v, ll tl, ll tr, ll l, ll r) {
    if (l == tl && tr == r)
      return tree[v];
    if (l > r)
      return {0, 0};
    ll mid = (tl + tr) / 2;
    Node left = _get(2 * v, tl, mid, l, min(mid, r));
    Node right = _get(2 * v + 1, mid + 1, tr, max(mid + 1, l), r);
    return {left.sum + right.sum, max(left.pref, left.sum + right.pref)};
  }
};

int main() {
  ll n, q;
  cin >> n >> q;
  FW tree(n);
  for (ll i = 0; i < n; i++) {
    ll v;
    cin >> v;
    tree.update(i, v);
  }

  // 2 is a query

  for (ll i = 0; i < q; i++) {
    ll mode;
    cin >> mode;

    if (mode == 1) {
      ll k, u;
      cin >> k >> u;
      tree.update(k - 1, u);
    } else {
      ll a, b;
      cin >> a >> b;
      cout << tree.get(a - 1, b - 1) << endl;
    }
  }

  return 0;
}
