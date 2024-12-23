#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int &tt) {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> b(m), c(k);
  for (ll i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (ll i = 0; i < k; i++) {
    cin >> c[i];
  }
  if (n == k) {
    for (int i = 0; i < m; i++) {
      cout << "1";
    }
  } else if (k < n - 1) {
    for (int i = 0; i < m; i++) {
      cout << "0";
    }
  } else {
    ll dorkar = k + 1;
    for (int i = 0; i < k; i++) {
      if (c[i] != i + 1) {
        dorkar = i + 1;
        break;
      }
    }
    for (int i = 0; i < m; i++) {
      if (b[i] == dorkar) {
        cout << "1";
      } else {
        cout << "0";
      }
    }
  }
  cout << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1, tt = 0;
  cin >> t;
  bool check = 0;
  while (t--) {
    solve(tt);
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
