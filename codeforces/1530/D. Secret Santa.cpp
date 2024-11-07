#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), ans(n);
  map<ll, ll> cnt;
  for (ll &x : a) {
    cin >> x;
    cnt[x]++;
  }
  ll ans_cnt = 0;
  for (auto ic : cnt) {
    ans_cnt += ic.second - 1;
  }
  set<ll> s;
  for (int i = 0; i < n; i++) {
    s.insert(i + 1);
  }
  vector<ll> sec(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    if (cnt[a[i]] == 1) {
      ans[i] = a[i];
      s.erase(a[i]);
    } else if (cnt[a[i]] > 1) {
      ans[i] = a[i];
      cnt[a[i]] = 0;
      sec[a[i]] = i;
      s.erase(a[i]);
    }
  }

  for (int i = 0; i < n; i++) {
    if (ans[i] == 0) {
      ll x = *s.begin();
      if (x == i + 1) {
        ans[i] = a[i];
        ans[sec[a[i]]] = x;
        sec[a[i]] = i;
      } else {
        ans[i] = x;
      }
      s.erase(x);
    }
  }
  cout << n - ans_cnt << '\n';
  for (auto ic : ans)
    cout << ic << " ";
  cout << '\n';
}
int main() {
  /* ios::sync_with_stdio(false); */
  /* cin.tie(nullptr); */
  int t;
  cin >> t;
  while (t--)
    solve();
}
