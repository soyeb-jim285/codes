#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> dp(1e6 + 1, -1);
ll fn(ll n) {
  if (dp[n] != -1)
    return dp[n];
  if (n == 0)
    return 0;
  ll ans = 1e9;
  for (ll i = n; i; i /= 10) {
    ll x = i % 10;
    if (x > 0)
      ans = min(ans, 1 + fn(n - i % 10));
  }
  return dp[n] = ans;
}
void solve() {
  ll n;
  cin >> n;
  cout << fn(n) << endl;
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
