#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
  ll n = 3, aa = 0, bb = 0, cc = 0;
  vector<vector<char>> a(n, vector<char>(n));
  for (int  i = 0; i < n ; i++) {
   for (int  j = 0; j < n ; j++) {
    cin >> a[i][j];
    if(a[i][j] == 'A') aa++;
    if(a[i][j] == 'B') bb++;
    if(a[i][j] == 'C') cc++;
   } 
  }
  if(aa == 2) cout << "A\n";
  if(bb == 2) cout << "B\n";
  if(cc == 2) cout << "C\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
#ifdef ONPC
  cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
