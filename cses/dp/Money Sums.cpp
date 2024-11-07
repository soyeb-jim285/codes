#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
set<ll> ans;
void fn(ll ind, vector<ll> &a, set<ll> &ans) {
  if (ind == a.size()) {
    return;
  }
  vector<ll> tmp;
  for (auto i : ans) {
    tmp.push_back(i + a[ind]);
  }
  ans.insert(a[ind]);
  for (auto i : tmp) {
    ans.insert(i);
  }
  fn(ind + 1, a, ans);
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  fn(0, a, ans);
  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << i << ' ';
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
