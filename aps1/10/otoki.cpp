#include <algorithm>
#include <iostream>
#include <vector>
#define MAX_HEIGHT 10e5

using namespace std;

pair<int, int> dirs[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int v, s;

class UnionFind {
public:
  vector<int> parent, size;
  int v, s;
  UnionFind(int n) {

    parent = vector<int>(n);
    size = vector<int>(n);
    for (int i = 0; i < n; i++) { // individual sets
      parent[i] = i;
      size[i] = 1;
    }
  }

  int root(int x) { // find
    if (parent[x] == x)
      return x; // reached the root
    int r = root(parent[x]);
    parent[x] = r; // path compression
    return r;
  }

  void join(int x, int y) { // union by size
    x = root(x);
    y = root(y); // replace by roots
    if (x == y)
      return;
    if (size[x] > size[y])
      swap(x, y);  // make x smaller
    parent[x] = y; // attach to larger root
    size[y] += size[x];
  }
};

int idx(int i, int j) { return i * s + j; }

int join_at_height(int height, vector<vector<int>> &grid,
                   vector<pair<int, int>> &at_height, UnionFind &uf) {
  int diff = 0;
  for (auto [i, j] : at_height) {
    diff += 1;
    for (auto [di, dj] : dirs) {
      int ii = i + di;
      int jj = j + dj;
      if (ii < 0 || ii >= v || jj < 0 || jj >= s || grid[ii][jj] < grid[i][j])
        continue;
      if (uf.root(idx(i, j)) != uf.root(idx(ii, jj))) {
        diff -= 1;
      }
      uf.join(idx(i, j), idx(ii, jj));
    }
  }
  return diff;
}

int main() {
  cin >> v >> s;
  vector<vector<int>> grid(v, vector<int>(s));
  vector<vector<pair<int, int>>> at_height(MAX_HEIGHT + 1,
                                           vector<pair<int, int>>());
  int highest = 0;
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < s; j++) {
      int h;
      cin >> h;
      grid[i][j] = h;
      at_height[h].push_back({i, j});
      highest = max(h, highest);
    }
  }

  UnionFind uf(v * s);
  vector<int> ans;
  int n_islands = 0;

  for (int height = highest + 1; height > 0; height--) {
    if (at_height[height].size() != 0) {
      int diff = join_at_height(height, grid, at_height[height], uf);
      n_islands += diff;
    }
    ans.push_back(n_islands);
  }

  for (int i = highest; i >= 0; i--) {
    cout << ans[i] << endl;
  }

  return 0;
}
