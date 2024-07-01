
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

ll dp[1 << 10][1001];

vector<ll> n_masks(ll mask) {
  vector<ll> masks;
  for ()
    return masks;
}

ll solve(int mask, int m) {
  if (m == 0) {
    // 1 if mask is valid (valid directions) else 0
  }
  if (dp[mask][m])
    return dp[mask][m];
  ll ans = 0;
  auto masks = n_masks(mask);
  for (auto mmask : masks) {
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;

  return 0;
}
