#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

struct FW {
  vector<ll> tree;
  ll n;
  FW(ll n) : n(n), tree(vector<ll>(4 * n, 1e18)) {}

  void update(ll pos, ll val, int dbg = 0) {
    _update(1, 0, n - 1, pos, val, dbg);
  }
  void _update(ll v, ll tl, ll tr, ll pos, ll val, int dbg) {
    if (dbg) {
      cout << "dbg v, tl, tr, pos, val " << v << " " << tl << " " << tr << " "
           << pos << " " << val << endl;
    }
    if (tl == tr) {
      tree[v] = val;
      return;
    }
    ll mid = tl + (tr - tl) / 2;

    if (pos <= mid)
      _update(2 * v, tl, mid, pos, val, dbg);
    else
      _update(2 * v + 1, mid + 1, tr, pos, val, dbg);
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
  }
  ll get(ll l, ll r) { return _get(1, 0, n - 1, l, r); }
  ll _get(ll v, ll tl, ll tr, ll l, ll r) {
    if (l <= tl && tr <= r)
      return tree[v];
    if (tl > r || tr < l)
      return 1e18;
    ll mid = tl + (tr - tl) / 2;
    return min(_get(2 * v, tl, mid, l, r), _get(2 * v + 1, mid + 1, tr, l, r));
  }
};

int main() {
  ll n, q;
  cin >> n >> q;
  FW pos(n);
  FW neg(n);
  for (ll i = 0; i < n; i++) {
    ll t;
    cin >> t;
    pos.update(i, t + i);
    neg.update(i, t - i);
  }

  for (ll i = 0; i < q; i++) {
    ll mode;
    cin >> mode;
    if (mode == 1) {
      ll k, x;
      cin >> k >> x;
      // cout << "!!!! " << k << " " << x << endl;
      // continue;
      pos.update(k - 1, x + (k - 1), 0);
      neg.update(k - 1, x - (k - 1), 0);
    } else {
      ll k;
      cin >> k;
      ll ans = 1e18;
      if (k - 2 >= 0)
        ans = min(ans, (k - 1) + neg.get(0, k - 2));
      if (k <= n - 1)
        ans = min(ans, pos.get(k - 1, n - 1) - (k - 1));
      cout << ans << endl;
    }
  }

  return 0;
}
