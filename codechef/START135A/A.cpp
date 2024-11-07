#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll a, b, k;
  cin >> a >> b >> k;
  ll ct = 0;
  while (b > a) {
    if (b % k == 0) {
      if (b / k < a) {
        ct += b - a;
        b = a;
        break;
      }
      b /= k;
      ct++;
    } else {
      ll rem = b % k;
      if (b - rem < a) {
        ct += b - a;
        b = a;
        break;
      }
      b -= rem;
      ct += rem;
    }
  }
  cout << ct << '\n';
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
