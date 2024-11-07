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
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < n; j++) {
        if (j % 2)
          cout << "..";
        else
          cout << "##";
      }
      cout << "\n";
      for (int j = 0; j < n; j++) {
        if (j % 2)
          cout << "..";
        else
          cout << "##";
      }
      cout << "\n";
    } else {
      for (int j = 0; j < n; j++) {
        if (j % 2 == 0)
          cout << "..";
        else
          cout << "##";
      }
      cout << "\n";
      for (int j = 0; j < n; j++) {
        if (j % 2 == 0)
          cout << "..";
        else
          cout << "##";
      }
      cout << "\n";
    }
  }
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
