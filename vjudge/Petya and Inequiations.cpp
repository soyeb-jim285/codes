#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, x, y;
  cin >> n >> x >> y;
  ll mx = y - n + 1;
  if (mx * mx + n - 1 < x || mx < 1) {
    cout << "-1\n";
  } else {
    cout << mx << "\n";
    for (int i = 0; i < n - 1; i++) {
      cout << "1\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
