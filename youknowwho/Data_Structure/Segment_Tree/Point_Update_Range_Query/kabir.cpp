#include <bits/stdc++.h>
#include <ctime>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() { cout << rnd() % 95 + 5 << "\n"; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 100;
  // cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
