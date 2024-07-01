#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;
// #define endl '\n'
typedef long long ll;

ll mod = 1e9 + 7;


vector<ll> z_function(string text) {
  ll T = text.size();
  vector<ll> z(T, 0);
  ll l = 0, r = 0;

  for (ll i = 1; i < T; i++) {
    if (i < r) {
      z[i] = min(z[i - l], r - i);
    }
    while (i + z[i] < T && text[i + z[i]] == text[z[i]]) {
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  string text, pattern; cin >> text >> pattern;
  ll P = pattern.size();
  
  vector<ll> z = z_function(pattern + "#" + text);
  ll ans = 0;

  for (auto el : z) {
    if (el == P) ans++;
  }
  
  cout << ans << endl;

  return 0;
}
