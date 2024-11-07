#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n = 1e5, m = 1e5;
  cout << n << " " << m << "\n";
  // for (int i = 0; i < n; i++) {
  //   cout << rnd() % 10 << " ";
  // }
  // cout << "\n";
  for (int i = 0; i < m; i++) {
    int type = rnd() % 2 + 1;
    cout << type << " ";
    if (type == 2) {
      int l = rnd() % n + 1, r = rnd() % n + 1;
      if (l > r)
        swap(l, r);
      cout << l << " " << r << "\n";
    } else {
      int l = rnd() % n + 1, r = rnd() % n + 1;
      if (l > r)
        swap(l, r);
      cout << l << " " << r << "\n";
      ll b = rnd() % 10 + 1;
      cout << b << "\n";
    }
  }
  // cout << 1 << " " << 0 << " " << n << "\n";
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
