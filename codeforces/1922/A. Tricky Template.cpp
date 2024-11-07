#include <bits/stdc++.h>
#include <string>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  string a, b, c;
  cin >> a >> b >> c;
  for (int i = 0; i < n; i++) {
    if (a[i] != c[i] && b[i] != c[i]) {
      cout << "YES\n";
      return;
    }
  }
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
