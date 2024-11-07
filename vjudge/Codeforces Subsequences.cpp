#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
void solve() {
  ll n;
  cin >> n;
  ll k = 1;
  for (int i = 1; i <= n; i++) {
    ll ans = binpow(i, 10);
    if (ans > n) {
      break;
    }
    k = i;
  }
  ll ind = -1;
  for (int i = 0; i <= 10; i++) {
    ll sum = binpow(k, 10 - i) * binpow(k + 1, i);
    if (sum >= n) {
      ind = i;
      break;
    }
  }
  string cd = "codeforces";
  for (int i = 0; i < (int)cd.size(); i++) {
    if (i < ind) {
      for (int j = 0; j < k + 1; j++) {
        cout << cd[i];
      }
    } else {
      for (int j = 0; j < k; j++) {
        cout << cd[i];
      }
    }
  }
  cout << endl;
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
