#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;

#define endl '\n'
typedef long long ll;
#define MAXN (int)1e5 + 1

vector<vector<int>> adj;
vector<vector<int>> radj;

vector<int> order;
vector<int> seen;

void dfs(int v) {
  seen[v] = true;
  for (int out : adj[v]) {
    if (!seen[out])
      dfs(out);
  }

  order.push_back(v);
}

int component[MAXN];

void dfs2(int v, int cmp_id) {
  seen[v] = true;
  component[v] = cmp_id;
  for (auto out : radj[v]) {
    if (!seen[out]) {
      dfs2(out, cmp_id);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  adj.resize(n);
  radj.resize(n);
  seen.assign(n, false);

  for (int i = 0; i < m; i++) {
    int fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    adj[fr].push_back(to);
    radj[to].push_back(fr);
  }

  for (int i = 0; i < n; i++) {
    if (!seen[i])
      dfs(i);
  }

  reverse(order.begin(), order.end());
  seen.assign(n, false);
  int n_comps = 0;
  for (auto v : order) {
    if (!seen[v]) {
      n_comps++;
      dfs2(v, n_comps);
    }
  }
  cout << n_comps << endl;
  for (int i = 0; i < n; i++) {
    cout << component[i] << " ";
  }
  cout << endl;

  return 0;
}
