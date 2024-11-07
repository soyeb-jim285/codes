#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll fn(vector<ll> a, ll pos) {
  ll cnt = 0, mx = a[0];
  for (int i = 0; i < sz(a) - 1; i++) {
    mx = max(mx, a[i + 1]);
    if (mx == a[pos])
      cnt++;
  }
  return cnt;
}
void solve() {
  ll n, pos, ind;
  cin >> n >> pos;
  vector<ll> a(n);
  pos--;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (i == pos)
      continue;
    if (a[i] > a[pos]) {
      ind = i;
      break;
    }
  }
  vector<ll> b = a;
  swap(b[pos], b[ind]);
  swap(a[pos], a[0]);
  cout << max(fn(a, 0), fn(b, ind)) << '\n';
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
