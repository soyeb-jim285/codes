#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<vector<bool>> dp(14, vector<bool>(1 << 15, false));
ll tulefel(ll val, ll indx, ll n) {
  ll ret = 0, lst = 0;
  for (int i = 0; i < n; i++) {
    lst <<= 1;
    lst += (val >> i) & 1;
  }
}
ll bitmask(ll gap, ll mask, ll b, ll n) {
  if (dp[gap][mask]) {
    return 1e18;
  }
  dp[gap][mask] = true;
  if (mask == b) {
    return 0;
  }
  for (int i = 0; i < n; i++) {
  }
}
void solve() {
  ll n;
  cin >> n;
  ll a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    a <<= 1;
    if (x == 'B') {
      a |= 1;
    }
  }
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    b <<= 1;
    if (x == 'B') {
      b |= 1;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
