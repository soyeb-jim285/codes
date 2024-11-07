#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      b[i][j] = c - '0';
    }
  vector<ll> col_a(m), row_a(n), col_b(m), row_b(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      row_a[i] = (row_a[i] + a[i][j]) % 3;
      col_a[j] = (col_a[j] + a[i][j]) % 3;
      row_b[i] = (row_b[i] + b[i][j]) % 3;
      col_b[j] = (col_b[j] + b[i][j]) % 3;
    }
  for (int i = 0; i < n; i++) {
    if (row_a[i] != row_b[i]) {
      cout << "NO\n";
      return;
    }
  }
  for (int i = 0; i < m; i++) {
    if (col_a[i] != col_b[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
