#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 2e5 + 1;
vector<ll> a(N);
ll digitsum(ll x) {
  ll res = 0;
  while (x) {
    res += x % 10;
    x /= 10;
  }
  return res;
}
void fn() {
  for (int i = 1; i < N; i++) {
    a[i] = a[i - 1] + digitsum(i);
  }
}
void solve() {
  ll n;
  cin >> n;
  cout << a[n] << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  fn();
  ll t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
