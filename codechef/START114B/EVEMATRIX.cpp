#include <bits/stdc++.h>
#include <system_error>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  if (n == 1)
    cout << "1\n";
  else if (n == 2)
    cout << "-1\n";
  else {
    vector<vector<ll>> ans(n, vector<ll>(n));
    ans[0][0] = 1;
    ans[0][1] = 3;
    ans[0][2] = 2;
    ans[1][0] = 5;
    ans[1][1] = 4;
    ans[1][2] = 6;
    ans[2][0] = 9;
    ans[2][1] = 8;
    ans[2][2] = 7;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i < 3 && j < 3)
          continue;
        if (i > j) {
          if (i % 2)
            ans[i][j] = (i + 1) * (i + 1) - (j + 1) + 1;
          else
            ans[i][j] = i * i + (j + 1);
        } else {
          if (j % 2)
            ans[i][j] = j * j + (i + 1);
          else
            ans[i][j] = (j + 1) * (j + 1) - (i + 1) + 1;
        }
      }
    }
    for (auto ic : ans) {
      for (auto i : ic)
        cout << i << " ";
      cout << "\n";
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
