#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef struct Trie {
  unordered_map<char, Trie *> letters;
  long long max_priority = 0;
  int idx;

  void insert(string &word, long long priority, int i) {
    Trie *node = this;
    for (auto c : word) {
      if (node->letters.count(c) == 0)
        node->letters[c] = new Trie;

      node = node->letters[c];
      if (priority > node->max_priority) {
        node->max_priority = priority;
        node->idx = i;
      }
    }
  }
  int match_index(string &query) {
    Trie *node = this;
    for (auto c : query) {
      if (node->letters.count(c) == 0)
        return 0;
      node = node->letters[c];
    }
    return node->idx + 1;
  }
} Trie;

int main() {
  int n, m, priority;
  string word;
  cin >> n;

  Trie trie;

  for (int i = 0; i < n; i++) {
    cin >> word >> priority;
    trie.insert(word, priority, i);
  }
  cin >> m;
  vector<string> queries(m);

  for (int i = 0; i < m; i++) {
    cin >> queries[i];
  }

  for (auto query : queries) {
    cout << trie.match_index(query) << '\n';
  }
  // should probably free the trie nodes here, but i really dont want to
  return 0;
}
