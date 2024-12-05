#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
  ll n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
  }
  UF uf(n);
  vector<tuple<bool, ll, ll>> q;
  vector<bool> ans;
  while (k--) {
    string s;
    cin >> s;
    ll u, v;
    cin >> u >> v;
    u--, v--;
    q.emplace_back(s == "ask", u, v);
  }
  for (int i = q.size() - 1; i >= 0; i--) {
    auto [s, u, v] = q[i];
    if (s) {
      ans.push_back(uf.sameSet(u, v));
    } else {
      uf.join(u, v);
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto x : ans) {
    if (x)
      cout << "YES\n";
    else
      cout << "NO\n";
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
