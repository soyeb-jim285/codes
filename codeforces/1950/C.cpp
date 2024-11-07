#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll a, b;
  char c;
  cin >> a >> c >> b;
  if (a < 12) {
    if (a == 0)
      a = 12;
    if (a < 10)
      cout << "0";
    cout << a << c;
    if (b < 10)
      cout << "0";
    cout << b << " AM\n";
  } else {
    if (a - 12 == 0)
      a = 24;
    if (a - 12 < 10)
      cout << "0";
    cout << a - 12 << c;
    if (b < 10)
      cout << "0";
    cout << b << " PM\n";
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
