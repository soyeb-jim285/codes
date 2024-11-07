#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  vector<ll> a = {1, 2, 3, 4, 5, 6, 7, 8};
  map<vector<ll>, ll> mp;
  while (next_permutation(a.begin(), a.end())) {
    vector<ll> b = {1, 2, 3, 4, 5, 6, 7, 8};
    ll ct = 0;
    for (int i = 0; i < b.size(); i++) {
      if (b[i] < a[b[i] - 1]) {
        b[i] = a[b[i] - 1];
        i--;
      }
    }
    mp[b]++;
    /* cout << "---a---\n"; */
    /* for (auto ic : a) { */
    /*   cout << ic << " "; */
    /* } */
    /* cout << endl; */
    /* for (auto ic : b) { */
    /*   cout << ic << " "; */
    /* } */
    /* cout << endl; */
  }
  /* for (auto ic : mp) { */
  /*   cout << "---mp---\n"; */
  /*   for (auto jc : ic.first) { */
  /*     cout << jc << " "; */
  /*   } */
  /*   cout << endl; */
  /*   cout << ic.second << endl; */
  /* } */
  /* cout << mp.size() << endl; */
  cout << mp[{1, 2, 3, 4, 8, 7, 7, 8}] << endl;
  cout << mp[{1, 2, 5, 4, 5, 8, 7, 8}] << endl;
  cout << mp[{1, 2, 8, 7, 6, 6, 7, 8}] << endl;
  cout << mp[{1, 8, 7, 6, 5, 6, 7, 8}] << endl;
  cout << mp[{1, 2, 3, 8, 7, 6, 7, 8}] << endl;
  cout << mp[{1, 2, 8, 7, 5, 6, 7, 8}] << endl;
  cout << mp[{1, 8, 7, 4, 5, 6, 7, 8}] << endl;
  cout << mp[{1, 2, 3, 4, 5, 6, 7, 8}] << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  /* freopen("output.txt", "w", stdout); */
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
