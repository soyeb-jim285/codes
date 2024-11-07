#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, a, b;
  cin >> n >> a >> b;
  if (a == b) {
    if (n % (a + 1) == 0) {
      cout << "Bob"
           << "\n";
    } else {
      cout << "Alice"
           << "\n";
    }
  } else if (a > b) {
    cout << "Alice"
         << "\n";
  } else {
    if (n < a + 1) {
      cout << "Alice"
           << "\n";
    } else {
      cout << "Bob"
           << "\n";
    }
  }
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
