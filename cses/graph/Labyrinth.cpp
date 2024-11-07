#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
string ans = "";
ll const N = 1001;
vector<vector<bool>> vis(N, vector<bool>(N, false));
vector<vector<char>> a(N, vector<char>(N, '#'));
map<pair<int, int>, pair<int, int>> parent;
void path(int x1, int y1, int i, int j) {
  while (1) {
    auto [x2, y2] = parent[{x1, y1}];
    if (x1 == x2 + 1)
      ans += "D";
    if (x1 == x2 - 1)
      ans += "U";
    if (y1 == y2 + 1)
      ans += "R";
    if (y1 == y2 - 1)
      ans += "L";
    if (parent[{x1, y1}] == make_pair(i, j))
      break;
    x1 = x2, y1 = y2;
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  cout << ans << endl;
}
void bfs(int i, int j, vector<vector<char>> &a) {
  vis[i][j] = true;
  queue<pair<int, int>> q;
  q.push({i, j});
  while (!q.empty()) {
    auto [x, y] = q.front();
    // cout << x << " " << y << endl;
    q.pop();
    if (x + 1 < N && !vis[x + 1][y] && a[x + 1][y] == '.') {
      parent[{x + 1, y}] = {x, y};
      vis[x + 1][y] = true;
      q.push({x + 1, y});
    }
    if (x + 1 < N && !vis[x + 1][y] && a[x + 1][y] == 'B') {
      cout << "YES\n";
      ll x1 = x + 1, y1 = y;
      parent[{x + 1, y}] = {x, y};
      path(x1, y1, i, j);
      return;
    }
    if (x - 1 >= 0 && !vis[x - 1][y] && a[x - 1][y] == '.') {
      parent[{x - 1, y}] = {x, y};
      vis[x - 1][y] = true;
      q.push({x - 1, y});
    }
    if (x - 1 >= 0 && !vis[x - 1][y] && a[x - 1][y] == 'B') {
      cout << "YES\n";
      ll x1 = x - 1, y1 = y;
      parent[{x - 1, y}] = {x, y};
      path(x1, y1, i, j);
      return;
    }
    if (y + 1 < N && !vis[x][y + 1] && a[x][y + 1] == '.') {
      parent[{x, y + 1}] = {x, y};
      vis[x][y + 1] = true;
      q.push({x, y + 1});
    }
    if (y + 1 < N && !vis[x][y + 1] && a[x][y + 1] == 'B') {
      cout << "YES\n";
      ll x1 = x, y1 = y + 1;
      parent[{x, y + 1}] = {x, y};
      path(x1, y1, i, j);
      return;
    }
    if (y - 1 >= 0 && !vis[x][y - 1] && a[x][y - 1] == '.') {
      parent[{x, y - 1}] = {x, y};
      vis[x][y - 1] = true;
      q.push({x, y - 1});
    }
    if (y - 1 >= 0 && !vis[x][y - 1] && a[x][y - 1] == 'B') {
      cout << "YES\n";
      ll x1 = x, y1 = y - 1;
      parent[{x, y - 1}] = {x, y};
      path(x1, y1, i, j);
      return;
    }
  }
  cout << "NO\n";
}
void solve() {
  ll n, m;
  cin >> n >> m;
  pair<int, int> start;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'A')
        start = {i, j};
    }
  bfs(start.first, start.second, a);
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
