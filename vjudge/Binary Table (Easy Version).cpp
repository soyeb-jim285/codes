#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void fn(ll a1, ll b1, ll a2, ll b2, ll a3, ll b3, vector<string> &a,
        vector<vector<ll>> &ans) {
  ans.push_back({a1 + 1, b1 + 1, a2 + 1, b2 + 1, a3 + 1, b3 + 1});
  a[a1][b1] = a[a1][b1] == '0' ? '1' : '0';
  a[a2][b2] = a[a2][b2] == '0' ? '1' : '0';
  a[a3][b3] = a[a3][b3] == '0' ? '1' : '0';
}
ll gch(char x) { return x - '0'; }
void gen(int i, int j, vector<string> &a, vector<vector<ll>> &ans) {
  if (a[i][j] == '1' && a[i + 1][j] == '1') {
    if (a[i][j + 1] == '1' && a[i + 1][j + 1] == '1') {
      fn(i, j, i + 1, j, i + 1, j + 1, a, ans);
      fn(i, j + 1, i + 1, j, i + 1, j + 1, a, ans);
      fn(i, j, i, j + 1, i + 1, j, a, ans);
      fn(i, j, i, j + 1, i + 1, j + 1, a, ans);
    } else if (a[i][j + 1] == '1' && a[i + 1][j + 1] == '0') {
      fn(i, j, i, j + 1, i + 1, j, a, ans);
    } else if (a[i][j + 1] == '0' && a[i + 1][j + 1] == '1') {
      fn(i, j, i + 1, j, i + 1, j + 1, a, ans);
    } else {
      fn(i, j, i, j + 1, i + 1, j + 1, a, ans);
      fn(i, j + 1, i + 1, j, i + 1, j + 1, a, ans);
    }
  } else if (a[i][j] == '1' && a[i + 1][j] == '0') {
    if (a[i][j + 1] == '1' && a[i + 1][j + 1] == '1') {
      fn(i, j, i, j + 1, i + 1, j + 1, a, ans);
    } else if (a[i][j + 1] == '1' && a[i + 1][j + 1] == '0') {
      fn(i, j, i + 1, j + 1, i + 1, j, a, ans);
      fn(i, j + 1, i + 1, j, i + 1, j + 1, a, ans);
    } else if (a[i][j + 1] == '0' && a[i + 1][j + 1] == '1') {
      fn(i, j, i, j + 1, i + 1, j, a, ans);
      fn(i, j + 1, i + 1, j, i + 1, j + 1, a, ans);
    } else {
      fn(i, j, i + 1, j, i + 1, j + 1, a, ans);
      fn(i, j, i, j + 1, i + 1, j + 1, a, ans);
      fn(i, j, i, j + 1, i + 1, j, a, ans);
    }
  } else if (a[i][j] == '0' && a[i + 1][j] == '1') {

    if (a[i][j + 1] == '1' && a[i + 1][j + 1] == '1') {
      fn(i, j + 1, i + 1, j, i + 1, j + 1, a, ans);
    } else if (a[i][j + 1] == '1' && a[i + 1][j + 1] == '0') {
      fn(i, j, i, j + 1, i + 1, j + 1, a, ans);
      fn(i, j, i + 1, j, i + 1, j + 1, a, ans);
    } else if (a[i][j + 1] == '0' && a[i + 1][j + 1] == '1') {
      fn(i, j, i, j + 1, i + 1, j, a, ans);
      fn(i, j, i, j + 1, i + 1, j + 1, a, ans);
    } else {
      fn(i, j + 1, i + 1, j, i + 1, j + 1, a, ans);
      fn(i, j, i, j + 1, i + 1, j, a, ans);
      fn(i, j, i + 1, j, i + 1, j + 1, a, ans);
    }
  } else {

    if (a[i][j + 1] == '1' && a[i + 1][j + 1] == '1') {
      fn(i, j, i, j + 1, i + 1, j, a, ans);
      fn(i, j, i + 1, j, i + 1, j + 1, a, ans);

    } else if (a[i][j + 1] == '1' && a[i + 1][j + 1] == '0') {
      fn(i, j + 1, i + 1, j, i + 1, j + 1, a, ans);
      fn(i, j, i, j + 1, i + 1, j, a, ans);
      fn(i, j, i, j + 1, i + 1, j + 1, a, ans);
    } else if (a[i][j + 1] == '0' && a[i + 1][j + 1] == '1') {
      fn(i, j, i + 1, j, i + 1, j + 1, a, ans);
      fn(i, j, i, j + 1, i + 1, j + 1, a, ans);
      fn(i, j + 1, i + 1, j, i + 1, j + 1, a, ans);
    }
  }
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<string> a(n);
  vector<vector<ll>> ans;
  for (ll i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      ll p = gch(a[i][j]) + gch(a[i + 1][j]) + gch(a[i][j + 1]) +
             gch(a[i + 1][j + 1]);
      if (p == 3)
        gen(i, j, a, ans);
    }
  }
  for (int i = 0; i < n - 1; i += 2) {
    for (int j = 0; j < m - 1; j += 2) {
      gen(i, j, a, ans);
    }
    if (a[i][m - 1] == '1' && a[i + 1][m - 1] == '1') {
      fn(i, m - 1, i, m - 2, i + 1, m - 2, a, ans);
      fn(i + 1, m - 1, i + 1, m - 2, i, m - 2, a, ans);
    } else if (a[i][m - 1] == '1' && a[i + 1][m - 1] == '0') {
      fn(i, m - 1, i, m - 2, i + 1, m - 1, a, ans);
      fn(i, m - 2, i + 1, m - 2, i, m - 1, a, ans);
      fn(i, m - 1, i + 1, m - 1, i + 1, m - 2, a, ans);
    } else if (a[i][m - 1] == '0' && a[i + 1][m - 1] == '1') {
      fn(i, m - 1, i + 1, m - 1, i + 1, m - 2, a, ans);
      fn(i, m - 2, i + 1, m - 1, i + 1, m - 2, a, ans);
      fn(i, m - 1, i, m - 2, i + 1, m - 1, a, ans);
    }
  }
  for (int i = 0; i < m - 1; i += 2) {
    if (a[n - 1][i] == '1' && a[n - 1][i + 1] == '1') {
      fn(n - 2, i, n - 2, i + 1, n - 1, i, a, ans);
      fn(n - 2, i, n - 2, i + 1, n - 1, i + 1, a, ans);
    } else if (a[n - 1][i] == '1' && a[n - 1][i + 1] == '0') {
      fn(n - 2, i, n - 1, i, n - 1, i + 1, a, ans);
      fn(n - 2, i + 1, n - 1, i, n - 1, i + 1, a, ans);
      fn(n - 2, i, n - 2, i + 1, n - 1, i, a, ans);
    } else if (a[n - 1][i] == '0' && a[n - 1][i + 1] == '1') {
      fn(n - 2, i, n - 1, i, n - 1, i + 1, a, ans);
      fn(n - 2, i, n - 2, i + 1, n - 1, i + 1, a, ans);
      fn(n - 2, i + 1, n - 1, i + 1, n - 1, i, a, ans);
    }
  }
  if (a[n - 1][m - 1] == '1') {
    fn(n - 2, m - 2, n - 2, m - 1, n - 1, m - 1, a, ans);
    fn(n - 2, m - 2, n - 1, m - 2, n - 1, m - 1, a, ans);
    fn(n - 2, m - 1, n - 1, m - 2, n - 1, m - 1, a, ans);
  }
  cout << ans.size() << "\n";
  for (auto ic : ans) {
    for (auto jc : ic)
      cout << jc << " ";
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
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
