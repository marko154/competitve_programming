
#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'

typedef long long ll;

vector<vector<pair<ll, ll>>> adj;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m, k;
  cin >> n >> m >> k;
  adj = vector<vector<pair<ll, ll>>>(n);

  for (ll i = 0; i < m; i++) {
    ll fr, to, w;
    cin >> fr >> to >> w;
    fr--;
    to--;
    adj[fr].push_back({to, w});
  }

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  vector<multiset<ll>> dist(n);
  pq.push({0, 0});
  dist[0].insert(0);

  while (!pq.empty()) {
    auto [d, node] = pq.top();
    pq.pop();
    if (d > *dist[node].rbegin())
      continue;
    for (auto [out, w] : adj[node]) {
      if (dist[out].size() < k ||
          dist[out].size() == k && d + w < *dist[out].rbegin()) {

        if (dist[out].size() == k)
          dist[out].erase(prev(dist[out].end()));
        dist[out].insert(d + w);
        pq.push({d + w, out});
      }
    }
  }
  for (auto d : dist[n - 1]) {
    cout << d << " ";
  }
  cout << endl;

  return 0;
}
