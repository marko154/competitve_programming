#include <bits/stdc++.h>

using namespace std;

int main() {

  int n;
  cin >> n;
  vector<array<int, 3>> edges;

  int fr, to, w;
  while (cin >> fr >> to >> w) {
    edges.push_back({fr, to, w});
  }

  vector<int> dist(n, 1e9);
  dist[0] = 0;

  for (int i = 0; i < n; i++) {
    cout << "h" << i << ": ";
    for (auto d : dist) {
      cout << d << " ";
    }
    cout << endl;
    for (auto [fr, to, w] : edges) {
      cout << fr << " " << to << " " << w << endl;
      if (dist[fr] + w < dist[to]) {
        dist[to] = dist[fr] + w;
      }
    }
  }

  return 0;
}
