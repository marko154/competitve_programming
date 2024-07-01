#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int h, w;
vector<vector<char>> grid;
vector<vector<int>> dist;
queue<pair<int, int>> monsters;
pair<int, int> start;
vector<pair<int, int>> dirs = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

bool inRange(int i, int j) { return i >= 0 && i < h && j >= 0 && j < w; }

// Breadth-First Search for Monsters
void bfsMonsters() {
  while (!monsters.empty()) {
    auto [i, j] = monsters.front();
    monsters.pop();
    for (auto [di, dj] : dirs) {
      if (di == 0 && dj == 0)
        continue;
      int ii = i + di;
      int jj = j + dj;
      if (!inRange(ii, jj) || grid[ii][jj] == '#')
        continue;
      if (dist[ii][jj] == -1) {
        dist[ii][jj] = dist[i][j] + 1;
        monsters.push({ii, jj});
      }
    }
  }
}

// Breadth-First Search for Escape
void bfsEscape() {
  queue<pair<int, int>> q;
  q.push(start);
  vector<vector<int>> D(h, vector<int>(w, -1));
  D[start.first][start.second] = 0;
  auto hash_func = [](const pair<int, int> &x) {
    return hash<long long>()(((long long)x.first) ^
                             (((long long)x.second) << 32));
  };
  map<pair<int, int>, pair<int, int>> back;
  while (!q.empty()) {
    auto [i, j] = q.front();
    int d = D[i][j];
    q.pop();
    if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
      cout << "YES" << endl;
      string path;
      path.resize(d);
      int c = d - 1;
      while (make_pair(i, j) != start) {
        int pi = i;
        int pj = j;
        tie(i, j) = back[make_pair(i, j)];
        if (i > pi) {
          path[c] = 'U';
        } else if (i < pi) {
          path[c] = 'D';
        } else if (j > pj) {
          path[c] = 'L';
        } else {
          path[c] = 'R';
        }
        c--;
      }
      cout << d << endl;
      cout << path << endl;
      exit(0);
    }
    for (auto [di, dj] : dirs) {
      int ii = i + di;
      int jj = j + dj;
      if (!inRange(ii, jj) || grid[ii][jj] == '#' || D[ii][jj] != -1)
        continue;
      if (dist[ii][jj] != -1 && dist[ii][jj] <= d + 1)
        continue;
      q.push({ii, jj});
      D[ii][jj] = d + 1;
      back[make_pair(ii, jj)] = {i, j};
    }
  }
  cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> h >> w;
  grid = vector<vector<char>>(h, vector<char>(w));
  dist = vector<vector<int>>(h, vector<int>(w, -1));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'M') {
        dist[i][j] = 0;
        monsters.push({i, j});
      } else if (grid[i][j] == 'A') {
        start = {i, j};
      }
    }
  }
  bfsMonsters();
  bfsEscape();

  return 0;
}
