#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  ll mn = 1e18;
  set<ll> mns;
  map<ll, ll> cnt;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    mn = min(mn, x);
    mns.insert(mn);
    if (x == mn)
      cnt[x]++;
  }
  ll mn_step = n;
  ll done = 0;
  while (mns.size()) {
    ll cur = *mns.begin();
    mns.erase(mns.begin());
    done += cnt[cur];
    ll step = n + cur - done;
    mn_step = min(mn_step, step);
    /* cout << mn_step << " " << cur << "\n"; */
  }
  cout << mn_step << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
