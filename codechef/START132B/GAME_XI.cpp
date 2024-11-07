#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, m;
  cin >> n >> m;
  priority_queue<ll> a, b;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    a.push(x);
  }
  for (int i = 0; i < m; i++) {
    ll x;
    cin >> x;
    b.push(x);
  }
  if (n < 4 || m < 4 || n + m < 11) {
    cout << "-1\n";
    return;
  }
  ll ans = 0, cnt = 4;
  while (cnt--) {
    ans += a.top();
    ans += b.top();
    a.pop();
    b.pop();
  }
  cnt = 3;
  while (cnt--) {
    ll x = -1;
    ll y = -1;
    if (a.size())
      x = a.top();
    if (b.size()) {
      y = b.top();
    }
    if (x > y) {
      ans += a.top();
      a.pop();
    } else {
      ans += b.top();
      b.pop();
    }
  }
  cout << ans << "\n";
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
