#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 1e5 + 9, NLOG = 17;
vector<ll> grp[N];
ll dpt[N], par[N][NLOG];
void dfs(ll node, ll parent) {
  par[node][0] = parent;
  for (int i = 1; i < NLOG; i++) {
    if (par[node][i - 1] != -1)
      par[node][i] = par[par[node][i - 1]][i - 1];
    else
      par[node][i] = -1;
  }
  for (int child : grp[node]) {
    if (child != parent) {
      dpt[child] = dpt[node] + 1;
      dfs(child, node);
    }
  }
}
ll lca(ll u, ll v) {
  if (dpt[u] < dpt[v])
    swap(u, v);
  int diff = dpt[u] - dpt[v];
  for (int i = NLOG - 1; i >= 0; i--) {
    if ((diff >> i) & 1) {
      u = par[u][i];
    }
  }
  if (u == v)
    return u;
  for (int i = NLOG - 1; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}
int kth_ancestor(int node, int k) {
  for (int i = 0; i < NLOG; i++) {
    if ((k >> i) & 1) {
      node = par[node][i];
      if (node == -1)
        break;
    }
  }
  return node;
}
int find_middle(int u, int v) {
  int lca_uv = lca(u, v);
  int dist_u_v = dpt[u] + dpt[v] - 2 * dpt[lca_uv];
  int middle_distance = dist_u_v / 2;

  if (dpt[u] - dpt[lca_uv] >= middle_distance) {
    return kth_ancestor(u, middle_distance);
  } else {
    return kth_ancestor(v, middle_distance + 1);
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    grp[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    grp[u].push_back(v);
    grp[v].push_back(u);
  }
  dpt[1] = 0;
  dfs(1, -1);
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << find_middle(u, v) << '\n';
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
