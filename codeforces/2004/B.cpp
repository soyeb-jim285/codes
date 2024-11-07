#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  vector<int> a(101), b(101);
  int w, x, y, z;
  cin >> w >> x >> y >> z;
  for (int i = w; i <= x; i++) {
    a[i]++;
  }
  for (int i = y; i <= z; i++) {
    a[i]++;
  }
  ll ans = 0, ind1 = -1, ind2;
  for (int i = 0; i < 100; i++) {
    if (a[i] == 0 || a[i + 1] == 0)
      continue;
    if (!(a[i] == 1 && a[i + 1] == 1))
      ans++;
  }
  if (ans == 0)
    ans++;
  cout << ans << "\n";
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
