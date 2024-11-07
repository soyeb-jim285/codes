#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool fn(int ind, ll x, vector<ll> &a, vector<vector<ll>> &dp) {
  if (ind == sz(a)) {
    return x == 0;
  }
  if (x == 1)
    return true;
  if (dp[ind][x] != -1)
    return dp[ind][x];
  bool ans = fn(ind + 1, x, a, dp);
  if (x % a[ind] == 0)
    ans |= fn(ind + 1, x / a[ind], a, dp);
  return dp[ind][x] = ans;
}
void solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> dp1(n + 1, -1);
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
