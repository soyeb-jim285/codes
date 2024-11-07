#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
const ll mod = 103003811;
const ll N = 2e7 + 9;
ll ext_gcd(ll A, ll B, ll *X, ll *Y) {
  ll x2, y2, x1, y1, x, y, r2, r1, q, r;
  x2 = 1;
  y2 = 0;
  x1 = 0;
  y1 = 1;
  for (r2 = A, r1 = B; r1 != 0;
       r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y) {
    q = r2 / r1;
    r = r2 % r1;
    x = x2 - (q * x1);
    y = y2 - (q * y1);
  }
  *X = x2;
  *Y = y2;
  return r2;
}
int F103[N], F1000037[N];
int pr[8], power[8], kr;
ll A[8], M[8];
// number of instance of p(prime) in n!
inline ll legendre(ll n, int p) {
  ll s = 0;
  while (n) {
    n /= p;
    s += n;
  }
  return s;
}
// return a^b % mod
inline int pow(ll a, ll b, int mod) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

void init() {
  F103[0] = 1;
  for (int i = 1; i <= 103; i++)
    F103[i] = i;
  for (int i = 103; i <= 103; i += 103)
    F103[i] = 1;
  for (int i = 1; i <= 103; i++)
    F103[i] = (F103[i] * 1LL * F103[i - 1]) % 103;
  F1000037[0] = 1;
  for (int i = 1; i <= 1000037; i++)
    F1000037[i] = i;
  for (int i = 1000037; i <= 1000037; i += 1000037)
    F1000037[i] = 1;
  for (int i = 1; i <= 1000037; i++)
    F1000037[i] = (F1000037[i] * 1LL * F1000037[i - 1]) % 1000037;
}
// return n!%mod except p, mod=p^k , without p
inline int factorial(ll n, int mod, int p) {
  if (n <= 1)
    return 1;
  ll num = n / mod;
  ll ex = n % mod;
  if (p == 103)
    ex = (pow(F103[mod], num, mod) * 1LL * F103[ex]) % mod;
  else if (p == 1000037)
    ex = (pow(F1000037[mod], num, mod) * 1LL * F1000037[ex]) % mod;
  ex = (ex * 1LL * factorial(n / p, mod, p)) % mod;
  return ex;
}
// return nCr%mod , mod=p^k , without p+with p
inline int nCr(ll n, ll r, int p, int mod) {
  ll tem = legendre(n, p) - legendre(r, p) - legendre(n - r, p);
  tem = pow(p, tem, mod);
  if (tem == 0)
    return 0;
  // without p
  int a = factorial(n, mod, p);
  int b = (factorial(r, mod, p) * 1LL * factorial(n - r, mod, p)) % mod;
  a = (a * 1LL * pow(b, (mod - mod / p) - 1, mod)) % mod;
  // with p
  a = (a * 1LL * tem) % mod;
  return a;
}

ll modpow(ll b, ll e, ll mod) {
  ll ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1)
      ans = ans * b % mod;
  return ans;
}
ll crt(ll *A, ll *M, ll n) {
  ll a1 = A[0];
  ll m1 = M[0];
  for (ll i = 1; i < n; i++) {
    ll a2 = A[i];
    ll m2 = M[i];

    ll g = __gcd(m1, m2);
    if (a1 % g != a2 % g)
      return -1;
    ll p, q;
    ext_gcd(m1 / g, m2 / g, &p, &q);

    ll mod = m1 / g * m2;
    ll x = (a1 * (m2 / g) * q + a2 * (m1 / g) * p) % mod;
    a1 = x;
    if (a1 < 0)
      a1 += mod;
    m1 = mod;
  }
  return a1;
}

inline int nCr(ll n, ll r, int mod) {
  kr = 0;
  int tem = mod;
  pr[kr] = 103;
  power[kr++] = 103;
  pr[kr] = 1000037;
  power[kr++] = 1000037;
  for (int i = 0; i < kr; i++) {
    int p = pr[i];
    int m = power[i];
    M[i] = power[i];
    A[i] = nCr(n, r, p, m) % m;
  }
  return crt(A, M, kr);
}
void solve() {
  ll n;
  cin >> n;
  ll ans = 0;
  while (n--) {
    ll a, b;
    cin >> a >> b;
    if (a == 1 && b == 1)
      ans = (ans + 1) % mod;
    if (a / 2 < b)
      continue;
    ans = (ans + nCr(a - b, b, mod) + nCr(a - b - 1, b - 1, mod)) % mod;
  }
  cout << ans % mod << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  // sieve();
  init();
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
