#include <bits/stdc++.h>
#include <set>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int n;
  cin >> n;
  ll g = 0, mn = 1e6;
  multiset<ll> s;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    s.insert(x);
    mn = min(mn, x);
    g = __gcd(g, x);
  }
  vector<ll> v;
  v.push_back(mn);
  s.erase(s.find(mn));
  ll lt = mn;
  while (lt != g && !s.empty()) {
    mn = 1e6;
    ll num = -1;
    for (auto x : s) {
      int gg = __gcd(lt, x);
      if (gg < mn) {
        mn = gg;
        num = x;
      }
    }
    lt = __gcd(lt, num);
    v.push_back(num);
    s.erase(s.find(num));
  }
  while (!s.empty()) {
    v.push_back(*s.begin());
    s.erase(s.begin());
  }
  g = 0;
  ll ans = 0;
  for (int i = 0; i < v.size(); i++) {
    g = __gcd(g, v[i]);
    ans += g;
  }
  cout << ans << "\n";
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
