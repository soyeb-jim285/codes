#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  string s;
  cin >> s;
  if (s == "Red") {
    cout << min(b, c) << endl;

  } else if (s == "Green") {
    cout << min(a, c) << endl;

  } else {
    cout << min(a, b) << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
