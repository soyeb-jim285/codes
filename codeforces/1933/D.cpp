#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, ones = 0;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  ll g = a[0];
  for (ll i = 1; i < n; i++) {
    g = __gcd(g, a[i]);
  }
  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == g)
      cnt++;
  }
  if (cnt > 1)
    cout << "NO\n";
  else
    cout << "YES\n";
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
