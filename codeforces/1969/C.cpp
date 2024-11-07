#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const p1 = 1e9 + 7, p2 = 1e9 + 9;
ll hsh(vector<ll> a, ll p1) {
  ll ans = 0;
  for (auto ic : a)
    ans = (ans * p1 + ans * ic) % p1;
  return ans;
}
ll fn(ll k, vector<ll> a, map<pair<pair<ll, ll>, ll>, ll> &dp) {
  if (k <= 0)
    return 0;
  ll hash1 = hsh(a, p1), hash2 = hsh(a, p2);
  if (dp[{{hash1, hash2}, k}] != 0)
    return dp[{{hash1, hash2}, k}];
  ll ans = 0LL;
  for (int i = 0; i < sz(a); i++) {
    for (auto ic : a)
      cout << ic << " ";
    cout << " || " << k << "\n";
    if (i != 0) {
      vector<ll> a1 = a;
      ll tmp = a1[i];
      a1[i] = a1[i - 1];
      ans = max(ans, fn(k - 1, a1, dp) + tmp - a1[i]);
      for (auto ic : a1)
        cout << ic << " ";
      cout << " || " << a[i] - a1[i] << " " << k << " " << ans << "\n";
    }
    if (i != sz(a) - 1) {
      vector<ll> a2 = a;
      ll tmp = a2[i];
      a2[i] = a2[i + 1];
      ans = max(ans, fn(k - 1, a2, dp) + tmp - a2[i]);
      for (auto ic : a2)
        cout << ic << " ";
      cout << " || " << a[i] - a2[i] << " " << k << " " << ans << "\n";
    }
  }
  return dp[{{hash1, hash2}, k}] = ans;
}
void solve() {
  ll n, k, sum = 0, mn = 1e18;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    mn = min(mn, a[i]);
  }
  if (n == 1) {
    cout << a[0] << '\n';
    return;
  }
  if (k >= n - 1) {
    cout << mn * n << '\n';
    return;
  }
  map<pair<pair<ll, ll>, ll>, ll> dp;
  cout << fn(k, a, dp) << '\n';
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
