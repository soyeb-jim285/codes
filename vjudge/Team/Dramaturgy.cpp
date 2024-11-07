#include <bits/stdc++.h>
#include <set>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), ck(n);
  multiset<ll> s;
  for (auto &i : a) {
    cin >> i;
  }
  ll kk = k;
  vector<ll> ori = a;
  for (int i = 0; i < 32; i++) {
    ll x = k % 2;
    k /= 2;
    for (int j = 0; j < n; j++) {
      if (x == 1) {
        if (a[j] % 2) {
          ck[j]++;
        }
      } else {
        ck[j]++;
      }
      a[j] /= 2;
    }
    if (k == 0)
      break;
  }
  ll mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, ck[i]);
  }
  ll andd = -1, cnt = 0, ls = -1;
  for (int i = 0; i < n; i++) {
    if (ck[i] == mx) {
      cnt++;
      if (ls == -1)
        ls = ori[i];
      else {
        ls &= ori[i];
      }
      if (andd == -1)
        andd = a[i];
      else
        andd &= a[i];
    }
  }
  if (andd != 0 || ls != kk)
    cout << -1 << "\n";
  else
    cout << cnt << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
