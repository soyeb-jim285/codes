#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, sum = 0;
  cin >> n;
  vector<ll> a(n);
  ll ones = 0, two = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = a[i] % 3;
    if (a[i] == 1) {
      ones++;
    } else if (a[i] == 2) {
      two++;
    }
    sum += a[i];
  }
  if (sum % 3 == 2) {
    cout << "1\n";
    return;
  }
  if (sum % 3 == 0) {
    cout << "0\n";
    return;
  }
  if (ones) {
    cout << "1\n";
  } else {
    cout << "2\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
