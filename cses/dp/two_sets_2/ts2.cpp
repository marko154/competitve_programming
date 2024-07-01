
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  ll S = n * (n + 1) / 2;
  if (S % 2) {
    cout << 0 << endl;
    return 0;
  }
  S /= 2;

  vector<vector<ll>> dp(n, vector<ll>(S + 1, 0));
  dp[0][1] = 1;

  for (int i = 1; i < n; i++)
    for (int s = 0; s <= S; s++) {
      dp[i][s] = dp[i - 1][s] % mod;
      if (s - i - 1 >= 0)
        dp[i][s] += dp[i - 1][s - i - 1] % mod;
    }

  cout << dp[n - 1][S] % mod << endl;

  return 0;
}
