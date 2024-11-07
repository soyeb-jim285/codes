#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool between(ll x, ll y, ll z) {
  if (x > z)
    swap(x, z);
  return x <= y && y <= z;
}
void solve() {
  ll n, x, y, z;
  cin >> n >> x >> y >> z;
  if (between(x, z, y))
    cout << "Yes\n";
  else
    cout << "No\n";
}
int main() { solve(); }
