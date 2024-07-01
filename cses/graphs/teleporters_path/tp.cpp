#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<int> indeg(n, 0);
  vector<int> outdeg(n, 0);

  for (int i = 0; i < m; i++) {
    int fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    adj[fr].push_back(to);
    indeg[to]++;
    outdeg[fr]++;
  }

  for (int i = 0; i < n; i++) {
    if (i == 0 || i == n - 1) {
      if ((indeg[i] + outdeg[i]) % 2 == 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
    } else {
      if ((indeg[i] + outdeg[i]) & 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
    }
  }
  vector<int> path;
  function<void(int)> dfs = [&](int v) {
    while (outdeg[v] > 0) {
      outdeg[v]--;
      dfs(adj[v][outdeg[v]]);
    }

    path.push_back(v);
  };

  dfs(0);

  if (path.size() != m + 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  reverse(path.begin(), path.end());
  for (auto v : path) {
    cout << v + 1 << " ";
  }
  cout << endl;

  return 0;
}
