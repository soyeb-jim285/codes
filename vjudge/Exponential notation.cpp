#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string s;
  bool ck = 0, dot = 0;
  cin >> s;
  ll pw = 0;
  string ans = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '.') {
      dot = 1;
      if (ans.size() > 0)
        pw = ans.size() - 1;
      else {
        pw = -1;
        ck = 1;
      }
    }
    if (s[i] >= '1' && s[i] <= '9' && ck == 1) {
      ck = 0;
    }
    if (pw < 0 && ck == 1) {
      pw--;
    }
    if (ans.size() == 0 && s[i] == '0')
      continue;
    if (s[i] != '.')
      ans += s[i];
  }
  if (dot == 0)
    pw = ans.size() - 1;
  ll ind = ans.size() - 1;
  for (int i = ans.size() - 1; i >= 0; i--) {
    if (ans[i] != '0') {
      ind = i;
      break;
    }
  }

  if (pw < 0)
    pw++;
  for (int i = 0; i <= ind; i++) {
    if (i == 0)
      cout << ans[i];
    else if (i == 1)
      cout << "." << ans[i];
    else
      cout << ans[i];
  }
  if (pw != 0) {
    cout << "E" << pw << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
