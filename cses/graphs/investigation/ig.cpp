
#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
typedef long long ll;
typedef struct {
  ll price;
  ll n_routes;
  ll min_flights;
  ll max_flights;
} Info;

ll mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;

  vector<vector<pair<ll, ll>>> adj(n);
  for (ll i = 0; i < m; i++) {
    ll fr, to, w;
    cin >> fr >> to >> w;
    fr--;
    to--;
    adj[fr].push_back({to, w});
  }

  ll inf = 1e17;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  vector<Info> info(n, {inf, 0, 0, 0});
  info[0].price = 0;
  info[0].n_routes = 1;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [d, node] = pq.top();
    pq.pop();
    if (d != info[node].price)
      continue;
    for (auto [out, w] : adj[node]) {
      if (d + w < info[out].price) {
        info[out].price = d + w;
        info[out].n_routes = info[node].n_routes;
        info[out].min_flights = info[node].min_flights + 1;
        info[out].max_flights = info[node].max_flights + 1;
        pq.push({d + w, out});
      } else if (d + w == info[out].price) {
        info[out].n_routes = (info[node].n_routes + info[out].n_routes) % mod;
        info[out].min_flights =
            min(info[out].min_flights, info[node].min_flights + 1);
        info[out].max_flights =
            max(info[out].max_flights, info[node].max_flights + 1);
      }
    }
  }
  Info ans = info[n - 1];
  cout << ans.price << " " << ans.n_routes << " " << ans.min_flights << " "
       << ans.max_flights << endl;

  return 0;
}
