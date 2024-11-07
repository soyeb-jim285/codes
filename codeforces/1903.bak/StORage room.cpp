#include <iostream>
#include <vector>
using namespace std;
typedef int ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> vc(n, vector<ll>(n));
  vector<ll> ans(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> vc[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    ans[i] = vc[i][0];
    if (i == 0)
      ans[i] = vc[0][1];
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      ans[i] = (ans[i] & vc[i][j]);
    }
  }
  bool ck = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int val = (ans[i] | ans[j]);
      if (i == j)
        val = 0;
      if (val != vc[i][j]) {
        ck = 0;
        break;
      }
    }
  }
  if (ck) {
    cout << "YES\n";
    for (auto ic : ans)
      cout << ic << " ";
    cout << "\n";
  } else
    cout << "NO\n";
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
