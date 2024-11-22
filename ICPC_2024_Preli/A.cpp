#include <bits/stdc++.h>
#include <bitset>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  set<ll> s;
  vector<pair<ll, ll>> vc;
  for (int i = 2; i <= 3 * n; i++) {
    for (int j = i + 1; j <= i + 10 && j <= 3 * n; j++) {
      vc.push_back({i, j});
    }
  }
  for (auto ic : vc) {
    ll a = ic.first, b = ic.second;
    ll mul = 1, sum = 0;
    set<ll> s;
    for (int i = 0; i < n; i++) {
      if (i % 2) {
        sum += a;
        mul *= a;
      } else {
        sum += b;
        mul *= b;
      }
      ll an = (mul & sum);
      s.insert(an);
    }
    if (sz(s) == n) {
      cout << n << " " << a << " " << bitset<8>(a) << " " << b << " "
           << bitset<8>(b) << "\n";
      if (b - a == 4)
        cout << "eita\n";
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
