#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll r = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R')
      r++;
  }
  ll win = n / 2 + 1 - r;
  bool ok = 0;
  string ans = "";
  for (int i = n - 1; i >= 0; i--) {
    if (win <= 0) {
      ans += 'P';
      continue;
    }
    if (s[i] == 'P')
      ans += 'S';
    else if (s[i] == 'R') {
      ans += 'P';
      win++;
    } else
      ans += 'R';
    win--;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
