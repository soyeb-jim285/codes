#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
bool min_max(ll mid, vector<ll> &vc) {
  ll rem = 0;
  for (int i = 0; i < vc.size(); i++) {
    if (vc[i] > mid) {
      rem += vc[i] - mid;
    } else {
      if (rem) {
        if (vc[i] + rem < mid) {
          rem = 0;
        } else {
          rem -= mid - vc[i];
        }
      }
    }
  }
  if (rem)
    return false;
  return true;
}
bool max_min(ll mid, vector<ll> &vc) {
  ll rem = 0;
  for (int i = 0; i < vc.size(); i++) {
    if (vc[i] > mid) {
      rem += vc[i] - mid;
    } else {
      if (vc[i] + rem >= mid) {
        rem -= mid - vc[i];
      } else
        return 0;
    }
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  vector<ll> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  ll mn = -1, mx = -1;
  ll low = 1, high = 1e12;
  while (low < high) {
    ll mid = (low + high) / 2;
    if (min_max(mid, vc)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    // cout << high << " " << low << " mx\n";
  }
  mx = high + 1;
  for (ll i = max(mx - 5, 1LL); i <= min(mx + 5, (ll)1e12); i++) {
    if (min_max(i, vc)) {
      mx = i;
      break;
    }
  }
  low = 1, high = 1e12;
  while (low < high) {
    ll mid = (low + high) / 2;
    if (max_min(mid, vc)) {
      low = mid + 1;
    } else
      high = mid - 1;
    // cout << high << " " << low << " mn\n";
  }
  mn = low - 1;
  for (ll i = max(low - 5, 1LL); i <= min(low + 5, (ll)1e12); i++) {
    if (max_min(i, vc)) {
      mn = i;
    }
  }
  cout << mx - mn << '\n';
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
