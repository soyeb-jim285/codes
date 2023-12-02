/*
    score = 30pt
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set                                                            \
  tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_pair_set                                                       \
  tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,               \
       tree_order_statistics_node_update>
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  if (n == 1) {
    vector<vector<ll>> mxvc(log2(m) + 1, vector<ll>(m)),
        mnvc(log2(m) + 1, vector<ll>(m));
    for (int i = 0; i < m; i++) {
      cin >> mxvc[0][i];
      mnvc[0][i] = mxvc[0][i];
    }
    for (int i = 1; i < log2(m) + 1; i++) {
      for (int j = 0; j + (1 << i) < m; j++) {
        mxvc[i][j] = max(mxvc[i - 1][j], mxvc[i - 1][j + (1 << (i - 1))]);
        mnvc[i][j] = min(mnvc[i - 1][j], mnvc[i - 1][j + (1 << (i - 1))]);
      }
    }
    ll ans = 1;
    for (int i = 1; i < m; i++) {
      ll l = i - ans;
      ll r = i;
      ll ii = log2(r - l + 1);
      ll mx = max(mxvc[ii][l], mxvc[ii][r + 1 - (1 << ii)]);
      ll mn = min(mnvc[ii][l], mnvc[ii][r + 1 - (1 << ii)]);
      if (mx - mn <= k) {
        ans++;
      }
    }
    cout << ans << "\n";
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ll x;
        cin >> x;
      }
    }
    cout << "NO idea\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
