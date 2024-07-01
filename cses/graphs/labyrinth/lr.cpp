#include <bits/stdc++.h>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));
  pair<int, int> s, e;

  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A')
        s = {i, j};
      if (grid[i][j] == 'B')
        e = {i, j};
    }

  queue<pair<int, int>> q;
  vector<vector<bool>> seen(h, vector<bool>(w, false));
  seen[s.first][s.second] = true;
  vector<vector<string>> prev(h, vector<string>(w, "."));

  auto dirs = vector<pair<int, int>>({{1, 0}, {0, 1}, {-1, 0}, {0, -1}});
  auto names = vector<string>({"D", "R", "U", "L"});

  while (q.size() > 0) {
    auto [i, j] = q.front();
    q.pop();
    if (grid[i][j] == 'B')
      break;
    for (int k = 0; k < 4; k++) {
      auto [di, dj] = dirs[k];
      int ii = i + di;
      int jj = j + dj;
      if (0 <= ii && ii < h && 0 <= jj && jj < w &&
          (grid[ii][jj] == '.' || grid[ii][jj] == 'B')) {
        q.push({ii, jj});
        prev[ii][jj] = names[k];
        if (grid[ii][jj] == '.')
          grid[ii][jj] = '#';
      }
    }
  }
  auto [ei, ej] = e;
  if (prev[ei][ej] == ".") {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    string rpath = "";
    while (grid[ei][ej] != 'A') {
      auto step = prev[ei][ej];
      rpath += step;
      if (step == "R")
        ej--;
      if (step == "L")
        ej++;
      if (step == "U")
        ei++;
      if (step == "D")
        ei--;
    }
    cout << rpath.size() << endl;
    reverse(rpath.begin(), rpath.end());
    cout << rpath << endl;
  }

  return 0;
}
