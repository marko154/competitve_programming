#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

string pattern, text;
map<pair<int, int>, int> memo;

int match(int t_start, int p_start) {
  if (p_start == pattern.length()) {
    int end = t_start - 1;
    memo[{t_start, p_start}] = end;
    return end;
  }
  if (memo.count({t_start, p_start}) > 0) {
    return memo[{t_start, p_start}];
  }

  char c = pattern[p_start];
  int end = -1;
  if (c == '*') {
    end = match(t_start, p_start + 1);
    if (end == -1 && t_start < text.length())
      end = match(t_start + 1, p_start);
  } else if (t_start >= text.length()) {
    end = -1;
    // normal letter or "?"
  } else if (c == '?' || c == text[t_start]) {
    end = match(t_start + 1, p_start + 1);
  } else {
    end = -1;
  }

  memo[{t_start, p_start}] = end;
  return end;
}

void find_match() {
  memo.clear();
  int end = -1, i;
  for (i = 0; i < text.length(); i++) {
    end = match(i, 0);
    if (end != -1)
      break;
  }

  if (end == -1) {
    cout << -1 << endl;
  } else {
    cout << i << " " << end << endl;
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> pattern >> text;
    find_match();
  }

  return 0;
}
