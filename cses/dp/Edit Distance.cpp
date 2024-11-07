#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define sz(a) ((int)((a).size()))

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
string s1, s2;
ll const N = 5000 + 1;
vector<vector<int>> dp(N, vector<int>(N, -1));
ll fn(ll i, ll j) {
  if (dp[i][j] != -1)
    return dp[i][j];
  if (i == sz(s1) && j == sz(s2))
    return dp[i][j] = 0;
  else if (i == sz(s1)) {
    return dp[i][j] = sz(s2) - j;
  } else if (j == sz(s2)) {
    return dp[i][j] = sz(s1) - i;
  }
  ll ans = 1e18;
  ans = min(ans, fn(i + 1, j + 1) + (s1[i] != s2[j]));
  if (s1[i] != s2[j]) {
    ans = min(ans, fn(i + 1, j) + 1);
    ans = min(ans, fn(i, j + 1) + 1);
  }
  return dp[i][j] = ans;
}
void solve() {
  cin >> s1 >> s2;
  cout << fn(0, 0) << '\n';
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
