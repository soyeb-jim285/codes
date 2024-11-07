#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll fn(ll k, vector<ll> &a, ll x, ll b) {
  ll ans = -(k - 1) * x;
  ll n = a.size();
  /* cout << k << "--k\n"; */
  for (ll i = 0; i < n; i++) {
    /* cout << a[i] << "--a[i]\n"; */
    if (a[i] <= k) {
      ans += (a[i] * (a[i] - 1) / 2) * b;
      /* cout << ans << "--\n"; */
    } else {
      ll rem = a[i] % k;
      ll num = a[i] / k;
      ans += rem * (k - rem) * num * (num + 1) * b;
      /* cout << ans << "++1\n"; */
      ans += b * (rem * (rem - 1) / 2) * (num + 1) * (num + 1);
      /* cout << ans << "++2\n"; */
      ans += (k - rem) * ((k - rem) - 1) / 2 * num * num * b;

      /* cout << ans << "++3\n"; */
    }
  }
  return ans;
}
void solve() {
  ll n, b, x, mn = 1e18, mx = 0;
  cin >> n >> b >> x;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
  ll l = 1, r = mx;
  while (r - l > 2) {
    /* cout << l << " " << r << "--\n"; */
    ll m1 = l + (r - l) / 3;
    ll m2 = r - (r - l) / 3;
    /* cout << m1 << " " << m2 << "\n"; */
    /* cout << fn(m1, a, x, b) << " " << fn(m2, a, x, b) << "\n"; */
    if (fn(m1, a, x, b) > fn(m2, a, x, b)) {
      r = m2;
    } else {
      l = m1;
    }
  }
  ll ans = max({0LL, fn(l, a, x, b), fn(mx, a, x, b), fn(1, a, x, b)});
  for (ll i = l + 1; i <= r; i++) {
    /* cout << i << " " << fn(i, a, x, b) << "-\n"; */
    ans = max(ans, fn(i, a, x, b));
  }
  cout << ans << "\n";
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

