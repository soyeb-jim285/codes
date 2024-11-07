#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), ind(n);
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
    ind[a[i] - 1] = i;
  }
  ll ln = 1, mx = 1;
  for (ll i = 1; i < n; ++i) {
    if (ind[i] > ind[i - 1]) {
      ln++;
    } else {
      mx = max(mx, ln);
      ln = 1;
    }
  }
  mx = max(mx, ln);
  cout << n - mx << "\n";
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
