#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  map<char, char> mp;
  map<char, char> par;
  for (char i = 'a'; i <= 'z'; i++) {
    mp[i] = i;
    par[i] = i;
  }
  ll q;
  cin >> q;
  while (q--) {
    char x, y;
    cin >> x >> y;
    for (char i = 'a'; i <= 'z'; i++) {
      if (mp[i] == x) {
        mp[i] = y;
      }
    }
  }
  for (int i = 0; i < s.size(); i++) {
    cout << mp[s[i]];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
