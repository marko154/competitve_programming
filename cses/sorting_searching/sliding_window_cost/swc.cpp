#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define endl '\n'

using namespace std;

#define ll long long
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

struct FW {
  vector<ll> tree;
  ll n;
  FW(ll n) : n(n), tree(vector<ll>(n + 1, 0)) {}

  void update(ll i, ll diff) {
    i++;
    while (i <= n) {
      tree[i] += diff;
      i += i & (-i);
    }
  }

  ll get(ll i) {
    i++;
    ll s = 0;
    while (i > 0) {
      s += tree[i];
      i -= i & (-i);
    }
    return s;
  }
};

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> arr(n);

  for (ll i = 0; i < n; i++)
    cin >> arr[i];
  vector<ll> sorted = arr;
  sort(sorted.begin(), sorted.end());
  sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

  ll s = 0;
  FW tree(sorted.size());
  FW present(sorted.size());

  auto idx = [&](ll val) {
    return lower_bound(sorted.begin(), sorted.end(), val) - sorted.begin();
  };

  ll un = sorted.size();
  ordered_set ms;

  for (ll i = 0; i <= n; i++) {
    if (i < k) {
      s += arr[i];
      ms.insert({arr[i], i});
      ll pos = idx(arr[i]);
      tree.update(pos, arr[i]);
      present.update(pos, 1);
    } else {
      ll cur = ms.find_by_order((k - 1) / 2)->first;
      ll first_larger =
          lower_bound(sorted.begin(), sorted.end(), cur + 1) - sorted.begin();
      ll n_left = present.get(first_larger - 1);
      ll n_right = present.get(un - 1) - n_left;
      ll left = tree.get(first_larger - 1);
      ll right = tree.get(un - 1) - left;
      ll cost = n_left * cur - left + right - n_right * cur;
      cout << cost << " ";
      if (i == n)
        break;
      s -= arr[i - k];
      ms.erase(ms.lower_bound({arr[i - k], 0}));
      ll pos = idx(arr[i - k]);
      tree.update(pos, -arr[i - k]);
      present.update(pos, -1);

      s += arr[i];
      ms.insert({arr[i], i});
      pos = idx(arr[i]);
      tree.update(pos, arr[i]);
      present.update(pos, 1);
    }
  }

  return 0;
}
