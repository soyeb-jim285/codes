#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  string s;
  cin >> s;
  ll n = s.size();
  vector<ll> vc(26);
  for (int i = 0; i < n; i++) {
    vc[s[i] - 'a']++;
  }
  vector<vector<ll>> cnt(26, vector<ll>(n + 1));
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < n; j++) {
      cnt[i][j + 1] = cnt[i][j];
      if (s[j] - 'a' == i) {
        cnt[i][j + 1]++;
      }
    }
  }
  ll ans = 1e9;
  for (int i = 0; i < 26; i++) {
    if (vc[i] == 0)
      continue;
    for (int j = 0; j < n; j++) {
      if (j + vc[i] <= n) {
        ll ck = vc[i] - cnt[i][j + vc[i]] + cnt[i][j];
        ans = min(ans, ck);
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
