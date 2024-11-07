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
  multiset<ll> a;
  vector<ll> vc(n);
  for (ll &x : vc) {
    cin >> x;
    a.insert(x);
  }
  sort(vc.begin(), vc.end());
  ll g = vc[0];
  multiset<ll> b;
  ll bg = *a.begin();
  while (!a.empty()) {
    ll k = *a.begin();
    if (k % bg) {
      b.insert(k);
    }
    a.erase(a.begin());
  }
  bg = *b.begin();
  while (!b.empty()) {
    ll k = *b.begin();
    if (k % bg) {
      cout << "NO\n";
      return;
    }
    b.erase(b.begin());
  }
  cout << "YES\n";
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
