#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 1e7 + 1;
vector<ll> phi(N);
void pre() {
  iota(phi.begin(), phi.end(), 0);
  phi[1] = 0;
  for (ll i = 2; i < N; i++) {
    if (phi[i] == i) {
      for (ll j = i; j < N; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
}
void solve() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll ans = 0;
  for (ll i = a; i <= b; i++) {
    ans += phi[i] * (d / i - (c - 1) / i);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  pre();
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
