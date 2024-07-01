
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;

#define endl '\n'

typedef long long ll;

struct UF {
  vector<int> size;
  vector<int> parent;
  int n_comps;
  int max_size = 1;

  UF(int n) {
    n_comps = n;
    size.resize(n, 1);
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  void join(int a, int b) {
    int ra = root(a);
    int rb = root(b);
    if (ra == rb)
      return;
    if (size[ra] > size[rb])
      swap(ra, rb);
    parent[ra] = rb;
    size[rb] += size[ra];
    max_size = max(max_size, size[rb]);
    n_comps--;
  }
  int root(int a) {
    if (parent[a] == a)
      return a;
    return parent[a] = root(parent[a]);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  UF uf(n);
  for (int i = 0; i < m; i++) {
    int fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    uf.join(fr, to);
    cout << uf.n_comps << " " << uf.max_size << endl;
  }

  return 0;
}
