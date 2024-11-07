#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> fact(22, 1);
void fc() {
  for (int i = 1; i < 22; i++) {
    fact[i] = fact[i - 1] * i * 1LL;
  }
}

void solve() {
  ll n, k, m;
  cin >> n >> k >> m;
  if (k == 0) {
    cout << "0\n";
    return;
  }
  if (n - k - m < 0) {
    cout << "1\n";
    return;
  }
  if (n - m < 0) {
    cout << "1\n";
    return;
  }
  ld one = 1.0;
  ld up = 1.0 * fact[n - k] / (fact[m] * fact[n - k - m]);
  ld down = 1.0 * fact[n] / (fact[m] * fact[n - m]);
  cout << one - up / down << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(4);
  fc();
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
