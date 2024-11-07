#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define PII pair<int, int>
#define endl "\n"
const int MAX = 1e9;
const int N = 200010;
const ll INF = 1e9 + 7;

void solve() {
  ll n;
  cin >> n;
  string s = to_string(n);
  bool ok1 = true, ok2 = true, ok3 = true;
  for (int i = 0; i < s.size(); i++) {
    if (i == 0) {
      ok1 = (s[i] != '1' ? false : true);
    } else if (i == s.size() - 1) {
      ok2 = (s[i] == '9' ? false : true);
    } else {
      // if (s[i] == '0') {
      //   ok3 = false;
      // }
      ok3 = (s[i] == '0' ? false : true);
    }
  }

  cout << (ok1 && ok2 && ok3 ? "YES" : "NO") << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
