#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;

#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
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
  vector<int> ans(n, 0);
  vector<int> loop_size;

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
    // bfs
    queue<int> q;
    ans[i] = loop_size[loop_idx[i]];
    q.push(i);
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto out : prev[node]) {
        if (status[out] == 0)
          continue;
        q.push(out);
        ans[out] = ans[node] + 1;
      }
    }
  }

  for (auto el : ans)
    cout << el << " ";
  cout << endl;

  return 0;
}
