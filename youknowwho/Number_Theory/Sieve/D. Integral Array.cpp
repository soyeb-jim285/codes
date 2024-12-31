#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k;
  cin >> n >> k;
  k = 0;
  vector<ll> a(n);
  set<ll> s;
  for (ll &x : a) {
    cin >> x;
    k = max(k, x);
    s.insert(x);
  }
  sort(a.begin(), a.end());
  vector<ll> nai;
  for (int i = 0; i < k; i++) {
    if (s.find(i + 1) == s.end()) {
      nai.push_back(i + 1);
    }
  }
  a.clear();
  for (auto x : s) {
    a.push_back(x);
  }
  if (a[0] != 1) {
    cout << "No\n";
    return;
  }
  for (int i = 0; i < nai.size(); i++) {
    for (int j = 0; j < n; j++) {
      if (nai[i] * a[j] > k) {
        break;
      }
      auto ic = lower_bound(a.begin(), a.end(), nai[i] * a[j]) - a.begin();
      ll res = a[ic] / a[j];
      if (res == nai[i]) {
        cout << "No\n";
        return;
      }
    }
  }
  cout << "Yes\n";
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
