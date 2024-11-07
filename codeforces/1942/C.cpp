#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, x, y, sum = 0;
  cin >> n >> x >> y;
  vector<ll> a(x), odds, evens;
  for (int i = 0; i < x; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll ans = x - 2;
  for (int i = 0; i < x - 1; i++) {
    if ((a[i + 1] - a[i]) % 2) {
      evens.push_back(a[i + 1] - a[i] - 1);
    } else {
      odds.push_back(a[i + 1] - a[i] - 1);
    }
  }
  ll d = a[0] - a[x - 1] + n;
  if (d % 2) {
    evens.push_back(d - 1);
  } else {
    odds.push_back(d - 1);
  }
  sort(odds.begin(), odds.end());
  sort(evens.begin(), evens.end());
  // cout << y << " " << ans << "\n";
  // for (auto ic : odds)
  //   cout << ic << " ";
  // cout << "\n";
  // for (auto ic : evens)
  //   cout << ic << " ";
  // cout << "\n";
  ll od = -1, ev = -1;
  for (int i = 0; i < sz(odds); i++) {
    if (odds[i] / 2 <= y) {
      ans += odds[i];
      y -= odds[i] / 2;
      od = i;
    } else {
      break;
    }
  }
  for (int i = 0; i < sz(evens); i++) {
    if (evens[i] / 2 <= y) {
      ans += evens[i];
      y -= evens[i] / 2;
      ev = i;
    } else {
      break;
    }
  }
  if (y) {
    if (od != sz(odds) - 1) {
      ans += y * 2;
      y = 0;
    }
  }
  if (y) {
    if (ev != sz(evens) - 1) {
      ans += y * 2;
      y = 0;
    }
  }
  cout << ans << "\n";
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
