#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> path;
vector<int> vis;
unordered_set<int> seen;
int start;

void dfs(int node) {
  // cout << node << endl;
  // for (auto v : path) {
  //   cout << v << " ";
  // }
  // cout << "endlist" << endl;
  if (vis[node]) {
    if (path.size() == 0)
      return;
    if (seen.count(node) > 0) {
      vector<int> temp;
      temp.push_back(node);
      while (path.back() != node) {
        temp.push_back(path.back());
        path.pop_back();
      }
      temp.push_back(node);
      cout << temp.size() << endl;
      reverse(temp.begin(), temp.end());
      for (auto v : temp) {
        cout << v << " ";
      }
      exit(0);
    }
    return;
  }
  path.push_back(node);
  vis[node] = 1;
  seen.insert(node);

  for (auto nb : adj[node]) {
    dfs(nb);
  }
  seen.erase(node);
  path.pop_back();
}

int main() {
  int n, m;
  cin >> n >> m;
  adj = vector<vector<int>>(n + 1, vector<int>());

  for (int i = 0; i < m; i++) {
    int fr, to;
    cin >> fr >> to;
    adj[fr].push_back(to);
  }

  vis = vector<int>(n + 1, 0);
  for (int s = 1; s <= n; s++) {
    path = vector<int>();
    seen = unordered_set<int>();
    start = s;
    dfs(s);
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}
