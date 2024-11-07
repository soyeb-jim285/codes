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
  set<ll> s;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  ll mex = 0;
  while (sz(s)) {
    ll x = *s.begin();
    s.erase(x);
    if (x == mex) {
      mex++;
    } else {
      break;
    }
  }
  s.clear();
  ll cnt = 0, l = 1, r = n;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    s.insert(a[i]);
    if (a[i] == cnt) {
      while (s.count(cnt)) {
        cnt++;
      }
    }
    if (cnt == mex && i != n - 1) {
      l = i + 1;
      ok = true;
      break;
    }
  }
  if (ok) {
    s.clear();
    cnt = 0;
    for (int i = n - 1; i >= l; i--) {
      s.insert(a[i]);
      if (a[i] == cnt) {
        while (s.count(cnt)) {
          cnt++;
        }
      }
      if (cnt == mex) {
        cout << 2 << "\n";
        cout << 1 << " " << l << "\n" << l + 1 << " " << n << "\n";
        return;
      }
    }
  }
  cout << "-1\n";
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
