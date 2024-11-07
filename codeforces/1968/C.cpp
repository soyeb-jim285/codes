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
  vector<ll> a(n), ans(n);
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }
  ans[0] = 1e6;
  for (int i = 1; i < n; i++) {
    ans[i] = ans[i - 1] + a[i];
  }
  for (auto ic : ans)
    cout << ic << " ";
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
