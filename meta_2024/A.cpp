#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> nums;
ll string_to_int(string s) {
  ll ans = 0;
  for (char c : s) {
    ans = ans * 10 + c - '0';
  }
  return ans;
}
void numgen() {
  for (int len = 1; len <= 18; len += 2) {
    for (int low = 1; low <= (18 - len) / 2 + 1; low++) {
      string s = "";
      for (int nm = low; nm < len / 2 + low; nm++) {
        s += char(nm + '0');
      }
      for (int i = len / 2 + low; i >= low; i--) {
        s += char(i + '0');
      }
      nums.push_back(string_to_int(s));
      s.clear();
    }
  }
}
void solve() {
  ll ans = 0;
  ll low, high, m;
  cin >> low >> high >> m;
  for (int i = 0; i < sz(nums); i++) {
    ll num = nums[i];
    if (num >= low && num <= high) {
      if (num % m == 0) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  numgen();
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case #" << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
