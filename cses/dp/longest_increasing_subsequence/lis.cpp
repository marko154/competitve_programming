#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  vector<ll> dp;

  for (int i = 0; i < n; i++) {
    ll el;
    cin >> el;
    auto it = lower_bound(dp.begin(), dp.end(), el);
    if (it == dp.end())
      dp.push_back(el);
    else
      *it = el;
  }

  cout << dp.size() << endl;

  return 0;
}
