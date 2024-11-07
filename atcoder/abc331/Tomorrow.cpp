#include <iostream>
using namespace std;
typedef long long ll;
typedef long double ld;
void solve() {
  ll mn, dd;
  cin >> mn >> dd;
  ll y, m, d;
  cin >> y >> m >> d;
  d++;
  if (d > dd) {
    d = 1;
    m++;
    if (m > mn) {
      m = 1;
      y++;
    }
  }
  cout << y << " " << m << " " << d << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
