#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  ll n, sum = 0;
  cin >> n;
  vector<ll> vc;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    sum += a;
    vc.push_back(b - a);
  }
  sort(vc.begin(), vc.end(), greater<ll>());
  ll mx = vc[0];
  cout << sum + mx << endl;
}
int main() { solve(); }
