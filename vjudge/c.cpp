#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  vector<ll> vc(3);
  cin >> vc[0] >> vc[1] >> vc[2];
  ll ans = 0;
  for (int i = 0; i < 3; i++) {
    if (vc[i] > 0) {
      ans++;
    }
  }
  if (vc[0] > 1 && vc[1] > 1) {
    vc[0]--;
    vc[1]--;
    ans++;
  }
  if (vc[0] > 1 && vc[2] > 1) {
    vc[0]--;
    vc[2]--;
    ans++;
  }
  if (vc[1] > 1 && vc[2] > 1) {
    vc[1]--;
    vc[2]--;
    ans++;
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
