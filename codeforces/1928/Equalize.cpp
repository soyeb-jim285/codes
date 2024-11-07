#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  set<ll> st;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    st.insert(x);
  }
  vector<ll> vc(st.begin(), st.end());
  ll ans = 1;
  for (ll i = 0; i < vc.size(); i++) {
    auto ic = upper_bound(vc.begin(), vc.end(), vc[i] + n - 1) - vc.begin();
    ic -= i;
    ans = max(ans, (ll)ic);
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
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
