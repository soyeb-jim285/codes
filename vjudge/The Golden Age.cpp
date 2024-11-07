#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll mx_pw(ll x, ll n) {
  ll ans = 0;
  while (n > 0) {
    n /= x;
    ans++;
  }
  return ans;
}
vector<ll> pow_a(64), pow_b(64);
void fn(ll x, ll mx_pow, vector<ll> &pow_x) {
  pow_x[0] = 1;
  for (int i = 1; i < mx_pow; i++) {
    pow_x[i] = pow_x[i - 1] * x;
  }
}
void solve() {
  ll x, y, l, r;
  cin >> x >> y >> l >> r;
  ll mx_a = mx_pw(x, r), mx_b = mx_pw(y, r);
  vector<ll> a;
  fn(x, mx_a, pow_a);
  fn(y, mx_b, pow_b);
  for (ll i = 0; i < mx_a; i++) {
    ll fst = pow_a[i];
    for (ll j = 0; j < mx_b; j++) {
      ll lst = pow_b[j];
      if (fst + lst <= r && fst + lst >= l) {
        a.push_back(fst + lst);
      }
    }
  }
  ll mx = 0;
  sort(a.begin(), a.end());
  for (ll i = 0; i < (int)a.size() - 1; i++) {
    mx = max(mx, a[i + 1] - a[i] - 1);
  }
  if (a.size()) {
    mx = max(mx, a[0] - l);
    mx = max(mx, r - a.back());
  } else {
    mx = r - l + 1;
  }
  cout << mx << endl;
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
