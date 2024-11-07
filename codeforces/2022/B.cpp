#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, x;
  cin >> n >> x;
  if (x > n)
    x = n;
  ll mx = -1, sum = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    sum += a;
    mx = max(mx, a);
  }
  if (sum % x) {
    cout << max(mx, sum / x + 1) << '\n';
  } else {
    cout << max(mx, sum / x) << '\n';
  }
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
