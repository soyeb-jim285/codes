#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define sz(a) ((int)((a).size()))

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  for (ll i = 0; i < n; i++)
    cin >> a[i];
  for (ll i = 0; i < m; i++)
    cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
