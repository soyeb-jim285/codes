#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  if (is_sorted(a.begin(), a.end())) {
    cout << 0 << '\n';
  }
  vector<ll> b = a;
  sort(b.begin(), b.end());
  priority_queue<ll, vector<ll>, greater<ll>> sb;
  priority_queue<ll> sg;
  ll indx = 0, mn = 1e13;
  for (ll i = 0; i < n; i++) {
    if (indx > i)
      continue;
    sb.push(a[i]);
    while (sb.size() && sb.top() == b[indx]) {
      sb.pop();
      indx++;
    }
    if (sb.size() == 0) {
      ll k = i + 1;
      while (a[k] == b[indx] && k < n) {
        k++;
        indx++;
      }
    }
    ll ans = (i + 1) * (i + 1) + (n - indx) * (n - indx);
    // cout << "pref" << i << " " << ans << '\n';
    mn = min(mn, ans);
  }
  indx = n - 1;
  for (ll i = n - 1; i >= 0; i--) {
    if (indx < i)
      continue;
    sg.push(a[i]);
    while (sg.size() && sg.top() == b[indx]) {
      sg.pop();
      indx--;
    }
    if (sg.size() == 0) {
      ll k = i - 1;
      while (a[k] == b[indx] && k >= 0) {
        k--;
        indx--;
      }
    }
    ll ans = (n - i) * (n - i) + (indx + 1) * (indx + 1);
    // cout << "suff" << i << " " << ans << '\n';
    mn = min(mn, ans);
  }
  cout << mn << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
