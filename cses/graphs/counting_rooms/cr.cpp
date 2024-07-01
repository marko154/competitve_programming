#include <bits/stdc++.h>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));

  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> grid[i][j];

  function<void(int, int)> dfs = [&](int i, int j) {
    if (i >= h || i < 0 || j >= w || j < 0 || grid[i][j] == '#')
      return;
    grid[i][j] = '#';
    for (auto [di, dj] :
         vector<pair<int, int>>({{1, 0}, {0, 1}, {-1, 0}, {0, -1}})) {
      dfs(i + di, j + dj);
    }
  };

  int ans = 0;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == '.') {
        dfs(i, j);
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
