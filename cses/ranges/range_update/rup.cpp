
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct FW {
  vector<ll> tree;
  ll n;
  FW(ll n) : n(n), tree(vector<ll>(n + 1, 0)) {}
  void update(ll i, ll diff) {
    while (i <= n) {
      tree[i] += diff;
      i += i & (-i);
    }
  }
  ll get(ll i) {
    ll s = 0;
    while (i > 0) {
      s += tree[i];
      i -= i & (-i);
    }
    return s;
  }
};

int main() {
  ios::sync_with_stdio();
  cin.tie(0);

  ll n, q;
  cin >> n >> q;

  FW tree(n);
  ll prev = 0;

  for (ll i = 0; i < n; i++) {
    ll v;
    cin >> v;
    tree.update(i + 1, v - prev);
    prev = v;
  }

  for (ll i = 0; i < q; i++) {
    ll mode;
    cin >> mode;
    if (mode == 2) {
      ll idx;
      cin >> idx;
      cout << tree.get(idx) << endl;
    } else {
      ll l, r, diff;
      cin >> l >> r >> diff;
      tree.update(l, diff);
      tree.update(r + 1, -diff);
    }
  }

  return 0;
}
