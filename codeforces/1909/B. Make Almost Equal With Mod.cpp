#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n, odd = 0, even = 0;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int k = 0; k < 64; k++) {
    map<ll, ll> mp;
    ll x = (1LL << k);
    for (int i = 0; i < n; i++) {
      ll p = a[i] % x;
      mp[p]++;
    }
    if (mp.size() == 2) {
      cout << x << endl;
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
