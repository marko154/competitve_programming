#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;

#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  vector<int> next(n);
  vector<vector<int>> prev(n);
  for (int i = 0; i < n; i++) {
    cin >> next[i];
    next[i]--;
    prev[next[i]].push_back(i);
  }
  // -2 - unprocessed -1 - tree, 0 - loop
  vector<int> status(n, -2);
  vector<int> loop_idx(n, -1);
  vector<int> dist_to_loop(n, 0);
  vector<int> loop_size;
  vector<int> idx_in_loop(n, -1);
  vector<int> loop_root(n, -1);

  for (int i = 0; i < n; i++) {
    if (status[i] != -2)
      continue;
    int temp = i;
    while (status[temp] == -2) {
      status[temp] = -3;
      temp = next[temp];
    }
    int end = temp;
    if (status[temp] == -3) {
      // loop
      int size = 0;
      while (true) {
        size++;
        status[temp] = 0;
        loop_idx[temp] = loop_size.size();
        idx_in_loop[temp] = size;
        temp = next[temp];
        if (end == temp)
          break;
      }
      loop_size.push_back(size);
    }
    temp = i;
    while (temp != end) {
      status[temp] = -1;
      temp = next[temp];
    }
  }

  for (int i = 0; i < n; i++) {
    if (status[i] != 0)
      continue;
    queue<int> q;
    int loop_id = loop_idx[i];
    dist_to_loop[i] = 0;
    q.push(i);
    while (!q.empty()) {
      int node = q.front();
      loop_root[node] = i;
      loop_idx[node] = loop_id;
      q.pop();
      for (auto out : prev[node]) {
        if (status[out] == 0)
          continue;
        q.push(out);
        dist_to_loop[out] = dist_to_loop[node] + 1;
      }
    }
  }

  auto loop_dist = [&](int a, int b) {
    int loopa = loop_idx[a];
    int ai = idx_in_loop[a];
    int bi = idx_in_loop[b];
    if (ai > bi)
      bi += loop_size[loopa];
    return bi - ai;
  };

  vector<vector<int>> up(30, vector<int>(n, 0));
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0) {
        up[i][j] = next[j];
      } else {
        up[i][j] = up[i - 1][up[i - 1][j]];
      }
    }
  }
  auto find = [&](int x, int k) {
    int i = 0;
    while (k) {
      if (k & 1)
        x = up[i][x];
      k = k >> 1;
      i++;
    }
    return x;
  };

  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (dist_to_loop[a] == 0) {
      if (dist_to_loop[b] == 0) {
        // loop loop
        int loopa = loop_idx[a];
        int loopb = loop_idx[b];
        if (loopa != loopb) {
          cout << -1 << endl;
        } else {
          cout << loop_dist(a, b) << endl;
        }
      } else {
        cout << -1 << endl;
      }

    } else {
      if (dist_to_loop[b] == 0) {
        // comopnent -> loop
        if (loop_idx[a] != loop_idx[b]) {
          cout << -1 << endl;
        } else {
          int ans = dist_to_loop[a] + loop_dist(loop_root[a], b);
          cout << ans << endl;
        }
      } else {
        // component, component
        int dista = dist_to_loop[a];
        int distb = dist_to_loop[b];
        if (distb > dista || find(a, dista - distb) != b) {
          cout << -1 << endl;
        } else {
          cout << dista - distb << endl;
        }
      }
    }
  }

  return 0;
}
