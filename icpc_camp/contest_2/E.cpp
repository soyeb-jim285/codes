#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k;
  cin >> n >> k;
  if (k == 1) {
    if (n == 1)
      cout << "Yes\n";
    else
      cout << "No\n";
    return;
  }
  if (k % 2 == 0) {
    cout << "Yes\n";
  } else {
    if (n == 2 * k) {
      cout << "No\n";
    } else {
      if (n <= 2 * k + (k + 1) / 2) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
