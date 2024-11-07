#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool has2(ll n) {
  while (n) {
    if (n % 3 == 2)
      return true;
    n /= 3;
  }
  return false;
}
void solve() {
  ll n;
  cin >> n;
  ll k = 1, cuto = 0;
  while (k < n) {
    cuto = k;
    k = 3 * k + 1;
  }
  k++;
  cuto *= 2;
  // cout << k << " " << cuto << "\n";
  vector<ll> ans(n);
  for (int i = 0; i < n; i++) {
    ans[i] = i + 1;
  }
  if (has2(n + 1)) {
    reverse(ans.begin(), ans.end());
    for (auto ic : ans)
      cout << ic << " ";
    cout << "\n";
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    if (has2(ans[0] + ans[i]) && has2(ans[n - 1] + ans[i + 1])) {
      // cout << i << "-*-";
      for (int ii = i; ii >= 0; ii--) {
        cout << ans[ii] << " ";
      }
      for (int ii = n - 1; ii > i; ii--) {
        cout << ans[ii] << " ";
      }
      // reverse(ans.begin(), ans.begin() + i);
      // reverse(ans.begin() + i, ans.end());
      break;
    }
  }
  // for (int i = 0; i < n; i++) {
  //   if (n + i + 1 < k) {
  //     if (ans[i] == i + 1 && ans[cuto - (i + 1) - 1] == i + 1)
  //       swap(ans[i], ans[cuto - (i + 1) - 1]);
  //   }
  // }
  // for (auto ic : ans)
  //   cout << ic << " ";
  // cout << "\n";
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
