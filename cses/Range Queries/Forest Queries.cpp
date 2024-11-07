#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, q;
  cin >> n >> q;
  vector<vector<char>> a(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<ll>> twod_prefix_sum(n + 1, vector<ll>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      twod_prefix_sum[i][j] =
          twod_prefix_sum[i - 1][j] + twod_prefix_sum[i][j - 1] -
          twod_prefix_sum[i - 1][j - 1] + (a[i - 1][j - 1] == '*');
    }
  }
  while (q--) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << twod_prefix_sum[x2][y2] - twod_prefix_sum[x1 - 1][y2] -
                twod_prefix_sum[x2][y1 - 1] + twod_prefix_sum[x1 - 1][y1 - 1]
         << '\n';
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
