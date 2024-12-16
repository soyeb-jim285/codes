#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll lcm(vector<ll> &a) {
  ll res = 1;
  for (ll x : a) {
    res = res / __gcd(res, x) * x;
  }
  return res;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  vector<ll> pref(n + 1), suf(n + 1);
  for (int i = 0; i < n; i++)
    pref[i + 1] = __gcd(pref[i], a[i]);
  for (int i = n - 1; i >= 0; i--)
    suf[i] = __gcd(suf[i + 1], a[i]);
  vector<ll> gcds(n);
  for (int i = 0; i < n; i++)
    gcds[i] = __gcd(pref[i], suf[i + 1]);
  cout << lcm(gcds) << '\n';
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
