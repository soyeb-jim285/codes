#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> parent, rk;
void make_set(ll v) {
  parent[v] = v;
  rk[v] = 0;
}

ll find_set(ll v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rk[a] < rk[b])
      swap(a, b);
    parent[b] = a;
    if (rk[a] == rk[b])
      rk[a]++;
  }
}

struct Edge {
  ll u, v, weight;
  bool operator<(Edge const &other) { return weight < other.weight; }
};
void dfs(ll v, vector<vector<pair<ll, ll>>> &grp, vector<bool> &used) {
  used[v] = true;
  for (auto [to, w] : grp[v]) {
    if (!used[to])
      dfs(to, grp, used);
  }
}

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> grp(n);
  vector<bool> used(n + 1, false);
  map<pair<ll, ll>, ll> mp;
  while (m--) {
    ll a, b;
    cin >> a >> b;
    vector<ll> vc(a);
    for (ll i = 0; i < a; i++) {
      cin >> vc[i];
    }
    for (ll i = 0; i < a - 1; i++) {
      if (mp.count({vc[i], vc[i + 1]}) == 0) {
        mp[{vc[i], vc[i + 1]}] = b;
      } else {
        mp[{vc[i], vc[i + 1]}] = min(mp[{vc[i], vc[i + 1]}], b);
      }
    }
  }
  vector<Edge> edges;
  ll cost = 0;
  vector<Edge> result;
  parent.resize(n);
  rk.resize(n);
  for (auto [a, b] : mp) {
    grp[a.first - 1].push_back({a.second - 1, b});
    grp[a.second - 1].push_back({a.first - 1, b});
    edges.push_back({a.first - 1, a.second - 1, b});
  }
  dfs(0, grp, used);
  for (ll i = 0; i < n; i++) {
    if (!used[i]) {
      cout << -1 << endl;
      return;
    }
  }
  for (ll i = 0; i < n; i++)
    make_set(i);

  sort(edges.begin(), edges.end());

  for (Edge e : edges) {
    if (find_set(e.u) != find_set(e.v)) {
      cost += e.weight;
      result.push_back(e);
      union_sets(e.u, e.v);
    }
  }
  cout << cost << endl;
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
