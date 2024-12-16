#include <bits/stdc++.h>
#include <cassert>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const mod = 1e7 + 7;
const int LIM = 1e6 + 1;
bitset<LIM> isPrime;
vector<int> eratosthenes() {
  const int S = 1e3, R = LIM / 2;
  vi pr = {2}, sieve(S + 1);
  pr.reserve(int(LIM / log(LIM) * 1.1));
  vector<pii> cp;
  for (int i = 3; i <= S; i += 2)
    if (!sieve[i]) {
      cp.push_back({i, i * i / 2});
      for (int j = i * i; j <= S; j += 2 * i)
        sieve[j] = 1;
    }
  for (int L = 1; L <= R; L += S) {
    array<bool, S> block{};
    for (auto &[p, idx] : cp)
      for (int i = idx; i < S + L; idx = (i += p))
        block[i - L] = 1;
    rep(i, 0, min(S, R - L)) if (!block[i]) pr.push_back((L + i) * 2 + 1);
  }
  for (int i : pr)
    isPrime[i] = 1;
  return pr;
}
void solve() {
  ll n;
  vector<int> primes = eratosthenes();
  cin >> n;
  while (n) {
    ll ans = 1;
    for (int i = 0; i < primes.size() && primes[i] <= n; i++) {
      ll cnt = 0;
      ll p = primes[i];
      while (n / p) {
        cnt = (cnt + n / p) % mod;
        p = p * primes[i];
      }
      ll k = (cnt + 1) * (cnt + 2) / 2LL;
      k = k % mod;
      ans = (ans * k) % mod;
    }
    cout << ans << '\n';
    cin >> n;
    if (n == 0)
      break;
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
