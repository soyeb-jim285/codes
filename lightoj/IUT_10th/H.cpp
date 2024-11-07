#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void encode(string &s) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] = 2 * (s[i] - 'A') + 'A';
    } else {
      ll x = toupper(s[i]);
      s[i] = 2 * (x - 'A') + 'A' + 1;
    }
  }
}
void decode(string &s) {
  for (int i = 0; i < s.size(); i++) {
    ll x = s[i] - 'A';
    if (x % 2 == 0) {
      s[i] = (s[i] - 'A') / 2 + 'A';
    } else {
      s[i] = (s[i] - 'A' - 1) / 2 + 'a';
    }
  }
}
void solve() {
  ll n;
  cin >> n;
  vector<set<string>> st(4);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s[0] == 'A') {
      encode(s);
      st[0].insert(s);
    } else if (s[0] == 'B') {
      encode(s);
      st[1].insert(s);
    } else if (s[0] == 'C') {
      encode(s);
      st[2].insert(s);
    } else {
      encode(s);
      st[3].insert(s);
    }
  }
  ll q;
  cin >> q;
  while (q--) {
    char x, lst;
    string mid;
    cin >> x >> mid >> lst;
    if (x == 'A') {
      if (st[0].size()) {
        string s = *st[0].begin();
        st[0].erase(st[0].begin());
        decode(s);
        cout << s << "\n";
      } else {
        cout << "Already Mastered\n";
      }
    } else if (x == 'B') {
      if (st[1].size()) {
        string s = *st[1].begin();
        st[1].erase(st[1].begin());
        decode(s);
        cout << s << "\n";
      } else {
        cout << "Already Mastered\n";
      }
    } else if (x == 'C') {
      if (st[2].size()) {
        string s = *st[2].begin();
        st[2].erase(st[2].begin());
        decode(s);
        cout << s << "\n";
      } else {
        cout << "Already Mastered\n";
      }
    } else {
      if (st[3].size()) {
        string s = *st[3].begin();
        st[3].erase(st[3].begin());
        decode(s);
        cout << s << "\n";
      } else {
        cout << "Already Mastered\n";
      }
    }
  }
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
