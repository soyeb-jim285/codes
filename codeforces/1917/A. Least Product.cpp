#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  ll neg = 0;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if (x < 0)
      neg++;
  }
  if (neg % 2)
    cout << "0\n";
  else
    cout << "1\n1 0\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
