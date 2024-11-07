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
  ll left = n, right = 0;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if (x >= 0)
      right += x;
    else {
      left--;
      right -= x;
    }
    // cout << left << " " << right << endl;
  }
  ll g = __gcd(left, right);
  left /= g;
  right /= g;
  if (left == 0) {
    cout << "inf" << endl;
    return;
  }
  cout << right << "/" << left << endl;
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
