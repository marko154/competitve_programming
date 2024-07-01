#include <bits/stdc++.h>
#include <ios>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;
// #define endl '\n'
typedef long long ll;


ll mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string text, pattern; cin >> text >> pattern;

  string s = pattern + "#" + text;
  int n = s.size();

  vector<int> pi(n, 0);
  int ans = 0;

  for (int i = 1; i <  n; i++) {
    int j = pi[i  -1];
    while (j > 0 && s[j] != s[i]) {
      j = pi[j - 1];
    }
    if (s[j] == s[i]) {
      j ++;
    }
    pi[i] = j;
    if (j == pattern.size()) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
