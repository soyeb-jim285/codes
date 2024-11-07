#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define sz(x) (int)(x).size()
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  vector<pair<ll, ll>> neg, mid, pos;
  vector<ll> a_neg, a_pos, a_mid;
  for (int i = 0; i < n; i++) {
    if (a[i].second < 0) {
      neg.push_back(a[i]);
    } else if (a[i].first > 0) {
      pos.push_back(a[i]);
    } else {
      mid.push_back(a[i]);
    }
  }
  ll sum = 0;
  for (int i = 0; i < sz(neg); i++) {
    sum += neg[i].second;
    a_neg.push_back(neg[i].second);
  }
  ll ct = 0;
  for (int i = 0; i < sz(pos); i++) {
    if (sum + pos[i].first >= 0) {
    }
    sum += pos[i].first;
    a_pos.push_back(pos[i].first);
  }
  for (int i = 0; i < sz(mid); i++) {
    if (sum == 0)
      break;
    if (sum < 0) {
      if (sum + mid[i].second >= 0) {
        a_mid.push_back(-sum);
        sum = 0;
      } else {
        a_mid.push_back(mid[i].second);
        sum += mid[i].second;
      }
    } else {
      if (sum + mid[i].first <= 0) {
        a_mid.push_back(-sum);
        sum = 0;
      } else {
        a_mid.push_back(mid[i].first);
        sum += mid[i].first;
      }
    }
    ct++;
  }
  if (sum != 0) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  int imed = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].second < 0) {
      cout << a[i].second << " ";
    } else if (a[i].first > 0) {
      cout << a[i].first << " ";
    } else {
      if (imed < sz(a_mid)) {
        cout << a_mid[imed] << " ";
      } else
        cout << "0 ";
      imed++;
    }
  }
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
