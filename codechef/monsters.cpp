#include <bits/stdc++.h>
#include <vector>
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

ll const N = 1e6 + 10;
vector<bool> is_prime(N + 1, 1);
void shieve() {
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= N; i++) {
    if (is_prime[i] && i * i <= N)
      for (ll j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
  }
}
void solve() {
  ll n;
  cin >> n;
  ll ans = 0;
  while (n >= 0) {
    if (n == 0) {
      cout << ans << "\n";
      return;
    } else if (is_prime[n]) {
      ans++;
      cout << ans << "\n";
      return;
    }
    n -= (1 << ans);
    ans++;
  }
  cout << "-1\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  shieve();
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
