#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  bool a = 0, b = 0, c = 0, d = 0;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    if (x > 0)
      a = 1;
    if (x < 0)
      b = 1;
    if (y > 0)
      c = 1;
    if (y < 0)
      d = 1;
  }
  if (a + b + c + d < 4)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
