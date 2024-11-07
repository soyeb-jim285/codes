#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string s;
  cin >> s;
  map<char, ll> mp;
  for (char c : s)
    mp[c]++;
  ll mn = 1e9;
  char x;
  for (auto ic : mp) {
    if (ic.second < mn) {
      mn = ic.second;
      x = ic.first;
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == x) {
      cout << i + 1;
      return;
    }
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
