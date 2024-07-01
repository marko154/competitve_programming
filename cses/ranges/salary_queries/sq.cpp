#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct FW {
  vector<int> tree;
  int n;
  FW(int n) : n(n), tree(vector<int>(n + 1, 0)) {}
  void update(int i, int diff) {
    while (i <= n) {
      tree[i] += diff;
      i += i & (-i);
    }
  }
  int get(int i) {
    int s = 0;
    while (i > 0) {
      s += tree[i];
      i -= i & (-i);
    }
    return s;
  }
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> uq;
  vector<int> salaries(n);

  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d ", &t);
    salaries[i] = t;
    uq.push_back(t);
  }

  vector<vector<int>> queries(q);

  for (int i = 0; i < q; i++) {
    char a;
    int b, c;
    scanf(" %c %d %d", &a, &b, &c);
    queries[i] = {a, b, c};
    uq.push_back(b);
    uq.push_back(c);
  }
  sort(uq.begin(), uq.end());

  unordered_map<int, int> cp;
  int idx = 0;
  int prev = 0;
  for (auto el : uq) {
    if (el != prev) {
      cp.emplace(el, ++idx);
      prev = el;
    }
  }

  FW tree(idx);
  for (auto v : salaries)
    tree.update(cp[v], 1);

  for (const auto &v : queries) {
    char c = v[0];
    if (c == '!') {
      int k = v[1], x = v[2];
      tree.update(cp[salaries[k - 1]], -1);
      salaries[k - 1] = x;
      tree.update(cp[x], 1);
    } else {
      int a = v[1];
      int b = v[2];
      printf("%d\n", tree.get(cp[b]) - tree.get(cp[a] - 1));
    }
  }

  return 0;
}
