#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
  ll n; 
  cin >> n;
  ll ad = n;
  ll xr = 2 * n;
  while(xr <= 8e18){
    xr *= 2;
    ll sum = xr + ad * 2;
    ll a = ad, b = sum - ad;
    if((a & b) % n == 0 && (a ^ b) % n == 0 && (a& b) > 0 && (a^b) > 0){
      cout << a << " " << b << "\n";
      return;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
#ifdef ONPC
  cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
