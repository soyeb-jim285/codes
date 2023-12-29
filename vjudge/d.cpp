#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll fn(string & target, vector<string> & vc)
{
  ll ans = 0;
  for (int  i = 0; i < vc.size(); i++) {
    string tmp = vc[i];
    bool check = 0;
    if(tmp.size() != target.size()) return -1;
    for (int  j = 0; j < tmp.size() ; j++) {
      bool bk = 1;
      for (int  k = 0; k < tmp.size(); k++) {
        if(tmp[(j+k)%(int)tmp.size()] != target[k]) {
        bk = 0;
          break;
        }
      }
      if(bk){
      ans+=j;
      check = 1;
      break;} 
    }
    if(check == 0) return -1;
  }
  return ans;
}
void solve()
{
  ll n;
  cin >> n; 
  vector<string> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  sort(vc.begin(), vc.end());
  ll ans = 1e9;
  for (int  i = 0; i < vc[0].size(); i++) {
    string tmp = vc[0];
    rotate(tmp.begin(), tmp.begin()+i, tmp.end());
    ll p = fn(tmp, vc);
    if(p == -1){
      cout << tmp << "\n";
      cout << "-1\n";return;
    }
    ans = min(ans, p);
  }
  cout << ans << "\n";
}
int main()
{
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
