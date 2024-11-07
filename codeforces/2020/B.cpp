#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll sqrll(ll x) {
  ll y = sqrtl(x);
  while (y * y > x)
    y--;
  while ((y + 1) * (y + 1) <= x)
    y++;
  return y;
}
bool fn(ll mid, ll n) {
  ll sq = sqrll(mid);
  if (mid - sq >= n)
    return 1;
  return 0;
}
void solve() {
  ll n;
  cin >> n;
  ll low = 1, high = 2e18;
  while (low < high) {
    ll mid = (low + high) / 2;
    if (fn(mid, n))
      high = mid;
    else
      low = mid + 1;
  }
  for (ll i = max(1LL, low - 5); i <= min((ll)2e18, low + 10); i++)
    if (fn(i, n)) {
      low = i;
      break;
    }
  cout << low << '\n';
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
