#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  ll sum = 0;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    sum += b[i];
  }
  if (sum % n != 0) {
    cout << "-1\n";
    return;
  }
  multiset<ll> sa, sb;
  for (int i = 0; i < n; i++) {
    sa.insert(a[i]);
    sb.insert(b[i]);
  }
  ll target = sum / n;
  vector<pair<ll, ll>> ans;
  while (!sa.empty()) {
    ll cur = *sa.begin();
    sa.erase(sa.begin());
    ll need = target - cur;
    if (sb.find(need) == sb.end()) {
      cout << "-1\n";
      return;
    }
    sb.erase(sb.find(need));
    ans.push_back({cur, need});
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i].first << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    cout << ans[i].second << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
