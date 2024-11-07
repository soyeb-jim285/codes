#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const mod = 1e9 + 7;
ll const N = 1e3 + 1;
vector<vector<ll>> dp(N, vector<ll>(N, -1));
ll fn(ll i, ll j, vector<vector<char>> &grid) {
  if (dp[i][j] != -1)
    return dp[i][j];
  ll n = grid.size();
  if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == '*')
    return 0;
  if (i == n - 1 && i == j)
    return 1;
  ll ans = 0;
  ans = (ans + fn(i + 1, j, grid)) % mod;
  ans = (ans + fn(i, j + 1, grid)) % mod;
  return dp[i][j] = ans;
}
void solve() {
  ll n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];
  cout << fn(0, 0, grid) % mod << endl;
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
