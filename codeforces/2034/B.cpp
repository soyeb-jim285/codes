#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  ll kk = k;
  string s;
  cin >> s;
  ll zeros = 0, ans = 0, zz = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (kk != k) {
        kk--;
        if (kk == 0) {
          kk = k;
        }
      } else {
        zeros++;
      }
      if (zeros >= m) {
        ans++;
        zeros = 0;
        kk--;
        if (kk == 0) {
          kk = k;
        }
      }
    } else {
      zeros = 0;
      if (kk != k) {
        kk--;
        if (kk == 0) {
          kk = k;
        }
      }
    }
  }
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
