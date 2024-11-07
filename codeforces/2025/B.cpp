#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
ll binpowmod(ll a, ll b, ll m) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res *= a;
      res = res % m;
    }
    a *= a;
    a = a % m;
    b >>= 1;
  }
  return res;
}
void solve() {
  ll n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
  }
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    ll ans = binpowmod(2, x, mod);
    if (ans < 0)
      ans += mod;
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
