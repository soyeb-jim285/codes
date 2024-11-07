#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void vertical(char x, vector<vector<char>> &grd,
              vector<vector<pair<int, int>>> &all_fours) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 7; j++) {
      if (grd[i][j] == x && grd[i + 1][j] == x && grd[i + 2][j] == x &&
          grd[i + 3][j] == x) {
        all_fours.push_back({{i, j}, {i + 1, j}, {i + 2, j}, {i + 3, j}});
      }
    }
  }
}
void horizontal(char x, vector<vector<char>> &grd,
                vector<vector<pair<int, int>>> &all_fours) {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      if (grd[i][j] == x && grd[i][j + 1] == x && grd[i][j + 2] == x &&
          grd[i][j + 3] == x) {
        all_fours.push_back({{i, j}, {i, j + 1}, {i, j + 2}, {i, j + 3}});
      }
    }
  }
}
void diagonal(char x, vector<vector<char>> &grd,
              vector<vector<pair<int, int>>> &all_fours) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      if (grd[i][j] == x && grd[i + 1][j + 1] == x && grd[i + 2][j + 2] == x &&
          grd[i + 3][j + 3] == x) {
        all_fours.push_back(
            {{i, j}, {i + 1, j + 1}, {i + 2, j + 2}, {i + 3, j + 3}});
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 3; j < 7; j++) {
      if (grd[i][j] == x && grd[i + 1][j - 1] == x && grd[i + 2][j - 2] == x &&
          grd[i + 3][j - 3] == x) {
        all_fours.push_back(
            {{i, j}, {i + 1, j - 1}, {i + 2, j - 2}, {i + 3, j - 3}});
      }
    }
  }
}
void find_fours(char x, vector<vector<char>> &grd,
                vector<vector<pair<int, int>>> &all_fours) {
  vertical(x, grd, all_fours);
  horizontal(x, grd, all_fours);
  diagonal(x, grd, all_fours);
}
bool canwin(char x, vector<vector<char>> &grd) {
  vector<vector<pair<int, int>>> all_fours;
  find_fours(x, grd, all_fours);
  char rest;
  if (x == 'C') {
    rest = 'F';
  } else {
    rest = 'C';
  }
  bool ans = 0;
  for (int i = 0; i < sz(all_fours); i++) {
    vector<vector<char>> below_grd(6, vector<char>(7, '.'));
    for (int j = 0; j < 4; j++) {
      ll ro = all_fours[i][j].first;
      for (int ii = ro + 1; ii < 6; ii++) {
        below_grd[ii][all_fours[i][j].second] = grd[ii][all_fours[i][j].second];
      }
    }
    vector<vector<pair<int, int>>> all_fours_below;
    find_fours(rest, below_grd, all_fours_below);
    if (sz(all_fours_below) == 0) {
      ans = 1;
      return ans;
    }
  }
  return ans;
}
void solve() {
  vector<vector<char>> grd(6, vector<char>(7));
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 7; j++) {
      cin >> grd[i][j];
    }
  }
  cout << canwin('C', grd) << " " << canwin('F', grd) << endl;
  if (canwin('C', grd) && canwin('F', grd)) {
    cout << "?\n";
  } else if (canwin('C', grd)) {
    cout << "C\n";
  } else if (canwin('F', grd)) {
    cout << "F\n";
  } else {
    cout << "0\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cout << "Case #" << tt++ << ": ";
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
