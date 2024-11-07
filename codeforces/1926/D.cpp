#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll invert_bits(ll x) {
  ll intmax = 2147483647;
  return x ^ intmax;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  multiset<ll> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  ll ans = 0;
  while (s.size()) {
    ll bg = *s.begin();
    s.erase(s.begin());
    ll x = invert_bits(bg);
    if (s.count(x))
      s.erase(s.find(x));
    ans++;
  }
  cout << ans << endl;
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
