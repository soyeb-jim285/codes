#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, q;
  cin >> n >> q;
  set<ll> s;
  for (int i = 0; i < n; i++) {
    s.insert(i + 1);
  }
  for (ll i = 0; i < q; i++) {
    ll x;
    cin >> x;
    if (s.count(x))
      s.erase(x);
    else
      s.insert(x);
  }
  cout << s.size() << '\n';
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
