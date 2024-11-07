# Tutorial_(en)

[A — Burenka Plays with Fractions](../problems/A._Burenka_Plays_with_Fractions.md)
---------------------------------------------------------------------------------

Authors: [glebustim](https://codeforces.com/profile/glebustim "Master glebustim")

 **Solution**Note that we always can make fractions equal in two operations: Multiply first fraction's enumerator by bc, the first fraction is equal to abcb=ac, Multiply second fraction's enumerator by ad, the second fraction is equal to acdd=ac.

That means that the answer does not exceed 2. 

If fractions are equal from input, the answer is 0. Otherwise, it can't be 0.

Now we have to check if the answer is 1. Let's assume that for making fractions equal in 1 operation we have to multiply first fraction's enumerator by x. Then axb=cd must be true. From this we can see that x=bcad. x must be integer, so bc must be divisible by ad. If we assume that we multiplied first fraction's denumerator by x, we can do the same calculations and see that ad must be divisible by bc. So, for checking if the answer is 1 we need to check if one of ad and bc is divisible by another one. If we multiply second fraction's enumerator or denumerator by x we will get the same conditions for answer being equla to 1.

If the answer is not 0 or 1, it's 2.

Complexity: O(1)

 **Code(C++)**
```cpp
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sfor(i, l, r) for (int i = l; i <= r; ++i)
#define bfor(i, r, l) for (int i = r; i >= l; --i)
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using oset = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x = a * d, y = b * c;
    if (x == y)
        cout << "0n";
    else if (y != 0 && x % y == 0 || x != 0 && y % x == 0)
        cout << "1n";
    else
        cout << "2n";
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}


```
[B — Interesting Sum](../problems/B._Interesting_Sum.md)
--------------------------------------------------------------------

 **Solution**Obviously, answer does not exceed max1+max2−min1−min2, where max1,max2 are two maximum values in the array, and min1,min2 are two minimum values. Let's find a segment, such as this is true. For that we will look at all positions containing max1 or max2 (S1) and all positions containing min1 or min2 (S2). After that we choose a pair l∈S1, r∈S2, such as abs(r−l) is minimum possible. Complexity: O(nlogn)

 **Code(C++)**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

vector<ll> vec;
ll n;

int main() {
	fastInp;

	ll t;
	cin >> t;

	while (t--) {
		cin >> n;

		vec.resize(n);
		for (auto& c : vec) cin >> c;

		sort(vec.begin(), vec.end());

		cout << vec[n - 1] + vec[n - 2] - vec[0] - vec[1] << "n";
	}

	return 0;
}

```
[C — Corners](../problems/C._Corners.md)
------------------------------------------------------------

Authors: [daubi](https://codeforces.com/profile/daubi "Grandmaster daubi")

 **Solution**Let's say that cnt1 is the number of ones in the table.

Note that if there is a connected area of zeros in the table of size at least 2, then we can add one 0 to this area by replacing only one 1 in the table. That means that if we have such area we can fill the table with zeros in cnt1 operations (we can't make more opertions because we need to replace at least one 1 by operation).

There can be no such area in the beginning, but after first operation it will appear. So, for finding the answer we just need to find an angle with minimal number of 1 in it, and which we can replace.

Complexity: O(nm)

 **Code(C++)**
```cpp
  
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>
#include <queue>
#include <complex>
#include <functional>

using namespace std;
const int INF = 1e9;
const int MAXN = 2000;
int a[MAXN][MAXN];

inline void solve1() {
    int n, m, sum = 0;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[j] - '0';
            sum += a[i][j];
        }
    }
    int minn = INF;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int cnt = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
            if (cnt == 0) continue;
            minn = min(minn, max(1, cnt - 1));
        }
    }
    if (sum == 0) cout << "0n";
    else cout << 1 + sum - minn << "n";
}

signed main() {
     int t = 1;
     cin >> t;
     while (t--) {
        solve1();
     }
}

```
[D1 — Xor-Subsequence (easy version)](../problems/D1._Xor-Subsequence_(easy_version).md)
--------------------------------------------------------------------------------------

Authors: [kirill.kligunov](https://codeforces.com/profile/kirill.kligunov "Expert kirill.kligunov")

 **Solution**Let's use dynamic programming to solve this task. dpi -- maximum length of good subsequence, that ends int i-th element of a, than naive solution is 

 dpi=maxij=0aj⊕i<ai⊕jdpj+1Let's observe that aj⊕i changes i not more than by 200.

This way we can relax dpi not from j=0, but j=i−512, because xor operation changes only last 8 bits, so for j′<i−512, definitely aj′⊕j>aj⊕j′.

Additional idea:

It not so hard to proove that we can try j from i−256 to i−1.

 **Code(C++)**
```cpp
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

vector<ll> vec;
ll n;

const ll CHECK = 512;

int solve() {

	cin >> n;

	vec.resize(n);
	for (auto& c : vec) cin >> c;

	vector<ll> dp(1);

	ll bst = 0;
	for (int i = 0; i < n; i++) {
		ll cur = 0;
		dp.push_back(1);
		for (int j = i - 1; j >= max(0ll, i - CHECK); j--) {
			if ((vec[i] ^ j) > (vec[j] ^ i)) {
				dp.back() = max(dp.back(), dp[j + 1] + 1);
			}
		}
		
		bst = max(bst, dp.back());
	}

	cout << bst << "n";

	return 0;
}

int main(){
    fastInp;
    int t;
    cin >> t;
    while(t--) solve();
}
```
[D2 — Xor-Subsequence (hard version)](../problems/D2._Xor-Subsequence_(hard_version).md)
--------------------------------------------------------------------------------------

Authors: [kirill.kligunov](https://codeforces.com/profile/kirill.kligunov "Expert kirill.kligunov")

 **Solution**Let's calculate answer for each prefix. Let's find answer if the last number in our subsequence is number with index i.

Let there be such j that a[j]⊕i<a[i]⊕j. That means that there are k bits in numbers a[j]⊕i and a[i]⊕j which are the same, and after that a[j]⊕i has different k+1-th bit. Let's notice that if first k bits are the same in a[j]⊕i and a[i]⊕j, then these bits are the same in a[j]⊕j and a[i]⊕i

Let's keep our answer in bit trie. We will add numbers a[j]⊕j for our prefix. To find dp value for index i, we will descend in our trie with pair of integers ai⊕i and i. Each time we descend with bit l(0 or 1), in the opposite subtree there might be numbers which we can use to recalculate our answer. If in that subtree exists indexс j, then k+1-th bit of a[j]⋅i to 0. Let's keep such dp for every subtree: maximum value of dp[j] for every j, such that j lies in the subtree (but we need to keep answer if k-th bit of j is 0, and if it's equals 1). We should try to improve our answer using j if we descend to the opposite subtree. Then we can easily find answer for current i. After that we only need to add our number in the trie and recalculate the dp.

Complexity: O(n * logC) where C its max value

 **Code(C++)**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxlog = 30;
const int maxn = 300000;

int nodes[maxn * maxlog + maxlog][2];
int nodev[maxn * maxlog + maxlog][2];
int last;

inline int f() {
    nodes[last][0] = 0;
    nodes[last][1] = 0;
    nodev[last][0] = 0;
    nodev[last][1] = 0;
    return last++;
}

int solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    for (auto& i : v) cin >> i;
    int ans = 0;
    last = 0;
    f();
    for (int i = 0; i < n; i++) {
        int a = 0;
        int b = v[i] ^ i;
        int c = i;
        int getmax = 0;
        for (int j = maxlog; j >= 0; j--) {
            if (nodes[a][((b >> j) & 1) ^ 1]) getmax = max(getmax, nodev[nodes[a][((b >> j) & 1) ^ 1]][(((b ^ c) >> j) & 1) ^ 1]);
            if (!nodes[a][(b >> j) & 1]) break;
            a = nodes[a][(b >> j) & 1];
        }
        ans = max(ans, getmax + 1);
        a = 0;
        b = v[i] ^ i;
        c = i;
        int d = getmax + 1;
        for (int j = maxlog; j >= 0; j--) {
            if (!nodes[a][(b >> j) & 1]) nodes[a][(b >> j) & 1] = f();
            nodev[nodes[a][(b >> j) & 1]][(c >> j) & 1] = max(nodev[nodes[a][(b >> j) & 1]][(c >> j) & 1], d);
            a = nodes[a][(b >> j) & 1];
        }
    }
    cout << ans << "n";
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
```
[E — Misha and Paintings](../problems/E._Misha_and_Paintings.md)
------------------------------------------------------------------------

Authors: [daubi](https://codeforces.com/profile/daubi "Grandmaster daubi"), [pakhomovee](https://codeforces.com/profile/pakhomovee "Master pakhomovee")

 **Solution**If k is greater than the number of different numbers in the matrix, then the answer is k minus the number of different elements.

Otherwise the answer does not exceed 2.

Let's proof that: choose the maximum square (let its side be equal to L), containing the top left corner of the matrix, such as recolouring it to some new colour makes the number of different colours in the table at least k.

If the number of different colours after recolouring is greater than k, then choose a square with bottom right corner in (L+1,L+1), such as recolouring it makes the number of different colours at least k. If we got exactly k colours then we are done. Otherwise let's extend the square by one. We got k or k−1 different colours. This way, by choosing the correct colour of the square we can get exactly k colours. Otherwise we are done.

It remains to learn how to check whether the answer is equal to 1. We will iterate over length of the side of the square of the answer. Now we need O(n2) to check whether the required square with such a side exists. To do this, we calculate for each square in the table with such a side length (there are n2 such squares), how many numbers this square completely covers (all appeareances of this numbers are in thsi square). To do this, let's iterate over the number c. Having considered its occurrences, it is easy to understand that the upper left corners of all squares with our side length, covering all cells with the number c, lie in some subrectangle of the table, so you can simply add 1 on this subrectangle using offline prefix sums. Having processed all the numbers in this way, we can count for each square how many numbers it covers completely, and therefore check whether it fits the requirements.

Complexity: O(n3)

 **Code(C++)**
```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;
const int INF = 1e9;

inline int min(int a, int b) {
    if (a < b) return a;
    return b;
}

inline int max(int a, int b) {
    if (a > b) return a;
    return b;
}

inline void solve1() {
    int n, k, cnt = 0;
    cin >> n >> k;
    vector <vector <int>> a(n, vector <int>(n)), pref(n + 1, vector <int>(n + 1));
    vector <array <int, 4>> all(n * n, { INF, -INF, INF, -INF });
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j]; --a[i][j];
            all[a[i][j]][0] = min(all[a[i][j]][0], i);
            all[a[i][j]][1] = max(all[a[i][j]][1], i);
            all[a[i][j]][2] = min(all[a[i][j]][2], j);
            all[a[i][j]][3] = max(all[a[i][j]][3], j);
        }
    }
    for (auto& i : all) {
        if (i[0] != INF) ++cnt;
    }
    if (cnt <= k) {
        cout << k - cnt;
        return;
    }
    for (int len = 1; len <= n; ++len) {
        for (auto& i : all) {
            if (i[0] == INF) continue;
            int mn_x = i[0], mx_x = i[1], mn_y = i[2], mx_y = i[3];
            mx_x = max(0, mx_x - len + 1);
            mx_y = max(0, mx_y - len + 1);
            mn_x = min(mn_x, n - len);
            mn_y = min(mn_y, n - len);
            if (mx_x <= mn_x && mx_y <= mn_y) {
                ++pref[mx_x][mx_y];
                --pref[mx_x][mn_y + 1];
                --pref[mn_x + 1][mx_y];
                ++pref[mn_x + 1][mn_y + 1];
            }
        }
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (x == 0 && y == 0) continue;
                else if (x == 0) pref[x][y] += pref[x][y - 1];
                else if (y == 0) pref[x][y] += pref[x - 1][y];
                else pref[x][y] += pref[x - 1][y] + pref[x][y - 1] - pref[x - 1][y - 1];
            }
        }
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (cnt - pref[x][y] == k || cnt - pref[x][y] + 1 == k) {
                    cout << 1;
                    return;
                }
            }
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                pref[i][j] = 0;
            }
        }
    }
    cout << 2;
}

int main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        //   cin >> t;
        while (t--) {
            solve1();
        }
    }

    return 0;
}


```
