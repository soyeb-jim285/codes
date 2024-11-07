#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n + 1), ind(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
    ind[a[i + 1]] = i + 1;
  }
  vector<pair<ll, ll>> ans;
  for (int i = 1; i <= n; i++) {
    if (a[i] == i)
      continue;
    ans.push_back({i, ind[i]});
    ll ax = a[i];
    ll ai = ind[i];
    swap(a[i], a[ind[i]]);
    ind[i] = i;
    ind[ax] = ai;
  }
  cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    cout << x << ' ' << y << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
