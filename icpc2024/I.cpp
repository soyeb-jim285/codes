#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll MaxDist(vector<pair<ll, ll>> &A) {
  ll N = A.size();
  ll minsum, maxsum, mindiff, maxdiff;
  minsum = maxsum = A[0].first + A[0].second;
  mindiff = maxdiff = A[0].first - A[0].second;
  for (int i = 1; i < N; i++) {
    ll sum = A[i].first + A[i].second;
    ll diff = A[i].first - A[i].second;
    if (sum < minsum)
      minsum = sum;
    else if (sum > maxsum)
      maxsum = sum;
    if (diff < mindiff)
      mindiff = diff;
    else if (diff > maxdiff)
      maxdiff = diff;
  }
  return max(maxsum - minsum, maxdiff - mindiff);
}
bool fn(ll d, ll t, ll x, ll y, vector<pair<ll, ll>> &vc) {
  ll mx = -1e10;
  for (int i = 0; i < vc.size(); i++) {
    mx = max(mx, abs(vc[i].first - (x - d)) + abs(vc[i].second - y + d));
  }
  return mx <= t;
}
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i].first >> vc[i].second;
  }
  ll t = MaxDist(vc);
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
