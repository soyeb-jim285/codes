#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll alice(ll t, ll c1, ll d1) {
  ll ans = 1 + c1 * (t / (c1 + d1));
  if (t % (c1 + d1) >= c1)
    ans += c1;
  else
    ans += t % (c1 + d1);
  return ans;
}
void solve() {
  ll c1, d1, c2, d2, q;
  cin >> c1 >> d1 >> c2 >> d2 >> q;
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
