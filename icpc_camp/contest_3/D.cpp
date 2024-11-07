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
  vector<ll> a(n), b(n);
  map<ll, ll> mp, ind;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ind[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    mp[b[i]] = i;
  }
  ll ct = 0;
  bool sp = 0;
  vector<pair<ll, ll>> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      int ai = ind[j];
      int hobe = mp[j];
      if (ai > hobe && a[hobe] > j) {
        ct++;
        ans.push_back({ai + 1, hobe + 1});
        swap(a[ai], a[hobe]);
        ind[a[ai]] = ai;
        ind[a[hobe]] = hobe;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int i = n; i >= 1; i--) {
      int ai = ind[i];
      int hobe = mp[i];
      if (ai > hobe && a[hobe] > i) {
        ct++;
        ans.push_back({ai + 1, hobe + 1});
        swap(a[ai], a[hobe]);
        ind[a[ai]] = ai;
        ind[a[hobe]] = hobe;
      }
    }
  }
  for (auto ic : a)
    cout << ic << " ";
  cout << "\n";
  cout << ct << "\n";
  for (auto [x, y] : ans) {
    cout << x << " " << y << "\n";
  }
}
int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
