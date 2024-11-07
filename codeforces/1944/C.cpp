#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, mx = -1;
  cin >> n;
  vector<ll> vc(n);
  map<ll, ll> mp;
  for (ll i = 0; i < n; i++) {
    cin >> vc[i];
    mx = max(mx, vc[i]);
    mp[vc[i]]++;
  }
  ll cnt = 0;
  for (int i = 0; i <= mx; i++) {
    if (mp[i] == 0) {
      cout << i << "\n";
      return;
    }
    if (mp[i] == 1) {
      if (cnt > 0) {
        cout << i << "\n";
        return;
      }
      cnt++;
    }
  }
  cout << mx + 1 << "\n";
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
