#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  vector<pair<ll, ll>> p(4);
  for (int i = 0; i < 4; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(), p.end());
  cout << (p[2].first - p[0].first) * (p[1].second - p[0].second) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
