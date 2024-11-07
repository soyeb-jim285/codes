#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void NumberofSlice() {
  ll n;
  cin >> n;
  if (n == 0) {
    cout << "1\n";
    return;
  }
  set<ll> angles;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    x = x % 180;
    if (x < 0)
      x += 180;
    angles.insert(x);
  }
  cout << angles.size() * 2 << "\n";
}
int main() {
    NumberofSlice();
  return 0;
}
