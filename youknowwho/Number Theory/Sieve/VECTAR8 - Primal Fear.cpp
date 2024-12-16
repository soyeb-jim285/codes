#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int LIM = 1e6;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
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
bool haveZero(int n) {
  while (n > 0) {
    if (n % 10 == 0)
      return true;
    n /= 10;
  }
  return false;
}
int removedFirst(int n) {
  int digits = 0, nn = n;
  while (n) {
    n /= 10;
    digits++;
  }
  ll ans = nn % binpow(10, digits - 1);
  return ans;
}
bool isValid(int n) {
  if (haveZero(n))
    return false;
  while (n > 0) {
    if (!isPrime[n])
      return false;
    n = removedFirst(n);
  }
  return true;
}
vector<ll> ans(LIM);
void init() {
  vector<int> pr = eratosthenes();
  ans[0] = 0;
  for (int i = 1; i < LIM; i++) {
    ans[i] = ans[i - 1];
    if (isValid(i)) {
      ans[i]++;
    }
    // if (i % 100 == 1) {
    //   cout << i << " " << ans[i] << '\n';
    // }
  }
}
void solve() {
  int n;
  cin >> n;
  cout << ans[n] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
