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
  ll n;
  cin >> n;
  vector<pair<ll, ll>> vc;
  for (int i = 0; i < n; i++) {
    ll x, y, a;
    cin >> x >> y >> a;
    vc.push_back({x, a});
    vc.push_back({y + 1, -a});
  }
  sort(vc.begin(), vc.end());
  ll mx = 0, sum = 0;
  for (int i = 0; i < vc.size(); i++) {
    sum += vc[i].second;
    mx = max(mx, sum);
  }
  cout << mx << "\n";
}
int main() {
  freopen64("blist.in", "r", stdin);
  freopen64("blist.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
