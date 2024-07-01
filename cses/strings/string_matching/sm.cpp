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
  string text, pattern;
  cin >> text >> pattern;

  if (pattern.size() > text.size()) {
    cout << 0 << endl;
    return 0;
  }

  ll p = 53;
  ll m = mod;

  vector<ll> ppow(text.size() + 1);
  ppow[0] = 1;
  for (ll i = 1; i < ppow.size(); i++) {
    ppow[i] = (p * ppow[i - 1]) % m;
  }

  ll pattern_hash = 0;
  for (ll i = 0; i < pattern.size(); i++) {
    pattern_hash = (pattern_hash + ppow[i] * (pattern[i] - 'a' + 1)) % m;
  }

  vector<ll> pref_hash(text.size() + 1, 0);
  for (ll i = 1; i < text.size() + 1; i++) {
    pref_hash[i] = (pref_hash[i - 1] + ppow[i - 1] * (text[i - 1] - 'a' + 1)) % m;
  }
  ll ans = 0;
  for (ll i = 0; i < text.size() - pattern.size() + 1; i++) {
    ll substr_hash = (pref_hash[i + pattern.size()] - pref_hash[i] + m) % m;
    if ((pattern_hash * ppow[i]) % m == substr_hash) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}

