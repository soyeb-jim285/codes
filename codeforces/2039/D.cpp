#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(m);
  for (ll &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end(), greater<ll>());
  vector<ll> ans(n + 1);
  ll mx = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 2 * i; j <= n; j += i) {
      if (ans[i] == ans[j]) {
        ans[j]++;
        mx = max(mx, ans[j] + 1);
      }
    }
  }
  if (mx > m) {
    cout << "-1\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    cout << a[ans[i]] << ' ';
  }
  cout << "\n";
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
