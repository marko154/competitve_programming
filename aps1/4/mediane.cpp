#include <iostream>
#include <queue>
#include <set>

using namespace std;

void print(multiset<int> myset, string name) {
  cout << name;
  for (auto it = myset.begin(); it != myset.end(); ++it)
    cout << ' ' << *it;
  cout << endl;
}

class MedianHeap {
  // replace (or benchmark compare) with a priority queueu
  multiset<int> left, right;
  // priority_queue<int> left, right;

public:
  int insert(int nval) {
    // print(left, "left");
    // print(right, "right");
    // cout << "inserting " << nval << endl;
    // cout << endl;
    if (left.size() == 0 || nval <= *left.rbegin()) {
      left.insert(nval);
    } else {
      right.insert(nval);
    }

    // rebalance
    while (left.size() < right.size()) {
      int smallest_right = *right.begin();
      right.erase(right.begin());
      left.insert(smallest_right);
    }
    // left always has more or equal element as right
    while (left.size() > right.size() + 1) {
      int largest_left = *left.rbegin();
      left.erase(prev(left.end()));
      right.insert(largest_left);
    }

    return *left.rbegin();
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  MedianHeap tree;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    cout << tree.insert(val) << endl;
  }

  return 0;
}
