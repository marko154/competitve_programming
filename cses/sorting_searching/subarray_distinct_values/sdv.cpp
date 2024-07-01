#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> arr(n);
  for (auto &i : arr)
    cin >> i;

  unordered_map<ll, ll> m;
  m[arr[0]] = 1;
  ll l = 0, r = 1;
  ll ans = 0;

  while (l < n) {
    while (r < n) {
      if (m.size() == k && m.count(arr[r]) == 0)
        break;
      m.emplace(arr[r], 0);
      m[arr[r]]++;
      r++;
    }

    ans += r - l;
    m[arr[l]]--;
    if (m[arr[l]] == 0)
      m.erase(arr[l]);
    l++;
  }

  cout << ans << endl;

  return 0;
}
