#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool almostPrime(ll n) {
  ll cnt = 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      cnt++;
    }
  }
  if (n > 1)
    cnt++;
  return cnt == 2;
}
void solve() {
  ll n;
  cin >> n;
  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (almostPrime(i))
      cnt++;
  }
  cout << cnt << endl;
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
