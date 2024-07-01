#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> inv;

void apply(int fr, int to, vector<int> &pos, vector<int> &arr) {
  int frn = arr[fr];
  int ton = arr[to];
  pos[frn] = to;
  pos[ton] = fr;
  swap(arr[fr], arr[to]);

  // frn - 1, frn
  if (frn - 1 > 0)
    if (pos[frn - 1] < pos[frn])
      inv.erase({frn - 1, frn});
    else
      inv.insert({frn - 1, frn});

  // frn, frn + 1
  if (frn + 1 <= arr.size())
    if (pos[frn] < pos[frn + 1])
      inv.erase({frn, frn + 1});
    else
      inv.insert({frn, frn + 1});

  // to - 1, to
  if (ton - 1 > 0)
    if (pos[ton - 1] < pos[ton])
      inv.erase({ton - 1, ton});
    else
      inv.insert({ton - 1, ton});

  // to, to + 1
  if (ton + 1 <= arr.size())
    if (pos[ton] < pos[ton + 1])
      inv.erase({ton, ton + 1});
    else
      inv.insert({ton, ton + 1});
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  vector<int> pos(n + 1);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }
  for (int x = 1; x < n; x++) {
    if (pos[x] > pos[x + 1])
      inv.insert({x, x + 1});
  }

  int fr, to;
  for (int i = 0; i < k; i++) {
    cin >> fr >> to;
    apply(fr - 1, to - 1, pos, arr);
    cout << inv.size() + 1 << endl;
  }

  return 0;
}
