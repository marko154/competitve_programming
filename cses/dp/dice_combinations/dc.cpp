
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;

ll memo[(ll)1e6 + 1];
ll mod = (ll)1e9 + 7;

ll solve(ll n) {
  if (n <= 0)
    return 0;
  if (memo[n])
    return memo[n];
  for (auto i : vector<int>({1, 2, 3, 4, 5, 6}))
    memo[n] += solve(n - i) % mod;
  if (n <= 6)
    memo[n]++;
  return memo[n] % mod;
}

int main() {
  ll n;
  cin >> n;
  cout << solve(n) << endl;
}
