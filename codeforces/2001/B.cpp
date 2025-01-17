#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "-1\n";
    return;
  }
  for (int i = n; i >= 1; i -= 2) {
    cout << i << ' ';
  }
  for (int i = 2; i < n; i += 2) {
    cout << i << ' ';
  }
  cout << '\n';
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
