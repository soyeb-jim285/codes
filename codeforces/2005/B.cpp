#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, m, q;
  cin >> n >> m >> q;
  vector<ll> t(m);
  for (ll &x : t) {
    cin >> x;
  }
  sort(t.begin(), t.end());
  while (q--) {
    ll x;
    cin >> x;
    ll sm = upper_bound(t.begin(), t.end(), x) - t.begin();
    if (sm == 0) {
      cout << t[0] - 1 << "\n";
      continue;
    }
    sm--;
    ll bg = upper_bound(t.begin(), t.end(), x) - t.begin();
    if (bg == m) {
      cout << n - t[m - 1] << '\n';
      continue;
    }
    ll d = t[bg] - t[sm] - 1;
    cout << (d + 1) / 2 << '\n';
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
/*
 * * * * * *
 */
