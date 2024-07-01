#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;

ll inf = 1e9;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (auto &c : coins)
    cin >> c;
  vector<int> dp(x + 1, inf);
  dp[0] = 0;

  for (int i = 0; i <= x; i++) {
    if (find(coins.begin(), coins.end(), i) != coins.end()) {
      dp[i] = 1;
    } else {
      for (auto j : coins)
        if (i - j >= 0)
          dp[i] = min(dp[i], 1 + dp[i - j]);
    }
  }

  cout << (dp[x] == inf ? -1 : dp[x]) << endl;

  return 0;
}
