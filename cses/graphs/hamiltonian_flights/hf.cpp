#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;
// #define endl '\n'
typedef long long ll;

ll mod = 1e9 + 7;
ll n, m;
ll dp[20][1 << 20];
vector<ll> adj[20];

ll solve(ll v, ll used_mask) {
  if (dp[v][used_mask]) {
    return dp[v][used_mask];
  }
  ll ans = 0;

  for (ll out : adj[v]) {
    if (out != n - 1) {
      if (!(used_mask & (1 << out))) {
        ll mask = used_mask | (1 << out);
        ans += solve(out, mask);
      }
    } else if (__builtin_popcount(used_mask) == n - 1) {
      ans += 1;
    }
  }

  return dp[v][used_mask] = ans % mod;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for (ll i = 0; i < m; i++) {
    ll fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    adj[fr].push_back(to);
  }

  // dp = vector<vector<ll>>(n, vector<ll>(1 << n, 0));
  dp[n - 1][(1 << n) - 1] = 1;

  cout << solve(0, 1) << endl;
}
