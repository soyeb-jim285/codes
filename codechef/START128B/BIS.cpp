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
  string s;
  cin >> s;
  ll oo = 0, no = 0, on= 0, nn = 0;
  for (int i = 0; i < n; i+=2) {
    if(s[i] == '0' && s[i+1] == '0'){
      oo++;
    }
    else if(s[i] == '0' && s[i+1] == '1'){
      on++;
    }
    else if(s[i] == '1' && s[i+1] == '0'){
      no++;
    }
    else nn++;
  }
  ll ans = nn + min(1LL, on) + oo;
  ans *= 2;
  ans += min(2LL , no);
  cout << ans << "\n";
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
