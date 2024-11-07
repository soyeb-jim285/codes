#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void solve() {
  ll n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cout << i + 1 << " ";
  }
  for (int i = n - 1; i >= k; i--) {
    cout << i + 1 << " ";
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
