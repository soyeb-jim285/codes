
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
const int LOG = 17; // Maximum value for log2(100000) ~ 16, so we take LOG = 17
vector<int> grp[MAXN];
int dpt[MAXN], par[MAXN][LOG];
void dfs(int node, int parent) {
  par[node][0] = parent; // Immediate parent
  for (int i = 1; i < LOG; i++) {
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

int lca(int u, int v) {
  if (dpt[u] < dpt[v])
    swap(u, v);

  int diff = dpt[u] - dpt[v];

  // Bring u and v to the same level
  for (int i = LOG - 1; i >= 0; i--) {
    if ((diff >> i) & 1) {
      u = par[u][i];
    }
  }

  if (u == v)
    return u;

  for (int i = LOG - 1; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }

  return par[u][0]; // LCA
}

// Find kth ancestor of a node
int kth_ancestor(int node, int k) {
  for (int i = 0; i < LOG; i++) {
    if ((k >> i) & 1) {
      node = par[node][i];
      if (node == -1)
        break;
    }
  }
  return node;
}

// Process each query to find the middle node
int find_middle(int u, int v) {
  int lca_uv = lca(u, v);
  int dist_u_v = dpt[u] + dpt[v] - 2 * dpt[lca_uv];

  int middle_distance = dist_u_v / 2;
  // return kth_ancestor(u, middle_distance);

  if (dpt[u] - dpt[lca_uv] >= middle_distance) {
    // Middle is on the path from u to lca
    return kth_ancestor(u, middle_distance);
  } else {
    // Middle is on the path from lca to v
    return kth_ancestor(v, middle_distance);
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    // Reset graph
    for (int i = 1; i <= n; i++) {
      grp[i].clear();
    }

    // Read edges
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      grp[u].push_back(v);
      grp[v].push_back(u);
    }

    // Preprocess using DFS
    dpt[1] = 0; // assuming 1 is the root
    dfs(1, -1);

    int q;
    cin >> q;

    while (q--) {
      int u, v;
      cin >> u >> v;
      cout << find_middle(u, v) << '\n';
    }
  }

  return 0;
}
