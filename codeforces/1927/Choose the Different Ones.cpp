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
  set<ll> a, b;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    a.insert(x);
  }
  for (int i = 0; i < m; i++) {
    ll x;
    cin >> x;
    b.insert(x);
  }
  ll ta = 0, tb = 0;
  for (int i = 1; i <= k; i++) {
    if (!a.count(i) && !b.count(i)) {
      cout << "NO\n";
      return;
    } else if (a.count(i) && !b.count(i)) {
      ta++;
    } else if (!a.count(i) && b.count(i)) {
      tb++;
    }
  }
  if (ta <= k / 2 && tb <= k / 2) {
    cout << "YES\n";
  } else
    cout << "NO\n";
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
