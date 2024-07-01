#include <bits/stdc++.h>
#include <queue>

using namespace std;

#define endl '\n'

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  ll inf = 1e17;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> adj1(n);
  vector<vector<pair<ll, ll>>> adj2(n);
  vector<ll> dist1(n, inf);
  vector<ll> dist2(n, inf);

  for (ll i = 0; i < m; i++) {
    ll fr, to, w;
    cin >> fr >> to >> w;
    fr--;
    to--;
    adj1[fr].push_back({to, w});
    adj2[to].push_back({fr, w});
  }

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.push({0, 0});
  dist1[0] = 0;

  while (!pq.empty()) {
    auto [d, node] = pq.top();
    pq.pop();
    if (d > dist1[node])
      continue;
    for (auto [out, w] : adj1[node]) {
      if (d + w < dist1[out]) {
        dist1[out] = d + w;
        pq.push({d + w, out});
      }
    }
  }

  pq.push({0, n - 1});
  dist2[n - 1] = 0;

  while (!pq.empty()) {
    auto [d, node] = pq.top();
    pq.pop();
    if (d > dist2[node])
      continue;
    for (auto [out, w] : adj2[node]) {
      if (d + w < dist2[out]) {
        dist2[out] = d + w;
        pq.push({d + w, out});
      }
    }
  }
  ll ans = inf;
  for (ll fr = 0; fr < n; fr++) {
    for (auto [to, w] : adj1[fr]) {
      ans = min(ans, dist1[fr] + w / 2 + dist2[to]);
    }
  }

  cout << ans << endl;

  return 0;
}
