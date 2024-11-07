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
  vector<ll> a(2 * n), dis(n + 1, -1);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
    if (dis[a[i]] == -1) {
      dis[a[i]] = i;
    } else {
      dis[a[i]] = i - dis[a[i]];
    }
  }
  vector<pair<ll, ll>> ans;
  for (int i = 1; i <= n; i++) {
    ans.push_back({dis[i], i});
  }
  sort(ans.begin(), ans.end(), greater<pair<ll, ll>>());
  for (auto ic : ans)
    cout << ic.second << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
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
