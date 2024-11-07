#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; ++i)
    cin >> a[i];
  ll ans = 0, two = 0, one = 0;
  for (ll i = 0; i < n; ++i) {
    ans += a[i] / 3;
    a[i] %= 3;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1)
      one++;
    else if (a[i] == 2)
      two++;
  }
  for (auto ic : a)
    cout << ic << " ";
  ans += min(one, two);
  if (two > one) {
    two -= one;
    ll k = two / 3;
    two %= 3;
    ans += 2 * k;
    if (two == 2) {
      ans++;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
