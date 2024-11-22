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
  cout << "1 10" << endl;
  ll o, oz, oo;
  cin >> oz;
  cout << "1 1" << endl;
  cin >> o;
  cout << "1 11" << endl;
  cin >> oo;
  ll go = o - oo;
  if (oz == go) {
    cout << "0 " << n << " 0" << endl;
  } else {
    cout << "0 " << n << " 1" << endl;
  }
  ll ans;
  cin >> ans;
}
int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
