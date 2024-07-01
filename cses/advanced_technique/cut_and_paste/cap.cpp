#include <bits/stdc++.h>
#include <ext/rope>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace __gnu_cxx;
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;

  string text;
  cin >> text;
  text[n] = '\0';
  crope rope = text.c_str();

  for (int i = 0; i < m; i++) {
    int fr, to;
    cin >> fr >> to;
    fr--;
    to--;
    rope.append(rope.substr(fr, to - fr + 1));
    rope.erase(fr, to - fr + 1);
  }

  cout << rope << endl;

  return 0;
}
