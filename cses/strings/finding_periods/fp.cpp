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
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }

  
  set<int> periods;
  for (int i = 0; i < n; i++) {
    if (i <= z[i] || i + z[i] == n) {
      periods.insert(i);
    }
    if (periods.count(z[i]) > 0) {
      int next = i + z[i];
      if (next == n || next < n && z[next] == z[i]) {
        // cool
      } else if (n - next < z[i] && next + z[next] == n) {

      } else {
        periods.erase(z[i]);
      }
    }
  }
  periods.insert(n);
  periods.erase(0);
  for (auto period : periods) {
    cout << period <<  " ";
  }
  cout << endl;

  return 0;
}
