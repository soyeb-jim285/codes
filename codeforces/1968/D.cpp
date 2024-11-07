#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k, pa, pb;
  cin >> n >> k >> pa >> pb;
  ll kk = k;
  vector<ll> p(n + 1), a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<bool> used(n + 1, false);
  ll cnt = 0, max_a = 0, max_b = 0, rem = 0;
  while (1) {
    if (used[pa] || k <= 0)
      break;
    used[pa] = true;
    max_a = max(max_a, rem + (k)*a[pa]);
    rem += a[pa];
    pa = p[pa];
    k--;
  }
  k = kk;
  rem = 0;
  used.assign(n + 1, false);
  while (1) {
    // cout << pb << " " << k << "----\n";
    if (used[pb] || k <= 0)
      break;
    used[pb] = true;
    max_b = max(max_b, rem + (k)*a[pb]);
    // cout << rem + k * a[pb] << " *-*\n";
    rem += a[pb];
    pb = p[pb];
    k--;
  }
  // cout << max_a << " " << max_b << "\n";
  if (max_a > max_b)
    cout << "Bodya\n";
  else if (max_a < max_b)
    cout << "Sasha\n";
  else
    cout << "Draw\n";
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
