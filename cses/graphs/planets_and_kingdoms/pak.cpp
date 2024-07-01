#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;

#define endl '\n'

typedef long long ll;

#define MAXN (int)1e5 + 1

bool onstack[MAXN];
int id[MAXN];
int lowlink[MAXN];
vector<vector<int>> adj;
stack<int> st;
int comp[MAXN];
int n_comps = 0;

int c = 1;

void tarjan(int v) {
  lowlink[v] = id[v] = c;
  c++;
  st.push(v);
  onstack[v] = true;

  for (auto w : adj[v]) {
    if (id[w] == 0) {
      tarjan(w);
      lowlink[v] = min(lowlink[v], lowlink[w]);
    } else if (onstack[w]) {
      lowlink[v] = min(lowlink[v], id[w]);
    }
  }

  if (lowlink[v] == id[v]) {
    n_comps++;
    while (true) {
      int temp = st.top();
      onstack[temp] = false;
      comp[temp] = n_comps;
      st.pop();
      if (temp == v)
        break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  adj.resize(n);

  for (int i = 0; i < m; i++) {
    int fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    adj[fr].push_back(to);
  }

  for (int i = 0; i < n; i++) {
    if (id[i] == 0)
      tarjan(i);
  }

  cout << n_comps << endl;
  for (int i = 0; i < n; i++) {
    cout << comp[i] << " ";
  }
  cout << endl;

  return 0;
}
