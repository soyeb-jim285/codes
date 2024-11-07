#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  multiset<ll> s;
  for (ll &x : a)
    cin >> x;
  for (int i = 0; i < n; i++) {
    s.insert(a[i]);
  }
  while (k-- && !s.empty()) {
    ll a = *s.begin();
    ll b = *s.rbegin();
    s.erase(s.begin());
    s.erase(--s.end());
    if (s.size()) {
      if (b - *s.begin() > *--s.end() - a) {
        s.insert(a);
      } else {
        s.insert(b);
      }
    } else {
      cout << 0 << endl;
      return;
    }
  }
  // cout << s.size() << endl;
  cout << *s.rbegin() - *s.begin() << endl;
  // ll ans = *s.rbegin();
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
