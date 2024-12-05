#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll fn(ll mid, vector<ll> &a) {
  ll n = a.size();
  ll ans = 0, lst = 0, cnt = 0;
  deque<ll> dq;
  for (int i = 0; i < n; i++) {
    if (dq.empty()) {
      dq.push_back(a[i]);
    } else {
      while (!dq.empty() && dq.back() < a[i]) {
        dq.pop_back();
      }
      dq.push_back(a[i]);
    }
    ll rem = n - i;
    if (rem <= mid) {
      ll mx = dq.front();
      dq.pop_front();
      cnt++;
      ans += mx * (mid - cnt);
      lst = mx;
    }
  }
  return ans;
}
void solve() {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  vector<ll> a(n);
  if (s[0] == '0') {
    a[0] = 0;
  } else {
    a[0] = 1;
  }
  for (int i = 1; i < n; i++) {
    a[i] = a[i - 1];
    if (s[i] == '0') {
      a[i]--;
    } else {
      a[i]++;
    }
  }
  ll low = 1, high = 2e5, ans = 0;
  while (low <= high) {
    ll mid = (low + high) / 2;
    ll res = fn(mid, a);
    if (res <= k) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << ans << '\n';
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
