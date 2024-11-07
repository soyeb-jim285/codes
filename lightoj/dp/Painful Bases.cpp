#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll setbit(ll mask, int pos) { return mask | (1LL << pos); }
ll unsetbit(ll mask, int pos) { return mask & ~(1LL << pos); }
bool checkbit(ll mask, int pos) { return (mask & (1LL << pos)) > 0; }
ll fn(int mask, int rem, int base, int k, vector<int> digits,
      vector<vector<ll>> &dp) {
  if (mask == 0 && rem == 0)
    return 1;
  if (dp[mask][rem] != -1)
    return dp[mask][rem];
  ll ans = 0;
  for (int i = 0; i < sz(digits); i++) {
    if (checkbit(mask, i)) {
      ll new_rem = (rem * base + digits[i]) % k;
      ans += fn(unsetbit(mask, i), new_rem, base, k, digits, dp);
    }
  }
  return dp[mask][rem] = ans;
}
vector<int> get_digits(string s) {
  vector<int> digits;
  for (char c : s) {
    if (c >= '0' && c <= '9')
      digits.push_back(c - '0');
    else
      digits.push_back(c - 'A' + 10);
  }
  return digits;
}
void solve() {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> digits = get_digits(s);
  vector<vector<ll>> dp(1 << sz(digits), vector<ll>(k, -1));
  cout << fn((1 << sz(digits)) - 1, 0, n, k, digits, dp) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
