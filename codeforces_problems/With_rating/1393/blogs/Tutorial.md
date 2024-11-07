# Tutorial

[1393A - Rainbow Dash, Fluttershy and Chess Coloring](../problems/A._Rainbow_Dash,_Fluttershy_and_Chess_Coloring.md "Codeforces Round 662 (Div. 2)") 

Idea: [AlFlen](https://codeforces.com/profile/AlFlen "Master AlFlen")

 **Tutorial**
### [1393A - Rainbow Dash, Fluttershy and Chess Coloring](../problems/A._Rainbow_Dash,_Fluttershy_and_Chess_Coloring.md "Codeforces Round 662 (Div. 2)")

By modeling the game on different grids it was possible to notice that the answer is equal to $\lfloor \frac{n}{2} \rfloor + 1$. You can prove that this is the answer by using induction method separately for grids with even and odd sides.

Initially it was asked to solve the problem for rectangular grids. You can think about this version of the problem.

 **Solution (74TrAkToR)**
```cpp
#include<bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << n / 2 + 1 << 'n';
    }
    return 0;
}
```
[1393B - Applejack and Storages](../problems/B._Applejack_and_Storages.md "Codeforces Round 662 (Div. 2)")

Idea: [74TrAkToR](https://codeforces.com/profile/74TrAkToR "Master 74TrAkToR")

 **Tutorial**
### [1393B - Applejack and Storages](../problems/B._Applejack_and_Storages.md "Codeforces Round 662 (Div. 2)")

Let's maintain the array $cnt_i$, in it we are going to store the number of planks for each length. Let's note that to be able to build a square and a rectangle we need to have four planks of the same length and also two pairs of planks of the same length. To check it we can maintain two values: $sum2=\sum_{i=1}^{10^5}\lfloor \frac{cnt_i}{2}\rfloor$ and $sum4=\sum_{i=1}^{10^5}\lfloor \frac{cnt_i}{4}\rfloor$. Then, you will be able to build a square and a rectangular storage if $sum4 \ge 1$ and $sum2 \ge 4$. The first constraint satisfies the requirement about a square (you should have $\ge 4$ planks of some length), and the second constraint satisfies the requirement about a rectangle (two pairs of the same length should be used and also two pairs are already used in the square).

 **Solution (74TrAkToR)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int const MAXN = 1e5 + 5;
int cnt[MAXN];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q, x, cnt2 = 0, cnt4 = 0;
    char type;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> x;
        
        cnt2 -= cnt[x] / 2;
        cnt4 -= cnt[x] / 4;
        cnt[x]++;
        cnt2 += cnt[x] / 2;
        cnt4 += cnt[x] / 4;
    }

    cin >> q;

    for (int i = 1; i <= q; ++i) {
        cin >> type >> x;
        cnt2 -= cnt[x] / 2;
        cnt4 -= cnt[x] / 4;
        
        if (type == '+') cnt[x]++;
        else cnt[x]--;
        
        cnt2 += cnt[x] / 2;
        cnt4 += cnt[x] / 4;
        
        if (cnt4 >= 1 && cnt2 >= 4) cout << "YES" << 'n';
        else cout << "NO" << 'n';
    }
    
    return 0;
}
```
[1393C - Pinkie Pie Eats Patty-cakes](../problems/C._Pinkie_Pie_Eats_Patty-cakes.md "Codeforces Round 662 (Div. 2)")

Idea: [74TrAkToR](https://codeforces.com/profile/74TrAkToR "Master 74TrAkToR") и [lapochka_queen](https://codeforces.com/profile/lapochka_queen "Unrated, lapochka_queen")

 **Tutorial**
### [1393C - Pinkie Pie Eats Patty-cakes](../problems/C._Pinkie_Pie_Eats_Patty-cakes.md "Codeforces Round 662 (Div. 2)")

Let's note that if you can find the arrangement with the maximum distance $\geq X$, then you can also find the arrangement with the maximum distance $\geq X-1$. It allows you to use the binary search on the answer.

To check that the answer is at least $X$, we can use the greedy algorithm. Each time let's use the element that we can use (we didn't use it on the last $x-1$ steps) and the number of the remaining elements equal to it is as large as possible. You can store the set of elements that you can use in the sorted by the number of appearances in $std::set$. This sol works $O(n log^2 n)$.

Also there is a solution in $O(n)$.

 **Solution (AlFlen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100009;
int cnt[MAXN];
vector<int> a;
int n;

bool check(int x) {
    for (int i = 1; i <= n; i ++) cnt[i] = 0;
    for (int i = 0; i < n; i ++) cnt[a[i]]++;

    set<pair<int, int>, greater<pair<int, int>>> ss; //use greater comparator to sort set in descending order
    for (int i = 1; i <= n; i ++) {
        if (cnt[i] > 0) ss.insert({cnt[i], i});
    }

    vector<int> b;
    for (int i = 0; i < n; i ++) {
        if (i >= x && cnt[b[i - x]]) {
            ss.insert({cnt[b[i - x]], b[i - x]});
        }

        if (ss.empty()) return 0;
        b.push_back(ss.begin()->second);
        ss.erase(ss.begin());
        cnt[b.back()]--;
    }

    return 1;
}

signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int ttt;
	cin >> ttt;

	while (ttt--) {
        cin >> n;

        a.resize(n);
        for (int i = 0; i < n; i ++) {
            cin >> a[i];
        }

        int l = 0, r = n;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (check(m)) {
                l = m;
            }

            else {
                r = m;
            }
        }

        cout << l - 1 << "n";
	}

	return 0;
}
```
[1393D - Rarity and New Dress](../problems/D._Rarity_and_New_Dress.md "Codeforces Round 662 (Div. 2)")

Idea: [74TrAkToR](https://codeforces.com/profile/74TrAkToR "Master 74TrAkToR")

 **Tutorial**
### [1393D - Rarity and New Dress](../problems/D._Rarity_and_New_Dress.md "Codeforces Round 662 (Div. 2)")

Let's note that if there is a rhombus of size $X$ in the cell $(i, j)$, then there are also rhombuses with the smaller sizes.

Let's divide the rhombus into the left part and the right part. Let's solve the problem separately for both of them and then the answer for the cell is going to be equal to the minimum of these values.

Note that if the maximum size for the cell $(i, j)$ is $X$, then the maximum size for the cell $(i, j+1)$ is at most $X+1$ (and at most $1$, if these two cells are not equal). Also the maximums size for the left part is at most minimum of the number of consecutive cells to the up and to left from the fixed cell.

To find the number of consective equal cells to the up, we will use the dynamic programming. If the cells $(i, j)$ and $(i-1, j)$ are equal, then the answer for the cell $(i, j)$ is equal to the answer for the cell $(i-1, j)$ plus $1$, otherwise it is equal to $1$. Similarly we can find the answer for the cells to the left.

Now we need to find the maximum size of the left part. We can use dynamic programming and calculate it accordingly to our observations.

Similarly for the right part.

The total complexity is $O(nm)$.

 **Solution (74TrAkToR)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 2005;
char a[maxn][maxn];
int cnt_up[maxn][maxn], cnt_down[maxn][maxn], L[maxn], R[maxn];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i != 1 && a[i][j] == a[i - 1][j]) cnt_up[i][j] = cnt_up[i - 1][j] + 1;
            else cnt_up[i][j] = 0;
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            if (i != n && a[i][j] == a[i + 1][j]) cnt_down[i][j] = cnt_down[i + 1][j] + 1;
            else cnt_down[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int go = j;
            while (go <= m && a[i][j] == a[i][go]) go++;
            go--;
            for (int pos = j; pos <= go; ++pos) {
                if (pos == j) L[pos] = pos;
                else {
                    L[pos] = max(L[pos - 1], pos - min(cnt_up[i][pos], cnt_down[i][pos]));
                }
            }
            j = go;
        }
        for (int j = m; j >= 1; --j) {
            int go = j;
            while (go >= 1 && a[i][j] == a[i][go]) go--;
            go++;
            for (int pos = j; pos >= go; --pos) {
                if (pos == j) R[pos] = pos;
                else {
                    R[pos] = min(R[pos + 1], pos + min(cnt_up[i][pos], cnt_down[i][pos]));
                }
            }
            j = go;
        }
        for (int j = 1; j <= m; ++j) {
            ans += (ll)min(j - L[j] + 1, R[j] - j + 1);
        }
    }
    cout << ans << 'n';
    return 0;
}

```
[1393E2 - Twilight and Ancient Scroll (harder version)](../problems/E2._Twilight_and_Ancient_Scroll_(harder_version).md "Codeforces Round 662 (Div. 2)")

Idea: [AlFlen](https://codeforces.com/profile/AlFlen "Master AlFlen")

 **Tutorial**
### [1393E2 - Twilight and Ancient Scroll (harder version)](../problems/E2._Twilight_and_Ancient_Scroll_(harder_version).md "Codeforces Round 662 (Div. 2)")

Let's use dynamic programming. $dp[i][j]$: the number of ways to form the non-decreasing subsequence on the strings $1 \ldots i$, s.t. the delete character in string $i$ is $j$. This works in $O(L^3)$, where $L$ is the total length of all strings.

Let's optimize this solution. For each string, sort all strings obtained by deleting at most one character from this string. You can do it in $O(L^2 \cdot log L)$ for all strings. Then you can use two pointers to calculate or dp. To calculate the answer for the layer $i$ we will consider strings in the sorted order, and add all dp values for the smaller strings. We can calculate this dp in $O(L^2)$ and solve the problem in $O(L^2 \cdot log L)$. We can use binary search and hash to compare strings in $O(log L)$. Then you can sort all the strings in $O(L \cdot log^2 L)$.

Note that you can sort the strings in $O(L)$. Look at the string $s$. For each character find the first character to the right not equal to it (array $nxt[i]$). Then we will store two pointers: to the beginning and the end of the list. Consider characters in the order from left to right. If $s_i$ > $s_{nxt[i]}$, add $i$ to the beginning of the list (to the position $l$ and increase $l$ by $1$), otherwise add it to the end of the list (to the position $r$ and decrease $r$ by $1$). Then add $s$ to some position in the list ($s$ will be in the list after it without the last character). Then you can use the hash to make the comparisons for two pointers in $O(log L)$. This sol works in $O(L \cdot log L)$ and fits into TL.

 **Solution (74TrAkToR)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 1e5 + 5, maxc = 1e6 + 5;
ll mod[2], P[2], p[2][maxc], rev_P[2];
vector < ll > h[2][maxn];
vector < int > sorted[maxn];
string s[maxn];
int nxt[maxc];
int a[maxc], dp[2][maxc], inf = 1e9 + 7;
int MOD = 1e9 + 7;

ll st(ll x, int y, int ok) {
    if (y == 0) return 1;
    if (y % 2 == 0) {
        ll d = st(x, y / 2, ok);
        return d * d % mod[ok];
    }
    return x * st(x, y - 1, ok) % mod[ok];
}

inline char get_c(int i, int x, int numb) {
    if (numb < x) return s[i][numb];
    if (numb + 1 < (int)s[i].size()) return s[i][numb + 1];
    return ' ';
}

inline ll get_hash(int t, int i, int x, int len) {
    if (len < x) return h[t][i][len];
    return (h[t][i][x] + (h[t][i][len + 1] - h[t][i][x + 1] + mod[t]) * rev_P[t]) % mod[t];
}

inline pair < ll, ll > get_h(int i, int x, int len) {
    return {get_hash(0, i, x, len), get_hash(1, i, x, len)};
}

inline int check(int i, int x, int j, int y) {
    int len1 = (int)s[i].size(), len2 = (int)s[j].size();
    if (x != len1) len1--;
    if (y != len2) len2--;
    int lef = 0, righ = min(len1, len2) + 1;
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        if (get_h(i, x, mid) == get_h(j, y, mid)) lef = mid;
        else righ = mid;
    }
    return get_c(i, x, lef) >= get_c(j, y, lef);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mod[0] = 1e9 + 7, mod[1] = 1e9 + 9, P[0] = 29, P[1] = 31, rev_P[0] = st(P[0], mod[0] - 2, 0), rev_P[1] = st(P[1], mod[1] - 2, 1);
    p[0][0] = 1, p[1][0] = 1;
    for (int i = 1; i < maxc; ++i) {
        for (int j = 0; j <= 1; ++j) p[j][i] = p[j][i - 1] * P[j] % mod[j];
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        for (int j = 0; j <= 1; ++j) {
            h[j][i].push_back(0);
            for (int pos = 0; pos < (int)s[i].size(); ++pos) {
                h[j][i].push_back((h[j][i][pos] + p[j][pos] * (s[i][pos] - 'a' + 1)) % mod[j]);
            }
        }
        nxt[(int)s[i].size() - 1] = (int)s[i].size() - 1;
        for (int pos = (int)s[i].size() - 2; pos >= 0; --pos) {
            if (s[i][pos] != s[i][pos + 1]) nxt[pos] = pos + 1;
            else nxt[pos] = nxt[pos + 1];
        }
        int l = 0, r = (int)s[i].size() - 1;
        for (int j = 0; j < (int)s[i].size(); ++j) {
            if (s[i][nxt[j]] <= s[i][j]) a[l++] = j;
            else a[r--] = j;
        }
        for (int j = 0; j < (int)s[i].size(); ++j) {
            sorted[i].push_back(a[j]);
            if (a[j] == (int)s[i].size() - 1) sorted[i].push_back((int)s[i].size());
        }
    }
    for (int i = 0; i <= (int)s[1].size(); ++i) {
        dp[0][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        int oks = (i - 1) % 2, ptr = 0, sum = 0, cur = -1;
        for (auto key : sorted[i]) {
            cur++;
            while (ptr < (int)sorted[i - 1].size() && check(i, key, i - 1, sorted[i - 1][ptr])) {
                sum += dp[(1^oks)][ptr];
                if (sum >= MOD) sum -= MOD;
                ptr++;
            }
            dp[oks][cur] = sum;
        }
    }
    int ans = 0;
    for (int i = 0; i <= (int)s[n].size(); ++i) {
        ans += dp[(n - 1) % 2][i];
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << 'n';
    return 0;
}
```
