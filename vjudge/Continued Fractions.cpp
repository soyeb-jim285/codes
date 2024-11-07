#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool is_sqre(ll x) {
  ll y = sqrt(x);
  if (y * y == x)
    return 1;
  return 0;
}
void solve() {
  ll n;
  cin >> n;
  if (n == 1) {
    cout << 1 << "\n";
    cout << "1\n";
    return;
  }
  ll p = 2 * (n - 1LL);
  set<ll> s;
  for (ll i = 1; i * i * i <= p; i++) {
    if (p % i == 0) {
      ll j = p / i;
      ll k1 = 9 + 4 * (j - 2);
      if (is_sqre(k1)) {
        ll x = sqrt(k1);
        if (x % 2) {
          ll b = (x - 3LL) / 2LL;
          if (b > 0 && b % 2 == 0) {
            s.insert(b);
          }
        }
      }
      if (p % (i + 1) == 0 && (i - 1) >= 1) {
        s.insert(i - 1);
      }
      if (i - 2 >= 1)
        if (p % (i - 1) == 0) {
          s.insert(i - 2);
        }
    }
  }
  cout << sz(s) << endl;
  for (auto x : s)
    cout << x << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
