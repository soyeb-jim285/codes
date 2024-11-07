#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void bi(ll n){
  if(n > 1){
    bi(n/2);
  }
  cout << n%2;
}
void solve()
{
  for (int i = 0; i < 10; i++) {
    ll x = i+1;
    for (int j = 1; j <= x*x; j++) {
      for (int k = 1; k <= x*x; k++) {
        ll b = j & k;
        ll c = j ^ k;
        if(b%x == 0 && c%x == 0 && b > 0 && c > 0){
          cout << j << " " << k << " " << x<< " " << b << " " << c << "\n";
          bi(j);
          cout << " ";
          bi(k);
          cout << " ";
          bi(x);
          cout << "\n";
                  
        }
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
