#include <bits/stdc++.h>
#include <cmath>
#include <unordered_map>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
unordered_map<ll, ll> memory;
ll phii(ll n) {
  ll result = n;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0)
        n /= i;
      result -= result / i;
    }
  }
  if (n > 1)
    result -= result / n;
  return result;
}
void solve() {
  ll n, q;
  cin >> n >> q;
  while (q--) {
    ll x;
    cin >> x;
    if (n % x) {
      cout << "0 ";
      continue;
    }
    ll num = n / x;
    if (memory[num]) {
      cout << memory[num] << " ";
    } else {
      ll ans = phii(num);
      memory[num] = ans;
      cout << ans << " ";
    }
  }
  memory.clear();
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
