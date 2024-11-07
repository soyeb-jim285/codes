#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, sum = 0;
  cin >> n;
  vector<pair<string, ll>> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    sum += a[i].second;
  }
  sort(a.begin(), a.end());
  ll k = sum % n;
  // cout << k << "\n";
  cout << a[k].first << "\n";
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
