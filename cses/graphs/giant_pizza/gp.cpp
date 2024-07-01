#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

unordered_map<int, bool> onstack;
unordered_map<int, int> id, llink;
stack<int> st;
unordered_map<int, vector<int>> adj;
unordered_map<int, int> comp;

int c = 1;
int n_comps = 0;

void tarjan(int v) {
  id[v] = llink[v] = c++;
  st.push(v);
  onstack[v] = true;
  for (auto out : adj[v]) {
    if (id.count(out) == 0) {
      tarjan(out);
      llink[v] = min(llink[v], llink[out]);
    } else if (onstack[out]) {
      llink[v] = min(llink[v], id[out]);
    }
  }

  if (id[v] == llink[v]) {
    while (true) {
      int temp = st.top();
      st.pop();
      comp[temp] = n_comps;
      onstack[temp] = false;

      if (temp == v)
        break;
    }
    n_comps++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    char s1, s2;
    int p1, p2;
    cin >> s1 >> p1 >> s2 >> p2;
    if (adj.count(s1) == 0) {
      adj[s1] = vector<int>();
      adj[-s1] = vector<int>();
    }
    if (adj.count(s2) == 0) {
      adj[s2] = vector<int>();
      adj[-s2] = vector<int>();
    }
    int d1 = s1 == '+' ? 1 : -1;
    int d2 = s2 == '+' ? 1 : -1;
    adj[-d1 * p1].push_back(p2 * d2);
    adj[-p2 * d2].push_back(p1 * d1);
  }

  for (int i = 1; i <= m; i++) {
    for (int sign : vector<int>({1, -1})) {
      if (id.count(i * sign) == 0) {
        tarjan(i * sign);
      }
    }
  }

  for (int i = 1; i <= m; i++) {
    if (comp[i] == comp[-i]) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  vector<set<int>> cond_adj(n_comps);
  // build cond graph
  for (int i = -m; i <= m; i++) {
    if (i == 0)
      continue;
    for (auto out : adj[i]) {
      int ci = comp[i];
      int co = comp[out];
      if (co != ci) {
        cond_adj[ci].insert(co);
      }
    }
  }
  // top sort
  vector<int> order;
  vector<bool> seen(n_comps, false);
  function<void(int)> dfs = [&](int v) {
    seen[v] = true;
    for (int out : cond_adj[v]) {
      if (!seen[out]) {
        dfs(out);
      }
    }
    order.push_back(v);
  };

  for (int i = 0; i < n_comps; i++) {
    if (!seen[i]) {
      dfs(i);
    }
  }
  reverse(order.begin(), order.end());
  vector<int> comp_order(n_comps);
  for (int i = 0; i < n_comps; i++) {
    comp_order[order[i]] = i;
  }

  vector<char> ans(m);

  for (int i = 1; i <= m; i++) {
    if (comp_order[comp[i]] < comp_order[comp[-i]]) {
      ans[i - 1] = '-';
    } else {
      ans[i - 1] = '+';
    }
  }

  for (auto ch : ans)
    cout << ch << " ";
  cout << endl;

  return 0;
}
