#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
typedef complex<long long> point;
typedef long long ll;

const int N = 1e5 + 10;
int M = 1e9 + 7;
const long long INF = 1e16;

// #define int long long

int saved[10001][10001];
int n, q;
vector<tuple<int, int, int>> v;

int dp(int ind, int balance) {
  if (ind == n)
    return 0;
  if (saved[ind][balance] != -1)
    return saved[ind][balance];
  int ans = dp(ind + 1, balance);
  auto [t, req, coin] = v[ind];
  if (balance >= req)
    ans = max(ans, dp(ind + 1, balance - req) + coin);
  return saved[ind][balance] = ans;
}

void solve() {
  memset(saved, -1, sizeof(saved));
  cin >> n >> q;
  vector<int> tm;
  for (int i = 0; i < n; i++) {
    int c, m, t;
    cin >> c >> m >> t;
    tm.push_back(t);
    v.emplace_back(t, m, c);
  }
  sort(tm.begin(), tm.end());
  sort(v.begin(), v.end());
  while (q--) {
    int m, b;
    cin >> m >> b;
    int tmp = lower_bound(tm.begin(), tm.end(), m + 1) - tm.begin();
    cout << dp(tmp, b) << "\n";
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
