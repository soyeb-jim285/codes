#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> odd, even;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if (i % 2 == 0)
      even.push_back(x);
    else
      odd.push_back(x);
  }
  vector<ll> odd_pre, even_pre;
  odd_pre.push_back(0);
  even_pre.push_back(0);
  for (auto i : odd)
    odd_pre.push_back(odd_pre.back() + i);
  for (auto i : even)
    even_pre.push_back(even_pre.back() + i);
  map<ll, ll> mp;
  // for(auto i: odd_pre) cout << i << " ";
  // cout << '\n';
  // for(auto i: even_pre) cout << i << " ";
  // cout << '\n';
  for (int i = 0; i < odd_pre.size(); i++) {
    // cout << odd_pre[i] << " " << even_pre[i] << '\n';
    mp[odd_pre[i] - even_pre[i]]++;
    if (i + 1 < even_pre.size()) {
      mp[odd_pre[i] - even_pre[i + 1]]++;
    }
  }
  for (auto ic : mp) {
    if (ic.second >= 2) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
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
