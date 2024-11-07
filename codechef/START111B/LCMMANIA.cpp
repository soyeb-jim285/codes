#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  ll ct = 0;
  while (n % 2 == 0) {
    n /= 2;
    ct++;
  }
  ct = 1 << ct;
  if (n == 1)
    cout << "-1\n";
  else
    cout << ct * (n - 1) / 2 << " " << ct << " " << ct << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
