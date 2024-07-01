#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
stack<int> path;
vector<int> seen;
int start;

void find_cycle(int node) {
  if (seen[node]) {
    if (path.size() == 0)
      return;
    int top = path.top();
    path.pop();
    if (path.size() > 0 && path.top() != node) {
      vector<int> temp;
      temp.push_back(node);
      temp.push_back(top);
      while (path.top() != node) {
        temp.push_back(path.top());
        path.pop();
      }
      cout << temp.size() + 1 << endl;
      cout << node << " ";
      for (int i = temp.size() - 1; i >= 0; i--) {
        cout << temp[i] << " ";
      }
      cout << endl;
      exit(0);
    }
    path.push(top);
    return;
  }
  path.push(node);
  seen[node] = 1;

  for (auto nb : adj[node]) {
    find_cycle(nb);
  }

  path.pop();
}

int main() {
  int n, m;
  cin >> n >> m;
  adj = vector<vector<int>>(n + 1, vector<int>());

  for (int i = 0; i < m; i++) {
    int fr, to;
    cin >> fr >> to;
    adj[fr].push_back(to);
    adj[to].push_back(fr);
  }

  seen = vector<int>(n + 1, 0);
  for (int s = 1; s <= n; s++) {
    path = stack<int>();
    start = s;
    find_cycle(s);
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}
