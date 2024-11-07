#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int dp[1001][100001];
int fn(int indx, int money, vector<int> &pages, vector<int> &cost) {
  if (dp[indx][money] != -1)
    return dp[indx][money];
  int n = pages.size();
  if (money <= 0 || indx >= n)
    return dp[indx][money] = 0;
  int ans = fn(indx + 1, money, pages, cost);
  if (money >= cost[indx])
    ans = max(ans, pages[indx] + fn(indx + 1, money - cost[indx], pages, cost));
  return dp[indx][money] = ans;
}
void solve() {
  memset(dp, -1, sizeof(dp));
  int n, money;
  cin >> n >> money;
  vector<int> pages(n), cost(n);
  for (auto &x : cost)
    cin >> x;
  for (auto &x : pages)
    cin >> x;
  cout << fn(0, money, pages, cost) << "\n";
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
