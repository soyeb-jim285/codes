#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi pi(const string &s) {
  vi p(sz(s));
  rep(i, 1, sz(s)) {
    int g = p[i - 1];
    while (g && s[i] != s[g])
      g = p[g - 1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}
bool match(const string &s, const string &pat) {
  vi p = pi(pat + '\0' + s), res;
  rep(i, sz(p) - sz(s), sz(p)) if (p[i] == sz(pat)) return true;
  return false;
}
vi match2(const string &s, const string &pat) {
  vi p = pi(pat + '\0' + s), res;
  rep(i, sz(p) - sz(s), sz(p)) if (p[i] == sz(pat))
      res.push_back(i - 2 * sz(pat));
  return res;
}
void solve() {
  string s, pat = "", ss = "";
  bool paisi = 0;
  int ind = -1;
  cin >> s;
  cout << "1 " << sz(s) << " ";
  for (int i = 0; i < sz(s); i++) {
    if (paisi) {
      char x = s[i] == '0' ? '1' : '0';
      pat += x;
    }
    if (s[i] == '0' && !paisi) {
      ind = i;
      pat += '1';
      paisi = 1;
    }
    if (paisi) {
      if (!match(ss, pat)) {
        char x = pat.back() == '0' ? '1' : '0';
        pat.pop_back();
        pat += x;
        if (!match(ss, pat)) {
          pat.pop_back();
          vi res = match2(ss, pat);
          cout << res[0] + 1 << " " << res[0] + sz(s) - ind << "\n";
          return;
        }
      }
    }
    ss += s[i];
  }
  if (!paisi) {
    cout << sz(s) << " " << sz(s) << "\n";
    return;
  }
  vi res = match2(s, pat);
  cout << res[0] + 1 << " " << res[0] + sz(s) - ind << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
