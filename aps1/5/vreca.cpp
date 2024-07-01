#include <iostream>
#include <vector>

#define N (1 << 20)
#define ll long long

using namespace std;

struct FWTree {
  vector<ll> fw;
  vector<ll> arr;

  FWTree() {
    fw.resize(N, 0);
    arr.resize(N, 0);
  }

  ll query(ll l, ll r) {
    return sum(min(r, (ll)N - 1)) - sum(max(l - 1, (ll)0));
  }

  ll sum(ll end) {
    ll s = 0;

    while (end >= 0) {
      s += fw[end];
      end -= max_p2_div(end);
    }
    return s;
  }
  void insert(ll val) {
    arr[val]++;
    update(val, 1);
  }
  void remove(ll val) {
    if (arr[val] > 0) {
      arr[val]--;
      update(val, -1);
    }
  }

  void update(ll pos, ll diff) {
    while (pos < N) {
      fw[pos] += diff;
      pos += max_p2_div(pos);
    }
  }

  ll max_p2_div(ll k) { return (k + 1) & (-(k + 1)); }
};

int main() {
  ll n, ans = 0;
  cin >> n;
  FWTree tree;

  for (ll i = 0; i < n; i++) {
    ll s, x;
    cin >> s >> x;
    if (s < 0) {
      // add x
      tree.insert(x);
    } else if (s == 0) {
      // remove x
      tree.remove(x);
    } else {
      ans += tree.query(min(s, x), max(s, x));
    }
  }

  cout << ans << endl;
  return 0;
}
