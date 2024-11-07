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
  k--;
  ll evn = k / 2, od = k / 2;
  if (k % 2)
    od++;
  ll dne = 0, dno = 0, even = 2, odd = 1;
  ll numodd = ceil(1.0 * n / 2) - od;
  ll numev = n / 2 - evn;
  bool bod = 1, bev = 0;
  for (int i = 0; i < n; i++) {
    if (bod) {
      cout << odd << ' ';
      odd += 2;
      numodd--;
      if (numodd == 0) {
        bod = 0;
        bev = 1;
      }
    }
    if (bev) {
      cout << even << ' ';
      even += 2;
      numev--;
      if (numev == 0)
        break;
    }
  }
  while (even <= n || odd <= n) {
    if (odd <= n)
      cout << odd << ' ';
    if (even <= n)
      cout << even << ' ';
    odd += 2;
    even += 2;
  }
  cout << '\n';
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
