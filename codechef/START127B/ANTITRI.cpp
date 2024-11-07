#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, l;
  cin >> n >> l;
  if (l >= 1999) {
    for (int i = 0; i < n; i++) {
      cout << i + 1 << " ";
    }
  } else {
    ll sum = 1;
    cout << sum << " ";
    for (int i = 1; i < n; i++) {
      cout << sum + l << " ";
      sum += l;
    }
  }
  cout << "\n";
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
