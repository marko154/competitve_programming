#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

vector<ll> fun;
vector<ll> id;
vector<ll> llink;
vector<bool> onstack;
vector<vector<ll>> adj;
stack<ll> st;
ll c = 0;

vector<ll> comp;
vector<ll> comp_fv;

void tarjan(ll v) {
  id[v] = llink[v] = c++;
  onstack[v] = true;
  st.push(v);

  for (auto w : adj[v])
    if (id[w] == -1) {
      tarjan(w);
      llink[v] = min(llink[v], llink[w]);
    } else if (onstack[w]) {
      llink[v] = min(llink[v], id[w]);
    }

  if (llink[v] == id[v]) {
    ll fv = 0;
    while (true) {
      ll temp = st.top();
      st.pop();
      fv += fun[temp];
      comp[temp] = comp_fv.size();
      onstack[temp] = false;
      if (temp == v)
        break;
    }
    comp_fv.push_back(fv);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m, s, e;
  cin >> n >> m >> s >> e;
  e--;
  s--;

  fun.resize(n);
  id.assign(n, -1);
  llink.assign(n, -1);
  comp.assign(n, -1);
  onstack.assign(n, false);
  adj.resize(n);

  for (ll i = 0; i < n; i++)
    cin >> fun[i];

  for (ll i = 0; i < m; i++) {
    ll fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    adj[fr].push_back(to);
  }

  for (ll i = 0; i < n; i++)
    if (id[i] == -1)
      tarjan(i);

  ll n_comps = comp_fv.size();
  vector<set<ll>> cond_adj(n_comps);
  vector<set<ll>> cond_adjr(n_comps);
  // build cond graph

  for (ll i = 0; i < n; i++)
    for (ll v : adj[i]) {
      ll ci = comp[i];
      ll cv = comp[v];
      if (ci != cv) {
        cond_adj[ci].insert(cv);
        cond_adjr[cv].insert(ci);
      }
    }

  vector<ll> reaches_end(n_comps, false);
  function<void(ll)> dfs = [&](ll v) {
    reaches_end[v] = true;
    for (auto out : cond_adjr[v])
      if (!reaches_end[out])
        dfs(out);
  };
  dfs(comp[e]);

  vector<ll> max_fv(n_comps, -2);
  function<ll(ll)> solve = [&](ll v) {
    if (max_fv[v] != -2)
      return max_fv[v];
    if (v == comp[e])
      return max_fv[v] = comp_fv[v];
    ll ans = 0;
    for (auto out : cond_adj[v])
      if (reaches_end[out])
        ans = max(ans, solve(out));

    return max_fv[v] = ans + comp_fv[v];
  };

  solve(comp[s]);
  cout << max_fv[comp[s]] << endl;

  return 0;
}
