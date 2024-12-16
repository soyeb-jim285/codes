#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, od = 0, ev = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if (i & 1)
      od += x;
    else
      ev += x;
  }
  ll sum = od + ev;
  ll k = sum / n;
  if (sum % n == 0 && od == k * (n / 2) && ev == k * ((n + 1) / 2)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
