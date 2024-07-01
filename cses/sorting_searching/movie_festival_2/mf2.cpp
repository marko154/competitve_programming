#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> arr(n);
  set<int> uq;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr.begin(), arr.end(),
       [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });

  auto cmp = [](int a, int b) { return a > b; };

  multiset<int> ms;
  for (int i = 0; i < k; i++) {
    ms.insert(0);
  }

  int ans = 0;
  for (auto m : arr) {
    if (m.first < *ms.begin())
      continue;
    auto it = ms.lower_bound(m.first);
    if (it != ms.begin()) {
      it--;
    }
    ms.erase(it);
    ms.insert(m.second);
    ans++;
  }
  cout << ans << endl;
  return 0;
}
