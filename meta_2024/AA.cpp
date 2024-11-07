#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> frnt, back;
vector<ll> nums;
ll rev(ll x) {
  ll ans = 0;
  while (x) {
    ans = ans * 10 + x % 10;
    x /= 10;
  }
  return ans;
}
string to_str(ll x) {
  string s;
  while (x) {
    s += char(x % 10 + '0');
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
bool is_non_decreasing(ll x) {
  string s = to_string(x);
  for (int i = 1; i < sz(s); i++) {
    if (s[i] < s[i - 1]) {
      return false;
    }
  }
  return true;
}
void numgen() {
  for (ll i = 1; i <= 88888888; i++) {
    if (is_non_decreasing(i) && i % 10 != 9) {
      frnt.push_back(i);
      back.push_back(rev(i));
    }
  }
}
ll len(ll x) {
  ll ans = 0;
  while (x) {
    ans++;
    x /= 10;
  }
  return ans;
}
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
void allnums() {
  numgen();
  for (int i = 1; i < 10; i++) {
    nums.push_back(i);
  }
  for (int i = 0; i < sz(frnt); i++) {
    ll ln = len(frnt[i]);
    ll lst = frnt[i] % 10;
    for (ll j = lst + 1; j < 10; j++) {
      for (ll k = 0; k < sz(back); k++) {
        if (len(back[k]) > ln)
          break;
        if (len(back[k]) == ln) {
          ll rv = rev(back[k]);
          ll fst = rv % 10;
          if (fst < j) {
            ll ans = frnt[i] * 10 + j;
            ans = ans * binpow(10, ln) + back[k];
            nums.push_back(ans);
          }
        }
      }
    }
  }
}
void solve() {
  ll l, h, m;
  cin >> l >> h >> m;
  ll ans = 0;
  for (ll x : nums) {
    if (x >= l && x <= h) {
      if (x % m == 0) {
        // cout << x << endl;

        ans++;
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  allnums();
  // cout << sz(frnt) << " " << sz(back) << endl;
  // cout << sz(nums) << endl;
  // for (auto x : frnt)
  //   cout << x << endl;
  // for (auto x : nums)
  //   cout << x << endl;
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
