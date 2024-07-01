#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  int n, q;
  cin >> n >> q;
  set<pair<int, int>> s;

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    s.insert({t, i});
  }

  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    auto lb = lower_bound(s.begin(), s.end(), t);
    s.erase(lb);
    cout << lb->second;
    s.insert({lb->first - t, lb->second});
  }

  return 0;
}
