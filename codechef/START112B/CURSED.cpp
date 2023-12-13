#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  multiset<ll> s;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    s.insert(x);
  }
  vector<ll> ans;
  ll p = 0, val = 0;
  while (s.size()) {
    auto ic = upper_bound(s.begin(), s.end(), p);
    if (ic == s.end()) {
      val = s.size();
      break;
    }
    ll num = *ic;
    s.erase(ic);
    ans.push_back(num);
    p += num;
  }
  cout << val << "\n";
  for (auto ic : ans) {
    cout << ic << " ";
  }
  for (auto ic = s.begin(); ic != s.end(); ic++) {
    cout << *ic << " ";
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
