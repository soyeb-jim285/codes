/*
    score = 100pt
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set                                                            \
  tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
void solve() {
  ll n;
  cin >> n;
  if (n == 0) {
    cout << "1\n";
    return;
  }
  set<ll> s;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    x = x % 180;
    if (x < 0)
      x += 180;
    s.insert(x);
  }
  cout << s.size() * 2 << "\n";
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
