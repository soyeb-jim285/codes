#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll const MOD = 998244353;
ll binpowmod(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res *= a;
      res = res % MOD;
    }
    a *= a;
    a = a % MOD;
    b >>= 1;
  }
  return res;
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(n);
  map<int, ll> mpa, mpb;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mpa[i] = a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    mpb[i] = b[i];
  }
  sort(all(a));
  sort(all(b));
  ll ans = 1;
  for (int i = 0; i < n; i++) {
    ll mn = min(a[i], b[i]);
    ans = (ans * mn) % MOD;
  }
  cout << ans << " ";
  for (int i = 0; i < m; i++) {
    ll x, ind;
    cin >> x >> ind;
    ind--;
    ll val;
    if (x == 1) {
      val = mpa[ind];
      auto ic = upper_bound(all(a), val) - a.begin();
      ic--;
      ll mn = min(a[ic], b[ic]);
      ans = (ans * binpowmod(mn, MOD - 2)) % MOD;
      a[ic] = val + 1;
      mpa[ind] = val + 1;
      mn = min(a[ic], b[ic]);
      ans = (ans * mn) % MOD;
    } else {
      val = mpb[ind];
      auto ic = upper_bound(all(b), val) - b.begin();
      ic--;
      ll mn = min(a[ic], b[ic]);
      ans = (ans * binpowmod(mn, MOD - 2)) % MOD;
      b[ic] = val + 1;
      mpb[ind] = val + 1;
      mn = min(a[ic], b[ic]);
      ans = (ans * mn) % MOD;
    }
    // for (auto x : a)
    //   cout << x << " ";
    // cout << "\n";
    // for (auto x : b)
    //   cout << x << " ";
    // cout << "\n";
    cout << ans << " ";
  }
  cout << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
