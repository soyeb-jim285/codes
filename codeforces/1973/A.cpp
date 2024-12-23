#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  if ((a + b + c) % 2) {
    cout << "-1\n";
  } else {
    if (a + b <= c) {
      cout << a + b << '\n';
    } else {
      cout << (a + b + c) / 2 << '\n';
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
