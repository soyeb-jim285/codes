#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string s;
  cin >> s;
  for (int i = 0; i < sz(s); i++) {
    ll mx = -1, ind = -1;
    for (int j = i; j < min(sz(s), i + 9); j++) {
      ll val = s[j] - '0' - (j - i);
      if (val > mx) {
        mx = val;
        ind = j;
      }
    }
    if (ind == -1) {
      continue;
    }
    for (int j = ind; j > i; j--) {
      s[j] = s[j - 1];
    }
    s[i] = mx + '0';
  }
  cout << s << endl;
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
