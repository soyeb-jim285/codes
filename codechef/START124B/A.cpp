#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  ll n;
  cin >> n;
  ll cnt = 0;
  while (1) {
    if (n == 0)
      break;
    if (n % 2 == 1) {
      cnt++;
    }
    n /= 2;
  }
  if (cnt % 2 == 0)
    cout << "EVEN" << endl;
  else
    cout << "ODD" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
