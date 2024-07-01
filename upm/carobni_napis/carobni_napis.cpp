#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, pattern;

  cin >> s >> pattern;
  vector<int> positions;
  for (int i = 0; i < s.size() - pattern.size() + 1; i++) {
    bool valid = true;
    for (int j = 0; j < pattern.size(); j++)
      if (s[i + j] != '?' && s[i + j] != pattern[j]) {
        valid = false;
        break;
      }
    if (valid)
      positions.push_back(i);
  }

  vector<bool> matches(pattern.size(), false);
  for (int size = 1; size <= pattern.size(); size++) {
    bool match = true;
    for (int i = 0; i < size; i++)
      if (pattern[i] != pattern[pattern.size() - size + i]) {
        match = false;
        break;
      }
    matches[size] = match;
  }

  auto is_compatible = [&](int i, int j) {
    if (i + pattern.size() <= j)
      return true;
    int pref_len = (pattern.size() + i) - j;
    return (bool)matches[pref_len];
  };
  int ans = 0;
  vector<int> dp(s.size(), 0);

  for (int i = positions.size() - 1; i >= 0; i--) {
    int best = 0;
    for (int j = i + 1; j < positions.size(); j++) {
      if (is_compatible(positions[i], positions[j])) {
        best = max(best, dp[positions[j]]);
      }
    }
    dp[positions[i]] = 1 + best;
    ans = max(ans, best + 1);
  }

  cout << ans << endl;

  return 0;
}
