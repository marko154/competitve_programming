#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
  int start, end;
} Range;

int main() {

  int m, n;
  cin >> m >> n;
  vector<Range> lights(n, {0, 0});

  for (int i = 0; i < n; i++) {
    int x, d;
    cin >> x >> d;
    lights[i] = {max(0, x - d), min(x + d, m)};
  }

  sort(lights.begin(), lights.end(),
       [](Range r1, Range r2) { return r1.start < r2.start; });

  int dark = m;
  int end = 0;

  for (auto light : lights) {
    int new_end = max(end, light.end);
    dark -= new_end - max(end, light.start);
    end = new_end;
  }
  cout << dark << endl;

  return 0;
}
