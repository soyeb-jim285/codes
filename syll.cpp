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
  string k =s;
  for (int  i = 0; i < n ; i++) {
    if(s[i]=='a' || s[i]=='e') s[i] = 'v';
    else s[i] = 'c';
  }
  string tmp = "";
  for (int  i = 0; i < n-1 ; i++) {
    if(s[i] == 'c') {
      if(s[i+1]=='c'){ 
      tmp += k[i];
      }
      else{
        if(i !=0)
          cout << tmp << "."; 
        tmp = "";
        tmp+=k[i];
      }
    }
    else
    tmp += k[i];
  }
  tmp+= k[n-1];
  cout << tmp;
  cout << "\n";
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
