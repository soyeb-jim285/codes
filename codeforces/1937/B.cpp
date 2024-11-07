#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, ans = 1;
  cin >> n;
  string s = "";
  vector<string> a(2);
  for (int i = 0; i < 2; i++) {
    cin >> a[i];
  }
  s += a[0][0];
  bool ok = true;
  for (int i = 1; i < n; i++) {
    if (ok) {
      if (a[0][i] == a[1][i - 1]) {
        ans++;
        s += a[0][i];
      } else {
        if (a[0][i] == '0') {
          s += a[0][i];
          ans = 1;
        } else {
          s += a[1][i - 1];
          ok = false;
        }
      }
    } else {
      s += a[1][i - 1];
    }
  }
  s += a[1][n - 1];
  cout << s << "\n";
  cout << ans << "\n";
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
