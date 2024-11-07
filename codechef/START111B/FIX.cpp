#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  vector<ll> vc(n), ans(n);
  set<ll> st1, st2;
  ll mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
    mx = max(mx, vc[i]);
  }
  for (int i = 0; i < n; i++) {
    if (st2.count(vc[i]))
      ans[i] = mx;
    else
      ans[i] = vc[i];
    st2.insert(vc[i]);
  }
  for (auto it : ans) {
    cout << it << " ";
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
