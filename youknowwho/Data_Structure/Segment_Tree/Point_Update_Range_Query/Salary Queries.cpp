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
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  ordered_pair_set st;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    st.insert({a[i], i});
  }
  while (q--) {
    char ch;
    cin >> ch;
    if (ch == '!') {
      ll k, x;
      cin >> k >> x;
      k--;
      st.erase({a[k], k});
      a[k] = x;
      st.insert({a[k], k});
    } else {
      ll l, r;
      cin >> l >> r;
      // cout << st.size() << " " << st.order_of_key({r + 1, -1}) << '\n';
      cout << st.order_of_key({r + 1, -1}) - st.order_of_key({l, -1}) << '\n';
    }
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
