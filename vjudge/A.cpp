#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<vector<char>> vc(n, vector<char>(n));
  vector<ll> row(n, 0), col(n, 0);
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      cin >> vc[i][j];
      if (vc[i][j] == '+') {
        row[i]++;
        col[j]++;
      } else {
        row[i]--;
        col[j]--;
      }
    }
  }
  vector<ll> r(n), c(n);
  for (ll i = 0; i < n; i++) {
    cin >> r[i];
  }
  for (ll i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<vector<int>> ans(n, vector<int>(n, 1));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      if (ans[i][j] == 0)
        continue;
      if (row[i] > r[i] && col[j] > c[j]) {
        if (vc[i][j] == '+') {
          ans[i][j] = 0;
          row[i]--;
          col[j]--;
        }
      }
      if (row[i] < r[i] && col[j] < c[j]) {
        if (vc[i][j] == '-') {
          ans[i][j] = 0;
          row[i]++;
          col[j]++;
        }
      }
    }
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      if (ans[i][j] == 0)
        continue;
      if (row[i] > r[i] && col[j] > c[j]) {
        if (vc[i][j] == '+') {
          ans[i][j] = 0;
          row[i]--;
          col[j]--;
        }
      }
      if (row[i] < r[i] && col[j] < c[j]) {
        if (vc[i][j] == '-') {
          ans[i][j] = 0;
          row[i]++;
          col[j]++;
        }
      }
    }
  }

  /* if (row != r || col != c) { */
  /*   cout << "NO" << endl; */
  /*   return; */
  /* } */
  cout << "YES" << endl;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++)
      cout << ans[i][j];
    cout << "\n";
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
