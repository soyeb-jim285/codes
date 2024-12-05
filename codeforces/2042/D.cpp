#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int n;
  cin >> n;                           // Number of users
  vector<tuple<int, int, int>> users; // (l_i, r_i, index)

  for (int i = 0; i < n; ++i) {
    int l_i, r_i;
    cin >> l_i >> r_i;
    users.emplace_back(l_i, r_i, i);
  }

  // Sort users based on l_i ascending, and r_i descending
  sort(users.begin(), users.end(),
       [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
         if (get<0>(a) == get<0>(b))
           return get<1>(a) > get<1>(b);
         return get<0>(a) < get<0>(b);
       });

  vector<int> result(n, 0);
  int min_rj = INT_MAX;

  for (auto &user : users) {
    int l_i = get<0>(user);
    int r_i = get<1>(user);
    int idx = get<2>(user);

    if (min_rj < r_i) {
      // Predictors exist
      int recommended_tracks = max(0, min_rj - (r_i + 1) + 1);
      result[idx] = recommended_tracks;
    } else {
      // No predictors
      result[idx] = 0;
    }
    min_rj = min(min_rj, r_i);
  }

  // Output the result for users in their original order
  for (int i = 0; i < n; ++i) {
    cout << result[i] << endl;
  }
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
