
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

  string text;
  cin >> text;
  int n = text.size();

  vector<int> z(n, 0);
  int l = 0, r = 0;

  for (int i = 1; i < n; i++) {
    if (i < r) {
      z[i] = min(r - i, z[i - l]);
    }

    while (i + z[i] < n && text[z[i]] == text[i + z[i]]) {
      z[i]++;
    }
    if (r < i + z[i]) {
      l = i;
      r = i + z[i];
    }
  }

  for (int i = n - 1; i > 0; i--) {
    if (i + z[i] == n) {
      cout << z[i] << " ";
    }
  }

  return 0;
}
