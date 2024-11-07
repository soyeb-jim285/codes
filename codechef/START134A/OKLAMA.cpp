#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  ll left = 0, right = 0;
  priority_queue<ll> pql, pqr;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  pqr.push(-a[0]);
  vector<ll> ans(n);
  ans[0] = a[0];
  right += a[0];
  if (n % 2 == 0)
    n--;
  for (int i = 1; i < n; i += 2) {
    ll x = a[i];
    ll y = a[i + 1];
    if (x > y)
      swap(x, y);
    ll lf = -1e18;
    if (sz(pql))
      lf = pql.top();
    ll rf = -pqr.top();
    if (x < lf && y < lf) {
      // cout << "a\n";
      left += x + y - lf;
      right += lf;
      pql.pop();
      pql.push(x);
      pql.push(y);
      pqr.push(-lf);
    } else if (x > rf && y > rf) {
      // cout << "b\n";
      left += rf;
      right += x + y - rf;
      pqr.pop();
      pqr.push(-x);
      pqr.push(-y);
      pql.push(rf);
    } else {
      // cout << "c\n";
      left += x;
      right += y;
      pql.push(x);
      pqr.push(-y);
    }
    // cout << left << ' ' << right << '\n';
    ans[i + 1] = right - left;
  }
  while (q--) {
    ll x;
    cin >> x;
    cout << ans[x - 1] << " ";
  }
  cout << "\n";
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
