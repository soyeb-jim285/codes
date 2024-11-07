#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k;
ll Test_of_love(ll ind, string &str, vector<ll> &dp, bool &destination) {
  if (ind >= str.size()) {
    destination = true;
    return 0;
  }
  if (dp[ind] != 1e14)
    return dp[ind];
  ll ans = 0;
  if (str[ind] == 'W') {
    ans = ans + 1 + Test_of_love(ind + 1, str, dp, destination);
  } else if (str[ind] == 'L') {
    ll mn = 1e12;
    for (ll i = 0; i < m; i++) {
      mn = (ll)min((ll)mn, (ll)Test_of_love(ind + i + 1, str, dp, destination));
    }

    ans = ans + mn;
  } else {
    ans = 1e12;
    return dp[ind] = ans;
  }
  return dp[ind] = ans;
}

void solve() {
  cin >> n >> m >> k;
  string str;
  cin >> str;
  str = "L" + str;
  // cout<<str<<endl;
  vector<ll> dp(n + 5, 1e14);
  bool destination = false;
  ll ans = Test_of_love(0, str, dp, destination);
  if (ans <= k && destination)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
