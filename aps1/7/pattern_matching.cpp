#include <array>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string pattern, text;
map<array<int, 2>, int> memo;

pair<int, int> match(int t_start, int p_start, int match_start) {
  if (p_start == pattern.length()) {
    int end = t_start - 1;
    memo[{t_start, p_start}] = end;
    return make_pair(match_start, end);
  }
  // if (memo.count({t_start, p_start}) > 0) {
  //   cout << "memo" << endl;
  //   return make_pair(match_start, memo[{t_start, p_start}]);
  // }

  char c = pattern[p_start];
  char t = t_start < text.length() ? text[t_start] : '.';
  // cout << t_start << " " << p_start << " " << match_start << " " << c << " "
  //      << t << endl;
  pair<int, int> rng = make_pair(-1, -1);
  if (c == '*') {
    match_start = p_start == 0 ? t_start : match_start;
    for (int offset = 0; t_start + offset <= text.length(); offset++) {
      rng = match(t_start + offset, p_start + 1, match_start);
      // lazy matching: take the first match
      if (rng.second != -1) {
        break;
      }
    }
    // normal letter or "?"
  } else if (t_start >= text.length()) {
  } else if (c == '?' || c == text[t_start]) {
    match_start = p_start == 0 ? t_start : match_start;
    rng = match(t_start + 1, p_start + 1, match_start);
  }
  memo[{t_start, p_start}] = rng.second;
  return rng;
}

void find_match() {
  memo.clear();
  pair<int, int> rng = make_pair(-1, -1);
  for (int i = 0; i < text.length(); i++) {
    rng = match(i, 0, -1);
    if (rng.first != -1) {
      // empty match can only happen when the pattern is only stars
      // in this case we we can always choose the first character
      rng.second = max(0, rng.second);
      break;
    }
  }
  if (rng.first != -1) {
    cout << rng.first << " " << rng.second << endl;
  } else {
    cout << -1 << endl;
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
