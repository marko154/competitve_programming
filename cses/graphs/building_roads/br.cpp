
#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> parent, size;
  set<int> comps;
  DSU(int n) {
    parent = vector<int>(n);
    size = vector<int>(n, 1);
    comps = set<int>();
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      comps.insert(i);
    }
  }

  int join(int a, int b) {
    int ra = root(a);
    int rb = root(b);
    if (ra == rb)
      return 0;
    if (size[ra] < size[rb])
      swap(ra, rb);
    size[ra] += size[rb];
    comps.erase(rb);
    parent[rb] = ra;
    return 1;
  }

  int root(int v) {
    if (parent[v] == v)
      return v;
    return parent[v] = root(parent[v]);
  }
  void finish() {
    vector<pair<int, int>> ne;
    while (comps.size() > 1) {
      auto p = make_pair(*comps.begin(), *(comps.rbegin()));
      join(p.first, p.second);
      ne.push_back(p);
    }
    cout << ne.size() << endl;
    for (auto e : ne)
      cout << e.first + 1 << " " << e.second + 1 << endl;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  DSU d(n);
  for (int i = 0; i < m; i++) {
    int fr, to;
    cin >> fr >> to;
    d.join(fr - 1, to - 1);
  }
  d.finish();

  return 0;
}
