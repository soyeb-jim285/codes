#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, q, sum = 0;
  cin >> n >> q;
  vector<ll> a(n);
  for (ll &x : a) {
    cin >> x;
    sum += x;
  }
  sum *= 2;
  while (q--) {
    ll k;
    cin >> k;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (ok)
        break;
      for (int j = i + 1; j < n; j++) {
        if (sum - a[i] - a[j] == k) {
          cout << a[i] << " ";
          for (int kk = 0; kk < n; kk++) {
            if (kk != i && kk != j)
              cout << a[kk] << " ";
          }
          cout << a[j] << '\n';
          ok = true;
          break;
        }
      }
    }
    if (!ok)
      cout << -1 << '\n';
  }
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
