#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int n;
  cin >> n;
  vector<ll> vc(n);
  multiset<ll> odd, even;
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
    if (vc[i] % 2 == 0)
      even.insert(vc[i]);
    else
      odd.insert(vc[i]);
  }
  ll ans = 0;
  while (sz(even) && sz(odd)) {
    ll big_odd = *odd.rbegin();
    ll small_even = *even.begin();
    if (big_odd > small_even) {
      even.erase(even.begin());
    } else {
      odd.erase(odd.find(big_odd));
    }
    odd.insert(small_even + big_odd);
    ans++;
  }
  cout << ans << '\n';
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
