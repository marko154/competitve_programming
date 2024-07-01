#include <bits/stdc++.h>
#include <ios>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using namespace std;
// #define endl '\n'
typedef long long ll;

ll mod = 1e9 + 7;

struct Node {
  unordered_map<char, Node*> children;
  bool isend = false;
};

struct Trie {
  Node* root;
  Trie() {
    root = new Node();
  }
  void insert(string word) {
    Node* node = root;
    for (char ch : word) {
      if (node->children.count(ch) == 0) {
        node->children[ch] = new Node();
      }
      node = node->children[ch];
    }
    node->isend = true;
  }
  
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string text; cin >> text;
  ll k; cin >> k;
  Trie trie;

  for (ll i = 0; i < k; i++) {
    string word; cin >> word;
    trie.insert(word);
  }

  vector<ll> dp(text.size(), -1);
  
  function<ll(ll)> solve = [&](ll i) {
    if (i >= text.size()) return 1ll;
    ll ans = 0;
    if (dp[i] != -1) return dp[i];
    
    Node* node = trie.root;
    for (ll j = i; j < text.size(); j++) {
      char ch = text[j];
      if (node->children.count(ch) == 0) break;
      node = node->children[ch];
      if (node->isend) {
        ans += solve(j + 1);
      }
    }
    return dp[i] = ans % mod;
  };
  
  cout << solve(0) << endl;

  return 0;
}
