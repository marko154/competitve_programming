#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
#define ll long long

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> pref(n + 1, 0);

  for (ll i = 1; i <= n; i++) {
    cin >> pref[i];
    pref[i] += pref[i - 1];
  }

  multiset<int> ms;
  for (ll i = a; i <= b; i++) {
    ms.insert(pref[i]);
  }
  ll ans = *ms.rbegin();
  for (ll i = 1; i <= n; i++) {
    ms.extract(pref[i + a - 1]);
    if (i + b <= n)
      ms.insert(pref[i + b]);
    if (ms.size())
      ans = max(*ms.rbegin() - pref[i], ans);
  }
  cout << ans << endl;

  return 0;
}
