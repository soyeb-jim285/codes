#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, pair<ll, ll>>> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second.first;
    a[i].second.second = i;
  }
  sort(a.begin(), a.end());
  vector<ll> ans;
  ll val, cost;
  for (int i = n - 1; i >= 0; i--) {
    if (ans.size() == 0) {
      ans.push_back(a[i].second.second);
      val = a[i].first;
      cost = a[i].second.first;
    } else {
      if (val > a[i].first && cost < a[i].second.first) {
        continue;
      } else {
        ans.push_back(a[i].second.second);
        val = a[i].first;
        cost = a[i].second.first;
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1 << " ";
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
