#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct pt {
  ll x, y;
};
ll area(vector<pt> a) {
  ll res = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    int j = (i + 1) % (int)a.size();
    res += a[i].x * a[j].y - a[i].y * a[j].x;
  }
  return abs(res);
}
void solve() {
  ll n;
  cin >> n;
  vector<pt> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  cout << area(a) << '\n';
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
