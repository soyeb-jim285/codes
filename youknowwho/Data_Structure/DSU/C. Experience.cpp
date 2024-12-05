#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct DSU {
  vector<pair<ll, ll>> e;
  DSU(int n) : e(n, {-1, 0}) {}
  pair<ll, ll> find(ll x) {
    if (e[x].first < 0)
      return {x, e[x].second};
    else {
      auto par = find(e[x].first);
      e[x].second += par.second - e[par.first].second;
      e[x].first = par.first;
      return {e[x].first, e[x].second + e[par.first].second};
    }
  }
  bool join(int a, int b) {
    a = find(a).first, b = find(b).first;
    if (a == b)
      return false;
    e[a].first += e[b].first;
    e[b].first = a;
    e[b].second -= e[a].second;
    return true;
  }
  void add(ll x, ll y) {
    ll root = find(x).first;
    e[root].second += y;
  }
};
void solve() {
  ll n, m;
  cin >> n >> m;
  DSU dsu(n);
  while (m--) {
    string s;
    cin >> s;
    if (s == "join") {
      ll u, v;
      cin >> u >> v;
      u--, v--;
      dsu.join(u, v);
    } else if (s == "add") {
      ll u, x;
      cin >> u >> x;
      u--;
      dsu.add(u, x);
    } else {
      ll u;
      cin >> u;
      u--;
      cout << dsu.find(u).second << '\n';
    }
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
