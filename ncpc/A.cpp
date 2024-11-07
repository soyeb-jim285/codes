#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 1e5 + 10;
ll const mod = 998244353;
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
vector<ll> fact(N);
void fc() {
  fact[0] = 1;
  for (ll i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
}
ll nCr(ll n, ll r) {
  if (r > n)
    return 0;
  ll ans = fact[n];
  ans = (ans * binpowmod(fact[r], mod - 2, mod)) % mod;
  ans = (ans * binpowmod(fact[n - r], mod - 2, mod)) % mod;
  return ans;
}
void solve() {
  ll n, k, ans = 0;
  cin >> n >> k;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ll lng = i;
      if (lng >= 3 && lng % 2 && lng <= k) {
        ll x = n / i;
        ll pans = fact[n];
        ll niche = binpowmod(fact[lng], x, mod);
        pans = (pans * binpowmod(niche, mod - 2, mod)) % mod;
        lng -= 2;
        ll onk = lng * (lng - 1) / 2;
        pans = (pans * binpowmod(onk, x, mod)) % mod;
        ans = (ans + pans) % mod;
      }
      if (i * i != n) {
        lng = n / i;
        if (lng >= 3 && lng % 2 && lng <= k) {
          ll x = i;
          ll pans = fact[n];
          ll niche = binpowmod(fact[lng], x, mod);
          /* cout << pans << " " << niche << " " << lng << " " << x << "\n"; */
          pans = (pans * binpowmod(niche, mod - 2, mod)) % mod;
          /* cout << pans << "++\n"; */
          ll onk = nCr(lng - 1, (lng - 1) / 2);
          pans = (pans * binpowmod(onk, x, mod)) % mod;
          /* cout << pans << "--\n"; */
          ans = (ans + pans) % mod;
        }
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  fc();
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
