#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (ll i = 0; i < n; ++i)
    cin >> arr[i];

  vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n, {0, 0}));

  for (ll size = 0; size < n; size++) {
    for (ll start = 0; start < n - size; start++) {
      if (size == 0)
        dp[size][start].first = arr[start];
      else {
        auto end = dp[size - 1][start];
        swap(end.first, end.second);
        end.first += arr[start + size];
        auto beg = dp[size - 1][start + 1];
        swap(beg.first, beg.second);
        beg.first += arr[start];
        if (beg.first > end.first)
          swap(beg, end);
        dp[size][start] = end;
      }
    }
  }

  cout << dp[n - 1][0].first << endl;

  return 0;
}
