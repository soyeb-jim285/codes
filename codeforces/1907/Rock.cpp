#include <iostream>
using namespace std;
typedef long long ll;
typedef long double ld;
void solve() {
  string s;
  cin >> s;
  for (char i = '1'; i <= '8'; i++) {
    string ans = "";
    ans += s[0];
    ans += i;
    if (ans == s)
      continue;
    cout << ans << "\n";
  }
  for (char i = 'a'; i <= 'h'; i++) {
    string ans = "";
    ans += i;
    ans += s[1];
    if (ans == s)
      continue;
    cout << ans << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
