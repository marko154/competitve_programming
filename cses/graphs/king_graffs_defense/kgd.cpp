
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

ll n_bridges;
vector<vector<ll>> adj;

vector<ll> low, id;
ll c = 1;

set<pair<ll, ll>> bridges;

void dfs(ll v, ll p) {
  low[v] = id[v] = c;
  c++;

  for (auto out : adj[v]) {
    if (out == p)
      continue;
    if (!id[out]) {
      dfs(out, v);
      low[v] = min(low[v], low[out]);
      if (low[out] > low[v]) {
        n_bridges++;
        bridges.insert({v, out});
        bridges.insert({out, v});
      }
    } else {
      low[v] = min(low[v], id[out]);
    }
  }
}

int count(int v) {
  int k = 1;
  id[v] = 1;

  for (auto out : adj[v]) {
    if (!id[out] && bridges.count({v, out}) == 0) {
      k += count(out);
    }
  }

  return k;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(0);

  ll n, m;
  cin >> n >> m;
  adj.resize(n);
  id.assign(n, 0);
  low.assign(n, 0);

  for (ll i = 0; i < m; i++) {
    ll fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    adj[fr].push_back(to);
    adj[to].push_back(fr);
  }

  for (ll i = 0; i < n; i++) {
    if (!id[i])
      dfs(i, -1);
  }

  vector<ll> sizes;
  id.assign(n, 0);
  for (int i = 0; i < n; i++) {
    if (!id[i]) {
      sizes.push_back(count(i));
    }
  }

  ll good = 0;
  for (auto size : sizes) {
    good += (size * (size - 1)) / 2;
  }

  ll all = (n * (n - 1)) / 2;
  ll ans = ((all - good) * 1e5) / all;
  printf("%.5f\n", (double)(ans / 1e5));

  return 0;
}
