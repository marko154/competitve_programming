
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

vector<vector<ll>> adj;
vector<ll> dp;
vector<ll> nxt;
ll n, m;

ll dfs(ll v) {
  if (v == n - 1)
    return 0;
  if (dp[v] != -1)
    return dp[v];
  ll ans = -1e9;
  for (auto out : adj[v]) {
    ll curr = 1 + dfs(out);
    if (curr > ans) {
      nxt[v] = out;
      ans = curr;
    }
  }
  return dp[v] = ans;
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
  nxt = vector<ll>(n, -1);
  ll ans = dfs(0);
  if (ans < 0) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << ans + 1 << endl;
  ll v = 0;
  while (true) {
    cout << v + 1 << " ";
    if (v == n - 1)
      break;
    v = nxt[v];
  }

  return 0;
}
