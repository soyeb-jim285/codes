#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, p = 1;
  cin >> n;
  vector<ll> ans;
  for (ll i = 1; i < n; i++) {
    if (__gcd(i, n) == 1) {
      p = (p * i) % n;
      ans.push_back(i);
    }
  }
  if (p != 1) {
    ans.pop_back();
  }
  cout << ans.size() << '\n';
  for (ll x : ans) {
    cout << x << ' ';
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
