#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 1e5 + 10;
vector<bool> is_prime(N, true), nums(N, false), grps(N, false);
vector<int> primes;
void sieve() {
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i < N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (ll j = i * i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    nums[x] = true;
  }
  ll ans = 0;
  for (auto p : primes) {
    // cout << p << "\n";
    bool paisi = 0, agei = 0;
    for (int i = p; i < N; i += p) {
      if (nums[i]) {
        paisi = 1;
        if (grps[i]) {
          agei = 1;
        } else {
          grps[i] = 1;
        }
      }
    }
    if (paisi) {
      ans++;
    }
    if (agei)
      ans--;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve();
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
