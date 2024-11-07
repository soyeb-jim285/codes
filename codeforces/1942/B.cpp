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
  vector<ll> a(n), ans(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool zero = false;
  ll mex = -1;
  set<ll> s;
  if (a[0] < 0) {
    cout << -a[0] << " ";
    s.insert(-a[0]);
    mex = 0;
  } else {
    cout << 0 << " ";
    zero = true;
    s.insert(0);
    mex = 1;
  }
  for (int i = 1; i < n; i++) {
    if (zero) {
      if (a[i] < 0) {
        cout << mex - a[i] << " ";
        s.insert(mex - a[i]);
      } else {
        cout << mex << " ";
        s.insert(mex);
        for (int j = mex + 1; j <= n; j++) {
          if (s.find(j) == s.end()) {
            mex = j;
            break;
          }
        }
      }
    } else {
      if (a[i] < 0) {
        cout << -a[i] << " ";
        s.insert(-a[i]);
      } else {
        cout << 0 << " ";
        s.insert(0);

        for (int j = mex + 1; j <= n; j++) {
          if (s.find(j) == s.end()) {
            mex = j;
            break;
          }
        }
        zero = true;
      }
    }
  }
  cout << "\n";
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
