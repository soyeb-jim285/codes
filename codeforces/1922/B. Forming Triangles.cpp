#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  map<ll, ll> mp;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  vector<ll> ind;
  for (auto ic : mp) {
    ind.push_back(ic.second);
  }
  ll ans = 0, sum = 0;
  for (int i = 0; i < ind.size(); i++) {
    ll p = (ind[i] * (ind[i] - 1) * (ind[i] - 2)) / 6;
    ans += p;
    ll k = ind[i] * (ind[i] - 1) / 2;
    ans += sum * k;
    sum += ind[i];
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
