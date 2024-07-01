
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, x;
  cin >> n >> x;
  vector<ll> coins(n);
  for (auto &c : coins)
    cin >> c;
  vector<vector<int>> dp() sort(coins.begin(), coins.end());

  for (auto c : coins)
    if (c <= x)
      dp[c] = 1;

  for (ll i = 0; i <= x; i++) {
    ll s = 0;
    for (auto j : coins)
      if (i - j >= 0)
        s += dp[i - j];
    dp[i] += s % mod;
  }

  cout << dp[x] % mod << endl;

  return 0;
}
