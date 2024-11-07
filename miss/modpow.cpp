#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll modpow(ll b, ll e, ll mod) {
  ll ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1)
      ans = ans * b % mod;
  return ans;
}
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
ll power(long long n, long long k, const ll mod) {
  ll ans = 1 % mod;
  n %= mod;
  if (n < 0)
    n += mod;
  while (k) {
    if (k & 1)
      ans = (long long)ans * n % mod;
    n = (long long)n * n % mod;
    k >>= 1;
  }
  return ans;
}
void solve() {
  ll n, m, mod;
  cin >> n >> m >> mod;
  cout << modpow(n, m, mod) << endl;
  cout << binpowmod(n, m, mod) << endl;
  cout << power(n, m, mod) << endl;
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
