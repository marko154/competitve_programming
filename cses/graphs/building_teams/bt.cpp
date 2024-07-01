
#include <bits/stdc++.h>
using namespace std;

vector<int> colors;
vector<vector<int>> adj;

bool dfs(int node, int color) {
  if (colors[node] != 0)
    return colors[node] == color;
  colors[node] = color;
  int nc = color == 2 ? 1 : 2;
  for (auto nb : adj[node])
    if (!dfs(nb, nc))
      return false;
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  colors = vector<int>(n + 1, 0);
  adj = vector<vector<int>>(n + 1, vector<int>());

  for (int i = 0; i < m; i++) {
    int fr, to;
    cin >> fr >> to;
    adj[fr].push_back(to);
    adj[to].push_back(fr);
  }

  for (int i = 1; i <= n; i++) {
    if (colors[i] != 0)
      continue;
    if (!dfs(i, 1)) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  for (int i = 1; i <= n; i++)
    cout << colors[i] << " ";
  cout << endl;

  return 0;
}
