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
  map<char, int> mp;
  for (int i = 0; i < n; i++) {
    mp[s[i]]++;
  }
  ll count = 0;
  for (auto i : mp) {
    if (i.first - 'A' + 1 <= i.second) {
      count++;
    }
  }
  cout << count << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
