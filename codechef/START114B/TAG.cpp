#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;

void dfs(ll ind, ll par, vector<vector<ll>> &grp, vector<ll> &leafs,
         vector<ll> &hight, vector<ll> &depth) {
  if (grp[ind].size() == 1 && ind != 1) {
    leafs[par]++;
    hight[ind] = 0;
  }
  for (auto child : grp[ind]) {
    if (child == par)
      continue;
    depth[child] = depth[ind] + 1;
    dfs(child, ind, grp, leafs, hight, depth);
    leafs[ind] += leafs[child];
    hight[ind] = min(hight[child] + 1, hight[ind]);
  }
}

void solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> grp(n + 1);
  for (int i = 0; i < n - 1; i++) {
    ll x, y;
    cin >> x >> y;
    grp[x].push_back(y);
    grp[y].push_back(x);
  }
  vector<ll> leafs(n + 1), hight(n + 1, 1e9), depth(n + 1);
  dfs(1LL, 0LL, grp, leafs, hight, depth);
  // for (int i = 0; i < n + 1; i++) {
  //   cout << leafs[i] << " " << hight[i] << " " << depth[i] << "\n";
  // }
  ll ans = 1;
  for (int i = 2; i < n + 1; i++) {
    if (depth[i] <= hight[i]) {
      ans = max(ans, leafs[i]);
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
