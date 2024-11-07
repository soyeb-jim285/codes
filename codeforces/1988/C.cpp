#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool if_one(ll num, int ind) { return num & (1LL << ind); }
ll bitflip(ll num, int ind) { return num ^ (1LL << ind); }
string binary(ll num) {
  string s = "";
  while (num) {
    s += (num % 2) + '0';
    num /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> ans;
  ans.push_back(n);
  ll nn = n;
  int ind = 0;
  while (ind <= 63) {
    if (if_one(n, ind)) {
      ll tmp = bitflip(n, ind);
      if (tmp > 0)
        ans.push_back(tmp);
    }
    nn /= 2;
    ind++;
  }
  sort(ans.begin(), ans.end());
  cout << sz(ans) << endl;
  for (auto i : ans) {
    cout << i << " ";
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
