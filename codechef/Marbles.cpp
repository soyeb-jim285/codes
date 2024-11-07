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
  ll a, b;
  cin >> a >> b;
  ll aa = a, bb = b;
  ll mn = 1e18, ct = 0;
  while (aa >= bb) {
    if (aa % bb == 0) {
      mn = min(mn, ct);
      break;
    }
    aa--;
    bb++;
    ct++;
  }
  ct = 0;
  while (1) {
    if (a % b == 0) {
      mn = min(mn, ct);
      break;
    }
    a++;
    b--;
    ct++;
  }
  cout << mn << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
