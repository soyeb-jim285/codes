#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), cnt(n), rcnt(n);
  vector<ll> pre(n), suf(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cnt[0] = 1;
  rcnt[n - 1] = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      cnt[i] = cnt[i - 1] + 1;
    } else {
      cnt[i] = 1;
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] == a[i + 1]) {
      rcnt[i] = rcnt[i + 1] + 1;
    } else {
      rcnt[i] = 1;
    }
  }
  pre[0] = a[0];
  suf[n - 1] = a[n - 1];
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + a[i];
  }
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = suf[i + 1] + a[i];
  }
  reverse(suf.begin(), suf.end());
  /* for (auto ic : pre) { */
  /*   cout << ic << ' '; */
  /* } */
  /* cout << '\n'; */
  /* for (auto ic : suf) { */
  /*   cout << ic << ' '; */
  /* } */
  /* cout << '\n'; */
  /* for (auto ic : rcnt) { */
  /*   cout << ic << ' '; */
  /* } */
  /* cout << "\n"; */
  for (int i = 0; i < n; i++) {
    ll left = 1e9, right = 1e9;
    // right
    if (i != n - 1) {
      /* cout << "right\n"; */
      auto ic = lower_bound(pre.begin() + i, pre.end(), pre[i] + a[i] + 1) -
                pre.begin();
      /* cout << ic << " -*-\n"; */
      /* cout << cnt[i + 1] << " **\n"; */
      if (ic != n) {
        if (ic - i == 1) {
          right = ic - i;
        } else {
          if (i + rcnt[i + 1] + 1 < n)
            right = max((ll)(ic - i), rcnt[i + 1] + 1LL);
        }
      }
    }
    if (i != 0) {
      /* cout << n - 1 - i << " *-\n"; */
      /* cout << suf[n - 1 - i] << " " << a[n] << "\n"; */
      auto ic = lower_bound(suf.begin() + n - 1 - i, suf.end(),
                            suf[n - 1 - i] + a[i] + 1) -
                suf.begin();
      /* cout << ic << " **\n"; */
      if (ic != n) {
        /* cout << "left\n"; */
        if (ic - (n - 1 - i) == 1) {
          left = ic - (n - 1 - i);
        } else {
          if (i - cnt[i - 1] - 1 >= 0)
            left = max((ll)(ic - (n - 1 - i)), cnt[i - 1] + 1LL);
        }
      }
    }
    /* cout << left << ' ' << right << '\n'; */
    if (left == 1e9 && right == 1e9) {
      cout << "-1 ";
    } else {
      cout << min(left, right) << ' ';
    }
    /* cout << '\n'; */
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
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
