#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void ask(int i, int j, int n) {
  // up
  ll d = 1;
  while (i - d >= 0) {
    cout << i - d + 1 << " " << j + 1 << endl;
    d++;
    string s;
    cin >> s;
    if (d > 4)
      break;
  }
  d = 1;
  while (i + d < n) {
    cout << i + d + 1 << " " << j + 1 << endl;
    d++;
    string s;
    cin >> s;
    if (d > 4)
      break;
  }
  d = 1;
  while (j - d >= 0) {
    cout << i + 1 << " " << j - d + 1 << endl;
    d++;
    string s;
    cin >> s;
    if (d > 4)
      break;
  }
  d = 1;
  while (j + d < n) {
    cout << i + 1 << " " << j + d + 1 << endl;
    d++;
    string s;
    cin >> s;
    if (d > 4)
      break;
  }
}

void solve() {
  ll n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (abs(i - j) % 5 == 0) {
        cout << i + 1 << " " << j + 1 << endl;
        string s;
        cin >> s;
        if (s == "hit") {
          ask(i, j, n);
        }
      }
    }
  }
}
int main() {
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
