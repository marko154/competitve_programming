#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int dp[501][501];

int main() {
  int a, b;
  cin >> a >> b;

  for (int i = 0; i <= min(a, b); i++)
    dp[i][i] = 0;

  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++) {
      if (i == j)
        continue;
      int ans = 1e9;
      for (int k = 1; k <= i - 1; k++)
        ans = min(ans, 1 + dp[i - k][j] + dp[k][j]);
      for (int k = 1; k <= j - 1; k++)
        ans = min(ans, 1 + dp[i][k] + dp[i][j - k]);
      dp[i][j] = ans;
    }

  cout << dp[a][b] << endl;

  return 0;
}
