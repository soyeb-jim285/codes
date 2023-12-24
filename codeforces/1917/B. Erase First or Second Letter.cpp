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
  // reverse(s.begin(), s.end());
  ll ans = 0;
  set<char> ss;
  for (int i = 0; i < n; i++) {
    ss.insert(s[i]);
    ans += ss.size();
  }
  cout << ans << "\n";
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
