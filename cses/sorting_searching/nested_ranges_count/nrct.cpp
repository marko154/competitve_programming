#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct FW {
  vector<int> tree;

  FW(int n) { tree = vector<int>(n + 1, 0); }
  void clear() { fill(tree.begin(), tree.end(), 0); }

  void update(int i, int diff) {
    while (i <= tree.size()) {
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
  ios::sync_with_stdio();
  cin.tie(0);
  int n;
  cin >> n;

  vector<int> contained(n, 0);
  vector<int> contains(n, 0);
  vector<array<int, 3>> ints(n);
  unordered_map<int, int> cp;
  set<int> uniq;

  for (int i = 0; i < n; i++) {
    cin >> ints[i][0] >> ints[i][1];
    ints[i][2] = i;
    uniq.insert(ints[i][0]);
    uniq.insert(ints[i][1]);
  }

  int N = 0;
  for (auto v : uniq) {
    cp[v] = N + 1;
    N++;
  }

  sort(ints.begin(), ints.end(), [](array<int, 3> &a, array<int, 3> &b) {
    return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
  });

  FW tree = FW(N);
  for (int i = n - 1; i >= 0; i--) {
    auto [l, r, idx] = ints[i];
    int t = cp[r];
    contains[idx] = tree.get(t);
    tree.update(t, 1);
  }

  tree.clear();

  for (auto [l, r, i] : ints) {
    int t = cp[r];
    contained[i] = tree.get(N) - tree.get(t - 1);
    tree.update(t, 1);
  }

  for (auto c : contains)
    cout << c << " ";
  cout << endl;

  for (auto c : contained)
    cout << c << " ";
  cout << endl;

  return 0;
}
