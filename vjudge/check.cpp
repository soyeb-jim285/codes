#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool fn(ll n, ll k) {
  bool ans = 1;
  if (n % k)
    ans = 0;
  if (ans) {
    ll digit_sum = 0;
    while (n > 0) {
      digit_sum += n % 10;
      n /= 10;
    }
    if (digit_sum % k)
      ans = 0;
  }
  return ans;
}
void solve() {
  // for (int i = 1; i < 10; i++) {
  ll ct = 0;
  for (int j = 1; j < 100000; j++) {
    if (fn(j, 3)) {
      cout << 3 << ' ' << j << endl;
      ct++;
    }
  }
  cout << ct << endl;
  // }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
