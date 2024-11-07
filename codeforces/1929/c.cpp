#include <bits/stdc++.h>
using namespace std;
#define sz(a) ((int)((a).size()))
typedef long long ll;
void solve() {
  ll k, x, a;
  cin >> k >> x >> a;
  ll aa = a;
  ll ct = 1, loss = 0, sum = 0;
  for (int i = 0; i < x; i++) {
    a -= ct;
    sum += ct;
    cout << ct << " ";
    ct = ceil(1.0 * (sum + 1) / (k - 1));
    if (a <= 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "\n";
  if (a * k > aa)
    cout << "YES\n";
  else
    cout << "NO\n";
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
