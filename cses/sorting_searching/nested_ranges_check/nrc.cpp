
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio();
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> contained(n, 0);
  vector<int> contains(n, 0);
  auto cmp = [](pair<int, int> a, pair<int, int> b) {
    return a.first == b.first ? a.second > b.second : a.first < b.first;
  };
  vector<pair<int, int>> s(n);
  set<pair<int, int>> e;
  map<pair<int, int>, int> m;

  int end = -1;

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    m[{l, r}] = i;
    s[i] = {l, r};
    e.insert({r, l});
  }
  sort(s.begin(), s.end(), cmp);

  for (auto [l, r] : s) {
    e.erase({r, l});

    if (end >= r) {
      contained[m[{l, r}]] = 1;
    }

    end = max(end, r);

    if (e.size() == 0)
      break;
    auto [rr, ll] = *e.begin();
    if (rr <= r) {
      contains[m[{l, r}]] = 1;
    }
  }

  for (auto c : contains)
    cout << c << " ";
  cout << endl;

  for (auto c : contained)
    cout << c << " ";
  cout << endl;

  return 0;
}
