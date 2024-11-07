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
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  vector<char> ans(n, '#');
  char x = 'a';
  ll ct = 0;
  bool lp = 1;
  while (lp) {
    for (int i = 0; i < n; i++) {
      if (vc[i] == ct) {
        ans[i] = x;
        vc[i] = -1;
        ct++;
      }
    }
    if (!ct)
      lp = 0;
    ct = 0;
    x++;
  }
  for (auto ic : ans) {
    cout << ic;
  }
  cout << '\n';
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
