#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  map<int, vector<int>> cnt;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    cnt[x].push_back(i);
  }
  ll lg = n;
  vector<int> ans(n, 0);
  for (auto &[x, v] : cnt) {
    for (int i = 0; i < v.size(); i++) {
      ans[v[i]] = lg;
      lg--;
    }
  }
  for (auto ic : ans)
    cout << ic << " ";
  cout << '\n';
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
