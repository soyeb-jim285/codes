#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll b, y;
  cin >> b >> y;
  for (int i = 0; i < 10000; i++) {
    ll n1 = i / 2;
    ll n2 = i - n1;
    ll cost = i * y + n1 * n1 + n2 * n2;
    if (cost > b) {
      cout << (1LL << (i - 1)) << '\n';
      return;
    }
  }
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
