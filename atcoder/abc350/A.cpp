#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll sttonum(string s) {
  ll num = 0;
  for (int i = 0; i < s.size(); i++)
    num = num * 10 + s[i] - '0';
  return num;
}
void solve() {
  string s;
  cin >> s;
  string num = s.substr(3, 3);
  if (sttonum(num) < 350 && sttonum(num) > 0 && sttonum(num) != 316)
    cout << "Yes\n";
  else
    cout << "No\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
