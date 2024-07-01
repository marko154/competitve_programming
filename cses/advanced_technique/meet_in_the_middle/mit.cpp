#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")

using namespace std;

#define endl '\n'

typedef long long ll;

vector<ll> arr;
ll n, x;
unordered_map<ll, int> sums1;
unordered_map<ll, int> sums2;

bool first = true;
int to;
int sum = 0;
void run(int fr) {
  if (sum > x) {
    return;
  }
  if (fr == to) {
    if (first) {
      sums1[sum]++;
    } else {
      sums2[sum]++;
    }
    return;
  }
  run(fr + 1);
  sum += arr[fr];
  run(fr + 1);
  sum -= arr[fr];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sums1.reserve(1 << 20);
  sums2.reserve(1 << 20);

  cin >> n >> x;
  arr = vector<ll>(n);
  for (auto &i : arr)
    cin >> i;

  int mid = n / 2;
  to = mid;
  run(0);
  to = n;
  first = false;
  run(mid);

  ll ans = 0;
  for (auto [sum, count] : sums1) {
    if (sums2.count(x - sum) > 0) {
      ans += (ll)count * (ll)sums2[x - sum];
    }
  }
  cout << ans << endl;

  return 0;
}
