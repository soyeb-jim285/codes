#include <bits/stdc++.h>
#include <deque>
#include <iostream>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<bool> fn(ll n, ll k) {
  vector<bool> res(k);
  int indx = 0;
  while (n) {
    if (n % 2)
      res[indx] = 1;
    indx++;
    n /= 2;
  }
  // reverse(res.begin(), res.end());
  return res;
}
void solve() {
  ll n, k;
  cin >> n >> k;
  if (n <= 60) {
    if (k - 1 > (1LL << (n - 1)) - 1) {
      cout << "-1\n";
      return;
    }
  }
  deque<ll> ans;
  ans.push_back(n);
  n--;
  ll cnt = 0;
  vector<bool> s = fn(k - 1, n);
  while (n) {
    if (s[cnt] == 1) {
      ans.push_back(n);
    } else {
      ans.push_front(n);
    }
    cnt++;
    n--;
  }
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << endl;
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
