#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n, mx = 0, mxchar = -1;
  cin >> n;
  string s, ans = "";
  cin >> s;
  vector<pair<char, int>> vc;
  for (int i = sz(s) - 1; i >= 0; i--) {
    if (vc.size() == 0) {
      vc.push_back({s[i], i});
      ans.push_back(s[i]);
    } else {
      if (s[i] >= vc.back().first) {
        vc.push_back({s[i], i});
        ans.push_back(s[i]);
      }
    }
    if (s[i] >= mxchar) {
      if (s[i] == mxchar)
        mx++;
      else {
        mxchar = s[i];
        mx = 1;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < sz(vc); i++) {
    s[vc[i].second] = ans[i];
  }
  if (is_sorted(s.begin(), s.end())) {
    cout << ans.size() - 1 - mx + 1 << "\n";
  } else
    cout << "-1\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
