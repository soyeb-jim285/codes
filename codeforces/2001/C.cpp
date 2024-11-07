#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void fn(ll a, vector<pair<int, int>> &ans, vector<set<ll>> &p, set<ll> &v) {
  while (sz(p[a])) {
    ll b = *p[a].begin();
    cout << "? " << a << ' ' << b << endl;
    ll x;
    cin >> x;
    if (x == a) {
      ans.push_back({a, b});
      p[a].erase(p[a].begin());
      p[b].erase(p[b].find(a));
    } else {
      p[a].erase(p[a].begin());
      p[b].erase(p[b].find(a));
    }
    if (sz(p[a])) {
      v.erase(a);
    }
    if (sz(p[b])) {
      v.erase(b);
    }
  }
}
void solve() {
  ll n;
  cin >> n;
  vector<set<ll>> p(n);
  set<ll> v;
  for (int i = 1; i <= n; i++) {
    v.insert(i);
    for (int j = 1; j <= n; j++) {
      if (i == j)
        continue;
      p[i].insert(j);
    }
  }
  vector<pair<int, int>> ans;
  while (sz(ans) < n - 1) {
  }
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
