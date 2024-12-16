#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  string s;
  cin >> s;
  ll sum = 0, twos = 0, threes = 0;
  for (char c : s) {
    sum += c - '0';
    if (c == '2')
      twos++;
    else if (c == '3')
      threes++;
  }
  ll rem = sum % 9;
  if (rem == 0) {
    cout << "YES" << endl;
    return;
  }
  if (rem % 2 && (9 - rem) <= 2 * twos) {
    cout << "YES0" << endl;
    return;
  }
  rem = (sum - 3 * threes) % 9;
  if (rem == 0) {
    cout << "YES" << endl;
    return;
  }
  if (rem % 2 && (9 - rem) <= 2 * twos) {
    cout << "YES1" << endl;
    return;
  }
  if (threes >= 1) {
    rem = (sum - 3 * threes + 3) % 9;
    if (rem == 0) {
      cout << "YES" << endl;
      return;
    }

    if (rem % 2 && (9 - rem) <= 2 * twos) {
      cout << "YES2" << endl;
      return;
    }
  }
  if (threes >= 2) {
    rem = (sum - 3 * threes + 6) % 9;
    if (rem == 0) {
      cout << "YES" << endl;
      return;
    }

    if (rem % 2 && (9 - rem) <= 2 * twos) {
      cout << "YES3" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
