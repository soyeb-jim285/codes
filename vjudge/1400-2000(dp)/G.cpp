#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, k;
  cin >> n >> k;
  multiset<ll> right, left;
  vector<ll> pos, tmp(n, 0), ans(n);
  for (int i = 0; i < k; i++) {
    ll x;
    cin >> x;
    pos.push_back(x);
  }
  for (int i = 0; i < k; i++) {
    cin >> tmp[pos[i] - 1];
    ll val = pos[i] - 1 + tmp[pos[i] - 1];
    right.insert(val);
  }
  for (int i = 0; i < n; i++) {
    ll a = 1e18;
    if (sz(right)) {
      a = *right.begin() - i;
    }
    if (sz(left)) {
      a = min(a, *left.begin() + i);
    }
    ans[i] = a;
    if (tmp[i] != 0) {
      right.erase(right.find(i + tmp[i]));
      left.insert(tmp[i] - i);
    }
    cout << a << " ";
  }
  cout << "\n";
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
