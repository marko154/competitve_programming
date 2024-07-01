#include <functional>
#include <iostream>
#include <queue>

using namespace std;

class MedianHeap {
  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<int>> right;

public:
  int insert(int nval) {
    if (left.size() == 0 || nval <= left.top()) {
      left.push(nval);
    } else {
      right.push(nval);
    }

    // rebalance
    if (left.size() < right.size()) {
      left.push(right.top());
      right.pop();
    }
    // left always has more or equal element as right
    if (left.size() > right.size() + 1) {
      right.push(left.top());
      left.pop();
    }

    return left.top();
  }
};

int main() {
  int n, val;
  cin >> n;

  MedianHeap heap;
  for (int i = 0; i < n; i++) {
    cin >> val;
    cout << heap.insert(val) << "\n";
  }

  return 0;
}
