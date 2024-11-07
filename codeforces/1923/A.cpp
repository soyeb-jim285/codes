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
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll one = 0, one_o = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    if (one && a[i] == 0) {
      zero++;
    }
    if (a[i] == 1) {
      one = 1;
    }
  }
  one = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (!one && a[i] == 0) {
      zero--;
    }
    if (a[i] == 1) {
      one = 1;
      break;
    }
  }
  cout << zero << '\n';
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
