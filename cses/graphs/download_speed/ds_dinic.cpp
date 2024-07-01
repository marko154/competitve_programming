
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll INF = 1e17;

ll n, m;
vector<vector<ll>> adj;
vector<vector<ll>> cap;
vector<ll> nxt;
vector<ll> level;
ll max_cap = 0;
ll limit;

bool bfs(ll src, ll sink) {
  queue<ll> q;
  q.push(src);
  level.assign(n, -1);
  level[src] = 0;

  while (!q.empty()) {
    ll v = q.front(); q.pop();
    for (ll out : adj[v]) {
      if (level[out] == -1 && cap[v][out] >= limit) {
        q.push(out);
        level[out] = level[v] + 1;
      }
    }
  }
  return level[sink] != -1;
}

ll dfs(ll v, ll sink, ll flow) {
  if (v == sink) {
    return flow;
  }
  for (; nxt[v] < adj[v].size(); nxt[v]++) {
    ll out = adj[v][nxt[v]];
    if (cap[v][out] >= limit && level[out] > level[v]) {
      ll _flow = dfs(out, sink, min(flow, cap[v][out]));
      cap[v][out] -= _flow;
      cap[out][v] += _flow;
      if (_flow) {
        return _flow;
      }
    }
  }

  return 0;
}

vector<ll> temp_nxt;

ll dinic(ll src, ll sink) {
  ll flow = 0;
  for (limit = 1 << 30; limit > 0; limit /= 2) {
    while (bfs(src, sink)) {
      nxt.assign(n, 0);
      ll new_flow = 0; 
      while((new_flow = dfs(src, sink, INF))) {
        flow += new_flow;
      }
    }
  }
  return flow;
}

int main() {
  cin >> n >> m;  
  adj.resize(n);
  cap.assign(n, vector<ll>(n,0));

  for (ll i = 0; i < m; i++) {
    ll fr, to, c;
    cin >> fr >> to >> c;
    to--; fr--;
    cap[fr][to] += c;
    max_cap = max(max_cap, cap[fr][to]);
    if (find(adj[fr].begin(), adj[fr].end(), to) == adj[fr].end()) {
      adj[fr].push_back(to);
    }
    if (find(adj[to].begin(), adj[to].end(), fr) == adj[to].end()) {
      adj[to].push_back(fr);
    }
  }

  cout << dinic(0, n - 1) << endl;

  return 0;
}
