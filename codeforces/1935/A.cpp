#include <bits/stdc++.h>
#include <iterator>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  string k = s;
  reverse(k.begin(), k.end());
  if (s == k) {
    cout << s << '\n';
    return;
  } else if (s > k) {
    if (n % 2) {
      cout << k << "\n";
    } else {
      cout << k + s << "\n";
    }
  } else {
    if (n % 2) {
      cout << s + k << "\n";
    } else {
      cout << s << "\n";
    }
  }
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
