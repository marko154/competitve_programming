
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<string> get_segments(string &pattern) {
  vector<string> segments;
  string temp;

  for (char ch : pattern) {
    if (ch == '*') {
      if (!temp.empty()) {
        segments.push_back(temp);
        temp.clear();
      }
    } else {
      temp += ch;
    }
  }

  if (!temp.empty()) {
    segments.push_back(temp);
  }

  return segments;
}

int find_segment(string &segment, int start, string &text) {
  for (int i = start; i + segment.length() <= text.length(); i++) {
    int j;
    for (j = 0; j < segment.length(); j++) {
      bool is_match = segment[j] == '?' || segment[j] == text[i + j];
      if (!is_match)
        break;
    }
    if (j == segment.length())
      return i;
  }
  return -1;
}

void find_match(string &pattern, string &text) {
  vector<string> segments = get_segments(pattern);
  int start = -1, end = 0;
  for (auto segment : segments) {
    end = find_segment(segment, end, text);
    if (end == -1)
      break;
    if (start == -1)
      start = end;
    end += segment.length();
  }
  if (segments.size() == 0)
    end = 1;
  if (pattern[0] == '*')
    start = 0;
  if (end == -1)
    cout << -1 << endl;
  else
    cout << start << " " << end - 1 << endl;
}

int main() {

  int n;
  cin >> n;
  string pattern, text;
  for (int i = 0; i < n; i++) {
    cin >> pattern >> text;
    find_match(pattern, text);
  }
  return 0;
}
