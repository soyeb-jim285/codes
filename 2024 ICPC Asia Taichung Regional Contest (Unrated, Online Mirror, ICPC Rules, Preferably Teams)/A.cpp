#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  vector<ll> v(4);
  for (int i = 0; i < 4; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  ll ans = 1;
  for (int i = 0; i < 4; i++) {
    if (v[i] == ans)
      ans++;
  }
  cout << ans << '\n';
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
