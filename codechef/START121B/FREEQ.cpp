#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 1e6 + 9;
vector<ll> primes;
vector<bool> is_prime(N, true);
void shieve() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i)
        is_prime[j] = false;
    }
  }
  for (int i = 2; i <= N; i++) {
    if (is_prime[i])
      primes.push_back(i);
  }
}
void solve() {
  ll n, sum = 0, ind = -1;
  cin >> n;
  if (n % 2) {
    cout << "1 ";
    n--;
  }
  for (int i = 0; i < sz(primes); i++) {
    if (n == 0)
      break;
    cout << primes[i] << " " << primes[i] << " ";
    n -= 2;
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  shieve();
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
