#include <bits/stdc++.h>
using namespace std;
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<vector<ll>> b(n, vector<ll>(61, 0));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ll ct = 0;
    while (a[i]) {
      b[i][ct] = a[i] % 2;
      a[i] /= 2;
      ct++;
    }
  }
  vector<ll> ans(61, 0);
  bool paisi = 0, even = 0;
  for (int i = 61 - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      ans[i] += b[j][i];
    }
  }
  bool done = 0;
  ll evn_cnt = 0;
  for (int i = 61 - 1; i >= 0; i--) {
    if (paisi) {
      if (ans[i] % 2 == 0) {
        evn_cnt++;
      }
      if (i - 1 >= 0)
        ans[i] = 1;
      continue;
    }
    if (ans[i] % 2 == 0 && ans[i] > 0) {
      paisi = 1;
      if (i - 1 >= 0)
        ans[i] = 1;
    }
  }
  if (evn_cnt % 2) {
    ans[0] = 0;
  }
  ll val = 0;
  for (int i = 0; i < 61; i++) {
    if (ans[i] % 2)
      val += (1LL << i);
  }
  cout << val << "\n";
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
