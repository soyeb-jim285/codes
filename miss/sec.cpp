#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 2e7 + 1, P = 103, Q = 1000037;
ll const mod = 103003811;
vector<ll> fac1(P), fac2(Q);
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
void precal() {
  fac1[0] = 1;
  for (ll i = 1; i < P; i++) {
    fac1[i] = (fac1[i - 1] * i) % P;
  }
  fac2[0] = 1;
  for (ll i = 1; i < Q; i++) {
    fac2[i] = (fac2[i - 1] * i) % Q;
  }
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
    ll N_i = binpowmod(M_i, congruence.m - 2, congruence.m);
    solution = (solution + a_i * M_i % M * N_i) % M;
  }
  return solution;
}
ll ncr(ll n, ll r, ll p) {
  if (n < r || n >= p || r >= p || n - r >= p)
    return 0;
  ll ans;
  if (p == P)
    ans = (fac1[n] * binpowmod(fac1[r], p - 2, p) % p *
           binpowmod(fac1[n - r], p - 2, p) % p) %
          p;
  else
    ans = (fac2[n] * binpowmod(fac2[r], p - 2, p) % p *
           binpowmod(fac2[n - r], p - 2, p) % p) %
          p;
  return ans;
}
ll ansval(ll a, ll b) {
  vector<Congruence> vc;
  Congruence c1, c2;
  c1.a = a * ncr(a - b - 1, b - 1, P) % P;
  c1.a = (c1.a * binpowmod(b, P - 2, P)) % P;
  c1.m = P;
  c2.a = a * ncr(a - b - 1, b - 1, Q) % Q;
  c2.a = (c2.a * binpowmod(b, Q - 2, Q)) % Q;
  c2.m = Q;
  // cout << P << ":" << c1.a << " " << Q << ":" << c2.a << "\n";
  vc.push_back(c1);
  vc.push_back(c2);
  return CRT(vc);
}
void solve() {
  ll n;
  cin >> n;
  ll ans = 0;
  while (n--) {
    ll a, b;
    cin >> a >> b;
    ans += a * ncr(a - b - 1, b - 1, mod);
  }
  cout << ans % mod << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  precal();
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
