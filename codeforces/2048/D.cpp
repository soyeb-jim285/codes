#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  for (auto &x : a)
    cin >> x;
  ll me = a[0];
  for (auto &x : b)
    cin >> x;
  vector<ll> ans(m, 0);
  sort(all(a));
  for (int i = 0; i < m; i++) {
    if (b[i] <= me) {
      continue;
    }
    auto it = upper_bound(all(a), b[i] - 1) - a.begin();
    ans[i] = n - it;
  }
  sort(all(ans));
  // for (auto x : ans)
  //   cout << x << " ";
  // cout << "\n";
  for (int i = 0; i < m; i++) {
    ll res = m / (i + 1);
    // cout << res << "----*\n";
    for (int j = i; j < m; j += (i + 1)) {
      // cout << ans[j] << " " << j << " --*\n";
      res += ans[j];
    }
    cout << res << " ";
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

