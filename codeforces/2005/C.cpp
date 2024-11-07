#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<char> val = {'n', 'a', 'r', 'e', 'k'};
ll fn(ll ind, int valind, vector<string> &s, vector<vector<ll>> &dp) {
  ll preval = valind;
  ll n = sz(s), m = sz(s[0]);
  if (ind == n) {
    return 0;
  }
  if (dp[ind][valind] != -1e9) {
    return dp[ind][valind];
  }
  ll sn = 0, sc = 0;
  vector<bool> paisi(m, false);
  vector<int> tmp;
  for (int i = 0; i < m; i++) {
    if (s[ind][i] == val[valind]) {
      tmp.push_back(i);
      valind++;
      if (valind == 5) {
        sc = -preval;
        for (auto x : tmp)
          paisi[x] = true;
        valind = 0;
        sn += 5;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (!paisi[i]) {
      if (s[ind][i] == 'n' || s[ind][i] == 'a' || s[ind][i] == 'r' ||
          s[ind][i] == 'e' || s[ind][i] == 'k') {
        sc++;
      }
    }
  }
  ll ans =
      max(fn(ind + 1, preval, s, dp), fn(ind + 1, valind, s, dp) + sn - sc);
  return dp[ind][preval] = ans;
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<vector<ll>> dp(n, vector<ll>(5, -1e9));
  cout << fn(0, 0, s, dp) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
