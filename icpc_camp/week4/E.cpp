#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  ll n, m;
  cin >> n >> m;
  ll digits = 2023;
  vector<vector<ll>> a(n + 1, vector<ll>(digits, 0));
  for (int i = 0; i < n + 1; i++) {
    a[i][digits - 1] = 1;
  }
  while (m--) {
    char c;
    cin >> c;
    if (c == '!') {
      ll x, y;
      cin >> x >> y;
      // for (auto ic : a[y]) {
      //   cout << ic << " ";
      // }
      // cout << "-*-\n";
      for (int j = 0; j + 1 < digits; j++) {
        a[x][j] += a[y][j + 1];
      }
    }
    // for (int i = 1; i < n + 1; i++) {
    //   for (auto ic : a[i]) {
    //     cout << ic << " ";
    //   }
    //   cout << "\n";
    // }
    // cout << "\n";
    if (c == '?') {
      ll x, y;
      cin >> x >> y;
      if (a[x] > a[y]) {
        cout << ">" << "\n";
      } else if (a[x] < a[y]) {
        cout << "<" << "\n";
      } else {
        cout << "=" << "\n";
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
/*
 * 2023^2023      = 0 0 0 0 0 1
 * 2023^2023^2023 = 0 0 0 0 1 0
 * (2023^2023^2023)^2023^2023 = 0 0 0 0 1 1
 *
 * */
