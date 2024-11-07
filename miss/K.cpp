#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define rep(i, j, n) for (int i = j; i < n; i++)

const int N = 2e5 + 10;
const int INF = 10;

vector<ll> inv(N), ans(N, -1);
bool ask(ll x, ll n, ll l, ll r) {
  // if (l == r) return 1;
  // cout << x << " " << n << ' ' << l << " " << r << "*/*/*\n";
  cout << "0 ";

  for (int i = 0; i < n; i++) {
    if (i >= l && i <= r) {
      cout << x << " ";

    } else {
      cout << inv[i] << " ";
    }
  }
  cout << endl;

  ll xx;
  cin >> xx;
  return xx > 0;
}

int dc(int ind1, int ind2, int x, int n) {
  if (ind2 == ind1)
    return ind1;
  int mid = (ind1 + ind2) / 2;
  // int tmp = (ind2 - ind1) / 3;
  // int mid1 = ind1 + tmp;
  // int mid2 = ind2 - tmp;
  // cout << x << " ";
  //

  if (ask(x, n, ind1, mid))
    return dc(ind1, mid, x, n);
  else
    return dc(mid + 1, ind2, x, n);
}

void solve() {
  ll n, x = -1, xx = 2;
  cin >> n;
  while (x != 0 && x != 2) {
    cout << "0 ";

    for (int i = 0; i < n / 2 + 1; i++) {
      cout << "1 ";
    }
    for (int i = n / 2 + 1; i < n; i++) {
      cout << xx << " ";
    }
    xx++;
    cout << endl;

    cin >> x;
  }
  xx--;

  for (int i = 0; i <= n / 2; i++) {
    if (x == 0)
      inv[i] = 1;
    else
      inv[i] = xx;
  }
  for (int i = n / 2 + 1; i < n; i++) {
    if (x == 0)
      inv[i] = xx;
    else
      inv[i] = 1;
  }
  // for (int i = 0; i < n; i++) {
  //     cout << inv[i] << " ";
  //
  // }
  // cout << endl;
  //

  for (int i = 2; i <= n; i++) {
    if (i == xx)
      continue;
    int ind = dc(0, n - 1, i, n);
    ans[ind] = i;
  }
  bool ct = 1;
  cout << "0 ";

  for (int i = 0; i < n; i++) {
    if (ans[i] == -1) {
      if (ct)
        cout << "1 ";
      else
        cout << xx << " ";
      ct = 0;

    } else {
      cout << ans[i] << " ";
    }
  }
  cout << endl;

  cin >> x;
  cout << "1 ";

  if (x == n) {
    ct = 1;
    for (int i = 0; i < n; i++) {
      if (ans[i] == -1) {
        if (ct)
          cout << "1 ";
        else
          cout << xx << " ";
        ct = 0;

      } else {
        cout << ans[i] << " ";
      }
    }
  } else {
    ct = 2;
    for (int i = 0; i < n; i++) {
      if (ans[i] == -1) {
        if (ct)
          cout << xx << " ";
        else
          cout << "1 ";
        ct = 0;

      } else {
        cout << ans[i] << " ";
      }
    }
  }
  cout << endl;
}

signed main() {
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}
