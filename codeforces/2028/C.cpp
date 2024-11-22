#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, m, v;
  cin >> n >> m >> v;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  vector<ll> pref(n + 1);
  for (int i = 0; i < n; i++)
    pref[i + 1] = pref[i] + a[i];
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
