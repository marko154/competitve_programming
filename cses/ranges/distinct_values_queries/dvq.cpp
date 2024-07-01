#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;

struct FW {
  vector<ll> tree;
  ll n;
  FW(ll n) : n(n), tree(n + 1, 0) {}

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
  ll n, q;
  cin >> n >> q;
  vector<ll> arr(n);
  vector<array<int, 3>> qs(q);

  for (auto &el : arr)
    cin >> el;

  for (int i = 0; i < q; i++) {
    cin >> qs[i][1] >> qs[i][0];
    qs[i][2] = i;
  }

  sort(qs.begin(), qs.end());
  map<ll, ll> prev;
  vector<int> ans(q);
  FW tree(n);
  ll i = 1;
  for (auto [b, a, idx] : qs) {
    // cout << a << " " << b << " " << idx << endl;
    while (i <= b) {
      if (prev.count(arr[i - 1]) > 0) {
        tree.update(prev[arr[i - 1]], -1);
      }
      tree.update(i, 1);
      prev[arr[i - 1]] = i;
      i++;
    }
    ans[idx] = tree.get(b) - tree.get(a - 1);
  }

  for (auto el : ans)
    cout << el << endl;

  return 0;
}
