#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll fn(ll ind, vector<ll> &pre, vector<ll> &vc, vector<pair<ll, ll>> &ranges) {
  ll n = ranges.size();
  if (ind >= n)
    return 0;
  ll ans = fn(ind + 1, pre, vc, ranges);
  ll tot = 0;
  vector<ll> cnt(101);
  for (int i = ranges[ind].first; i <= ranges[ind].second; i++) {
    cnt[vc[i]]++;
  }
  for (int i = 1; i <= 100; i++) {
    tot += (cnt[i] * (cnt[i] - 1)) / 2;
  }
  pair<ll, ll> p = make_pair(ranges[ind].second, 1e9);
  auto ic = upper_bound(ranges.begin(), ranges.end(), p) - ranges.begin();
  cout << ind << " " << ranges[ind].first << " " << ranges[ind].second << " "
       << tot << "\n";
  ans = max(ans, fn(ic, pre, vc, ranges) + tot);
  return ans;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> vc(n), pre(n + 1), cnt(101);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
    cnt[vc[i]]++;
    for (int j = 1; j <= 100; j++) {
      pre[i + 1] += cnt[j] * (cnt[j] - 1) / 2;
    }
  }
  vector<pair<ll, ll>> ranges;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (vc[i] == vc[j]) {
        ranges.push_back({i, j});
      }
    }
  }
  for (auto x : ranges) {
    cout << x.first << " " << x.second << "\n";
  }
  for (int i = 0; i < n; i++) {
    cout << i + 1 << ": " << pre[i + 1] << "\n";
  }
  cout << fn(0, pre, vc, ranges) << "\n";
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
