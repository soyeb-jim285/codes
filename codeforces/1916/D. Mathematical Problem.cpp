#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n;
  cin >> n;
  if (n == 1)
    cout << "1\n";
  else {
    for (int i = 0; i <= (n - 3) / 2; i++) {
      ll x = i;
      ll y = x;
      ll z = n - 3 - x - y;
      cout << "1";
      while (x--)
        cout << "0";
      cout << "6";
      while (y--)
        cout << "0";
      cout << "9";
      while (z--)
        cout << "0";
      cout << "\n";
    }
    cout << "196";
    for (int i = 0; i < n - 3; i++) {
      cout << "0";
    }
    cout << "\n";
    for (int i = 0; i <= (n - 3) / 2; i++) {
      ll x = i;
      ll y = x;
      ll z = n - 3 - x - y;
      cout << "9";
      while (x--)
        cout << "0";
      cout << "6";
      while (y--)
        cout << "0";
      cout << "1";
      while (z--)
        cout << "0";
      cout << "\n";
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
