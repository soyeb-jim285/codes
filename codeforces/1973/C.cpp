#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, ind = -1;
  cin >> n;
  vector<ll> a(n);
  set<ll> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1)
      ind = i;
    s.insert(a[i]);
  }
  map<ll, ll> mp;
  if (ind % 2) {
    ll mn = 1e10;
    for (int i = 0; i < n; i += 2) {
      mn = min(mn, a[i]);
    }
    ll sum = n + mn;
    for (int i = 0; i < n; i += 2) {
      mp[a[i]] = sum - a[i];
      s.erase(sum - a[i]);
    }
  } else {
    ll mn = 1e10;
    for (int i = 1; i < n; i += 2) {
      mn = min(mn, a[i]);
    }
    ll sum = n + mn;
    for (int i = 1; i < n; i += 2) {
      mp[a[i]] = sum - a[i];
      s.erase(sum - a[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (mp[i + 1] == 0) {
      mp[i + 1] = *--s.end();
      s.erase(--s.end());
    }
  }
  for (int i = 0; i < n; i++) {
    cout << mp[a[i]] << ' ';
  }
  cout << "\n";
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
