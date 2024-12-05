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
  vector<ll> a(n);
  map<ll, ll> cnt;
  for (ll &x : a) {
    cin >> x;
    cnt[x]++;
  }
  vector<pair<ll, ll>> b;
  for (auto [x, y] : cnt)
    b.emplace_back(y, x);
  sort(b.begin(), b.end());
  ll ans = 0;
  vector<ll> new_v;
  for (int i = 0; i < sz(b); i++) {
    for (int j = 0; j < b[i].first; j++)
      new_v.push_back(b[i].second);
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0 && cnt[new_v[i]]) {
      if (cnt[new_v[i]] == 1)
        ans++;
      ans++;
      cnt[new_v[i]] = 0;
    }
  }
  cout << ans << '\n';
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
