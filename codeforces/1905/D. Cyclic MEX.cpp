#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;

ll fn(vector<vector<ll>> &st, ll r) {
  ll ans = 0;
  if (r >= st[0].size())
    return 0;
  for (int i = 0; i <= r; i++) {
    ll x = log2(r - i + 1);
    ll mini = min(st[x][i], st[x][r - (1 << x) + 1]);
    ans += mini;
  }
  return ans;
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll ind = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      ind = i;
    }
  }
  vector<ll> vc(n - 1), fal(n);
  fal[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    vc[i] = a[(ind + i + 1) % n];
    fal[i + 1] = vc[i];
  }
  ll k = log2(n) + 2;
  vector<vector<ll>> st(k + 1, vector<ll>(n - 1));
  for (int i = 0; i < n - 1; i++) {
    st[0][i] = vc[i];
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j + (1 << i) <= n - 1; j++) {
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
  // ll falmex = 0, fal_ans = 0;
  // for (int i = 0; i < n; i++) {
  //   if (fal[i] != falmex) {
  //     fal_ans += falmex;
  //   } else {
  //     falmex++;
  //   }

  // cout << "-------->\n";
  ll l = 0, r = n - 2;
  while (r - l > 3) {
    ll mid = (l + r) / 2;

    if (fn(st, mid) < fn(st, mid + 1)) {
      l = mid;
    } else {
      r = mid;
    }
    // cout << l << " " << r << "\n";
  }
  // cout << r << " " << fn(st, r) << "\n";

  ll mx = 0;
  for (int i = max(0LL, r - 4); i <= min(n - 2, r + 4); i++) {
    mx = max(mx, fn(st, i));
  }
  cout << fn(st, r) + n << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
