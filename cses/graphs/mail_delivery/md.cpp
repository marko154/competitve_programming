#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<set<int>> adj(n);
  vector<int> deg(n, 0);

  for (int i = 0; i < m; i++) {
    int fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    adj[fr].insert(to);
    adj[to].insert(fr);
    deg[fr]++;
    deg[to]++;
  }

  for (int i = 0; i < n; i++) {
    if (deg[i] % 2 == 1) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  vector<int> path;

  function<void(int)> dfs = [&](int v) {
    while (adj[v].size() > 0) {
      auto out = *adj[v].begin();
      adj[v].erase(out);
      adj[out].erase(v);
      dfs(out);
    }

    path.push_back(v);
  };

  dfs(0);
  reverse(path.begin(), path.end());
  if (path.size() != m + 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for (auto v : path) {
    cout << v + 1 << " ";
  }
  cout << endl;

  return 0;
}
