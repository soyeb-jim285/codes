#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
typedef complex<long double> point;
#define x real()
#define y imag()
ll setbit(ll mask, int i) { return mask | (1LL << i); }
ll unsetbit(ll mask, int i) { return mask & ~(1LL << i); }
bool checkbit(ll mask, int i) { return mask & (1LL << i); }
struct line {
  ld a, b, c;
};
line make_line(point slope, point p) {
  return {slope.y, -slope.x, slope.x * p.y - slope.y * p.x};
}
ld det(ld a, ld b, ld c, ld d) { return a * d - b * c; }
point intersection(line l1, line l2) {
  ld zn = det(l1.a, l1.b, l2.a, l2.b);
  return point(-det(l1.c, l1.b, l2.c, l2.b) / zn,
               -det(l1.a, l1.c, l2.a, l2.c) / zn);
}
ll fn(ll mask, int n, point p, point m, vector<point> &v, vector<ll> &dp) {
  if (mask == (1LL << n) - 1)
    return 0;
  if (dp[mask] != -1)
    return dp[mask];
  for (int i = 0; i < n; i++) {
    if (!checkbit(mask, i))
      for (int j = 0; j < n; j++) {
        if (i != j && !checkbit(mask, i)) {
          line l1 = make_line(m, v[i]);
          point m2 = point(-m.y, m.x);
          line l2 = make_line(m2, v[j]);
          point inter = intersection(l1, l2);
          dp[mask][i] = min(dp[mask][i], dp[mask ^ (1LL << i)[j]])
        }
      }
  }
  return dp[mask];
}
void solve() {
  ll n;
  cin >> n;
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    ll px, py;
    cin >> px >> py;
    p[i] = point(px, py);
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
