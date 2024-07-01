
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll INF = 1e9;

int main() {
  ll n, m;
  cin >> n >> m;

  vector<unordered_set<ll>> adj(n);
  vector<vector<ll>> adj_rev(n);
  vector<vector<ll>> cap(n, vector<ll>(n, 0));

  for (ll i = 0; i < m; i++) {
    ll fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    adj[fr].insert(to);
    adj[to].insert(fr);
    adj_rev[to].push_back(fr);
    cap[fr][to] += 1;
  }
  ll src = 0, sink = n - 1;
  vector<ll> parent;

  auto bfs = [&]() {
    parent.assign(n, -1);
    queue<pair<ll, ll>> q;
    q.push({src, INF});

    while (!q.empty()) {
      auto [v, flow_to_v] = q.front();
      q.pop();
      if (v == sink) {
        return flow_to_v;
      }
      for (ll out : adj[v]) {
        if (parent[out] == -1 && cap[v][out] > 0) {
          q.push({out, min(flow_to_v, cap[v][out])});
          parent[out] = v;
        }
      }
    }
    return 0LL;
  };

  ll flow = 0, new_flow = 0;
  while ((new_flow = bfs())) {
    flow += new_flow;
    ll v = sink;
    while (v != src) {
      ll prev = parent[v];
      cap[prev][v] -= new_flow;
      cap[v][prev] += new_flow;
      v = prev;
    }
  }

  cout << flow << endl;
  vector<int> back;
  auto bfs2 = [&]() {
    vector<bool> seen(n, false);
    back.assign(n, -1);
    seen[sink] = true;
    queue<int> q;
    q.push(sink);

    while (!q.empty()) {
      auto v = q.front(); q.pop();
      if (v == src) {
        return;
      }
      for (int out : adj_rev[v]) {
        if (!seen[out] && cap[v][out] > 0) {
          q.push(out);
          back[out] = v;
          seen[out] = true;
        }
      }
    }
  };

  for (int i = 0; i < flow; i++) {
    bfs2();
    vector<int> path;
    int v = src; 
    while (v != sink) {
      path.push_back(v + 1);
      int next = back[v];
      cap[next][v] = 0;
      v = next;
    }
    path.push_back(sink + 1);
    cout << path.size() << endl;
    for (auto el : path) cout << el << " " ;
    cout << endl;
  }

  return 0;
}
