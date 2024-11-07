#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;

ll const mod = 1e9 + 7;

void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  map<char, ll> mp;
  for (int i = 0; i < sz(s); i++) {
    mp[s[i]]++;
  }
  ll ans = 1;
  for (auto it : mp) {
    ans = ans * (it.second + 1) % mod;
  }
  cout << ans - 1 << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
