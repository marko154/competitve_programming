#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;
// #define endl '\n'
typedef long long ll;

ll mod = 1e9 + 7;

vector<int> find_matches(string text, string pattern) {
  int T = text.size(), P = pattern.size();
  vector<int> matches;
  if (P > T) return matches;

  vector<int> ppow(T, 0);
  ppow[0] = 1;
  int p = 31, m = mod;

  for (int i = 1; i < T; i++) {
    ppow[i] = (ppow[i - 1] * p) % m;
  }

  int p_hash = 0;
  for (int i = 0; i < P; i++) {
    p_hash = (p_hash + (pattern[i] - 'a' + 1) * ppow[i]) % m;
  }

  vector<int> h(T + 1, 0); 
  for (int i = 0; i < T; i++) {
    h[i + 1] = (h[i] + (text[i] - 'a' + 1) * ppow[i]) % m;
  }

  for (int i = 0; i + P < T + 1; i++) {
    int s_hash = (h[i + P] - h[i] + m) % m;
    if (s_hash == (p_hash * ppow[i] % m)) {
      matches.push_back(i + 1);
    }
  }

  return matches;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string text, pattern;
    cin >> text >> pattern;
    vector<int> matches = find_matches(text, pattern);

    if (matches.size() == 0) {
      cout << "Not Found" << endl;
    } else {
      cout << matches.size() << endl;
      for (auto match : matches)
        cout << match << " ";
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
