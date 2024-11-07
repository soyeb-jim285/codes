#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> vc(n);
  map<pair<ll, ll>, ll> mp;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
    ll modx = vc[i] % x, mody = vc[i] % y;
    if (modx < 0)
      modx += x;
    if (mody < 0)
      mody += y;
    mp[{modx, mody}]++;
  }
  /* for (auto ic : mods) */
  /*   cout << ic.first << " " << ic.second << endl; */
  /* cout << "\n"; */
  for (int i = 0; i < n; i++) {
    ll modx = (x - vc[i] % x) % x, mody = vc[i] % y;
    if (modx < 0)
      modx += x;
    if (mody < 0)
      mody += y;

    ll modxx = vc[i] % x, modyy = vc[i] % y;
    if (modxx < 0)
      modxx += x;
    if (modyy < 0)
      modyy += y;
    /* cout << modxx << " " << modyy << " " << modx << " " << mody << endl; */
    if (mp[{modx, mody}]) {
      /* cout << "here\n"; */
      ans += mp[{modx, mody}];
      if (modxx == modx && modyy == mody)
        ans--;
    }
  }
  cout << ans / 2 << "\n";
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
