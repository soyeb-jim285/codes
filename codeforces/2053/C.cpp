#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  ll n, k;
  cin >> n >> k;
  ll len = n, segs = 1, ans = 0, cnt = 0;
  vector<pair<ll, ll>> nums;
  while (n >= k) {
    cnt++;
    if (n % 2) {
      ll a = n / 2 + 1;
      ll sum = a;
      // cout << a << " " << sum << "-\n";
      for (int i = sz(nums) - 1; i >= 0; i--) {
        ll dd = cnt - nums[i].second - 1;
        ll dx = (1LL << dd);
        sum += sum + nums[i].first * dx;
        // cout << nums[i].first << " " << dx << " " << sum << "*-**-\n";
      }
      ans += sum;
      // cout << sum << " " << ans << " add\n";
      nums.push_back({a, cnt});
      segs = 1;
    } else {
      nums.push_back({n / 2, cnt});
      segs *= 2;
    }
    n /= 2;
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
