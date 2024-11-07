#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll smal(vector<ll> &vc) {
  ll n = vc.size();
  // to store the minimum value that is ending
  // up to the current index
  ll min_ending_here = 1e18;

  // to store the minimum value encountered so far
  ll min_so_far = 1e18;

  // traverse the array elements
  for (int i = 0; i < n; i++) {
    // if min_ending_here > 0, then it could not possibly
    // contribute to the minimum sum further
    if (min_ending_here > 0) {
      // if (i != 0)
      min_so_far = min(min_so_far, min_ending_here + vc[i]);
      min_ending_here = vc[i];
    } else {
      min_ending_here += vc[i];
      min_so_far = min(min_so_far, min_ending_here);
    }
    // cout << min_ending_here << " " << min_so_far << " " << vc[i] << " " << i
    //      << "\n";
  }

  // required smallest sum contiguous subarray value
  return min_so_far;
}
void solve() {
  ll n, sum = 0, neg = 0, pos = 0;
  cin >> n;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
    sum += vc[i];
  }
  ll mn = smal(vc);
  // cout << mn << " -*\n";
  if (mn < 0)
    sum -= 2LL * mn;
  cout << sum << "\n";
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
