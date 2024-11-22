#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll fn(ll val, vector<ll> &vc, vector<ll> &dp) {
  if (dp[val] != -1)
    return dp[val];
  if (val == 0)
    return dp[val] = 1;
  for (int i = 0; i < vc.size(); i++) {
    if (val - vc[i] >= 0)
      dp[val] = (dp[val] + fn(val - vc[i], vc, dp));
  }
  return dp[val] = ans;
}
void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  vector<int> dp(k + 1, -1);
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
