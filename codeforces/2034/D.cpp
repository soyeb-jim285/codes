#include <bits/stdc++.h>
#include <cassert>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void fn(int ind1, int ind2, vector<ll> &vc) {
  // if (abs(vc[ind1] - vc[ind2]) != 1)
  //   cout << ind1 << " " << ind2 << " " << vc[ind1] << " " << vc[ind2] <<
  //   "\n";
  // assert(abs(vc[ind1] - vc[ind2]) == 1);
  if (vc[ind1] > vc[ind2]) {
    vc[ind1]--;
    vc[ind2]++;
  } else {
    vc[ind1]++;
    vc[ind2]--;
  }
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a) {
    cin >> x;
  }
  vector<pair<int, int>> ans;
  vector<ll> b = a;
  sort(b.begin(), b.end());
  set<int> zeros, ones, twos, one;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1 && one.size() == 0)
      one.insert(i);
    if (a[i] != b[i]) {
      if (a[i] == 0) {
        zeros.insert(i);
      } else if (a[i] == 1) {
        ones.insert(i);
      } else {
        twos.insert(i);
      }
    }
  }
  if (sz(ones) == 0) {
    ones = one;
  }
  for (auto ic : a) {
    cout << ic << " ";
  }
  cout << "\n";
  for (auto ic : b) {
    cout << ic << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    if (abs(a[i] - b[i]) == 1) {
      if (a[i] == 0) {
        ll fnt_o = *ones.begin();
        ones.erase(fnt_o);
        zeros.erase(i);
        ans.emplace_back(fnt_o + 1, i + 1);
        ones.insert(i);
        fn(fnt_o, i, a);
      } else if (a[i] == 1) {
        if (b[i] == 0) {
          ll lst_z = *zeros.rbegin();
          zeros.erase(lst_z);
          ones.erase(i);
          ans.emplace_back(lst_z + 1, i + 1);
          fn(lst_z, i, a);
          if (ones.size() == 0)
            ones.insert(lst_z);
        } else {
          ll fst_t = *twos.begin();
          twos.erase(fst_t);
          ones.erase(i);
          ans.emplace_back(fst_t + 1, i + 1);
          fn(fst_t, i, a);
          if (ones.size() == 0)
            ones.insert(fst_t);
        }
      } else {
        ll lst_o = *ones.rbegin();
        ones.erase(lst_o);
        twos.erase(i);
        ans.emplace_back(lst_o + 1, i + 1);
        fn(lst_o, i, a);
        if (ones.size() == 0)
          ones.insert(i);
      }
    }
  }
  one.clear();
  ones.clear();
  twos.clear();
  zeros.clear();
  for (int i = 0; i < n; i++) {
    if (a[i] == 1 && one.size() == 0)
      one.insert(i);
    if (a[i] != b[i]) {
      if (a[i] == 0) {
        zeros.insert(i);
      } else if (a[i] == 1) {
        ones.insert(i);
      } else {
        twos.insert(i);
      }
    }
  }
  if (sz(ones) == 0) {
    ones = one;
  }

  for (auto ic : a) {
    cout << ic << " ";
  }
  cout << '\n';
  // cout << sz(ans) << " OK\n";
  // vector<int> all_indx;
  // for (auto ic : zeros)
  //   all_indx.push_back(ic);
  // for (auto ic : ones)
  //   all_indx.push_back(ic);
  // for (auto ic : twos)
  //   all_indx.push_back(ic);
  // int indx = sz(all_indx) - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] != b[i]) {
      for (auto ic : a)
        cout << ic << " ";
      cout << "\n";
      cout << i << " " << a[i] << " " << b[i] << "\n";
      // assert(abs(a[i] - b[i]) == 2);
      if (a[i] == 0) {
        if (b[i] == 2) {
          ll lst_o = *ones.begin();
          ones.erase(lst_o);
          zeros.erase(i);
          ans.emplace_back(lst_o + 1, i + 1);
          fn(lst_o, i, a);
          zeros.insert(lst_o);
          ll fst_t = *twos.begin();
          twos.erase(fst_t);
          ans.emplace_back(fst_t + 1, i + 1);
          fn(fst_t, i, a);
          ones.insert(fst_t);
        } else {
          ll fst_o = *ones.begin();
          ones.erase(fst_o);
          zeros.erase(i);
          ans.emplace_back(fst_o + 1, i + 1);
          fn(fst_o, i, a);
          if (ones.size() == 0)
            ones.insert(fst_o);
        }
      } else if (a[i] == 1) {
        if (b[i] == 0) {
          ll lst_z = *zeros.rbegin();
          zeros.erase(lst_z);
          ones.erase(i);
          ans.emplace_back(lst_z + 1, i + 1);
          fn(lst_z, i, a);
          if (ones.size() == 0)
            ones.insert(lst_z);
        } else {
          ll fst_t = *twos.begin();
          twos.erase(fst_t);
          ones.erase(i);
          ans.emplace_back(fst_t + 1, i + 1);
          fn(fst_t, i, a);
          if (ones.size() == 0)
            ones.insert(fst_t);
        }
      } else {
        // ll fst_o = *ones.begin();
        // ones.erase(fst_o);
        // twos.erase(i);
        // ans.emplace_back(fst_o + 1, i + 1);
        // fn(fst_o, i, a);
        // ones.insert(fst_o);
        // ll lst_t = *twos.rbegin();
        // twos.erase(lst_t);
        // ans.emplace_back(lst_t + 1, i + 1);
        // fn(lst_t, i, a);
        // if (ones.size() == 0)
        //   ones.insert(lst_t);
      }
    }
  }
  // for (auto ic : a) {
  //   cout << ic << " ";
  // }
  // cout << "\n";
  // assert(a == b);
  // assert(sz(ans) <= n);
  cout << sz(ans) << "\n";
  for (auto [x, y] : ans) {
    cout << x << " " << y << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
