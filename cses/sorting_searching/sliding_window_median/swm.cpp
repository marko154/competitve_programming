#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> arr(n);
  for (auto &i : arr)
    cin >> i;

  ordered_set ms;
  for (int i = 0; i < k; i++)
    ms.insert({arr[i], i});

  cout << ms.find_by_order((k - 1) / 2)->first << " ";

  for (int j = k; j < n; j++) {
    ms.erase(ms.lower_bound({arr[j - k], 0}));
    ms.insert({arr[j], j});
    cout << ms.find_by_order((k - 1) / 2)->first;
    if (j < n - 1)
      cout << " ";
  }

  return 0;
}
