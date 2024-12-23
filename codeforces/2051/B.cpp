#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  ll n, a, b, c;
  cin >> n >> a >> b >> c;
  ll age = n / (a + b + c), rem = n % (a + b + c);
  ll ans = age * 3;
  if (rem == 0) {
  } else if (rem <= a) {
    ans++;
  } else if (rem <= a + b) {
    ans += 2;
  } else {
    ans += 3;
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
