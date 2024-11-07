#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#include <map>
#include <vector>

std::map<int, std::vector<long long>> fact, invFact;
long long inv(long long a, long long mod) {
  long long b = mod, u = 0, v = 1;
  while (a != 0) {
    long long t = b / a;
    b -= t * a;
    std::swap(a, b);
    u -= t * v;
    std::swap(u, v);
  }
  u %= mod;
  if (u < 0)
    u += mod;
  return u;
}

void precalc(int n, const std::vector<int> &mods) {
  for (auto mod : mods) {
    fact[mod].resize(n + 1);
    invFact[mod].resize(n + 1);
    fact[mod][0] = invFact[mod][0] = 1;
    for (int i = 1; i <= n; ++i) {
      fact[mod][i] = (fact[mod][i - 1] * i) % mod;
      invFact[mod][i] = inv(fact[mod][i], mod);
    }
  }
}
std::vector<int> primeFactors(int n) {
  std::vector<int> factors;
  for (int i = 2; i * i <= n; i++) {
    if (n % i)
      continue;
    while (n % i == 0)
      n /= i;
    factors.push_back(i);
  }
  if (n > 1)
    factors.push_back(n);
  return factors;
}

long long chineseRemainderTheorem(const std::vector<long long> &residues,
                                  const std::vector<int> &mods) {
  long long prod = 1, sum = 0;
  for (auto mod : mods)
    prod *= mod;
  for (int i = 0; i < residues.size(); ++i) {
    long long p = prod / mods[i];
    sum += residues[i] * inv(p, mods[i]) * p;
    sum %= prod;
  }
  return sum;
}

long long nCr(int n, int r, int mod) {
  std::vector<int> mods = primeFactors(mod);
  std::vector<long long> residues;
  for (auto m : mods) {
    if (r > n)
      residues.push_back(0);
    else
      residues.push_back(fact[m][n] * invFact[m][r] % m * invFact[m][n - r] %
                         m);
  }
  return chineseRemainderTheorem(residues, mods);
}

void solve() {
  ll a = 1e7 + 2;
  ll b = 3;
  ll mod = 103 * 1000037;
  cout << nCr(a, b, 103 * 1000037) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll mod = 103 * 1000037;
  vector<int> mods = {103, 1000037};
  precalc(2e7, mods);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
