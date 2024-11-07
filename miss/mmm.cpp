#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int powmod(int a, int b, int p) {
  int res = 1;
  while (b)
    if (b & 1)
      res = int(res * 1ll * a % p), --b;
    else
      a = int(a * 1ll * a % p), b >>= 1;
  return res;
}

int generator(int p) {
  vector<int> fact;
  int phi = p - 1, n = phi;
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      fact.push_back(i);
      while (n % i == 0)
        n /= i;
    }
  if (n > 1)
    fact.push_back(n);

  for (int res = 2; res <= p; ++res) {
    bool ok = true;
    for (size_t i = 0; i < fact.size() && ok; ++i)
      ok &= powmod(res, phi / fact[i], p) != 1;
    if (ok)
      return res;
  }
  return -1;
}
void solve() {
  ll p = 761, q = 7;
  cout << generator(p) << endl;
  cout << generator(q) << endl;
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
