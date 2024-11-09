#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<ll> ans;
  ans.insert(0);
  for (int i = 0; i < n; i++) {
    vector<ll> tmp = vector<ll>(ans.begin(), ans.end());
    for (int j = 0; j < (int)tmp.size(); j++) {
      ans.insert(tmp[j] + a[i]);
    }
  }
  ans.erase(0);
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x << " ";
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
