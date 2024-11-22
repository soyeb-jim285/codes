#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
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
  int n;
  cin >> n;
  ll sum = 0;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    sum %= mod;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    sum += b[i];
    sum %= mod;
  }
  ll down = binpowmod(2 * n, mod - 2, mod);
  for (ll i = 0; i < n; i++) {
    ll r = i + 1;
    ll up = (r * sum) % mod;
    ll ans = (up * down) % mod;
    cout << ans;
    if (i < n - 1)
      cout << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
