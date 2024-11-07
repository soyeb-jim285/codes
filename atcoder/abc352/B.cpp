#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  int cnt = 0;
  for (int i = 0; i < s2.size(); i++) {
    if (s1[cnt] == s2[i]) {
      cnt++;
      cout << i + 1 << " ";
    }
  }
  cout << endl;
}
int main() { solve(); }
