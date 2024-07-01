#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  double n, m, q;
  cin >> n >> m >> q;
  double inf = numeric_limits<double>::infinity();
  vector<vector<double>> dist(n + 1, vector<double>(n + 1, inf));

  for (int i = 0; i < m; i++) {
    double fr, to, w;
    cin >> fr >> to >> w;
    dist[fr][to] = min(dist[fr][to], w);
    dist[to][fr] = min(dist[to][fr], w);
  }
  for (int i = 1; i <= n; i++) {
    dist[i][i] = 0;
  }

  for (int via = 1; via <= n; via++) {
    for (int fr = 1; fr <= n; fr++) {
      for (int to = 1; to <= n; to++) {
        dist[fr][to] = min(dist[fr][to], dist[fr][via] + dist[via][to]);
      }
    }
  }

  for (int i = 0; i < q; i++) {
    double fr, to;
    cin >> fr >> to;
    double D = dist[fr][to];
    D = D == inf ? -1 : D;
    cout << (long long)D << endl;
  }

  return 0;
}
