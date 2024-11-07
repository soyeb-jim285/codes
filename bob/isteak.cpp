#include <bits/stdc++.h>
using namespace std;
#define int long long int

void test_case() {
  pair<int, int> st, en;
  cin >> st.first >> st.second;
  cin >> en.first >> en.second;
  int n;
  cin >> n;
  vector<array<int, 3>> lines(n);
  for (auto &[a, b, c] : lines)
    cin >> a >> b >> c;
  // two points are same
  if (st == en) {
    cout << "Possible\n";
    return;
  }
  auto present_in_line = [&](int x, int y, int i) {
    auto [a, b, c] = lines[i];
    return a * x + b * y + c == 0;
  };

  auto check_two_points_in_same_line = [&](int x1, int y1, int x2, int y2) {
    for (int i = 0; i < n; i++) {
      if (present_in_line(x1, y1, i) && present_in_line(x2, y2, i))
        return true;
    }
    return false;
  };

  // two points are in same line
  if (check_two_points_in_same_line(st.first, st.second, en.first, en.second)) {
    cout << "Possible\n";
    return;
  }

  // two points are in different lines and all the lines are not parallel
  auto check_point_in_any_line = [&](int x, int y) {
    for (int i = 0; i < n; i++) {
      if (present_in_line(x, y, i))
        return true;
    }
    return false;
  };

  bool okay = check_point_in_any_line(st.first, st.second) &&
              check_point_in_any_line(en.first, en.second);
  set<pair<int, int>> slope;
  for (auto [a, b, c] : lines) {
    int g = __gcd(a, b);
    a /= g, b /= g;
    // cout << "a: " << a << " b: " << b << '\n';
    // cout << "g: " << g << '\n';
    slope.insert({a, b});
  }
  okay &= ((int)slope.size() != 1);
  //   cout << "okay: " << okay << '\n';
  // cout << "slope.size(): " << slope.size() << '\n';
  cout << (okay ? "Possible" : "Impossible") << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;

  for (int cs = 1; cs <= t; cs++) {
    // cout << "Case " << cs << ": ";
    test_case();
  }

  return 0;
}
