#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    pair<int, int> A, B;
    cin >> A.first >> A.second >> B.first >> B.second;

    int n;
    cin >> n;
    set<pair<int, int>> sa, sb;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int d = __gcd(a, b);
        int k = 0, cnt = 0;
        if (a * A.first + b * A.second + c == 0) cnt++;
        if ()
            if ((a < 0 && b >= 0) || (b < 0 && a >= 0)) k = 1;
        a = abs(a), b = abs(b);
        a /= d, b /= d;
        if (k) a = -a;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
#ifdef ONPC
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
