#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, m, p;
  cin >> n >> m >> p;
  if (n * m < p) {
    cout << "-1\n";
  } else if (n * m == p) {
    cout << p - 1 << "\n";
  } else {
    for (ll i = 0; i <= p; i += n) {
      ll k = p - i;
      ll kk = m - i / n;
      if (k % kk == 0) {
        cout << p << "\n";
        return;
      }
    }
    cout << p + 1 << "\n";
  }
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
