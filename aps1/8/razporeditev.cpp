#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum color { uncolored = 0, black = 1, white = 2 };

vector<vector<int>> G;
vector<color> colors;

color next_color(color c) { return c == black ? white : black; }

bool bfs_color(int node) {
  colors[node] = black;
  queue<int> q;
  q.push(node);

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int next : G[curr]) {
      if (colors[next] != uncolored) {
        if (colors[curr] == colors[next])
          return false;
        else
          continue;
      }
      colors[next] = next_color(colors[curr]);
      q.push(next);
    }
  }

  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  G.resize(n);
  colors.resize(n, uncolored);

  for (int i = 0; i < m; i++) {
    int kid1, kid2;
    cin >> kid1 >> kid2;
    G[kid1 - 1].push_back(kid2 - 1);
    G[kid2 - 1].push_back(kid1 - 1);
  }

  for (int i = 0; i < n; i++) {
    if (colors[i] != uncolored)
      continue;
    bool valid = bfs_color(i);
    if (!valid) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << colors[i] << endl;
  }

  return 0;
}
