#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'

typedef long long ll;

vector<vector<pair<ll, ll>>> adj;
vector<bool> seen;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  cin >> n >> m;
  adj = vector<vector<pair<ll, ll>>>(n);
  vector<array<ll, 3>> edges;

  for (ll i = 0; i < m; i++) {
    ll fr, to, w;
    cin >> fr >> to >> w;
    fr--;
    to--;
    adj[fr].push_back({to, w});
    edges.push_back({fr, to, w});
  }

  ll inf = 1e17;
  vector<ll> dist(n, inf);
  set<ll> todo;
  for (int i = 0; i < n; i++)
    todo.insert(i);

  while (todo.size() > 0) {
    int start = *todo.begin();
    todo.erase(todo.begin());
    fill(dist.begin(), dist.end(), inf);
    dist[start] = 0;
    int i = 0;
    vector<ll> back(n, -1);
    ll last = -1;
    while (true) {
      last = -1;
      for (auto [fr, to, w] : edges) {
        if (dist[to] > dist[fr] + w) {
          todo.erase(to);
          dist[to] = dist[fr] + w;
          back[to] = fr;
          last = to;
        }
      }
      i++;
      if (i >= n || last == -1)
        break;
    }
    if (i >= n) {
      vector<ll> cycle;
      for (int i = 0; i < n; i++) {
        last = back[last];
      }
      ll temp = last;
      while (true) {
        if (temp == last && cycle.size() > 0)
          break;
        cycle.push_back(temp);
        temp = back[temp];
      }
      reverse(cycle.begin(), cycle.end());
      cout << "YES" << endl;
      for (auto v : cycle) {
        cout << v + 1 << " ";
      }
      cout << cycle.front() + 1 << endl;
      exit(0);
    }
  }

  cout << "NO" << endl;

  return 0;
}
