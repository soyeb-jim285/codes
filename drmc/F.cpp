
#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void dfs_land(vector<vector<char>> &a, vector<vector<bool>> &vis, int i, int j,
              ll &xx, ll &yy) {
  ll n = a.size();
  ll m = a[0].size();
  // cout << i << " " << j << "a\n";
  // if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '.' || vis[i][j])
  //   return;
  vis[i][j] = true;
  if (i > xx && j == m - 1) {
    xx = i;
    yy = j;
  }
  if (i == 0 && j < yy && yy != m - 1) {
    yy = j;
    xx = 0;
  }
  if (i + 1 < n && a[i + 1][j] == '#' && !vis[i + 1][j])
    dfs_land(a, vis, i + 1, j, xx, yy);
  if (i - 1 >= 0 && a[i - 1][j] == '#' && !vis[i - 1][j])
    dfs_land(a, vis, i - 1, j, xx, yy);
  if (j + 1 < m && a[i][j + 1] == '#' && !vis[i][j + 1])
    dfs_land(a, vis, i, j + 1, xx, yy);
  if (j - 1 >= 0 && a[i][j - 1] == '#' && !vis[i][j - 1])
    dfs_land(a, vis, i, j - 1, xx, yy);
  if (i + 1 < n && j + 1 < m && a[i + 1][j + 1] == '#' && !vis[i + 1][j + 1])
    dfs_land(a, vis, i + 1, j + 1, xx, yy);
  if (i - 1 >= 0 && j + 1 < m && a[i - 1][j + 1] == '#' && !vis[i - 1][j + 1])
    dfs_land(a, vis, i - 1, j + 1, xx, yy);
  if (i + 1 < n && j - 1 >= 0 && a[i + 1][j - 1] == '#' && !vis[i + 1][j - 1])
    dfs_land(a, vis, i + 1, j - 1, xx, yy);
  if (i - 1 >= 0 && j - 1 >= 0 && a[i - 1][j - 1] == '#' && !vis[i - 1][j - 1])
    dfs_land(a, vis, i - 1, j - 1, xx, yy);
}
void dfs_water(vector<vector<char>> &a, vector<vector<bool>> &vis, int i,
               int j) {
  // cout << i << " " << j << "b\n";
  ll n = a.size();
  ll m = a[0].size();
  if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '#' || vis[i][j])
    return;
  vis[i][j] = true;
  a[i][j] = '#';
  if (i + 1 < n && a[i + 1][j] == '.' && !vis[i + 1][j])
    dfs_water(a, vis, i + 1, j);
  if (i - 1 >= 0 && a[i - 1][j] == '.' && !vis[i - 1][j])
    dfs_water(a, vis, i - 1, j);
  if (j + 1 < m && a[i][j + 1] == '.' && !vis[i][j + 1])
    dfs_water(a, vis, i, j + 1);
  if (j - 1 >= 0 && a[i][j - 1] == '.' && !vis[i][j - 1])
    dfs_water(a, vis, i, j - 1);
  if (i + 1 < n && j + 1 < m && a[i + 1][j + 1] == '.' && !vis[i + 1][j + 1])
    dfs_water(a, vis, i + 1, j + 1);
  if (i - 1 >= 0 && j + 1 < m && a[i - 1][j + 1] == '.' && !vis[i - 1][j + 1])
    dfs_water(a, vis, i - 1, j + 1);
  if (i + 1 < n && j - 1 >= 0 && a[i + 1][j - 1] == '.' && !vis[i + 1][j - 1])
    dfs_water(a, vis, i + 1, j - 1);
  if (i - 1 >= 0 && j - 1 >= 0 && a[i - 1][j - 1] == '.' && !vis[i - 1][j - 1])
    dfs_water(a, vis, i - 1, j - 1);
  // dfs_water(a, vis, i + 1, j);
  // dfs_water(a, vis, i - 1, j);
  // dfs_water(a, vis, i, j + 1);
  // dfs_water(a, vis, i, j - 1);
  // dfs_water(a, vis, i + 1, j + 1);
  // dfs_water(a, vis, i - 1, j + 1);
  // dfs_water(a, vis, i - 1, j + 1);
  // dfs_water(a, vis, i + 1, j - 1);
}
ll dfs_water_cnt(vector<vector<char>> &a, vector<vector<bool>> &vis, int i,
                 int j) {
  // cout << i << " " << j << "c\n";
  ll n = a.size();
  ll m = a[0].size();
  if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '#' || vis[i][j])
    return 0;
  vis[i][j] = true;
  a[i][j] = '#';
  ll cnt = 1;
  if (i + 1 < n && a[i + 1][j] == '.' && !vis[i + 1][j])
    cnt += dfs_water_cnt(a, vis, i + 1, j);
  if (i - 1 >= 0 && a[i - 1][j] == '.' && !vis[i - 1][j])
    cnt += dfs_water_cnt(a, vis, i - 1, j);
  if (j + 1 < m && a[i][j + 1] == '.' && !vis[i][j + 1])
    cnt += dfs_water_cnt(a, vis, i, j + 1);
  if (j - 1 >= 0 && a[i][j - 1] == '.' && !vis[i][j - 1])
    cnt += dfs_water_cnt(a, vis, i, j - 1);
  if (i + 1 < n && j + 1 < m && a[i + 1][j + 1] == '.' && !vis[i + 1][j + 1])
    cnt += dfs_water_cnt(a, vis, i + 1, j + 1);
  if (i - 1 >= 0 && j + 1 < m && a[i - 1][j + 1] == '.' && !vis[i - 1][j + 1])
    cnt += dfs_water_cnt(a, vis, i - 1, j + 1);
  if (i + 1 < n && j - 1 >= 0 && a[i + 1][j - 1] == '.' && !vis[i + 1][j - 1])
    cnt += dfs_water_cnt(a, vis, i + 1, j - 1);
  if (i - 1 >= 0 && j - 1 >= 0 && a[i - 1][j - 1] == '.' && !vis[i - 1][j - 1])
    cnt += dfs_water_cnt(a, vis, i - 1, j - 1);
  // cnt += dfs_water_cnt(a, vis, i + 1, j);
  // cnt += dfs_water_cnt(a, vis, i - 1, j);
  // cnt += dfs_water_cnt(a, vis, i, j + 1);
  // cnt += dfs_water_cnt(a, vis, i, j - 1);
  // cnt += dfs_water_cnt(a, vis, i + 1, j + 1);
  // cnt += dfs_water_cnt(a, vis, i - 1, j + 1);
  // cnt += dfs_water_cnt(a, vis, i - 1, j + 1);
  // cnt += dfs_water_cnt(a, vis, i + 1, j - 1);
  return cnt;
}
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<bool>> vis(n, vector<bool>(m));
  ll lst_x = 0, lst_y = 0;
  vector<vector<bool>> vis2(n, vector<bool>(m));
  ll tmp_x = -1, tmp_y = -1;
  ll x = -1, y = 1e7;
  if (k > n * m) {
    cout << "YES\n";
    return;
  }
  while (k >= 0) {
    if (tmp_x == lst_x && tmp_y == lst_y) {
      break;
    }
    // cout << lst_x << " " << lst_y << " " << k << '\n';
    dfs_land(a, vis, lst_x, lst_y, x, y);
    tmp_x = lst_x;
    tmp_y = lst_y;
    if (vis[n - 1][m - 1]) {
      cout << "Yes\n";
      return;
    }
    bool done = false;
    if (y == m - 1) {
      lst_x = x + 1;
      lst_y = y;
    }
    if (x == 0) {
      lst_x = x;
      lst_y = y + 1;
    }
    // for (int i = n - 1; i >= 0; i--) {
    //   if (vis[i][m - 1] == true) {
    //     // cout << i << " " << m - 1 << " " << vis[i][m - 1] << " " << a[i][m
    //     -
    //     // 1]
    //     //      << '\n';
    //     done = true;
    //     break;
    //   }
    //   if (a[i][m - 1] == '.' && vis[i][m - 1] == false) {
    //     lst_x = i;
    //     lst_y = m - 1;
    //   }
    // }
    // // cout << done << " ---*--\n";
    // if (!done) {
    //   for (int i = m - 1; i >= 0; i--) {
    //     if (vis[0][i] == true)
    //       break;
    //     if (a[0][i] == '.' && vis[0][i] == false) {
    //       lst_x = 0;
    //       lst_y = i;
    //     }
    // }
    // cout << lst_x << " " << lst_y << " " << k << "-*-*-*-*-\n";
    ll cnt = dfs_water_cnt(a, vis2, lst_x, lst_y);
    if (cnt == 0)
      break;
    // cout << cnt << "---\n";
    // for (auto ic : vis) {
    //   for (auto jc : ic) {
    //     cout << jc;
    //   }
    //   cout << '\n';
    // }
    k -= cnt;
    if (k < 0) {
      break;
    }
    // for (auto ic : a) {
    //   for (auto jc : ic) {
    //     cout << jc;
    //   }
    //   cout << '\n';
    // }
    // for (auto ic : vis) {
    //   for (auto jc : ic) {
    //     cout << jc;
    //   }
    //   cout << '\n';
    // }
  }
  cout << "No\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    // cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
