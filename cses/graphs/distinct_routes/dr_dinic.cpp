#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll INF = 1e9;
ll n, m, s, t;

vector<vector<ll>> adj;
vector<vector<ll>> adj_forward;
vector<vector<ll>> cap;
vector<ll> nxt, level;

bool bfs() {
  level.assign(n, -1);  
  level[s] = 0;
  queue<ll> q({ s });

  while (!q.empty()) {
    ll v = q.front(); q.pop();
    for (ll out : adj[v]) {
      if (level[out] == -1 && cap[v][out] > 0) {
        q.push(out);
        level[out] = level[v] + 1;
      }
    }
  }
  return level[t] != -1;
}

ll dfs(ll v, ll flow) {
  if (v == t) {
    return flow;
  }
  for(; nxt[v] < adj[v].size(); nxt[v]++) {
    ll out = adj[v][nxt[v]];
    if (level[out] == level[v] + 1 && cap[v][out] > 0) {
      ll f = dfs(out, min(flow, cap[v][out]));
      if (f >  0) {
        cap[v][out] -= f;
        cap[out][v] += f;
        return f;
      }
    }
  }

  return 0;
}

ll dinic() {
  ll flow = 0;

  while (bfs()) {
    ll new_flow = 0;
    nxt.assign(n, 0);
    while ((new_flow = dfs(s, INF))) {
      flow += new_flow;
    }
  }
  return flow;
}

vector<ll> path;
bool dfs2(ll v) {
  if (v == t) {
    path.push_back(v);
    return true;
  }
  for (ll out : adj_forward[v]) {
    if (cap[v][out] == 0) {
      if (dfs2(out)) {
        cap[v][out] = 1;
        path.push_back(v);
        return true;
      }
    }
  }
  return false;
}

int main() {
  cin >> n >> m;

  adj.resize(n);
  adj_forward.resize(n);
  cap.resize(n, vector<ll>(n, 0));

  for (ll i = 0; i < m; i++) {
    ll fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    adj_forward[fr].push_back(to);
    // TODO: dedupe
    adj[fr].push_back(to);
    adj[to].push_back(fr);
    cap[fr][to] += 1;
  }
  s = 0; t = n - 1;

  ll flow = dinic();
  cout << flow << endl;
  vector<ll> back;
  for (ll i = 0; i < flow; i++) {
    path.clear();
    dfs2(s);
    cout << path.size() << endl;
    reverse(path.begin(), path.end());
    for (auto el : path) cout << el + 1 << " " ;
    cout << endl;
  }

  return 0;
}
