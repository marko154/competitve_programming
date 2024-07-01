#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;

#define endl '\n'
#define ar array

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> adj(n);
  for (ll i = 0; i < m; i++) {
    ll fr, to, w;
    cin >> fr >> to >> w;
    fr--;
    to--;
    adj[fr].push_back({to, w});
    adj[to].push_back({fr, w});
  }

  ll ans = 0;

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  vector<ll> dist(n, 1e17);
  dist[0] = 0;
  vector<bool> seen(n, false);

  pq.push({0, 0});
  ll processed = 0;

  while (pq.size() > 0) {
    auto [d, to] = pq.top();
    pq.pop();
    if (seen[to])
      continue;
    processed++;
    ans += d;
    seen[to] = true;

    for (auto [out, w] : adj[to]) {
      if (!seen[out] && w < dist[out]) {
        dist[out] = w;
        pq.push({w, out});
      }
    }
  }

  if (processed == n) {
    cout << ans << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
