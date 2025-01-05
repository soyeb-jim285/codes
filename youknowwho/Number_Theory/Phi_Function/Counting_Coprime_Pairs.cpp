#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll const N = 1e7 + 5;
vector<ll> spf(N), mobius(N);
void init() {
  for (ll i = 2; i < N; i++) {
    if (spf[i] == 0) {
      for (ll j = i; j < N; j += i) {
        if (spf[j] == 0) {
          spf[j] = i;
        }
      }
    }
  }
  for (ll i = 1; i < N; i++) {
    if (i == 1)
      mobius[i] = 1;
    else {
      if (spf[i / spf[i]] == spf[i])
        mobius[i] = 0;
      else
        mobius[i] = -1 * mobius[i / spf[i]];
    }
  }
}
void solve() {
  init();
  ll n, mx = -1;
  cin >> n;
  vector<ll> cnt(N);
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    cnt[x]++;
    mx = max(mx, x);
  }
  ll ans = 0;
  for (ll i = 1; i <= mx; i++) {
    ll cur = 0;
    for (ll j = i; j <= mx; j += i) {
      cur += cnt[j];
    }
    cout << i << " " << mobius[i] << " " << cur << "\n";
    ans += cur * (cur - 1) / 2 * mobius[i];
    // cout << i << " " << cur * (cur - 1) / 2 * mobius[i] << "\n";
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
