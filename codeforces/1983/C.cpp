#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool ok(vector<ll> &a, vector<ll> &b, vector<ll> &c, ll tol, ll &l, ll &r) {
  ll n = a.size();
  ll sum = 0;
  bool aa = 1, bb = 0, cc = 0;
  for (int i = 0; i < n; i++) {
    if (aa) {
      sum += a[i];
      if (sum * 3 >= tol) {
        l = i + 1;
        // cout << sum << " " << i << " a" << endl;
        aa = 0;
        bb = 1;
        sum = 0;
        continue;
      }
    }
    if (bb) {
      sum += b[i];
      if (sum * 3 >= tol) {
        r = i + 1;
        // cout << sum << " " << i << " b" << endl;

        bb = 0;
        cc = 1;
        sum = 0;
        continue;
      }
    }
    if (cc) {
      sum += c[i];
      // cout << sum << " " << i << " c" << endl;
    }
  }
  // cout << "---------------------\n";
  if (cc && sum * 3 >= tol) {
    return 1;
  } else {
    return 0;
  }
}
void solve() {
  ll n, tol = 0;
  cin >> n;
  vector<ll> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tol += a[i];
  }
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < n; i++)
    cin >> c[i];
  ll l, r;
  // cout << ok(b, c, a, tol, l, r) << " " << l << " " << r << endl;

  if (ok(a, b, c, tol, l, r))
    cout << "1 " << l << " " << l + 1 << " " << r << " " << r + 1 << " " << n
         << "\n";
  else if (ok(a, c, b, tol, l, r))
    cout << "1 " << l << " " << r + 1 << " " << n << " " << l + 1 << " " << r
         << "\n";
  else if (ok(b, a, c, tol, l, r))
    cout << l + 1 << " " << r << " 1 " << l << " " << r + 1 << " " << n << "\n";
  else if (ok(b, c, a, tol, l, r))
    cout << r + 1 << " " << n << " 1 " << l << " " << l + 1 << " " << r << "\n";
  else if (ok(c, a, b, tol, l, r))
    cout << l + 1 << " " << r << " " << r + 1 << " " << n << " 1 " << l << "\n";
  else if (ok(c, b, a, tol, l, r))
    cout << r + 1 << " " << n << " " << l + 1 << " " << r << " 1 " << l << "\n";

  else
    cout << "-1\n";
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
