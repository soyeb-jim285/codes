#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const mod = 998244353;
ll ans[80];
ll fact[100];
void fc() {
  fact[0] = 1;
  for (ll i = 1; i < 100; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
}
void fn(ll fst, ll sec, ll lst, vector<ll> &a) {
  ll n = a.size();
  ll d = a[sec] - a[fst];
  ll lst_val = a[lst], sz = (lst_val - a[fst]) / d + 1;
  for (ll k = lst + 1; k < n; k++) {
    if (a[k] - lst_val == d) {
      // cout << sz << " " << a[fst] << " " << a[sec] << " " << a[lst] << " "
      //      << a[k] << " " << a[k] - a[lst] << " " << d << endl;
      fn(fst, sec, k, a);
      ans[sz] = (ans[sz] + 1) % mod;
    }
  }
}
ll ncr(ll n, ll r) { return (fact[n] * ((fact[r] * fact[n - r]) % mod)) % mod; }
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  multiset<ll> s;
  map<ll, ll> cnt;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
    cnt[a[i]]++;
  }
  ans[0] = n;
  ans[1] = n * (n - 1) / 2;
  for (auto ic : cnt) {
    ll cntt = ic.second;
    for (int i = 2; i < cntt; i++) {
      ans[i] = (ans[i] + ncr(cntt, i)) % mod;
    }
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      if (a[j] - a[i] == 0) {
        continue;
      }
      fn(i, j, j, a);
    }
  }
  for (ll i = 0; i < n; i++) {
    cout << ans[i] << " ";
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
