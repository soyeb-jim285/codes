#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool fn(ll num, ll k, vector<ll> &a) {
  priority_queue<ll> div, ndiv;
  for (auto ic : a) {
    if (ic % k) {
      ndiv.push(ic);
    } else {
      div.push(ic);
    }
  }
  ll cnt = 0;
  ll ok = 0;
  // cout << "pass0\n";
  // cout << num << " " << k << " " << endl;
  while (sz(div)) {
    ll x = div.top();
    if (x < num)
      break;
    div.pop();
    ok++;
    while (x / k >= num) {
      cnt++;
      x /= k;
    }
  }
  // cout << "pass1\n";
  while (sz(ndiv)) {
    ll x = ndiv.top();
    ndiv.pop();
    if (x < num && cnt > 0) {
      cnt--;
      x *= k;
    }
    if (x >= num) {
      ok++;
    }
  }
  // cout << "pass2\n";
  return ok >= num;
}
void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), aa(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll l = 1, r = 1e6;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (fn(mid, k, a)) {
      l = mid + 1;
    } else {
      r = mid;
    }
    // cout << l << ' ' << r << '\n';
  }
  cout << l - 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
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
