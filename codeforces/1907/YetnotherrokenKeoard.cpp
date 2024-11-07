#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
void solve() {
  string s;
  cin >> s;
  vector<ll> ca, chuto;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'b') {
      s[i] = '.';
      if (chuto.size()) {
        ll ind = chuto.back();
        chuto.pop_back();
        s[ind] = '.';
      }
    } else if (s[i] == 'B') {
      s[i] = '.';
      if (ca.size()) {
        ll ind = ca.back();
        ca.pop_back();
        s[ind] = '.';
      }
    } else {
      if (s[i] >= 'a' && s[i] <= 'z')
        chuto.push_back(i);
      else
        ca.push_back(i);
    }
  }
  for (auto c : s) {
    if (c != '.')
      cout << c;
  }
  cout << "\n";
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
