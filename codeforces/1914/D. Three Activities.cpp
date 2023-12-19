#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> v(3, vector<ll>(n));
  vector<pair<ll, ll>> a(n), b(n), c(n);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    a[i] = {v[0][i], i};
    b[i] = {v[1][i], i};
    c[i] = {v[2][i], i};
  }
  sort(a.begin(), a.end(), greater<pair<ll, ll>>());
  sort(b.begin(), b.end(), greater<pair<ll, ll>>());
  sort(c.begin(), c.end(), greater<pair<ll, ll>>());
  ll mx = 0;
  for (int i = 0; i < n - 2; i++) {
    ll tmp = a[i].first;
    if (a[i].second == b[i].second) {
      tmp += b[i + 1].first;
      if (c[i].second == a[i].second) {
        if (c[i + 1].second == b[i].second) {
          tmp += c[i + 2].first;
        } else {
          tmp += c[i + 1].first;
        }
      } else {
        tmp += c[i].first;
      }
    } else {
      tmp += b[i].first;
      if (c[i].second == a[i].second) {
        tmp += c[i + 1].first;
      } else {
        tmp += c[i].first;
      }
      mx = max(mx, tmp);
    }
  }
  cout << mx << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
