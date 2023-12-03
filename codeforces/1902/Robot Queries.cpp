#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
ll const N = 1e5 + 10, k = 25;
vector<vector<ll>> mxt(k + 1, vector<ll>(N));
vector<vector<ll>> rmxt(k + 1, vector<ll>(N));
vector<vector<ll>> mnt(k + 1, vector<ll>(N));
vector<vector<ll>> rmnt(k + 1, vector<ll>(N));
ll p = 1e9 + 7;
string s, rev;
vector<ll> vc(N), rvc(N);
void fn(string &str, vector<ll> &vce, ll n) {
  ll up = 0, right = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == 'U')
      up++;
    if (str[i] == 'D')
      up--;
    if (str[i] == 'R')
      right++;
    if (str[i] == 'L')
      right--;
    vce[i] = up * p + right;
  }
}
void spmx(vector<vector<ll>> &mxtt, vector<ll> &vcc) {
  for (int i = 0; i < N; i++) {
    mxtt[0][i] = vcc[i];
  }
  for (int i = 1; i <= k; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
      mxtt[i][j] = max(mxtt[i - 1][j], mxtt[i - 1][j + (1 << (i - 1))]);
}
void spmn(vector<vector<ll>> &mntt, vector<ll> &vcc) {
  for (int i = 0; i < N; i++) {
    mntt[0][i] = vcc[i];
  }
  for (int i = 1; i <= k; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
      mntt[i][j] = min(mntt[i - 1][j], mntt[i - 1][j + (1 << (i - 1))]);
}
ll mnn(ll l, ll r, vector<vector<ll>> &mxtt) {
  ll i = log2(r - l + 1);
  ll minimum = min(mxtt[i][l], mxtt[i][r - (1 << i) + 1]);
  return minimum;
}
ll mxx(ll l, ll r, vector<vector<ll>> &mxtt) {
  ll i = log2(r - l + 1);
  ll minimum = max(mxtt[i][l], mxtt[i][r - (1 << i) + 1]);
  return minimum;
}
bool an(ll l, ll r, ll ned, vector<vector<ll>> &mntt,
        vector<vector<ll>> &mxtt) {
  if (l > r)
    return 0;
  ll mxnum = mxx(l, r, mxtt);
  ll minnum = mnn(l, r, mntt);
  if (mxnum == ned || minnum == ned)
    return 1;
  if (ned > minnum && ned < mxnum) {
    bool ans = an(l, r / 2, ned, mntt, mxtt);
    ans |= an(r / 2 + 1, r, ned, mntt, mxtt);
    return ans;
  } else
    return 0;
}
void solve() {
  ll n, q;
  cin >> n >> q;
  cin >> rev;
  s = rev;
  reverse(rev.begin(), rev.end());
  fn(s, vc, n);
  fn(rev, rvc, n);
  spmx(mxt, vc);
  spmx(rmxt, rvc);
  spmn(mnt, vc);
  spmn(rmnt, rvc);
  while (q--) {
    ll x, y, fst, lst;
    cin >> x >> y >> fst >> lst;
    ll ned = x * p + y;
    if (ned == 0)
      cout << "YES\n";
    else if (an(0, fst - 2, ned, mnt, mxt) || an(lst, n - 1, ned, mnt, mxt))
      cout << "YES\n";
    else {
      ned -= vc[lst];
      if (ned == 0) {
        cout << "YES\n";
      } else if (an(fst, lst - 1, ned, rmnt, rmxt))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--)
    solve();
  return 0;
}
