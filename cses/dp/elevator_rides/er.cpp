#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

ll n, x;
vector<ll> w;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> x;
  w = vector<ll>(n);
  for (auto &i : w)
    cin >> i;

  vector<pair<ll, ll>> dp(1 << n);
  dp[0] = make_pair(1, 0);

  for (int mask = 1; mask < (1 << n); mask++) {
    dp[mask] = {1e9, 1e9};
    for (int b = 0; b < n; b++) {
      if (mask & (1 << b)) {
        auto [pk, pW] = dp[mask ^ (1 << b)];
        if (pW + w[b] <= x) {
          pW += w[b];
        } else {
          pk++;
          pW = w[b];
        }

        if (pk < dp[mask].first ||
            (pk == dp[mask].first && dp[mask].second > pW)) {
          dp[mask] = {pk, pW};
        }
      }
    }
  }

  cout << dp.back().first << endl;

  return 0;
}
