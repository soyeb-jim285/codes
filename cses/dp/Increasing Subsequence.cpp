#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
  vector<ll> a(n), lis_indx, lis, pos(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (lis_indx.empty() || lis_indx.back() < a[i]) {
      lis_indx.push_back(a[i]);
      pos[i] = lis_indx.size();
    } else {
      auto ic = lower_bound(lis_indx.begin(), lis_indx.end(), a[i]);
      pos[i] = ic - lis_indx.begin() + 1;
      lis_indx[pos[i] - 1] = a[i];
    }
    // cout << i << " : ";
    // for (auto ic : lis_indx) {
    //   cout << ic << " ";
    // }
    // cout << "\n";
  }
  ll lst = lis_indx.size();
  for (int i = n - 1; i >= 0; i--) {
    if (pos[i] == lst) {
      lis.push_back(a[i]);
      lst--;
    }
  }
  reverse(lis.begin(), lis.end());
  // for (auto ic : lis)
  //   cout << ic << " ";
  // cout << "\n";
  cout << lis_indx.size() << endl;
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
