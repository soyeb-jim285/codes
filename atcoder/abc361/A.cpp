#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k, x;
  cin >> n >> k >> x;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
    if (i == k - 1) {
      cout << x << " ";
    }
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
