#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n, x, y;
  cin >> n >> x >> y;
  ll yy = y / 3;
  yy = min(x, yy);
  n -= yy;
  x -= yy;
  /* cout << n << " " << x << " " << y << "\n"; */
  if (2 * n <= x)
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
