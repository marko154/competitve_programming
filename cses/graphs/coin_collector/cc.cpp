#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;

// #define endl '\n'

typedef long long ll;

#define MAXN (int)1e5 + 1

vector<vector<ll>> adj;
vector<set<ll>> cond;
vector<ll> cond_val;
ll comp[MAXN];

bool onstack[MAXN];
ll value[MAXN];
ll id[MAXN];
ll llink[MAXN];
stack<ll> st;
ll c = 1;

void tarjan(ll v) {
  id[v] = llink[v] = c++;
  onstack[v] = true;
  st.push(v);

  for (auto w : adj[v]) {
    if (id[w] == 0) {
      tarjan(w);
      llink[v] = min(llink[v], llink[w]);
    } else if (onstack[w]) {
      llink[v] = min(llink[v], llink[w]);
    }
  }

  if (llink[v] == id[v]) {
    ll val = 0;
    while (true) {
      ll temp = st.top();
      comp[temp] = cond_val.size();
      val += value[temp];
      st.pop();
      onstack[temp] = false;
      if (temp == v)
        break;
    }
    cond_val.push_back(val);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  adj.resize(n);
  for (ll i = 0; i < n; i++)
    cin >> value[i];

  for (ll i = 0; i < m; i++) {
    ll fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    adj[fr].push_back(to);
  }

  for (ll i = 0; i < n; i++)
    if (id[i] == 0)
      tarjan(i);
  ll n_comps = cond_val.size();
  cond.resize(n_comps);
  for (ll i = 0; i < n; i++) {
    for (auto out : adj[i]) {
      int fr = comp[i];
      int to = comp[out];
      if (fr != to)
        cond[fr].insert(to);
    }
  }
  ll ans = 0;
  vector<ll> max_com_val(n_comps, 0);
  function<ll(ll)> dfs = [&](ll v) {
    if (max_com_val[v])
      return max_com_val[v];
    ll val = 0;
    for (auto out : cond[v])
      val = max(val, dfs(out));
    return max_com_val[v] = val + cond_val[v];
  };

  for (ll i = 0; i < n_comps; i++) {
    ans = max(dfs(i), ans);
  }

  cout << ans << endl;

  return 0;
}
