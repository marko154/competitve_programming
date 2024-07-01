#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;
// #define endl '\n'
typedef long long ll;

ll mod = 1e9 + 7;

vector<int> z_function(string text) {
int T = text.size();
vector<int> z(T, 0);
int l = 0, r = 0;

for (int i = 1; i < T; i++) {
  if (i < r) {
    z[i] = min(r - i, z[i - l]);
  }

  while (i + z[i] < T && text[z[i]] == text[i + z[i]]) {
    z[i]++;
    l = i;
    r = i + z[i];
  }
}

return z;
}

vector<int> find_matches(string text, string pattern) {
vector<int> matches;
vector<int> z = z_function(pattern + "#" + text);
for (int i = 0; i < z.size(); i++) {
  if (z[i] == pattern.size()) {
    matches.push_back(i - pattern.size());
  }
}
return matches;
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
int n; cin >> n;

for (int i = 0; i < n; i++) {
  string text, pattern;
  cin >> text >> pattern;
  vector<int> matches = find_matches(text, pattern);

  if (matches.size() == 0) {
    cout << "Not Found" << endl;
  } else {
    cout << matches.size() << endl;
    for (auto match : matches) cout << match << " ";
    cout << endl;
  }
  cout << endl;
}

return 0;
}
