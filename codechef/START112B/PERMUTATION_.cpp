#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n, x;
  cin >> n >> x;
  ll p = x + n + 1 - 2 * x;
  if (p == x || p <= 0 || p > n) {
    cout << "-1\n";
    return;
  } else {
    cout << x << " ";
    for (int i = 0; i < n; i++) {
      if (i + 1 != p && i + 1 != x)
        cout << i + 1 << " ";
    }
    cout << p << "\n";
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
