#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __int128_t lll;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll const mod = 1e9 + 7;
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
  ll ans = n % mod, lst = n % mod, sq = 1;
  for (ll i = 2; i * i <= n; i++) {
    ll gd = n / i;
    ans = (ans + gd * i) % mod;
    ll tmp = n / i;
    tmp = tmp % mod;
    ll ck = lst * (lst + 1) % mod;
    ck = binpowmod(2, mod - 2) * ck % mod;
    ll ckk = tmp * (tmp + 1) % mod;
    ckk = binpowmod(2, mod - 2) * ckk % mod;
    ck = (ck - ckk + mod) % mod;
    // cout << gd << " " << gd * i << " " << ck << " " << ckk << " " << lst << "
    // "
    //      << tmp << " " << ans << "\n";
    ck = ck * (i - 1) % mod;
    if (ck < mod)
      ck = ck % mod;
    ans = (ans + ck) % mod;
    // cout << ans << "\n";
    lst = tmp % mod;
    sq = i;
  }
  ll ck = lst * (lst + 1) % mod;
  ck = binpowmod(2, mod - 2) * ck % mod;
  ll ckk = sq * (sq + 1) % mod;
  ckk = binpowmod(2, mod - 2) * ckk % mod;
  ck = (ck - ckk + mod) % mod;
  if (ck < mod)
    ck = ck % mod;
  ck = ck * sq % mod;
  // cout << ck << " " << lst << " " << sq << "\n";
  ans = (ans + ck) % mod;
  cout << ans << '\n';
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
