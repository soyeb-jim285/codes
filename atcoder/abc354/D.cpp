#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a == c || b == d) {
    cout << 0 << "\n";
    return;
  }
  ll arem = a % 4;
  if (arem < 0)
    arem += 4;
  ll brem = b % 2;
  if (brem < 0)
    brem += 2;
  if (a < 0) {
    c -= a;
    a = 0;
    a += arem;
    c += arem;
  }
  if (b < 0) {
    d -= b;
    b = 0;
    b += brem;
    d += brem;
  }
  ll fst, secd;
  ll p = (c - a) / 4;
  fst = 4 * p;
  secd = fst;
  ll rem = (c - a) % 4;
  vector<ll> vals = {2, 1, 0, 1};
  vector<ll> vals2 = {1, 2, 1, 0};
  // cout << a << " " << b << " " << c << " " << d << "\n";
  for (int i = 0; i < rem; i++) {
    ll k = a % 4;
    // if (k < 0)

    fst += vals[(i + k) % 4];
    secd += vals2[(i + k) % 4];
  }
  if (b % 2) {
    swap(fst, secd);
  }
  // cout << fst << " " << secd << "\n";
  // cout << fst << " " << secd << "\n";
  ll area = 0;
  if ((d - b) % 2) {
    // cout << d - b - 1 << "\n";
    // cout << fst << " " << secd << "\n";
    area = (fst + secd) * ((d - b - 1LL) >> 1) + fst;
  } else {
    area = (fst + secd) * (d - b) / 2;
  }
  cout << area << "\n";
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
