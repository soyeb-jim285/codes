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
  set<pair<ll, ll>> s;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    s.insert({i + 1, x});
  }
  while (s.size()) {
    auto a = *s.begin();
    s.erase(s.begin());
    if (s.find({a.second, a.first}) != s.end()) {
      cout << "2\n";
      return;
    }
  }
  cout << "3\n";
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
