#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct TrieNode {
  int count;
  TrieNode *children[26];
  TrieNode() : count(0) {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }
  void insert(const string &word) {
    TrieNode *node = root;
    for (char ch : word) {
      int index = ch - 'a';
      if (node->children[index] == nullptr) {
        node->children[index] = new TrieNode();
      }
      node = node->children[index];
      node->count++;
    }
  }
  int countPrefixWithWildcard(TrieNode *node, const string &prefix, int pos) {
    if (!node)
      return 0;

    if (pos == prefix.size())
      return node->count;

    char ch = prefix[pos];
    int totalCount = 0;

    if (ch == '*') {
      for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
          totalCount +=
              countPrefixWithWildcard(node->children[i], prefix, pos + 1);
        }
      }
    } else {
      int index = ch - 'a';
      totalCount =
          countPrefixWithWildcard(node->children[index], prefix, pos + 1);
    }

    return totalCount;
  }
  int countPrefix(const string &prefix) {
    return countPrefixWithWildcard(root, prefix, 0);
  }
};
void solve() {
  int n;
  cin >> n;
  Trie pre, suf, both;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    pre.insert(s);
    string tmp = "";
    for (int j = 0; j < s.size(); j++) {
      tmp += s[j];
      tmp += s[s.size() - j - 1];
    }
    both.insert(tmp);
    reverse(s.begin(), s.end());
    suf.insert(s);
  }
  ll q;
  cin >> q;
  while (q--) {
    string p, s;
    cin >> p >> s;
    reverse(s.begin(), s.end());
    string tmp = "";
    ll pi = 0, si = 0;
    while (pi < p.size() || si < s.size()) {
      if (pi < p.size()) {
        tmp += p[pi];
      } else {
        tmp += "*";
      }
      if (si < s.size()) {
        tmp += s[si];
      } else {
        tmp += "*";
      }
      pi++;
      si++;
    }
    cout << pre.countPrefix(p) + suf.countPrefix(s) - both.countPrefix(tmp)
         << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
