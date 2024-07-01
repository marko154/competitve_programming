#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

vector<ll> dp;
ll n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  vector<vector<ll>> adj(n);
  vector<ll> indeg(n, 0);

  for (ll i = 0; i < m; i++) {
    ll fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    adj[fr].push_back(to);
    indeg[to]++;
  }

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (indeg[i] == 0)
      q.push(i);
  }

  vector<int> ans;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    ans.push_back(v);
    for (auto out : adj[v]) {
      indeg[out]--;
      if (indeg[out] == 0)
        q.push(out);
    }
  }
  if (ans.size() != n) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    for (auto v : ans) {
      cout << v + 1 << " ";
    }
    cout << endl;
  }

  return 0;
}
