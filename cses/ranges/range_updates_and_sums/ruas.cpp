
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;

struct FW {
  vector<ll> lazy;
  vector<ll> v_sum;
  vector<ll> override;
  vector<ll> size;
  ll n;
  FW(ll N) {
    n = N;
    lazy = vector<ll>(4 * n, 0); // this is only for the children
    v_sum = vector<ll>(4 * n, 0);
    override = vector<ll>(4 * n, 0);
    size = vector<ll>(4 * n, 0);
  }

  void assign(ll v, ll new_val) {
    override[v] = new_val;
    lazy[v] = 0;
    v_sum[v] = new_val * size[v];
  }
  void inc(ll v, ll diff) {
    lazy[v] += diff;
    v_sum[v] += diff * size[v];
  }

  void push(ll v) {
    if (override[v]) {
      assign(2 * v, override[v]);
      assign(2 * v + 1, override[v]);
      override[v] = 0;
    }
    inc(2 * v, lazy[v]);
    inc(2 * v + 1, lazy[v]);
    lazy[v] = 0;
  }
  void pull(ll v) { v_sum[v] = v_sum[2 * v] + v_sum[2 * v + 1]; }

  void update(ll l, ll r, ll val) { _update(1, 0, n - 1, l, r, val); }
  void _update(ll v, ll tl, ll tr, ll l, ll r, ll new_val) {
    size[v] = tr - tl + 1;
    if (tl > r || tr < l)
      return;
    if (l <= tl && tr <= r) {
      assign(v, new_val);
      return;
    }
    push(v);
    ll mid = (tl + tr) / 2;
    _update(2 * v, tl, mid, l, r, new_val);
    _update(2 * v + 1, mid + 1, tr, l, r, new_val);
    pull(v);
  }
  void _increase(ll v, ll tl, ll tr, ll l, ll r, ll diff) {
    if (tl > r || tr < l)
      return;
    if (l <= tl && tr <= r) {
      inc(v, diff);
      return;
    }
    push(v);
    ll mid = (tl + tr) / 2;
    _increase(2 * v, tl, mid, l, r, diff);
    _increase(2 * v + 1, mid + 1, tr, l, r, diff);
    pull(v);
  }

  void increase(ll l, ll r, ll diff) { _increase(1, 0, n - 1, l, r, diff); }

  ll _sum(ll v, ll tl, ll tr, ll l, ll r) {
    if (l <= tl && tr <= r)
      return v_sum[v];
    if (tl > r || tr < l)
      return 0;
    push(v);
    ll mid = (tl + tr) / 2;
    return _sum(2 * v, tl, mid, l, r) + _sum(2 * v + 1, mid + 1, tr, l, r);
  }

  ll sum(ll l, ll r) { return _sum(1, 0, n - 1, l, r); }
};

int main() {
  ll n, q;
  cin >> n >> q;
  FW tree(n);
  for (ll i = 0; i < n; i++) {
    ll val;
    cin >> val;
    tree.update(i, i, val);
  }

  for (ll i = 0; i < q; i++) {
    ll mode;
    cin >> mode;
    if (mode == 1) {
      ll a, b, x;
      cin >> a >> b >> x;
      tree.increase(a - 1, b - 1, x);
    } else if (mode == 2) {
      ll a, b, x;
      cin >> a >> b >> x;
      tree.update(a - 1, b - 1, x);
    } else {
      ll a, b;
      cin >> a >> b;
      cout << tree.sum(a - 1, b - 1) << endl;
    }
  }
  return 0;
}
