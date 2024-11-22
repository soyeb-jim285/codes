#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, p;
  cin >> n >> p;
  if (n == 1) {
    if (p == 1) {
      cout << "Evenius\n";
    } else {
      cout << "Oddius\n";
    }
    return;
  }
  if (p == 1) {
    cout << "Oddius\n";
    return;
  }
  if (p == 2) {
    if (n % 4 == 1)
      cout << "Evenius\n";
    else
      cout << "Oddius\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
