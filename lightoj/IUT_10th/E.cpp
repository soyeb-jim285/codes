#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<char> ans(n);
  cout << "? ";
  for (int i = 0; i < n; i++) {
    cout << "a";
  }
  cout << endl;
  flush(cout);
  ll full;
  cin >> full;
  for (int i = 0; i < n; i++) {
    cout << "? ";
    for (int j = 0; j < n; j++) {
      if (i == j) {
        cout << "z";
      } else {
        cout << "a";
      }
    }
    cout << endl;
    flush(cout);
    ll x;
    cin >> x;
    ll dif = full - x;
    x = (dif + 25) / 2;
    ans[i] = 'a' + x;
  }
  cout << "! ";
  for (char c : ans) {
    cout << c;
  }
  cout << endl;
}
int main() {
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
