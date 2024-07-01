#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef struct {
  int a, b;
} Task;

struct DiffTask {
  bool operator()(const Task &t1, const Task &t2) const {
    return (t1.b - t1.a) < (t2.b - t2.a);
  }
};

int main() {

  int n, w;
  cin >> n >> w;
  vector<Task> tasks_by_a(n, {0, 0});
  for (int i = 0; i < n; i++) {
    cin >> tasks_by_a[i].a;
    cin >> tasks_by_a[i].b;
  }

  vector<Task> tasks_by_b = tasks_by_a;

  sort(tasks_by_a.begin(), tasks_by_a.end(),
       [](Task t1, Task t2) { return t1.a < t2.a; });
  sort(tasks_by_b.begin(), tasks_by_b.end(),
       [](Task t1, Task t2) { return t1.b < t2.b; });

  int idxa = 0;
  int idxb = 0;

  set<Task, DiffTask> selected_a;
  set<Task> selected;
  for (int i = 0; i < w; i++) {
    Task smallest_ai = tasks_by_a[idxa];
    if (selected.size() == 0) {
      selected.insert(smallest_ai);
      selected_a.insert(smallest_ai);
      idxa++;
    } else if (selected_a.size() == 0) {
      selected.insert(smallest_ai);
    } else {
      Task best_flip = *selected_a.begin();
      int flip_cost = best_flip.b - best_flip.a;
      int remove_add_cost = tasks_by_b[idxb].b - tasks_by_a[idxa - 1].a;
      int smallest_ai_cost = smallest_ai.a;

      if (flip_cost < remove_add_cost && smallest_ai_cost) {
        // flip
      }
    }
  }

  /*
   * Suppose we have a selection of tasks worth w stars, with minimal time.
   * to get w + 1 stars, we can do 3 things:
   *    - add ai, where i is not in the selection
   *    - flip aj to bj where j is in the selection
   *    - remove a one, add a two
   *  take the best of these options until you get to W
   *
   *  sorted_by_a = [...]
   *  sorted_by_b = [...]
   *
   *  minheap_with_selection = [...]
   * * */

  return 0;
}
