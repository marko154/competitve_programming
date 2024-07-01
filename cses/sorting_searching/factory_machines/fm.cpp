#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n_products(vector<ll> machines, ll time, ll t) {
  ll ans = 0;
  for (auto machine : machines) {
    ans += time / machine;
    if (ans > t)
      return t;
  }
  return ans;
}

int main() {
  ll n, t;
  cin >> n >> t;
  vector<ll> arr(n);
  for (auto &i : arr)
    cin >> i;
  ll l = 0;
  ll r = 10e17;

  while (l < r) {
    ll mid = l + (r - l) / 2;
    ll prods = n_products(arr, mid, t);
    if (prods < t) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }

  cout << r << endl;

  return 0;
}
