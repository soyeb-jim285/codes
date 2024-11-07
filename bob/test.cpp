#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll cross_product(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
  return (b.first - a.first) * (c.second - a.second) -
         (b.second - a.second) * (c.first - a.first);
}
typedef complex<ld> point;
void solve() {
  ll t = 1;
  cout << t << '\n';
  while (t--) {
    ll r = rnd() % (ll)1e3 + 1;
    ll low = -1e4, high = 1e4;
    pair<ll, ll> a, b, c;
    a = {rnd() % (high - low + 1) + low, rnd() % (high - low + 1) + low};
    b = {rnd() % (high - low + 1) + low, rnd() % (high - low + 1) + low};
    c = {rnd() % (high - low + 1) + low, rnd() % (high - low + 1) + low};
    if (cross_product(a, b, c) < 0)
      swap(b, c);
    cout << r << '\n';
    cout << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second
         << ' ' << c.first << ' ' << c.second << '\n';
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
