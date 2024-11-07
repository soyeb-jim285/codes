#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, sum = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    sum += x;
    a[i] = x;
  }
  sort(a.begin(), a.end());
  ll tar = sum / n;
  if (n == 1) {
    cout << 0 << "\n";
    return;
  }
  ll sm = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    sm += tar - a[i];
    mx = max(mx, sm);
  }
  cout << mx - sm << "\n";
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
