#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  set<ll> s;
  for (int i = 0; i < n; i++) {
    s.insert(i + 1);
  }
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    ll nm = *--s.end();
    if (nm >= k) {
      a[i] = nm;
      s.erase(nm);
    } else {
      break;
    }
  }
  ll nm = m;
  for (int i = n - 1; i >= 0; i--) {
    if (nm <= 0)
      break;
    a[i] = nm;
    s.erase(nm);
    nm--;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      a[i] = *s.begin();
      s.erase(a[i]);
    }
  }
  for (auto ic : a) {
    cout << ic << " ";
  }
  cout << "\n";
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
