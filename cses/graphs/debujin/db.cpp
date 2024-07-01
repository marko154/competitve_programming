#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  n--;

  vector<vector<int>> adj(1 << n);
  vector<int> edges_left(1 << n, 2);

  for (int i = 0; i < (1 << n); i++) {
    int mask = (1 << n) - 1;
    cout << i << " " << (((i << 1) | 1) & mask) << endl;
    cout << i << " " << (((i << 1)) & mask) << endl;
    adj[i].push_back(((i << 1) | 1) & mask);
    adj[i].push_back(((i << 1)) & mask);
  }

  vector<int> cycle;

  function<void(int)> dfs = [&](int v) {
    cout << "dfs " << v << endl;
    while (edges_left[v] > 0) {
      edges_left[v]--;
      dfs(adj[v][edges_left[v]]);
    }
    cycle.push_back(v);
  };

  dfs(0);
  cout << endl;
  for (int i = 0; i < cycle.size(); i++) {
    if (i == 0) {
      cout << string(n, '0');
    } else {
      cout << (cycle[i] & 1);
    }
  }
  cout << endl;

  return 0;
}
