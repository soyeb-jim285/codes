#include <iostream>
using namespace std;
typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll one = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      one++;
  }
  if (n == one)
    cout << "NO\n";
  else
    cout << "YES\n";
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
