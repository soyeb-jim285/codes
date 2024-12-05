#include <bits/stdc++.h>
#include <utility>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct UF {
  vector<pair<ll, pair<ll, ll>>> e;
  UF(int n) : e(n, {-1, {n + 1, -1}}) {
    for (int i = 0; i < n; i++) {
      e[i].second.first = i + 1;
      e[i].second.second = i + 1;
    }
  }
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)].first; }
  int find(int x) {
    if (e[x].first < 0)
      return x;
    else {
      int par = find(e[x].first);
      e[x].second.first = min(e[x].second.first, e[par].second.first);
      e[x].second.second = max(e[x].second.second, e[par].second.second);
      e[x].first = par;
      return par;
    }
  }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a].first += e[b].first;
    e[b].first = a;
    e[a].second.first = min(e[a].second.first, e[b].second.first);
    e[a].second.second = max(e[a].second.second, e[b].second.second);
    // cout << a << ' ' << e[a].second.first << ' ' << e[a].second.second <<
    // "-\n";
    return true;
  }
};
void solve() {
  ll n, m;
  cin >> n >> m;
  UF uf(n);
  // for (auto [a, b] : uf.e) {
  //   cout << a << ' ' << b.first << ' ' << b.second << " *\n";
  // }
  // cout << "----\n";
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if (s == "union") {
      ll u, v;
      cin >> u >> v;
      u--, v--;
      uf.join(u, v);
    } else {
      ll x;
      cin >> x;
      x--;
      auto [sz, pm] = uf.e[uf.find(x)];
      cout << pm.first << " " << pm.second << " " << -sz << '\n';
    }
    // for (auto [a, b] : uf.e) {
    //   cout << a << ' ' << b.first << ' ' << b.second << " *\n";
    // }
    // cout << "----\n";
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
