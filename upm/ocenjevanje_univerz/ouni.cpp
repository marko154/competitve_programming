#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  ll a, b;
  cin >> a >> b;

  double bottom = 0, top = 1;

  for (ll i = 0; i < n - 1; i++) {
    ll ai, bi;
    cin >> ai >> bi;
    ll d = b - bi;
    ll c = ai - a + b - bi;
    if (c == 0) {
      if (d < 0) {
        cout << "Slabe metrike" << endl;
        return 0;
      }
    } else if (c > 0) {
      top = min(top, (double)d / c);
    } else {
      bottom = max(bottom, (double)d / c);
    }
  }
  if (0 <= bottom && bottom <= top && top <= 1) {
    double best = (bottom + top) / 2;
    cout << best << " " << 1 - best << endl;
  } else {
    cout << "Slabe metrike" << endl;
  }

  return 0;
}
