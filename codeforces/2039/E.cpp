#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

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
ll inversions(vector<ll> &a) {
  ll n = a.size();
  ll ans = 0;
  ordered_set s;
  for (int i = 0; i < n; i++) {
    ans += s.order_of_key(a[i]);
    s.insert(a[i]);
  }
  return ans;
}
void solve() {
  vector<ll> a = {0, 1};
  vector<vector<ll>> vc;
  set<vector<ll>> st;
  st.insert(a);
  vector<ll> ans(10);
  ans[2] = 1;
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
