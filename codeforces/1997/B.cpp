#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<vector<char>> a(2, vector<char>(n));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  ll ans = 0;
  for (int i = 0; i < n - 2; i++) {
    if (a[0][i] == '.' && a[0][i + 1] == '.' && a[0][i + 2] == '.' &&
        a[1][i] == 'x' && a[1][i + 1] == '.' && a[1][i + 2] == 'x') {
      ans++;
    }
    if (a[0][i] == 'x' && a[0][i + 1] == '.' && a[0][i + 2] == 'x' &&
        a[1][i] == '.' && a[1][i + 1] == '.' && a[1][i + 2] == '.') {
      ans++;
    }
  }
  cout << ans << "\n";
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
