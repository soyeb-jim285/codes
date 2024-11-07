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
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  if (n > 3) {
    cout << "YES\n";
    return;
  }
  if (is_sorted(a.begin(), a.end())) {
    cout << "YES\n";
    return;
  }
  if (n == 3) {
    if (a[1] <= max(a[0], a[2]) && a[1] >= min(a[0], a[2])) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    return;
  }
  cout << "NO\n";
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
