#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main() {
  ll n, k;
  cin >> n >> k;

  ordered_set s;

  for (ll i = 1; i <= n; i++)
    s.insert(i);
  auto it = s.find(1 + k % n);
  while (s.size() > 1) {
    // move forward k places and remove from set
    auto nxt = next(it);
    cout << *it << " ";
    s.erase(it);
    ll idx = s.order_of_key(*nxt);
    it = s.find_by_order((idx + k) % s.size());
  }
  cout << *s.begin() << endl;
  return 0;
}
