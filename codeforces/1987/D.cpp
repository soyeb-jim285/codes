#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll fn(ll ind, ll rst, vector<pair<ll, ll>> &nums, vector<vector<ll>> &dp) {
  if (ind == sz(nums))
    return 0;
  if (dp[ind][rst] != -1)
    return dp[ind][rst];
  ll ans = 0;
  if (rst >= nums[ind].second) {
    ans = max(ans, fn(ind + 1, rst - nums[ind].second, nums, dp) + 1);
    ans = max(ans, fn(ind + 1, rst + 1, nums, dp));
  } else {
    ans = max(ans, fn(ind + 1, rst + 1, nums, dp));
  }
  return dp[ind][rst] = ans;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  vector<pair<ll, ll>> nums;
  for (auto ic : mp) {
    nums.push_back({ic.first, ic.second});
  }
  vector<vector<ll>> dp(sz(nums), vector<ll>(sz(nums), -1));
  cout << nums.size() - fn(0, 0, nums, dp) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
