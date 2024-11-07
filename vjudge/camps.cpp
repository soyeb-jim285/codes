#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool fn(vector<ll> &v, ll mx, ll k) {
  ll count = 1, sum = 0;
  bool ck = 0;
  for (int i = 0; i < sz(v); i++) {
    // if (v[i] > mx)
    //   return false;
    if (sum + v[i] > mx) {
      sum = 0;
      count++;
    }
    sum += v[i];
    if (sz(v) - i + count <= k)
      return 1;
  }
  // cout << count << "---*---\n";
  if (count <= k)
    return true;
  else
    return false;
}
void solve() {
  ll n, k, mx = 0;
  cin >> n >> k;
  k++;
  vector<ll> v(n + 1);
  for (int i = 0; i < n + 1; i++) {
    cin >> v[i];
    mx = max(mx, v[i]);
  }
  ll low = mx, high = 1e9;
  while (low < high) {
    ll mid = (low + high) / 2;
    if (fn(v, mid, k))
      high = mid;
    else
      low = mid + 1;
  }
  // cout << fn(v, 5, k) << '\n';
  cout << low << '\n';
  if (sz(v) == k) {
    for (auto x : v)
      cout << x << '\n';
    return;
  }
  ll sum = 0, count = 0, ck = -1;
  for (int i = 0; i < sz(v); i++) {
    if (sum + v[i] > low) {
      cout << sum << '\n';
      // cout << sum + v[i] << "-----\n";
      sum = 0;
      count++;
    }
    sum += v[i];
    if (sz(v) - i + count <= k) {
      ck = i;
      // cout << sz(v) - i + count << "-----\n";
      break;
    }
  }
  if (ck != -1)
    for (int i = ck; i < sz(v); i++) {
      if (i == ck)
        cout << sum << '\n';
      else
        cout << v[i] << '\n';
    }
  else {
    cout << sum << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
