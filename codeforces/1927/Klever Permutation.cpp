#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> ans(n);
  ll rem = n % k;
  ll div = ceil(1.0 * n / k);
  ll ct = 1;
  for (int i = 0; i < k; i++) {
    if (i == rem && rem != 0)
      div--;
    if (i % 2 == 0) {
      for (int j = 0; j < div; j++) {
        ans[j * k + i] = ct;
        ct++;
      }
    } else {
      for (int j = div - 1; j >= 0; j--) {
        ans[j * k + i] = ct;
        ct++;
      }
    }
  }
  for (auto ic : ans) {
    cout << ic << ' ';
  }
  cout << "\n";
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
