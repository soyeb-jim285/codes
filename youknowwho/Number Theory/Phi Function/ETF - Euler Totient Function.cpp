#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll const N = 1e6 + 1;
vector<ll> phi(N);

void phis() {
  rep(i, 0, N) phi[i] = i;
  rep(i, 2, N) {
    if (phi[i] == i) {
      for (ll j = i; j < N; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
}

void solve() {
  ll n;
  cin >> n;
  cout << phi[n] << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  phis();
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
