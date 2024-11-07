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
  for (ll &x : a)
    cin >> x;
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + a[i];
  }
  vector<ll> ans(n + 1);
  for (ll i = 1; i * (i + 1LL) <= 2LL * n; i++) {
    for (ll j = i; j <= n; j++) {
      ll val = pre[j] - pre[j - i];
      /* cout << pre[j] << " " << pre[j - i] << " " << val << "\n"; */
      if (val <= n)
        ans[val]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
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
