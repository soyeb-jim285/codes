#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n, k;
  cin >> n >> k;
  if (n == 1 && k == 0) {
    cout << "1\n";
    return;
  }
  if (k > n - 2) {
    cout << "-1\n";
    return;
  }
  ll ct = 1;
  for (int i = 0; i < n; i++) {
    if (i == n - 2 - k) {
      cout << n << " ";
      continue;
    }
    cout << ct++ << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
/*
 * 5 1
 * 1 2 3 4 5
 * 3 1
 * 1 2 3 -> 3-3 = 0
 * 1 3 2 -> 2-2 = 0
 * 2 1 3 -> 2-2 = 0
 * 2 3 1 -> 2-2 = 0
 * 3 1 2 -> 2-1 = 1
 * 3 2 1 -> 1-1 = 0
 * 4 1
 * 1 4 2 3
 * 4 1 2 3
 * 5 1
 * 1 2 5 3 4
 * 5 2
 * 1 5 2 3 4
 * 7 2
 * 1 2 3 7 4 5 6
 */
