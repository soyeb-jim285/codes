#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
typedef __uint128_t ull;
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
ull brent(ull n) {
  if (n % 2 == 0)
    return 2;
  ull y = rnd() % (n - 1) + 1;
  ull c = rnd() % (n - 1) + 1;
  ull m = rnd() % (n - 1) + 1;
  ull g = 1, r = 1, q = 1, x, ys;

  while (g == 1) {
    x = y;
    for (ull i = 0; i < r; i++)
      y = (modmul(y, y, n) + c) % n;
    ull k = 0;
    while (k < r && g == 1) {
      ys = y;
      for (ull i = 0; i < min(m, r - k); i++) {
        y = (modmul(y, y, n) + c) % n;
        q = modmul(q, max(x, y) - min(x, y), n);
      }
      g = __gcd(q, n);
      k += m;
    }
    r *= 2;
  }

  if (g == n) {
    do {
      ys = (modmul(ys, ys, n) + c) % n;
      g = __gcd(max(x, ys) - min(x, ys), n);
    } while (g == 1);
  }
  return g;
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
ull stringToUll(string s) {
  ull num = 0;
  for (char c : s)
    num = num * 10 + c - '0';
  return num;
}
string numToString(ull num) {
  string s;
  while (num) {
    s += num % 10 + '0';
    num /= 10;
  }
  reverse(all(s));
  return s;
}
void solve() {
  string n;
  cin >> n;
  ull nn = stringToUll(n);
  while (nn) {
    vector<ull> ans = factor(nn);
    map<ull, int> mp;
    for (auto x : ans)
      mp[x]++;
    for (auto x : mp)
      cout << numToString(x.first) << "^" << x.second << " ";
    cout << "\n";
    cin >> n;
    nn = stringToUll(n);
  }
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
