#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  ll ans = 0, cnt = 0;
  for (int i = 0; i < min(sz(s1), sz(s2)); i++) {
    if (s1[i] == s2[i]) {
      cnt++;

    } else {
      break;
    }
  }
  ans += cnt;
  if (cnt) {
    ans++;
  }
  ans += sz(s1) + sz(s2) - 2 * cnt;
  cout << ans << '\n';
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
