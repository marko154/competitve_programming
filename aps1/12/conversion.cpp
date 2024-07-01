
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  string s, t;
  cin >> s;
  cin >> t;
  int m = t.length();
  int n = s.length();

  vector<vector<int>> dp(m + 1, vector(n + 1, 0));

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (j == 0) {
        dp[i][j] = i * x;
      } else if (i == 0) {
        dp[i][j] = j * y;
      } else {
        dp[i][j] = min(y + dp[i][j - 1], x + dp[i - 1][j]);
        int replace_cost = s[j - 1] == t[i - 1] ? 0 : z;
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + replace_cost);
      }
    }
  }

  cout << dp[m][n] << endl;
  string ans = "";

  while (!(m == 0 && n == 0)) {
    if (n > 0 && dp[m][n - 1] + y == dp[m][n]) {
      n -= 1;
      ans = string("-") + s[n] + string(" ") + ans;
    } else if (m > 0 && dp[m - 1][n] + x == dp[m][n]) {
      m -= 1;
      ans = string("+") + t[m] + string(" ") + ans;
    } else {
      m -= 1;
      n -= 1;
      if (t[m] != s[n])
        ans = s[n] + string(">") + t[m] + " " + ans;
      else
        ans = t[m] + string(" ") + ans;
    }
  }
  cout << ans << endl;

  return 0;
}
