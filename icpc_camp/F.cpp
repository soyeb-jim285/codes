#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  string s1, s2;
  cin >> s1 >> s2;
  vector<tuple<ll, ll, ll, bool>> vc;
  for (int i = 0; i < n; i++) {
    vc.push_back({a[i], s1[i] - '0', s2[i] - '0', 0});
  }
  sort(vc.begin(), vc.end(), greater<tuple<ll, ll, ll, bool>>());
  ll steps = 0;
  for (int i = 0; i < n; i++) {
    auto [cost, x, y, t] = vc[i];
    if (x == 1 && y == 1) {
      steps++;
    }
  }
  ll ans = 1e18;
  for (int i = 0; i <= steps; i++) {
    ll sum = 0, baki = 0;
    for (int j = 0; j < n; j++) {
      auto [cost, x, y, t] = vc[j];
      if (x)
        baki += cost;
    }
    ll now = i;
    for (int j = 0; j < n; j++) {
      auto [cost, x, y, t] = vc[j];
      if (x && !y) {
        baki -= cost;
        sum += baki;
      } else if (now && x && y) {
        baki -= cost;
        now--;
        vc[j] = {cost, 0, y, 1};
        sum += baki;
      }
    }
    for (int j = n - 1; j >= 0; j--) {
      auto [cost, x, y, t] = vc[j];
      if (!x && y) {
        baki += cost;
        sum += baki;
        if (t) {
          vc[j] = {cost, 1, y, 0};
        }
      }
    }
    ans = min(ans, sum);
  }
  cout << ans << "\n";
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
