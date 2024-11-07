#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((ll)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll solve(ll b, ll c, ll d) {
  vector<vector<ll>> dp(64, vector<ll>(2));
  dp[0][0] = true;
  ll a = 0;
  for (int i = 0; i < 63; ++i) {
    for (int carry = 0; carry < 2; ++carry) {
      if (!dp[i][carry])
        continue;
      ll bbit = (b >> i) & 1;
      ll cbit = (c >> i) & 1;
      ll dbit = (d >> i) & 1;
      ll a_i = 0;
      ll bam = dbit + (cbit & a_i) + carry;
      // cout << bbit << " " << cbit << " " << dbit << " " << a_i << " " <<
      // carry
      // << " " << bam << "\n";
      ll dan = a_i | bbit;
      if (bam % 2 == dan) {
        ll new_carry = bam / 2;
        dp[i + 1][new_carry] = true;
      }
      a_i = 1;
      bam = dbit + (cbit & a_i) + carry;
      dan = a_i | bbit;
      if (bam % 2 == dan) {
        ll new_carry = bam / 2;
        dp[i + 1][new_carry] = true;
      }
    }
  }
  if (dp[63][0] == 0)
    return -1;
  ll carry = 0;
  for (int i = 63; i >= 0; --i) {
    ll bbit = (b >> i) & 1;
    ll cbit = (c >> i) & 1;
    ll dbit = (d >> i) & 1;
    ll a_i = 0;
    ll bam = dbit + (cbit & a_i) + carry;
    // cout << bbit << " " << cbit << " " << dbit << " " << a_i << " " <<
    // carry
    // << " " << bam << "\n";
    ll dan = a_i | bbit;
    if (dp[i][carry] && bam % 2 == dan) {
      carry = bam / 2;
      continue;
    }
    a |= (1LL << i);
    a_i = 1;
    bam = dbit + (cbit & a_i) + carry;
    dan = a_i | bbit;
    carry = bam / 2;
  }
  return a;
}

void solve() {
  ll b, c, d;
  cin >> b >> c >> d;

  cout << solve(b, c, d) << '\n';
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
