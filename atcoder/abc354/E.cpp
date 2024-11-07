#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool check(ll bitmask, ll pos) { return bitmask & (1 << pos); }
ll setbit(ll bitmask, ll pos) { return bitmask | (1 << pos); }
ll resetbit(ll bitmask, ll pos) { return bitmask & ~(1 << pos); }
ll fn(ll mask, ll ind, bool pl, vector<int> &dp, vector<pair<ll, ll>> &a) {
  ll n = a.size();
  if (ind == n || mask == (1 << n) - 1) {
    return pl ^ 1;
  }
  if (dp[mask] != -1) {
    return dp[mask];
  }
  if (check(mask, ind)) {
    return dp[mask] = fn(mask, ind + 1, pl, dp, a);
  }

  ll ans;
  if (pl == 0) {
    ans = 1;
    ans = min(ans, fn(mask, ind + 1, pl ^ 1, dp, a));
  } else {
    ans = 0;
    ans = max(ans, fn(mask, ind + 1, pl ^ 1, dp, a));
  }
  for (int i = ind + 1; i < n; i++) {
    if (check(mask, i)) {
      continue;
    }
    if (a[ind].first == a[i].first || a[ind].second == a[i].second) {
      ll nmask = setbit(mask, ind);
      if (pl == 0) {
        ans = min(ans, fn(setbit(nmask, i), ind + 1, pl ^ 1, dp, a));
      } else {
        ans = max(ans, fn(setbit(nmask, i), ind + 1, pl ^ 1, dp, a));
      }
    }
  }
  return dp[mask] = ans;
}
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  vector<int> dp(1 << n, -1);
  cout << (fn(0, 0, 0, dp, a) ? "Aoki" : "Takahashi") << "\n";
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
