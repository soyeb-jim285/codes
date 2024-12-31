#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int LIM = 5e6 + 5;
vector<bool> isPrime(LIM, true);
vector<int> spf(LIM);
vector<ll> p_facts(LIM);
void eratosthenes() {
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i < LIM; i++) {
    if (isPrime[i]) {
      spf[i] = i;
      for (int j = 2 * i; j < LIM; j += i) {
        isPrime[j] = false;
        spf[j] = i;
      }
    }
  }
}
void init() {
  eratosthenes();
  for (int i = 2; i < LIM; i++) {
    int x = i;
    while (x > 1) {
      int y = spf[x];
      while (x % y == 0) {
        x /= y;
        p_facts[i]++;
      }
    }
  }
  for (int i = 1; i < LIM; i++) {
    p_facts[i] += p_facts[i - 1];
  }
  // for (int i = 1; i < 100; i++) {
  //   cout << i << ' ' << p_facts[i] << '\n';
  // }
}
void solve() {
  ll a, b;
  cin >> a >> b;
  cout << p_facts[a] - p_facts[b] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
