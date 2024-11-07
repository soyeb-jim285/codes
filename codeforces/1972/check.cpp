#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, m;
  cin >> n >> m;
  if (n < m)
    swap(n, m);
  set<pair<ll, ll>> s;
  for (ll i = 1; i <= n; i++) {
    cerr << i << "\n";
    vector<ll> primes;
    ll x = i;
    for (ll j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        primes.push_back(j);
        while (x % j == 0) {
          x /= j;
        }
      }
    }
    if (x > 1) {
      primes.push_back(x);
    }
    for (int j = 0; j < primes.size(); j++) {
      for (ll k = primes[j]; k <= i; k += primes[j]) {
        // cout << "HERE\n";
        ll g = __gcd(i, k);
        if (k * g % (i + k) == 0) {
          s.insert({i, k});
        }
      }
    }
  }
  cerr << s.size() << "\n";
  // cout << a.size() << "\n";
  cout << "{";
  for (auto [x, y] : s) {
    cout << "{" << x << "," << y << "}," << "\n";
  }
  cout << "}";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("check.txt", "w", stdout);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
