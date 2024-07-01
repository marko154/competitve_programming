
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

bool seen[5001];
vector<ll> dist;
vector<vector<int>> adj;
unordered_set<int> marked;
int n, m;

void dfs_end(int v) {
  if (v == n - 1) {
    cout << -1 << endl;
    exit(0);
  }
  if (seen[v])
    return;
  seen[v] = true;
  for (auto out : adj[v]) {
    dfs_end(out);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  ll inf = -1e17;
  vector<array<ll, 3>> edges;
  adj = vector<vector<int>>(n, vector<int>());
  dist = vector<ll>(n, inf);
  dist[0] = 0;

  for (ll i = 0; i < m; i++) {
    ll fr, to, w;
    cin >> fr >> to >> w;
    edges.push_back({fr - 1, to - 1, w});
    adj[fr - 1].push_back(to - 1);
  }
  for (ll i = 0; i < 2 * n; i++) {
    for (auto [fr, to, w] : edges) {
      if (dist[fr] != inf && dist[fr] + w > dist[to]) {
        dist[to] = dist[fr] + w;
        if (i >= n && dist[fr] != inf) {
          marked.insert(to);
        }
      }
    }
  }
  for (auto v : marked) {
    memset(seen, 0, 5001);
    dfs_end(v);
  }
  cout << dist[n - 1] << endl;

  return 0;
}
