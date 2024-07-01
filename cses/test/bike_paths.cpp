#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> adj;
vector<vector<int>> adjr;

vector<bool> seen;
vector<int> order;

void dfs(int v) {
  seen[v] = true;
  for (auto out : adj[v]) {
    if (!seen[out]) {
      dfs(out);
    }
  }
  order.push_back(v);
}

vector<int> component;
vector<int> comp_size;

void dfs2(int v, int cmp_id) {
  seen[v] = true;
  component[v] = cmp_id;
  comp_size[cmp_id]++;
  for (auto out : adjr[v]) {
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
  adjr.resize(n);

  for (int i = 0; i < m; i++) {
    int fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    adj[fr].push_back(to);
    adjr[to].push_back(fr);
  }
  seen.assign(n, false);

  for (int i = 0; i < n; i++)
    if (!seen[i]) {
      dfs(i);
    }
  seen.assign(n, false);
  reverse(order.begin(), order.end());
  component.resize(n);

  int n_comps = 0;
  for (auto v : order)
    if (!seen[v]) {
      comp_size.push_back(0);
      dfs2(v, n_comps);
      n_comps++;
    }
  vector<set<int>> adj_scc(n_comps);

  for (int i = 0; i < n; i++) {
    for (auto v : adj[i]) {
      int ci = component[i];
      int cv = component[v];
      if (ci != cv)
        adj_scc[ci].insert(cv);
    }
  }

  vector<int> n_reachable(n_comps, 0);
  function<int(int)> reach = [&](int v) {
    if (n_reachable[v])
      return n_reachable[v];
    int ans = comp_size[v];
    seen[v] = true;

    for (auto out : adj_scc[v])
      if (!seen[out])
        ans += reach(out);
    return n_reachable[v] = ans;
  };

  for (int i = 0; i < n_comps; i++) {
    seen.assign(n_comps, false);
    if (n_reachable[i] == 0)
      reach(i);
  }

  for (int i = 0; i < n; i++)
    cout << n_reachable[component[i]] - 1 << endl;

  return 0;
}
