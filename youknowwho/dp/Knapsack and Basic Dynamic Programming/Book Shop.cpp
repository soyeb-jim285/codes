#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> price(n), pages(n);
  for (int i = 0; i < n; i++) {
    cin >> price[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> pages[i];
  }
  vector<ll> dp(x + 1);
  for (int i = 0; i < n; i++) {
    for (int j = x; j >= price[i]; j--) {
      dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
    }
  }
  cout << dp[x] << endl;
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
