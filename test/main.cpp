#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll size, ll pc) {
  ll min = (1LL << (size - 1));
  for (int i = 0; i < pc - 1; i++) {
    min |= 1LL << i;
  }
  ll max = (1LL << (size - 1));
  for (int i = 0; i < pc - 1; i++) {
    max |= 1LL << (size - 2 - i);
  }

  ll ans = 0;

  for (ll i = ceil(sqrt(min)); i * i <= max; i++) {
    if (pc == __builtin_popcountll(i * i)) {
      ans++;
    }
  }
  return ans;
}

int main() {
  ll n;
  cin >> n;
  ll size = 64 - __builtin_clzll(n);
  ll pc = __builtin_popcountll(n);
  cout << solve(size, pc) << endl;
  // cout << "int ans[63][62] = {" << endl;
  // for (int i = 1; i <= 62; i++) {
  //   cout << "{";
  //   for (int j = 0; j <= 62; j++) {
  //     cout << solve(i, j);
  //     if (j != 62)
  //       cout << ",";
  //   }
  //   cout << "}," << endl;
  // }
  //
  // cout << "};" << endl;

  return 0;
}
