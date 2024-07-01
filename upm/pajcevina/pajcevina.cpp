
#include <bits/stdc++.h>
using namespace std;

vector<array<int, 2>> edges;
int n, m;

vector<int> parent, sz;
int n_comps;

int root(int v) {
  if (parent[v] == v) return v;
  return parent[v] = root(parent[v]);
}

void join(int a, int b) {
  int ra = root(a);
  int rb = root(b);
  if (ra == rb) return;
  
  n_comps -= 1;
  if (sz[ra] < sz[rb]) {
    swap(ra, rb);
  }
  sz[ra] += sz[rb];
  parent[rb] = ra;
}

int main() {
  cin >> n >> m;
  
  n_comps = n;
  parent.resize(n);
  sz.assign(n, 1);
  for (int i =0; i < n; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int fr, to;
    cin >> fr >> to;
    fr--; to--;
    edges.push_back({fr, to});
  }

  int q;
  cin >> q;
  set<int> joins;
  vector<int> vjoins;

  for (int i = 0; i < q; i++) {
    int eidx;
    cin >> eidx;
    eidx--;
    joins.insert(eidx);
    vjoins.push_back(eidx);
  }

  reverse(vjoins.begin(), vjoins.end());

  for (int i = 0; i < m; i++) {
    if (joins.count(i) == 0) {
      auto [fr, to] = edges[i];
      join(fr, to);
    }
  }
  
  vector<int> ans;
  for (int eidx : vjoins) {
    ans.push_back(n_comps);
    auto [fr, to] = edges[eidx];
    join(fr, to);
  }
  reverse(ans.begin(), ans.end());
  for (auto s : ans) {
    cout << s << " ";
  }
  cout << endl;

  return 0;
}
