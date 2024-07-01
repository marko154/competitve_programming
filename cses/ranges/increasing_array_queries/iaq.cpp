
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;

// support range assignment, range sum
struct FW {
  ll n;
  vector<ll> override;
  vector<ll> v_sum;

  FW(ll n)
      : n(n), override(vector<ll>(4 * n, 0)), v_sum(vector<ll>(4 * n, 0)) {}

  void push(ll v, ll l_size, ll r_size) {
    if (!override[v])
      return;
    override[2 * v] = override[v];
    v_sum[2 * v] = l_size * override[v];
    override[2 * v + 1] = override[v];
    v_sum[2 * v + 1] = r_size * override[v];
    override[v] = 0;
  }
  void assign(ll l, ll r, ll new_val) { _assign(1, 0, n - 1, l, r, new_val); }

  void _assign(ll v, ll tl, ll tr, ll l, ll r, ll new_val) {
    if (tl > r || tr < l)
      return;
    if (l <= tl && tr <= r) {
      override[v] = new_val;
      v_sum[v] = (tr - tl + 1) * new_val;
      return;
    }
    ll mid = (tl + tr) / 2;
    push(v, mid - tl + 1, tr - mid);
    _assign(2 * v, tl, mid, l, r, new_val);
    _assign(2 * v + 1, mid + 1, tr, l, r, new_val);
    v_sum[v] = v_sum[2 * v] + v_sum[2 * v + 1];
  }

  ll get(ll l, ll r) { return _get(1, 0, n - 1, l, r); }

  ll _get(ll v, ll tl, ll tr, ll l, ll r) {
    if (tl > r || tr < l)
      return 0;
    ll size = (tr - tl + 1);
    if (l <= tl && tr <= r)
      return v_sum[v];
    ll mid = (tl + tr) / 2;
    push(v, mid - tl + 1, tr - mid);
    return _get(v * 2, tl, mid, l, r) + _get(v * 2 + 1, mid + 1, tr, l, r);
  }
};

int main() {
  ll n, q;
  cin >> n >> q;

  vector<pair<ll, ll>> stk;
  vector<ll> arr(n);
  vector<ll> pref(n + 1, 0);
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
    pref[i + 1] = arr[i] + pref[i];
  }

  unordered_map<ll, vector<pair<ll, ll>>> queries_starting_at;
  for (ll i = 0; i < q; i++) {
    ll a, b;
    cin >> a >> b;
    queries_starting_at[a - 1].push_back({b - 1, i});
  }

  vector<ll> ans(q);
  FW tree(n);

  for (ll i = n - 1; i >= 0; i--) {
    ll el = arr[i];
    while (stk.size() > 0 && stk.back().first < el)
      stk.pop_back();
    ll end = stk.size() > 0 ? stk.back().second : n;
    stk.push_back({el, i});
    tree.assign(i, end - 1, el);

    for (auto [r, idx] : queries_starting_at[i]) {
      ll actual = pref[r + 1] - pref[i];
      ans[idx] = tree.get(i, r) - actual;
    }
  }

  for (auto a : ans)
    cout << a << endl;

  return 0;
}
