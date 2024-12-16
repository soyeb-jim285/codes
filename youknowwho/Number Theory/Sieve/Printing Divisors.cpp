#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
typedef unsigned long long ull;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
ull modmul(ull a, ull b, ull M) {
  ll ret = a * b - M * ull(1.L / M * a * b);
  return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
  ull ans = 1;
  for (; e; b = modmul(b, b, mod), e /= 2)
    if (e & 1)
      ans = modmul(ans, b, mod);
  return ans;
}
bool isPrime(ull n) {
  if (n < 2 || n % 6 % 4 != 1)
    return (n | 1) == 3;
  ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
      s = __builtin_ctzll(n - 1), d = n >> s;
  for (ull a : A) { // ^ count trailing zeroes
    ull p = modpow(a % n, d, n), i = s;
    while (p != 1 && p != n - 1 && a % n && i--)
      p = modmul(p, p, n);
    if (p != n - 1 && i != s)
      return 0;
  }
  return 1;
}
ull pollard(ull n) {
  ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
  auto f = [&](ull x) { return modmul(x, x, n) + i; };
  while (t++ % 40 || __gcd(prd, n) == 1) {
    if (x == y)
      x = ++i, y = f(x);
    if ((q = modmul(prd, max(x, y) - min(x, y), n)))
      prd = q;
    x = f(x), y = f(f(y));
  }
  return __gcd(prd, n);
}
vector<ull> factor(ull n) {
  if (n == 1)
    return {};
  if (isPrime(n))
    return {n};
  ull x = pollard(n);
  auto l = factor(x), r = factor(n / x);
  l.insert(l.end(), all(r));
  return l;
}
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
  ull n;
  cin >> n;
  vector<ull> f = factor(n);
  map<ull, int> cnt;
  for (auto x : f)
    cnt[x]++;
  vector<ull> ps, cnts;
  for (auto [p, c] : cnt)
    ps.push_back(p), cnts.push_back(c);
  vector<ull> mask(ps.size());
  bool shesh = false;
  vector<int> dir(ps.size(), 1), cur(ps.size());
  cout << "1 ";
  while (!shesh) {
    for (int i = 0; i < ps.size(); i++) {
      if (dir[i] == 1) {
        cur[i]++;
        if (cur[i] > cnts[i]) {
          cur[i]--;
          dir[i] = -1;
          if (i == ps.size() - 1) {
            shesh = true;
          }
        } else {
          break;
        }
      } else if (dir[i] == -1) {
        cur[i]--;
        if (cur[i] < 0) {
          cur[i]++;
          dir[i] = 1;
          if (i == ps.size() - 1) {
            shesh = true;
          }
        } else {
          break;
        }
      }
    }
    if (shesh)
      break;
    ll ans = 1;
    for (int i = 0; i < ps.size(); i++) {
      ans *= binpow(ps[i], cur[i]);
    }
    cout << ans << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ":\n";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
