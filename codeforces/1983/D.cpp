#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll minSwaps(vector<ll> &arr, int n) {
  pair<ll, ll> arrPos[n];
  for (int i = 0; i < n; i++) {
    arrPos[i].first = arr[i];
    arrPos[i].second = i;
  }

  sort(arrPos, arrPos + n);
  vector<bool> vis(n, false);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i] || arrPos[i].second == i)
      continue;
    int cycle_size = 0;
    int j = i;
    while (!vis[j]) {
      vis[j] = 1;
      j = arrPos[j].second;
      cycle_size++;
    }
    if (cycle_size > 0) {
      ans += (cycle_size - 1);
    }
  }
  return ans;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  set<ll> sa, sb;
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sa.insert(a[i]);
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    sb.insert(b[i]);
    mp[b[i]] = i + 1;
  }
  if (sa != sb) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    a[i] = mp[a[i]];
  }
  cout << (minSwaps(a, n) % 2 == 0 ? "YES" : "NO") << "\n";
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
