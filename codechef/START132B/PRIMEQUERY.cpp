#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> vc(n), pre_one(n + 1), pre_two(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  for (int i = 0; i < n; i++) {
    pre_one[i + 1] = pre_one[i] + (vc[i] == 1);
    pre_two[i + 1] = pre_two[i] + (vc[i] == 2);
  }
  ll q;
  cin >> q;
  while (q--) {
    ll l, r, k;
    cin >> l >> r >> k;
    ll ones = pre_one[r] - pre_one[l - 1];
    ll twos = pre_two[r] - pre_two[l - 1];
    ll nums = r - l + 1 - ones - twos;
    if (ones < twos)
      swap(ones, twos);
    if (ones - twos >= min(k, nums)) {
      twos += min(k, nums);
      k -= min(k, nums);
      nums -= min(k, nums);
      if (k > 0) {
        ll tot = (ones + twos) / 2;
        ll two = tot - twos;
        if (k >= two) {
          ones = ones + twos - tot;
          twos = tot;
        } else {
          ones -= k;
          twos += k;
        }
      }
    } else {
      k -= ones - twos;
      nums -= ones - twos;
      twos = ones;
      ones += min(k, nums) / 2;
      twos += min(k, nums) - min(k, nums) / 2;
    }
    cout << ones * twos << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
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
