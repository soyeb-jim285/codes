#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll N = 1e7;
vector<bool> is_prime(N + 1, true);
void sieve() {
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
      for (ll j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= N; i++) {
    if (is_prime[i])
      n--;
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
