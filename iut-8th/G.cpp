

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 2e7 + 1;
ll const mod = 103003811;
vector<ll> euler(N + 1, -1), primes;
//[Precompute] Generate primes and also calculate the euler number
void genprime() {
  for (ll i = 2; i <= N; i++) {
    if (euler[i] == -1) {
      primes.push_back(i);
      euler[i] = i - 1;
      for (ll j = 2 * i; j <= N; j += i) {
        if (euler[j] == -1)
          euler[j] = j;
        euler[j] = (euler[j] / i) * (i - 1);
      }
    }
  }
}
// Calculates x raised to the power of p % m
ll powll(ll x, ll p, ll m = 1LL << 62) {
  if (p == 0)
    return 1;
  if (p == 1)
    return x % m;
  ll ans = powll(x, p / 2, m);
  ans = ((ans % m) * (ans % m)) % m;
  if (p & 1)
    ans = (ans * x % m) % m;
  return ans % m;
}
ll inverse(ll x, ll m) {
  if (x == 1)
    return 1;
  return powll(x, euler[m] - 1, m) % m;
}
// finds (n!)_p
ll ff(ll n, ll p, ll q) {
  ll x = 1, y = powll(p, q);
  for (ll i = 2; i <= n; i++)
    if (i % p)
      x = (x * i) % y;
  return x % y;
}
struct Congruence {
  ll a, m;
};
ll CRT(vector<Congruence> const &congruences) {
  ll M = 1;
  for (auto const &congruence : congruences) {
    M *= congruence.m;
  }
  ll solution = 0;
  for (auto const &congruence : congruences) {
    ll a_i = congruence.a;
    ll M_i = M / congruence.m;
    ll N_i = inverse(M_i, congruence.m);
    solution = (solution + a_i * M_i % M * N_i) % M;
  }
  return solution;
}
// Generalized Lucas Theorem calculates nCm mod p^q
ll f(ll n, ll m, ll p, ll q) {
  ll r = n - m, x = powll(p, q);
  ll e0 = 0, eq = 0;
  ll mul = (p == 2 && q >= 3) ? 1 : -1;
  ll cr = r, cm = m, carry = 0, cnt = 0;
  while (cr || cm || carry) {
    cnt++;
    ll rr = cr % p, rm = cm % p;
    if (rr + rm + carry >= p) {
      e0++;
      if (cnt >= q)
        eq++;
    }
    carry = (carry + rr + rm) / p;
    cr /= p;
    cm /= p;
  }
  mul = powll(p, e0) * powll(mul, eq);
  ll ret = (mul % x + x) % x;
  ll temp = 1;
  for (ll i = 0;; i++) // This is THE line that calculates the formula
  {
    ret = ((ret * ff((n / temp) % x, p, q) % x) % x *
           (inverse(ff((m / temp) % x, p, q), x) % x *
            inverse(ff((r / temp) % x, p, q), x) % x) %
           x) %
          x;

    if (temp > n / p && temp > m / p && temp > r / p)
      break;
    temp = temp * p;
  }
  return (ret % x + x) % x;
}
ll ncr_mod_m(ll n, ll r, ll m) {
  if (n < r)
    return 0;
  vector<Congruence> congs;
  Congruence cg;
  cg.a = f(n, r, 103, 1);
  cg.m = 103;
  congs.push_back(cg);
  cg.a = f(n, r, 1000037, 1);
  cg.m = 1000037;
  congs.push_back(cg);
  // // nCr % m = ??
  // for (ll i = 0; primes[i] <= m; i++) {
  //   if (m % primes[i] == 0) {
  //     ll p = primes[i], q = 0;
  //     while (m % p == 0)
  //       q++, m /= p;
  //     cg.a = f(n, r, p, q);
  //     cg.m = powll(p, q);
  //     congs.push_back(cg);
  //   }
  // }
  ll ans = CRT(congs);
  return ans;
}
void solve() {
  ll n;
  cin >> n;
  ll ans = 0;
  map<pair<int, int>, int> mp;
  while (n--) {
    ll a, b;
    cin >> a >> b;
    if (mp.find({a, b}) != mp.end()) {
      ans = (ans + mp[{a, b}]) % mod;
      continue;
    }
    if (a == 1 && b == 1) {
      mp[{a, b}] = 1;
      ans = (ans + 1) % mod;
    } else {
      if (2 * b > a)
        continue;
      ll val = a * ncr_mod_m(a - b - 1, b - 1, mod) % mod;
      // ans = (ans + (((a * ncr_mod_m(a - b - 1, b - 1, mod)) % mod) % mod));
      vector<Congruence> congs;
      Congruence cg;
      cg.a = inverse(b, 103LL);
      cg.m = 103LL;
      congs.push_back(cg);
      cg.a = inverse(b, 1000037LL);
      cg.m = 1000037LL;
      congs.push_back(cg);
      val = (val * CRT(congs)) % mod;
      mp[{a, b}] = val;
      ans = (ans + val) % mod;
      // cout << CRT(congs) << " -*-\n";
    }
  }
  if (ans < 0)
    ans += mod;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  genprime();
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
/*
n * (n - r - 1)! / ((r-1)! * (n - r - 1)!)
*/
