#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
struct UF {
  vector<ll> e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<pair<int, int>> e;
  vector<bool> used(m);
  for (int i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    e.emplace_back(u, v);
  }
  ll q;
  cin >> q;
  vector<ll> query(q);
  for (int i = 0; i < q; i++) {
    cin >> query[i];
    query[i]--;
    used[query[i]] = true;
  }
  UF uf(n);
  ll comp = n;
  for (int i = 0; i < m; i++) {
    if (!used[i]) {
      if (uf.join(e[i].first, e[i].second))
        comp--;
    }
  }
  vector<ll> ans(q);
  for (int i = q - 1; i >= 0; i--) {
    ans[i] = comp;
    if (uf.join(e[query[i]].first, e[query[i]].second))
      comp--;
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << "\n";
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
