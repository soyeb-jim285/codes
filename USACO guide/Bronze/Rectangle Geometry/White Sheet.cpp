#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
struct pt {
  ll x, y;
};
void solve() {
  vector<vector<pt>> rec(3, vector<pt>(4));
  for (int i = 0; i < 3; i++) {
    cin >> rec[i][0].x >> rec[1][0].y >> rec[i][2].x >> rec[i][2].y;
    rec[i][1].x = rec[i][2].x;
    rec[i][1].y = rec[i][0].y;
    rec[i][3].x = rec[i][0].x;
    rec[i][3].y = rec[i][2].y;
  }
  for (int i = 0; i < 2; i++) {
    if (rec[i + 1][0].x < rec[0][2].x)
      rec[i + 1][0].x = rec[0][2].x;
    else
      rec[i + 1][0].x = 0;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
