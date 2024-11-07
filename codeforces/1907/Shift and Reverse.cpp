#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
void solve() {
  int n;
  cin >> n;
  vector<ll> vc(n);
  ll mn = 1e16, mnin1 = -1, mnin2 = -1;
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
    if (vc[i] <= mn) {
      if (vc[i] < mn) {
        mnin1 = i;
        mnin2 = i;
      } else {
        mnin2 = i;
      }
      mn = vc[i];
    }
  }
  if (is_sorted(vc.begin(), vc.end())) {
    cout << "0\n";
    return;
  }
  if (vc[0] == mn && vc[n - 1] == mn) {
    for (int i = 0; i < n; i++) {
      if (vc[i] != mn) {
        mnin2 = i - 1;
        break;
      }
    }
    for (int i = mnin2 + 1; i < n; i++) {
      if (vc[i] == mn) {
        mnin1 = i;
        break;
      }
    }
  }
  // cout << mnin1 << " " << mnin2 << " mnmn\n";
  bool ck = 0;
  ll ans = 1e12;
  for (int i = 0; i < n - 1; i++) {
    if (vc[(i + 1 + mnin1) % n] < vc[(i + mnin1) % n]) {
      ck = 1;
      break;
    }
  }
  if (!ck) {
    if (mnin1 <= mnin2) {
      ans = min({ans, n - mnin1, mnin1 + 2});
    } else {
      ans = min({ans, n - mnin1, mnin1 + 2});
    }
  }
  ck = 0;
  bool ck2 = 0;
  for (int i = 0; i < n - 1; i++) {
    // cout << vc[(i + 1 + mnin2) % n] << " " << vc[(i + 2 + mnin2) % n]
    //      << "----**\n";
    if (vc[(i + 1 + mnin2) % n] < vc[(i + 2 + mnin2) % n]) {
      // cout << vc[(i + 1 + mnin2) % n] << " " << vc[(i + 2 + mnin2) % n]
      //      << "\n";
      ck2 = 1;
      break;
    }
  }
  // cout << ck << " ck\n";
  //  for (int i = n - 1; i > 0; i--) {
  //    if (vc[(n - 1 + i + mnin2) % n] < vc[(n - 1 + i - 1 + mnin2) % n]) {
  //      cout << vc[(n - 1 + i + mnin2) % n] << " "
  //           << vc[(n - 1 + i - 1 + mnin2) % n] << "\n";
  //      ck = 1;
  //      break;
  //   }
  //  }
  if (!ck2) {
    if (mnin1 <= mnin2) {
      ans = min({ans, n - mnin2, mnin2 + 2});
    } else {
      ans = min({ans, n - mnin2, mnin2 + 2});
    }
  }
  if (ans == 1e12)
    cout << "-1\n";
  else
    cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
