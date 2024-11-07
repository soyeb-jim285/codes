#include <bits/stdc++.h>
#include <strings.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> nums(13), sum(13);
void fn() {
  nums[0] = 1, nums[1] = 9, nums[2] = 81;
  for (int i = 3; i < 13; i++) {
    nums[i] = nums[i - 1] * 8 + nums[i - 2] * 9;
  }
  for (int i = 1; i < 13; i++) {
    sum[i] = sum[i - 1] + nums[i];
  }
}
ll len(ll n) {
  ll ans = 0;
  while (n > 0) {
    n /= 10;
    ans++;
  }
  return ans;
}
ll num(ll k) {
  if (k < 0)
    return 0;
  else
    return nums[k];
}
ll index(ll n) {
  ll ln = len(n);
  if (ln == 1)
    return n;
  ll ans = sum[ln - 1];
  string s = "";
  while (n > 0) {
    s += (n % 10) + '0';
    n /= 10;
  }
  reverse(s.begin(), s.end());
  ll lst = -1;
  for (int i = 0; i < sz(s); i++) {
    ll k = s[i] - '0';
    if (k == 0) {
      lst = k;
      continue;
    }
    if (i == sz(s) - 1) {
      if (k >= lst)
        ans += k - 1;
      else
        ans += k;
      break;
    }
    if (i == 0) {
      ans += (k - 1) * num(ln - 1) * 8 / 9 + (k - 1) * num(ln - 2);
    } else {
      if (lst < k) {
        ans += num(ln - 1 - i) +
               (k - 2) * (num(ln - 1 - i) * 8 / 9 + num(ln - 2 - i));
      } else {
        ans += num(ln - 1 - i) +
               (k - 1) * (num(ln - 1 - i) * 8 / 9 + num(ln - 2 - i));
      }
    }
    lst = k;
  }
  return ans + 1;
}
void solve() {
  ll n;
  cin >> n;
  ll l = 1, r = 1e12;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (index(mid) >= n) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  fn();
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
