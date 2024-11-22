#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll niche = 4 * (a + b + c) * (a + b + c);
  ll upor = (a + b + c) * (b + c - a) * (a + c - b) * (a + b - c);
  ll g = __gcd(niche, upor);
  niche /= g;
  upor /= g;
  cout << upor << "/" << niche << "\n";
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
