#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
pair<int, int> mv(int x1, int y1, int ph) {}
ll fn(int xi, int yi, int xf, int yf, int ph, int k,
      vector<vector<char>> &grid) {
  int n = grid.size(), m = grid[0].size();
  if (xi < 0 || xi >= n || yi < 0 || yi >= m || k < 0) {
    return 1e9;
  }
}
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> grid(n, vector<char>(m));
  int x1, y1, x2, y2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'B') {
        x1 = i, y1 = j;
      }
      if (grid[i][j] == 'P') {
        x2 = i, y2 = j;
      }
    }
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
