#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n, x, sum = 0;
  cin >> n >> x;
  vector<string> s(n);
  vector<ll> zeros;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    sum += sz(s[i]);
    reverse(s[i].begin(), s[i].end());
    for (int j = 0; j < sz(s[i]); j++) {
      if (s[i][j] != '0') {
        zeros.push_back(j);
        break;
      }
    }
  }
  sort(zeros.begin(), zeros.end(), greater<ll>());
  for (int i = 0; i < sz(zeros); i += 2) {
    sum -= zeros[i];
  }
  if (sum > x)
    cout << "Sasha\n";
  else
    cout << "Anna\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
