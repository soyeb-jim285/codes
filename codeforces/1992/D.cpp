#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll n, m, k;
ll fn(int ind, bool &bl, string &s, vector<ll> &dp) {
  // cout << ind << "***\n";
  if (ind >= sz(s)) {
    bl = true;
    // cout << "ind: " << ind << " " << sz(s) << "\n";
    return 0;
  }
  // cout << "ind: " << ind << " " << s[ind] << " " << dp[ind] << "*-*\n";
  if (dp[ind] != 1e14)
    return dp[ind];
  // cout << "ind: " << ind << " " << s[ind] << "*-*-*\n";
  ll ans = 0;
  if (s[ind] == 'W') {
    // cout << "W " << ans << " " << ind << "\n";
    ans = ans + 1 + fn(ind + 1, bl, s, dp);
  } else if (s[ind] == 'L') {
    // cout << "L " << ans << " " << ind << "\n";
    ll mn = 1e12;
    for (int i = 0; i < m; i++) {
      // cout << "m ** " << i << " " << ind + i + 1 << "\n";
      mn = min(mn, fn(ind + i + 1, bl, s, dp));
    }
    // cout << "mn: " << mn << " " << ind << "\n";
    ans = ans + mn;
  } else {
    ans = 1e12;
    return dp[ind] = ans;
    // cout << "C " << ans << " " << ind << "\n";
  }
  // cout << "ind: " << ind << " " << ans << "\n";
  return dp[ind] = ans;
}
void solve() {
  cin >> n >> m >> k;
  string s;
  cin >> s;
  string s1 = "L";
  s = s1 + s;
  // cout << s << "\n";
  vector<ll> dp(n + 10, 1e14);
  bool bl = false;
  ll ans = fn(0, bl, s, dp);
  // cout << ans << " " << bl << "\n";
  if (ans <= k && bl)
    cout << "YES\n";
  else
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
