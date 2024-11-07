
#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
void findTriplets(vector<ll> &arr, ll n) {
  bool found = false;

  // sort array elements
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n - 1; i++) {
    // initialize left and right
    int l = i + 1;
    int r = n - 1;
    int x = arr[i];
    while (l < r) {
      if (x + arr[l] + arr[r] == 0) {
        // print elements if it's sum is zero
        l++;
        r--;
        cout << "YES\n";
        return;
        found = true;
        //   break;
      } else if (x + arr[l] + arr[r] < 0)
        l++;
      else
        r--;
    }
  }

  if (found == false)
    cout << "NO\n" << endl;
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    mp[x]++;
  }
  vector<ll> a;
  for (auto ic : mp) {
    a.push_back(ic.first);
    if (ic.second > 1)
      a.push_back(ic.first);
    if (ic.second > 2)
      a.push_back(ic.first);
  }
  // for (int i = 0; i < sz(a); i++) {
  //   for (int j = i + 1; j < sz(a); j++) {
  //     ll sum = a[i] + a[j];
  //     auto ic = lower_bound(a.begin() + j + 1, a.end(), -sum) - a.begin();
  //     if (ic > j && ic != sz(a) && a[ic] == -sum) {
  //       cout << "YES\n";
  //       return;
  //     }
  //   }
  // }
  // cout << "NO\n";
  findTriplets(a, sz(a));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 1;
  // cin >> t;
  while (t--) {
    // cout << "Case " << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
/*

###...#
#.....#
.....##
....#..
....###



*/
