#include <algorithm>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

string to_regex(string &pattern) {
  string rgx = "";
  replace(pattern.begin(), pattern.end(), '?', '.');
  for (auto ch : pattern) {
    if (ch == '*')
      rgx += ".*?";
    else
      rgx += ch;
  }
  return rgx;
}

int main() {
  string input, ipattern;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ipattern >> input;
    regex pattern(to_regex(ipattern));
    sregex_iterator iter(input.begin(), input.end(), pattern);
    sregex_iterator end;

    if (iter != end) {
      int len = iter->length();
      if (len == 0)
        len++;
      cout << iter->position() << " " << iter->position() + len - 1 << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
