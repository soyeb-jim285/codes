#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool bin_check(ll n) {
  while (n) {
    if (n % 10 > 1) {
      return false;
    }
    n /= 10;
  }
  return true;
}
bool fact(ll n) {
  if (bin_check(n))
    return true;
  bool ans = 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      if (bin_check(i)) {
        ans |= fact(n / i);
      }
      if (bin_check(n / i)) {
        ans |= fact(i);
      }
    }
  }
  return ans;
}
void solve() {
  ll n;
  cin >> n;
  cout << (fact(n) ? "YES" : "NO") << '\n';
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
