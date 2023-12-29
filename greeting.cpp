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
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_pair_set tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
void solve()
{
  ll n;
  cin >> n;
  vector<pair<ll,ll>> a(n);
  for (int  i = 0; i < n ; i++) {
    cin >> a[i].first >> a[i].second; 
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  ordered_set s;
  for (int  i = 0; i < n ; i++) {
    s.insert(-a[i].second);
    ans += s.order_of_key(-a[i].second);
  }
  cout << ans << "\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
#ifdef ONPC
  cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
