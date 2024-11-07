#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  vector<ll> vc(n), pre_left(n), pre_right(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  pre_right[1] = 1;
  pre_left[n - 2] = 1;
  for (int i = 1; i < n - 1; i++) {
    if (abs(vc[i] - vc[i - 1]) < abs(vc[i] - vc[i + 1])) {
      pre_right[i + 1] = pre_right[i] + abs(vc[i] - vc[i + 1]);
    } else {
      pre_right[i + 1] = pre_right[i] + 1;
    }
  }
  for (int i = n - 2; i >= 1; i--) {
    if (abs(vc[i] - vc[i - 1]) < abs(vc[i] - vc[i + 1])) {
      pre_left[i - 1] = pre_left[i] + 1;
    } else {
      pre_left[i - 1] = pre_left[i] + abs(vc[i] - vc[i - 1]);
    }
  }
  /* for (auto ic : pre_left) */
  /*   cout << ic << " "; */
  /* cout << "\n"; */
  /* for (auto ic : pre_right) */
  /*   cout << ic << " "; */
  /* cout << "\n"; */
  ll q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    if (l == r) {
      cout << "0\n";
    } else {
      ll ans = 0;
      if (l > r) {
        ans += pre_left[r - 1] - pre_left[l - 1];
      } else {
        ans += pre_right[r - 1] - pre_right[l - 1];
      }
      cout << ans << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
