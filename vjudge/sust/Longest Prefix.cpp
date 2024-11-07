#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string a, b;
  cin >> a >> b;
  map<char, int> mp;
  for (char c : b)
    mp[c]++;
  ll ans = 0;
  for (int i = 0; i < sz(a); i++) {
    /* cout << a[i] << " " << mp[a[i]] << "\n"; */
    if (mp[a[i]] > 0) {
      mp[a[i]]--;
      ans++;
    } else
      break;
  }
  cout << ans << "\n";
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
