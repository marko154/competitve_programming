#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

typedef vector<int> Path;
typedef vector<int> DistToEnd;

pair<Path, DistToEnd> build_path(vector<int> &back_ref, vector<int> &dist,
                                 int start, int end) {
  Path path;
  DistToEnd dist_to_end(n, -1);
  int length = dist[end];

  int node = end;
  while (node != start && node != -1) {
    dist_to_end[node] = length - dist[node];
    path.push_back(node);
    node = back_ref[node];
  }
  dist_to_end[start] = length;
  path.push_back(start);

  return {path, dist_to_end};
}

pair<Path, DistToEnd> dijkstra_initial(int start, int end) {
  vector<int> dist(n, -1);
  dist[start] = 0;
  vector<int> back_ref(n, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  q.push({0, start});

  while (q.size() > 0) {
    auto [d, v] = q.top();
    // maybe early return if v == end
    q.pop();
    if (d != dist[v])
      continue;
    for (auto [nb, w] : adj[v]) {
      int new_d = d + w;
      if (dist[nb] == -1 || dist[nb] > new_d) {
        dist[nb] = new_d;
        back_ref[nb] = v;
        q.push({new_d, nb});
      }
    }
  }
  return build_path(back_ref, dist, start, end);
}

int dijkstra_optimized(int start, int end, DistToEnd &dist_to_end, Path path,
                       int best_so_far) {
  vector<int> dist(n, -1);
  dist[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  q.push({0, start});

  while (q.size() > 0) {
    auto [d, v] = q.top();
    q.pop();
    if (v == end || best_so_far != -1 && d >= best_so_far)
      return d;
    if (d != dist[v] || dist_to_end[v] == -2)
      continue;
    if (dist_to_end[v] != -1) {
      q.push({d + dist_to_end[v], end});
      // at this point we can be sure that no other path through `v` will be
      // shorter so we dont have to process the neighbors
      continue;
    }
    for (auto [nb, w] : adj[v]) {
      int new_d = d + w;
      if (dist[nb] == -1 || dist[nb] > new_d) {
        dist[nb] = new_d;
        q.push({new_d, nb});
      }
    }
  }
  return dist[end];
}

int remove_edge(int from, int to) {
  int weight;
  vector<pair<int, int>> connections;
  for (auto [nb, w] : adj[from]) {
    if (nb == to) {
      weight = w;
    } else {
      connections.push_back({nb, w});
    }
  }
  adj[from] = connections;
  return weight;
}
void add_edge(int from, int to, int w) { adj[from].push_back({to, w}); }

int main() {
  cin >> n >> m;
  adj.resize(n);

  for (int i = 0; i < m; i++) {
    int from, to, w;
    cin >> from >> to >> w;
    add_edge(from, to, w);
    add_edge(to, from, w);
  }

  auto [sh_path, dist_to_end] = dijkstra_initial(0, n - 1);
  int sh_len = dist_to_end[0];
  vector<int> d_t_e(n, -1);
  for (int i = 0; i < n; i++) {
    if (dist_to_end[i] != -1)
      d_t_e[i] = -2;
  }
  d_t_e[n - 1] = 0;
  int ans = -1;

  for (int i = 0; i < sh_path.size() - 1; i++) {
    int to = sh_path[i];
    int from = sh_path[i + 1];
    int removed_weight = remove_edge(from, to);
    remove_edge(to, from);
    int temp = dist_to_end[from];
    int dist_to_start = (sh_len - temp);
    d_t_e[from] = -1;
    int path_len =
        dist_to_start + dijkstra_optimized(from, n - 1, d_t_e, sh_path, ans);
    d_t_e[from] = temp;
    if (path_len >= sh_len && (ans == -1 || ans >= path_len)) {
      ans = path_len;
    }
    add_edge(from, to, removed_weight);
    add_edge(to, from, removed_weight);
  }
  cout << ans << endl;
  return 0;
}
