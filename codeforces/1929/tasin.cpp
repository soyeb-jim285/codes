#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, x, a;
  cin >> n >> x >> a;
  ll xx = x;
  ll b = a;
  b -= x;
  if (b <= 0) {
    cout << "NO\n";
    return;
  }
  b *= n;
  if (b <= a) {
    cout << "NO\n";
    return;
  }
  ll c = 1, np = 0;
  ll s = 0;
  ll nn = a;
  // cout << c << " " << s << " " << nn << endl;
  while (xx) {
    nn -= c;
    s += c;
    c = (s + 1) / (n - 1);
    if ((s + 1) % (n - 1))
      c++;
    xx--;
    if (nn <= 0) {
      cout << "NO\n";
      return;
    }
  }
  if (nn * n <= a) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
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
