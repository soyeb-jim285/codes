#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool isvowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
void solve() {
  string s;
  cin >> s;
  ll k;
  cin >> k;
  ll n = s.size();
  ll vls = 0, cnts = 0, mx = 0, ln = 0;
  for (int i = 0; i < n; i++) {
    if (isvowel(s[i])) {
      vls++;
      cnts = 0;
    } else {
      cnts++;
      vls = 0;
    }
    if (vls >= k) {
      mx = max(mx, ln);
      ln = k - 2;
      vls = k - 1;
    }
    if (cnts >= k) {
      mx = max(mx, ln);
      ln = k - 2;
      cnts = k - 1;
    }
    ln++;
  }
  mx = max(mx, ln);
  cout << mx << "\n";
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
