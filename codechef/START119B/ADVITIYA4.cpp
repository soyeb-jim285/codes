#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  ll mx = 1, ln = 1, lst = 1;
  char ls = s[n - 1];
  for (int i = 1; i < sz(s); i++) {
    if (s[i] == s[i - 1]) {
      ln++;
    } else {
      mx = max(mx, ln);
      ln = 1;
    }
  }
  lst = ln;
  mx = max(mx, ln);
  cout << mx << " ";

  while (k--) {
    char x;
    cin >> x;
    if (x == ls) {
      lst++;
    } else {
      ls = x;
      lst = 1;
    }
    mx = max(mx, lst);
    cout << mx << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
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
