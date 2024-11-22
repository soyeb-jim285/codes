#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool fn(ll mid, ll b, ll c, ll n) { return b * (mid - 1LL) + c < n; }
void solve() {
  ll n, b, c;
  cin >> n >> b >> c;
  if (b == 0) {
    if (c < n) {
      if (c < n - 2) {
        cout << "-1" << "\n";
      } else {
        cout << n - 1 << "\n";
      }
    } else {
      cout << n << "\n";
    }
    return;
  }
  ll num = c < n ? (n - c - 1) / b + 1 : 0;
  cout << n - num << "\n";
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
