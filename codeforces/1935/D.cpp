#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, c;
  cin >> n >> c;
  vector<ll> a(n);
  vector<pair<ll, ll>> pre(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0) {
      pre[i] = {(a[i] + 1) % 2, a[i] % 2};
    } else {
      pre[i] = {pre[i - 1].first + (a[i] + 1) % 2,
                pre[i - 1].second + a[i] % 2};
    }
  }
  ll ans = (c + 1) * (c + 2) / 2;
  ll p = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= 2 * c) {
      ll pp = a[i] / 2;
      if (a[i] % 2) {
        pp++;
      }
      p += min(c, a[i]) - pp + 1;
    }
    if (c >= a[i]) {
      p += c - a[i] + 1;
    }
    auto ic =
        upper_bound(a.begin(), a.begin() + i, 2 * c - a[i] + 1) - a.begin();
    ic--;
    if (a[i] % 2 == 0) {
      p -= pre[i].first;
    } else {
      p -= pre[i].second;
    }
  }
  cout << ans - p << "\n";
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
/*
0 1
1 1
0 3
1 2
*/
