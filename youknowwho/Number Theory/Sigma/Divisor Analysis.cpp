#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
ll binpowmod(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res *= a;
      res = res % mod;
    }
    a *= a;
    a = a % mod;
    b >>= 1;
  }
  return res;
}
void solve() {
  ll n;
  cin >> n;
  ll num = 1, sum = 1, mul = 1, base = 1;
  vector<pair<ll, ll>> v(n);
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    v[i] = {a, b};
    num = num * (b + 1) % mod;
    ll x = binpowmod(a, b + 1) - 1;
    x = (x * binpowmod(a - 1, mod - 2)) % mod;
    sum = (sum * x) % mod;
    mul = (mul * binpowmod(a, b)) % mod;
    base = (base * a) % mod;
  }
  cout << mul << " " << base << '\n';
  for (int i = 0; i < n; i++) {
    mul = (mul * binpowmod(base, v[i].second + 1)) % mod;
    // mul = (mul * binpowmod(binpowmod(v[i].first, 2), mod - 2)) % mod;
  }
  cout << num << ' ' << sum << ' ' << mul << '\n';
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
