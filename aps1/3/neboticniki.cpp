#include <iostream>
#include <stack>

using namespace std;

long long count_views(long long *arr, int start, int end, int dir) {
  long long ans = 0;

  stack<long long> stack;

  for (int i = start; i != end; i += dir) {
    long long el = arr[i];
    while (!stack.empty() && stack.top() < el) {
      stack.pop();
      ans += stack.size();
    }
    stack.push(el);
  }
  while (!stack.empty()) {
    stack.pop();
    ans += stack.size();
  }

  return ans;
}

int main() {
  long long n;
  cin >> n;
  long long *arr = new long long[n]();

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  long long ans = count_views(arr, 0, n, 1) + count_views(arr, n - 1, -1, -1);
  cout << ans << endl;
  delete[] arr;
}
