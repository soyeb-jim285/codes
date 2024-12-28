#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  ll n;
  cin >> n;
  vector<pii> ranges(n);
  vector<bool> fixed(2 * n);
  map<pii, int> cnt;
  for (auto &[l, r] : ranges) {
    cin >> l >> r;
    l--, r--;
    cnt[{l, r}]++;
    if (l == r) {
      fixed[l] = 1;
    }
  }
  vector<ll> pref(2 * n + 1);
  for (int i = 0; i < 2 * n; i++) {
    pref[i + 1] = pref[i] + (fixed[i] == 1);
  }
  // for (auto ic : pref)
  //   cout << ic << " ";
  // cout << "\n";
  for (int i = 0; i < n; i++) {
    auto [l, r] = ranges[i];
    ll d = r - l + 1;
    ll ase = pref[r + 1] - pref[l];
    if (d == 1) {
      if (cnt[{l, r}] == 1) {
        cout << "1";
      } else {
        cout << "0";
      }
    } else {
      if (d == ase) {
        cout << "0";
      } else {
        cout << "1";
      }
    }
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
