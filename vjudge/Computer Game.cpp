#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool fn(ll mid, ll a, ll b, ll n, ll k) {
  return (mid * a + (n - mid) * b) >= k;
}
void solve() {
  ll k, n, a, b;
  cin >> k >> n >> a >> b;
  if (n * b >= k) {
    cout << -1 << endl;
    return;
  }
  ll low = 0, high = n;
  while (low < high) {
    ll mid = (low + high + 1) / 2;
    if (fn(mid, a, b, n, k)) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  cout << low << endl;
}
int main() {
  ios::sync_with_stdio(false);
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
