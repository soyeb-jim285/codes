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
  vector<ll> ans;
  for (ll i = 1; i <= 1e6; i++) {
    ll k = i * i + 3LL * i + 2LL;
    ll b;
    if (i % 2LL) {
      b = n - 1LL;
    } else {
      b = 2LL * n - 2LL;
    }
    if (k == 0) {
      ans.push_back(i);
    } else if (b % k == 0) {
      ans.push_back(i);
    }
  }
  cout << sz(ans) << endl;
  for (auto x : ans)
    cout << x << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
