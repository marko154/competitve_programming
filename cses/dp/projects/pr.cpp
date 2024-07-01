

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll, 3> a3l;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;

  vector<a3l> arr(n);
  for (auto &e : arr)
    cin >> e[1] >> e[0] >> e[2];
  sort(arr.begin(), arr.end());
  vector<pair<ll, ll>> dp;

  for (auto [b, a, p] : arr) {
    auto it = lower_bound(dp.begin(), dp.end(), make_pair(a, (ll)0));
    ll score = p;
    if (it != dp.begin())
      score += (it - 1)->second;
    if (dp.size() > 0)
      score = max(score, dp.back().second);
    dp.push_back({b, score});
  }

  cout << dp.back().second << endl;

  return 0;
}
