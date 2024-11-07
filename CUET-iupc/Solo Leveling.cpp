#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, p, x, a;
  cin >> n >> p >> x >> a;
  p += x;
  priority_queue<ll> q;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    q.push(-v[i]);
    if (q.size() > a) {
      ll k = q.top();
      q.pop();
      p += k;
    }
    if (p < 0) {
      cout << i << '\n';
      return;
    }
  }
  cout << n << '\n';
}
int main() {
  ios::sync_with_stdio(false);
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
