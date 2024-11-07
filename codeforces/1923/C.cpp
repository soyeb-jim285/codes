#include <bits/stdc++.h>
#include <ios>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, q;
  cin >> n >> q;
  vector<ll> vc(n);
  vector<ll> pre(n + 1), ones(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  pre[0] = 0;
  ones[0] = 0;
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + vc[i - 1];
    ones[i] = ones[i - 1] + (vc[i - 1] == 1);
  }
  while (q--) {
    ll l, r;
    cin >> l >> r;
    if (l - r == 0) {
      cout << "NO\n";
      continue;
    }
    ll one = ones[r] - ones[l - 1];
    ll len = r - l + 1;
    if (pre[r] - pre[l - 1] < 2 * one + len - one) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
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
