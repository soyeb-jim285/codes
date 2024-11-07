#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  vector<char> val = {'a', 'e', 'i', 'o', 'u'};
  ll n;
  cin >> n;
  vector<char> ans;
  for (int i = 0; i < n; i++) {
    ans.push_back(val[i % 5]);
  }
  sort(ans.begin(), ans.end());
  for (char c : ans) {
    cout << c;
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
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
