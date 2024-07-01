#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

vector<vector<ll>> adj;
vector<ll> dp;
ll n, m;
ll mod = 1e9 + 7;

ll dfs(ll v) {
  if (v == n - 1)
    return 1;
  if (dp[v] != -1)
    return dp[v];
  ll ans = 0;
  for (auto out : adj[v]) {
    ans = (ans + dfs(out)) % mod;
  }
  return dp[v] = ans % mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  adj = vector<vector<ll>>(n);
  for (ll i = 0; i < m; i++) {
    ll fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    adj[fr].push_back(to);
  }
  dp = vector<ll>(n, -1);
  cout << dfs(0) << endl;

  return 0;
}
