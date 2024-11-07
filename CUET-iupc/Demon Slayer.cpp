#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct pt {
  ll x, y;
};
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<pt> v(m);
  vector<ll> cnt(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> v[i].x >> v[i].y;
  }
  for (int i = 0; i < m - 1; i++) {
    for (int j = i + 1; j < m; j++) {
      ll up = (v[j].x - v[i].x) * v[i].y;
      ll dn = v[i].y - v[j].y;
      if (dn == 0)
        continue;
      if (up % dn == 0) {
        ll k = up / dn + v[i].x;
        if (k >= 1 && k <= n)
          cnt[k]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    ll k = cnt[i + 1];
    ll kk = 1 + 8 * k;
    ll up = sqrt(kk) + 1;
    cout << up / 2 << ' ';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
