#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, mn = 1e9;
  cin >> n;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
    mn = min(mn, vc[i]);
  }
  if (vc.front() == mn && vc.back() == mn) {
    cout << "YES\n";
  } else
    cout << "NO\n";
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
