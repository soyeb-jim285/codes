#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  map<char, ll> mp;
  for (int i = 0; i < s.size(); i++) {
    mp[s[i]]++;
  }
  ll mx = 0;
  for (auto ic : mp)
    mx = max(mx, ic.second);
  if (mx > n - mx) {
    cout << 2 * mx - n << "\n";
    return;
  }
  if (n % 2)
    cout << "1\n";
  else
    cout << "0\n";
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
