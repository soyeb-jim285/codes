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
  bool ck = 0;
  for (int i = 0; i < n; i++) {
    if (ck == 1) {
      cout << "NO\n";
      continue;
    }
    if (s[i] == '1') {
      if (i != n - 1)
        cout << "IDK\n";
      else
        cout << "YES\n";
    } else {
      cout << "NO\n";
      ck = 1;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
