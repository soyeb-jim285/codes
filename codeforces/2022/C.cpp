#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
map<pair<int, int>, int> dp;
ll fn(ll ind, ll dif, vector<vector<char>> &a, map<pair<int, int>, int> &dp) {
  ll n = sz(a[0]);
  if (dp.find({ind, dif}) != dp.end()) {
    return dp[{ind, dif}];
  }
  if (ind > n || ind + dif > n) {
    return 0;
  }
  if (ind == n) {
    if (dif >= 0) {
      return 0;
    }
    if (dif == -3) {
      ll cnt = a[1][ind + dif] == 'A';
      cnt += a[1][ind + dif + 1] == 'A';
      cnt += a[1][ind + dif + 2] == 'A';
      return (ll)(cnt >= 2);
    }
  }
  if (ind + dif == n) {
    if (dif <= 0) {
      return 0;
    }
    if (dif == 3) {
      ll cnt = a[0][ind] == 'A';
      cnt += a[0][ind + 1] == 'A';
      cnt += a[0][ind + 2] == 'A';
      return (ll)(cnt >= 2);
    }
  }
  // 1 2
  ll ans = 0;
  if (dif == 0 || dif == -1) {
    if (ind + 1 <= n && ind + dif + 2 <= n) {
      ll cnt = a[0][ind] == 'A';
      cnt += a[1][ind + dif] == 'A';
      cnt += a[1][ind + dif + 1] == 'A';
      ans = max(ans, fn(ind + 1, dif + 1, a, dp) + (ll)(cnt >= 2));
    }
  }
  // 2 1
  if (dif == 0 || dif == 1) {
    if (ind + 2 <= n && ind + dif + 1 <= n) {
      ll cnt = a[0][ind] == 'A';
      cnt += a[0][ind + 1] == 'A';
      cnt += a[1][ind + dif] == 'A';
      ans = max(ans, fn(ind + 2, dif - 1, a, dp) + (ll)(cnt >= 2));
    }
  }
  if (dif == 0 || dif == 1 || dif == 2 || dif == 3) {
    if (ind + 3 <= n && ind + dif <= n) {
      ll cnt = a[0][ind] == 'A';
      cnt += a[0][ind + 1] == 'A';
      cnt += a[0][ind + 2] == 'A';
      ans = max(ans, fn(ind + 3, dif - 3, a, dp) + (ll)(cnt >= 2));
    }
  }
  if (dif == 0 || dif == -1 || dif == -2 || dif == -3) {
    if (ind <= n && ind + dif + 3 <= n) {
      {
        ll cnt = a[1][ind + dif] == 'A';
        cnt += a[1][ind + dif + 1] == 'A';
        cnt += a[1][ind + dif + 2] == 'A';
        ans = max(ans, fn(ind, dif + 3, a, dp) + (ll)(cnt >= 2));
      }
    }
  }
  return dp[{ind, dif}] = ans;
}
void solve() {
  ll n;
  cin >> n;
  vector<vector<char>> a(2, vector<char>(n));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  cout << fn(0, 0, a, dp) << '\n';
  dp.clear();
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
