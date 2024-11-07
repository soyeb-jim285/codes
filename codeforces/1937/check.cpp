#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  vector<ll> a = {0, 1, 2, 3, 4};
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      for (int ii = 0; ii < 5; ii++) {
        for (int jj = 0; jj < 5; jj++) {
          cout << i << " " << j << " " << ii << " " << jj << " "
               << (a[i] | a[j]) << " " << (a[ii] | a[jj]) << endl;
          if ((a[i] | a[j]) > (a[ii] | a[jj]))
            cout << ">" << endl;
          else if ((a[i] | a[j]) < (a[ii] | a[jj]))
            cout << "<" << endl;
          else
            cout << "=" << endl;
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
