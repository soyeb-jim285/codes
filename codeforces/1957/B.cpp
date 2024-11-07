#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll stringtonum(string s) {
  ll res = 0;
  for (int i = 0; i < sz(s); i++) {
    res = res * 2 + s[i] - '0';
  }
  return res;
}
string numtobin(ll num) {
  string res = "";
  while (num) {
    res += (num % 2) + '0';
    num /= 2;
  }
  reverse(res.begin(), res.end());
  return res;
}
void solve() {
  ll n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << k << '\n';
    return;
  }
  vector<ll> ans;
  ll fst = 1;
  while (fst - 1 <= k)
    fst *= 2;
  if (fst - 1 > k)
    fst /= 2;
  ll sum = fst - 1;
  ans.push_back(fst - 1);
  while (ans.size() < n) {
    ans.push_back(k - sum);
    sum += k - sum;
  }
  for (auto ic : ans)
    cout << ic << ' ';
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
