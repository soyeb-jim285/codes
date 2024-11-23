#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll unique_substrings(const string &s) {
  set<string> all;
  for (int i = 0; i < sz(s); i++) {
    for (int j = i; j < sz(s); j++) {
      all.insert(s.substr(i, j - i + 1));
    }
  }
  return sz(all);
}
vector<string> all_substrings(const string &s) {
  vector<string> res;
  for (int i = 0; i < sz(s); i++) {
    for (int j = i; j < sz(s); j++) {
      res.push_back(s.substr(i, j - i + 1));
    }
  }
  return res;
}
void solve() {
  string s;
  cin >> s;
  int n = sz(s);
  if (n == 2) {
    if (s[0] == s[1]) {
      cout << s << "\n";
    } else {
      cout << "-1\n";
    }
    return;
  }
  for (int i = 0; i < n - 2; i++) {
    if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
      cout << s[i] << s[i + 1] << s[i + 2] << "\n";
      return;
    } else if (s[i] == s[i + 1]) {
      cout << s[i] << s[i + 1] << "\n";
      return;
    } else if (s[i + 1] == s[i + 2]) {
      cout << s[i + 1] << s[i + 2] << "\n";
      return;
    }
  }
  cout << "-1\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
