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
  vector<string> vc(n);
  vector<bool> indx(k);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
    ll cnt = 0, ind = -1;
    for (int j = 0; j < k; j++) {
      if (vc[i][j] == '1') {
        cnt++;
        ind = j;
      }
    }
    if (cnt == 1) {
      indx[ind] = true;
    }
  }
  bool ans = 1;
  for (auto ic : indx) {
    ans &= ic;
  }
  if (ans)
    cout << "YES\n";
  else
    cout << "NO\n";
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
