#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const INF = 1e18;
void bfs(ll i, ll j, bool mos, vector<vector<char>> &a,
         vector<vector<bool>> &vis, vector<vector<char>> &path,
         vector<vector<ll>> &val, queue<pair<ll, ll>> &q) {
  ll n = a.size(), m = a[0].size();
  while (q.size()) {
    auto ic = q.front();
    q.pop();
    if (ic.first + 1 < n && vis[ic.first + 1][ic.second] == 0 &&
        a[ic.first + 1][ic.second] != '#') {
      vis[ic.first + 1][ic.second] = 1;
      q.push({ic.first + 1, ic.second});
      val[ic.first + 1][ic.second] = val[ic.first][ic.second] + 1;
      if (mos) {
        path[ic.first + 1][ic.second] = 'D';
      }
    }
    if (ic.first - 1 >= 0 && vis[ic.first - 1][ic.second] == 0 &&
        a[ic.first - 1][ic.second] != '#') {
      vis[ic.first - 1][ic.second] = 1;
      q.push({ic.first - 1, ic.second});
      val[ic.first - 1][ic.second] = val[ic.first][ic.second] + 1;
      if (mos) {
        path[ic.first - 1][ic.second] = 'U';
      }
    }
    if (ic.second + 1 < m && vis[ic.first][ic.second + 1] == 0 &&
        a[ic.first][ic.second + 1] != '#') {
      vis[ic.first][ic.second + 1] = 1;
      q.push({ic.first, ic.second + 1});
      val[ic.first][ic.second + 1] = val[ic.first][ic.second] + 1;
      if (mos) {
        path[ic.first][ic.second + 1] = 'R';
      }
    }
    if (ic.second - 1 >= 0 && vis[ic.first][ic.second - 1] == 0 &&
        a[ic.first][ic.second - 1] != '#') {
      vis[ic.first][ic.second - 1] = 1;
      q.push({ic.first, ic.second - 1});
      val[ic.first][ic.second - 1] = val[ic.first][ic.second] + 1;
      if (mos) {
        path[ic.first][ic.second - 1] = 'L';
      }
    }
  }
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m)), path(n, vector<char>(m));
  vector<vector<ll>> val(n, vector<ll>(m, INF)), monster(n, vector<ll>(m, INF));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'A') {
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<pair<ll, ll>> q;
        q.push({i, j});
        vis[i][j] = 1;
        val[i][j] = 0;
        bfs(i, j, 1, a, vis, path, val, q);
      }
    }
  }
  vector<vector<bool>> vis(n, vector<bool>(m, 0));
  queue<pair<ll, ll>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'M') {
        q.push({i, j});
        vis[i][j] = 1;
        monster[i][j] = 0;
      }
    }
  }
  bfs(0, 0, 0, a, vis, path, monster, q);
  for (int i = 0; i < n; i++) {
    if (a[i][0] != '#') {
      if (val[i][0] < monster[i][0]) {
        cout << "YES\n";
        cout << val[i][0] << endl;
        ll ii = i, jj = 0;
        string ans;
        while (a[ii][jj] != 'A') {
          ans += path[ii][jj];
          if (path[ii][jj] == 'D') {
            ii--;
          } else if (path[ii][jj] == 'U') {
            ii++;
          } else if (path[ii][jj] == 'R') {
            jj--;
          } else if (path[ii][jj] == 'L') {
            jj++;
          }
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
        return;
      }
    }
    if (a[i][m - 1] != '#') {
      if (val[i][m - 1] < monster[i][m - 1]) {
        cout << "YES\n";
        cout << val[i][m - 1] << endl;
        ll ii = i, jj = m - 1;
        string ans;
        while (a[ii][jj] != 'A') {
          ans += path[ii][jj];
          if (path[ii][jj] == 'D') {
            ii--;
          } else if (path[ii][jj] == 'U') {
            ii++;
          } else if (path[ii][jj] == 'R') {
            jj--;
          } else if (path[ii][jj] == 'L') {
            jj++;
          }
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
        return;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (a[0][i] != '#') {
      if (val[0][i] < monster[0][i]) {
        cout << "YES\n";
        cout << val[0][i] << endl;
        ll ii = 0, jj = i;
        string ans;
        while (a[ii][jj] != 'A') {
          ans += path[ii][jj];
          if (path[ii][jj] == 'D') {
            ii--;
          } else if (path[ii][jj] == 'U') {
            ii++;
          } else if (path[ii][jj] == 'R') {
            jj--;
          } else if (path[ii][jj] == 'L') {
            jj++;
          }
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
        return;
      }
    }
    if (a[n - 1][i] != '#') {
      if (val[n - 1][i] < monster[n - 1][i]) {
        cout << "YES\n";
        cout << val[n - 1][i] << endl;
        ll ii = n - 1, jj = i;
        string ans;
        while (a[ii][jj] != 'A') {
          ans += path[ii][jj];
          if (path[ii][jj] == 'D') {
            ii--;
          } else if (path[ii][jj] == 'U') {
            ii++;
          } else if (path[ii][jj] == 'R') {
            jj--;
          } else if (path[ii][jj] == 'L') {
            jj++;
          }
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
        return;
      }
    }
  }
  cout << "NO";
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
