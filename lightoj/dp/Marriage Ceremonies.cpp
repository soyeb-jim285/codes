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
  vector<vector<ll>> a(n, vector<ll>(n));
  vector<ll> val(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i < n; i++) {
    val[i] = i;
    ll sp = i, mx = 0;
    for (int j = 0; j < i; j++) {
      if ((a[i][val[j]] + a[val[j]][i]) - (a[j][val[j]] + a[i][i]) > mx) {
        sp = j;
        mx = (a[i][val[j]] + a[val[j]][i]) - (a[j][val[j]] + a[i][i]);
      }
    }
    cout << sp << " *\n";
    swap(val[i], val[sp]);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i][val[i]];
  }
  cout << ans << "\n";
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
