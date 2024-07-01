#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll INF = 1e17;

ll n, m;
vector<unordered_set<ll>> adj;
vector<vector<ll>> cap;

vector<ll> parent;

ll bfs(ll source, ll sink) {
  queue<pair<ll, ll>> q;
  q.push({source, INF});
  parent.assign(n, -1);

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

  return 0;
}

ll edmonds_karp(ll source, ll sink) {
  ll flow = 0;
  ll new_flow;

  while ((new_flow = bfs(source, sink))) {
    flow += new_flow;

    ll v = sink;
    while (v != source) {
      ll p = parent[v];
      cap[p][v] -= new_flow;
      cap[v][p] += new_flow;
      v = p;
    }
  }

  return flow;
}

int main() {
  cin.tie()->sync_with_stdio(false);

  cin >> n >> m;
  adj.resize(n);
  cap.resize(n, vector<ll>(n, 0));

  for (ll i = 0; i < m; i++) {
    ll fr, to, c;
    cin >> fr >> to >> c;
    fr--;
    to--;
    cap[fr][to] += c;
    adj[fr].insert(to);
    adj[to].insert(fr);
  }

  cout << edmonds_karp(0, n - 1) << endl;

  return 0;
}
