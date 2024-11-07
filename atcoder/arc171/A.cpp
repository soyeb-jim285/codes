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
  ll k = n - a;
  if (k < 0) {
    cout << "No\n";
    return;
  } else if (k == 0) {
    if (b == 0) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
    return;
  }
  ll pw = ceil(1.0 * b / k);
  ll tot;
  if (n % 2) {
    tot = pw + max(a, pw - 1);
  } else {
    tot = pw + max(a, pw);
  }
  if (tot > n) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
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
