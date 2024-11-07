#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 2e5 + 10;
vector<ll> a(N);
void fn() {
  a[0] = 1;
  ll sum = a[0];
  for (int i = 1; i < N; i++) {
    a[i] = sum + 1;
    if (sum < 1e10)
      sum += a[i];
  }
}

void solve() {
  ll n, k, x;
  cin >> n >> k >> x;
  if (a[k - 1] <= x) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  fn();
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
