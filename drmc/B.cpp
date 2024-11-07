#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), pre(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + a[i];
  }
  ll ans = 0;
  // for (auto ic : pre)
  //   cout << ic << " ";
  for (int i = 0; i < n; i++) {
    ll boro = pre[n] - pre[i + 1];
    ll chuto = pre[i];
    ans += boro - (n - 1 - i) * a[i];
    ans += (i)*a[i] - chuto;
    // cout << boro << " " << chuto << " " << ans << '\n';
  }
  cout << ans / 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 1;
  // cin >> t;
  while (t--) {
    // cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
