#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
set<string> fn(string s1, string s2) {
  set<string> ss;
  ss.insert("BG");
  ss.insert("BR");
  ss.insert("BY");
  ss.insert("GR");
  ss.insert("GY");
  ss.insert("RY");
  ss.erase(s1);
  ss.erase(s2);
  return ss;
}
ll string_to_ind(string s) {
  if (s == "BG" || s == "GB")
    return 0;
  if (s == "BR" || s == "RB")
    return 1;
  if (s == "BY" || s == "YB")
    return 2;
  if (s == "GR" || s == "RG")
    return 3;
  if (s == "GY" || s == "YG")
    return 4;
  if (s == "RY" || s == "YR")
    return 5;
  return -1;
}
ll fin(ll l, ll r, string s, vector<vector<ll>> &pre, vector<vector<ll>> &suf) {
  int ind = string_to_ind(s);
  int pl = pre[l][ind], sl = suf[l][ind];
  ll ans = 1e12;
  if (sl <= r && sl != -1)
    ans = min(ans, r - l);
  if (sl != -1)
    ans = min(ans, sl - l + sl - r);
  if (pl != -1)
    ans = min(ans, l - pl + r - pl);
  return ans;
}
void solve() {
  ll n, q;
  cin >> n >> q;
  vector<string> a(n);
  for (auto &x : a)
    cin >> x;
  vector<vector<ll>> pre(n, vector<ll>(6, -1)), suf(n, vector<ll>(6, -1));
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      pre[i] = pre[i - 1];
    }
    if (a[i] == "BG" || a[i] == "GB")
      pre[i][0] = i;
    if (a[i] == "BR" || a[i] == "RB")
      pre[i][1] = i;
    if (a[i] == "BY" || a[i] == "YB")
      pre[i][2] = i;
    if (a[i] == "GR" || a[i] == "RG")
      pre[i][3] = i;
    if (a[i] == "GY" || a[i] == "YG")
      pre[i][4] = i;
    if (a[i] == "RY" || a[i] == "YR")
      pre[i][5] = i;
    // cout << a[i] << " =\n";
    // for (int j = 0; j < 6; j++) {
    //   cout << pre[i][j] << " ";
    // }
    // cout << "\n";
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i != n - 1) {
      suf[i] = suf[i + 1];
    }
    if (a[i] == "BG" || a[i] == "GB")
      suf[i][0] = i;
    if (a[i] == "BR" || a[i] == "RB")
      suf[i][1] = i;
    if (a[i] == "BY" || a[i] == "YB")
      suf[i][2] = i;
    if (a[i] == "GR" || a[i] == "RG")
      suf[i][3] = i;
    if (a[i] == "GY" || a[i] == "YG")
      suf[i][4] = i;
    if (a[i] == "RY" || a[i] == "YR")
      suf[i][5] = i;
  }
  // for (int i = 0; i < n; i++) {
  //   cout << i << " \n";
  //   for (int j = 0; j < 6; j++) {
  //     cout << pre[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // for (int i = 0; i < n; i++) {
  //   cout << i << " \n";
  //   for (int j = 0; j < 6; j++) {
  //     cout << suf[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  while (q--) {
    ll l, r;
    cin >> l >> r;
    l--, r--;
    if (l > r)
      swap(l, r);
    set<char> s;
    s.insert(a[l][0]);
    s.insert(a[l][1]);
    s.insert(a[r][0]);
    s.insert(a[r][1]);
    if (sz(s) == 4) {
      ll aa, bb, cc, dd;
      set<string> ss = fn(a[l], a[r]);
      ll ans = 1e12;
      for (auto x : ss) {
        // cout << x << " " << fin(l, r, x, pre, suf) << "\n";
        ans = min(ans, fin(l, r, x, pre, suf));
      }
      if (ans == 1e12)
        cout << -1 << "\n";
      else
        cout << ans << "\n";
    } else {
      cout << r - l << "\n";
    }
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
