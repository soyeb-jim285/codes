#include <bits/stdc++.h>
#include <deque>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  ll n, k, num = 1;
  cin >> n >> k;
  vector<ll> ans(n, -1);
  for (int i = k - 1; i < n; i += k) {
    ans[i] = num++;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (ans[i] == -1) {
      ans[i] = num++;
    }
  }
  for (auto x : ans)
    cout << x << " ";
  cout << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
