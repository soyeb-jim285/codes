#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
void solve() {
  ll a, b, l;
  cin >> a >> b >> l;
  ll aa = a, bb = b;
  ll ans = 0;
  set<ll> k;
  for (ll i = 0; l % binpow(a, i) == 0; i++) {
    for (ll j = 0; l % binpow(b, j) == 0; j++) {
      ll kk = binpow(a, i) * binpow(b, j);
      if (l % kk == 0) {
        k.insert(l / kk);
      }
    }
  }
  cout << sz(k) << "\n";
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
