#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll fc(ll n) {
  ll k = n;
  for (int i = 2; i * i <= n; i++) {
    ll cnt = 0;
    if (n % i == 0) {
      while (n % i == 0) {
        cnt++;
        n /= i;
        if (cnt == 2) {
          k /= (i * i);
          cnt = 0;
        }
      }
    }
  }
  return k;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  map<ll, ll> mp;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 0)
      a[i] = fc(a[i]);
    mp[a[i]]++;
  }
  for (auto it : mp) {
    ans += it.second * (it.second - 1) / 2;
  }
  ans += (mp[0] * (n - mp[0]));
  cout << ans << endl;
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
