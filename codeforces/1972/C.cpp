#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool fn(ll mid, ll k, vector<ll> &vc) {
  for (int i = 0; i < sz(vc); i++) {
    if (vc[i] < mid) {
      k -= (mid - vc[i]);
    }
  }
  if (k < 0)
    return false;
  return true;
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> vc(n);
  for (ll &x : vc)
    cin >> x;
  sort(vc.begin(), vc.end());
  ll low = 0, high = 1e12 + 10;
  while (high - low > 1) {
    ll mid = (low + high) / 2;
    ll col = 0;
    for (int i = 0; i < n; i++) {
      if (vc[i] < mid)
        col += mid - vc[i];
    }
    if (col <= m) {
      low = mid;
    } else
      high = mid;
  }
  for (int i = 0; i < sz(vc); i++) {
    if (vc[i] < low) {
      m -= (low - vc[i]);
      vc[i] = low;
    }
  }
  assert(m >= 0);
  ll ans = (low - 1LL) * n + 1LL;
  for (int i = 0; i < n; i++) {
    if (vc[i] > low)
      ans++;
  }
  cout << ans + m << "\n";
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
