
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;

#define endl '\n'
typedef long long ll;

struct UF {
  vector<ll> parent;
  vector<ll> size;
  UF(ll n) {
    parent = vector<ll>(n);
    size = vector<ll>(n, 1);
    for (ll i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  void join(ll a, ll b) {
    ll ra = root(a);
    ll rb = root(b);
    if (ra == rb)
      return;
    if (size[ra] > size[rb])
      swap(ra, rb);
    parent[ra] = rb;
    size[rb] += size[ra];
  }

  ll root(ll a) {
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
  vector<array<ll, 3>> edges;

  for (ll i = 0; i < m; i++) {
    ll fr, to, w;
    cin >> fr >> to >> w;
    fr--;
    to--;
    edges.push_back({fr, to, w});
  }

  sort(edges.begin(), edges.end(),
       [&](array<ll, 3> e1, array<ll, 3> e2) { return e1[2] < e2[2]; });

  ll ans = 0;
  UF uf(n);
  for (auto [fr, to, w] : edges) {
    if (uf.root(fr) != uf.root(to)) {
      ans += w;
      uf.join(fr, to);
    }
  }

  if (uf.size[uf.root(0)] != n) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
