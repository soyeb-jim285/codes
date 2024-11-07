#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k;
  cin >> n >> k;
  ll sum = 0, last_sum = 0, p = 2, ct = 0;
  while (sum < k) {
    last_sum = sum;
    sum += ceil(1.0 * n / p);
    cout << sum << " " << p << endl;
    p *= 2LL;
    ct++;
    if (sum == k)
      ct++;
  }
  sum = last_sum;
  cout << sum << " " << ct << endl;
  ll pp = k - sum;
  cout << ct * (2 * pp - 1) << endl;
}
int main() {
  /* ios::sync_with_stdio(false); */
  /* cin.tie(nullptr); */
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
