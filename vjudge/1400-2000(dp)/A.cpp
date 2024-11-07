#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, m, k, d;
  cin >> n >> m >> k >> d;
  vector<vector<ll>> vc(n, vector<ll>(m));
  vector<ll> val(n);
  for (int i = 0; i < n; i++) {
    vector<ll> dp(m, 1e18);
    multiset<ll> st;
    dp[0] = 1;
    st.insert(1);
    cin >> vc[i][0];
    for (int j = 1; j < m - 1; j++) {
      cin >> vc[i][j];
      dp[j] = *st.begin() + vc[i][j] + 1;
      if (st.size() > d)
        st.erase(st.find(dp[j - d - 1]));
      st.insert(dp[j]);
    }
    cin >> vc[i][m - 1];
    dp[m - 1] = *st.begin() + vc[i][m - 1] + 1;
    val[i] = dp[m - 1];
  }
  vector<ll> pre(n + 1);
  for (int i = 0; i < n; i++)
    pre[i + 1] = pre[i] + val[i];
  ll mn = 1e18;
  for (int i = 0; i + k <= n; i++) {
    mn = min(mn, pre[i + k] - pre[i]);
  }
  cout << mn << '\n';
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
