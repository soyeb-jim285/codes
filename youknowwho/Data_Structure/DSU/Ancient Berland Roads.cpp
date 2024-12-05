#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct UF {
  vector<pair<ll, ll>> e;
  UF(int n) : e(n, {-1, 0}) {}
  int find(int x) {
    if (e[x].first < 0)
      return x;
    else {
      auto par = find(e[x].first);
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
    e[a].second += e[b].second;
    e[b].first = a;
    return true;
  }
  void add(int x, int y) { e[find(x)].second += y; }
};
void solve() {
  ll n, m, q;
  cin >> n >> m >> q;
  vector<bool> used(m);
  vector<stack<ll>> st(n);
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    st[i].push(x);
  }
  vector<pair<ll, ll>> e;
  for (int i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    e.emplace_back(u, v);
  }
  multiset<ll> s;
  vector<pair<bool, ll>> query;
  for (int i = 0; i < q; i++) {
    char c;
    cin >> c;
    if (c == 'P') {
      ll u, x;
      cin >> u >> x;
      u--;
      st[u].push(x);
      query.emplace_back(false, u);
    } else {
      ll u;
      cin >> u;
      u--;
      query.emplace_back(true, u);
      used[u] = true;
    }
  }
  UF uf(n);
  for (int i = 0; i < n; i++) {
    uf.e[i].second = st[i].top();
    s.insert(st[i].top());
  }
  for (int i = 0; i < m; i++) {
    if (!used[i]) {
      s.erase(s.find(uf.e[uf.find(e[i].first)].second));
      s.erase(s.find(uf.e[uf.find(e[i].second)].second));
      uf.join(e[i].first, e[i].second);
      s.insert(uf.e[uf.find(e[i].first)].second);
    }
  }
  vector<ll> ans(q);
  for (int i = q - 1; i >= 0; i--) {
    ans[i] = *s.rbegin();
    if (query[i].first) {
      if (uf.find(e[query[i].second].first) ==
          uf.find(e[query[i].second].second)) {
        continue;
      }
      s.erase(s.find(uf.e[uf.find(e[query[i].second].first)].second));
      s.erase(s.find(uf.e[uf.find(e[query[i].second].second)].second));
      uf.join(e[query[i].second].first, e[query[i].second].second);
      s.insert(uf.e[uf.find(query[i].second)].second);

    } else {
      auto root = uf.find(query[i].second);
      s.erase(s.find(uf.e[root].second));
      ll ager = st[query[i].second].top();
      st[query[i].second].pop();
      uf.add(query[i].second, st[query[i].second].top() - ager);
      s.insert(uf.e[uf.find(query[i].second)].second);
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
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
