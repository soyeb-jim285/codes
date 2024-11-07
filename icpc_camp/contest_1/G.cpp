#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ld const err = 1e-5;
long double dist(pair<ld, ld> a, pair<ld, ld> b) {
  return sqrtl((a.first - b.first) * (a.first - b.first) +
               (a.second - b.second) * (a.second - b.second));
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<pair<ld, ld>> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i].first >> b[i].second;
  }
  vector<ld> dis1, dis2;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      dis1.push_back(0);
    } else {
      dis1.push_back(dis1.back() + dist(a[i], a[i - 1]));
    }
  }
  for (int i = 0; i < m; i++) {
    if (i == 0) {
      dis2.push_back(0);
    } else {
      dis2.push_back(dis2.back() + dist(b[i], b[i - 1]));
    }
  }
  ll ans = dis2.size();
  for (int i = 0; i < dis1.size(); i++) {
    auto it =
        upper_bound(dis2.begin(), dis2.end(), dis1[i] + err) - dis2.begin();
    it--;
    if (abs(dis2[it] - dis1[i]) > err) {
      ans++;
    }
  }
  cout << 2 * ans - n - m << "\n";
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
