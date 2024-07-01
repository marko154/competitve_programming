

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct FW {
  vector<int> tree;
  int n;
  FW(int n) : n(n), tree(vector<int>(n + 1, 0)) {}

  void update(int i, int val) {
    i++;
    while (i <= n) {
      tree[i] += val;
      i += i & (-i);
    }
  }

  int get(int i) {
    i++;
    int s = 0;
    while (i > 0) {
      s += tree[i];
      i -= i & (-i);
    }
    return s;
  }
};

int main() {
  int n;
  cin >> n;
  FW tree(n);
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    tree.update(i, 1);
  }

  for (int i = 0; i < n; i++) {
    int pos;
    cin >> pos;
    int l = 0;
    int r = n - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (tree.get(mid) >= pos)
        r = mid;
      else
        l = mid + 1;
    }
    cout << arr[r];
    if (i < n - 1)
      cout << " ";
    tree.update(r, -1);
  }
  return 0;
}
