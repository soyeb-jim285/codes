# Tutorial

[1811A - Insert Digit](../problems/A._Insert_Digit.md "Codeforces Round 863 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin"), prepared: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1811A - Insert Digit](../problems/A._Insert_Digit.md "Codeforces Round 863 (Div. 3)")

Note that numbers of the same length are compared lexicographically. That is, until some index the numbers will match, and then the digit in our number should be greater.

Let's write out the numbers s1,s2,…si until si≥d. As soon as this condition is false or the line ends, insert the digit d.

We got the lexicographically maximum number, which means just the maximum number.

 **Solution**
```cpp
#include <iostream>

using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] - '0' >= d) {
            cout << s[i];
        } else {
            cout << d;
            for (int j = i; j < n; ++j) {
                cout << s[j];
            }
            cout << 'n';
            return;
        }
    }
    cout << d << 'n';
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        solve();
    }
    return 0;
}
```
[1811B - Conveyor Belts](../problems/B._Conveyor_Belts.md "Codeforces Round 863 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), prepared: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1811B - Conveyor Belts](../problems/B._Conveyor_Belts.md "Codeforces Round 863 (Div. 3)")

Note that the conveyor matrix $n \times n$ consists of $n$ cycles, through each of which we can move without wasting energy. Now you need to find the distance between the cycles where the start and end cells are located. In one step from any cycle, you can go either to the cycle that is closer to the edge of the matrix, or to the cycle that is further from the edge of the matrix. It turns out that it is enough to find on which cycles there are cells on the edge and take their difference modulo.

 **Solution**
```cpp
def layer(n, x, y):
    return min([x, y, n + 1 - x, n + 1 - y])


def solve():
    n, x1, y1, x2, y2 = map(int, input().split())
    print(abs(layer(n, x1, y1) - layer(n, x2, y2)))


t = int(input())
for _ in range(t):
    solve()
```
[1811C - Restore the Array](../problems/C._Restore_the_Array.md "Codeforces Round 863 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), prepared: [myav](https://codeforces.com/profile/myav "Pupil myav")

 **Tutorial**
### [1811C - Restore the Array](../problems/C._Restore_the_Array.md "Codeforces Round 863 (Div. 3)")

To solve the problem, you can build an array $a$ as follows 

* $a_1 = b_1$
* $a_i = \min(b_{i-1}, b_i)$ at $2 \le i \le n-1$
* $a_n = b_{n-1}$

Let's show that from the constructed array $a$ we can get an array $B$ equal to the original array $b$: 

* $B_1 = \max(a_1, a_2) = \max(b_1, \min(b_1, b_2))$
	+ If $b_1 \gt b_2$, then $\max(b_1, b_2) = b_1$
	+ If $b_2 \ge b_1$, then $\max(b_1, b_1) = b_1$So $B_1 = b_1$
* $B_i = \max(a_i, a_{i+1}) = \max(\min(b_{i-1}, b_i), \min(b_i, b_{i+1}))$ at $2 \le i \le n-2$
	+ If $b_{i+1} \ge b_i$ and $b_{i-1} \ge b_i$, then $\max(\min(b_{i-1}, b_i), \min(b_i, b_{i+1}) = \min(b_i, b_i) = b_i$
	+ If $b_{i+1} \ge b_i \ge b_{i-1}$, then $\max(b_{i-1}, b_i) = b_i$
	+ If $b_{i-1} \ge b_i \ge b_{i+1}$, then $\max(b_i, b_{i+1}) = b_i$By the construction of the array $b$ it is not possible that $b_i \gt b_{i+1}$ and $b_i \gt b_{i-1}$. So $B_i = b_i$
* $B_{n-1} = \max(a_{n-1}, a_n) = \max(\min(b_{n-2}, b_{n-1}), b_{n-1})$
	+ If $b_{n-2} \gt b_{n-2}$, then $\max(b_{n-1}, b_{n-1}) = b_{n-1}$
	+ If $b_{n-1} \ge b_{n-2}$, then $\max(b_{n-2}, b_{n-1}) = b_{n-1}$ So $B_{n-1} = b_{n-1}$

We get that $B_i = b_i$ for $1 \le i \le n-1$, so $B = b$ and array $a$ is built correctly.

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int>b(n-1), a;
    for(int i = 0; i < n - 1; i++) cin >> b[i];
    a.emplace_back(b[0]);
    for(int i = 0; i < n - 2; i++){
        a.emplace_back(min(b[i], b[i + 1]));
    }
    a.emplace_back(b[n - 2]);
    for(auto &i : a) cout << i << ' ';
    cout << "n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```
[1811D - Umka and a Long Flight](../problems/D._Umka_and_a_Long_Flight.md "Codeforces Round 863 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40"), prepared: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

 **Tutorial**
### [1811D - Umka and a Long Flight](../problems/D._Umka_and_a_Long_Flight.md "Codeforces Round 863 (Div. 3)")

1. F20+F21+…+F2n=Fn⋅Fn+1, which can be proved by induction: Fn⋅Fn+1=Fn⋅(Fn−1+Fn)=Fn−1⋅Fn+F2n.
2. If the partition exists, it has the form [F0,F1,…,Fn], since the area of the rectangle with another partition will be greater than Fn⋅Fn+1.
3. We will cut the rectangles in the order Fn,Fn−1,…,F0. Denote the coordinates of the colored cell at the step n as ⟨xn,yn⟩.
4. If Fn−1<yn≤Fn and n>1, then there is no partition, since the square Fn at any location overlaps the colored cell.
5. Cut off the square Fn from the right or left edge, depending on the location of the colored cell, that is, ⟨xn−1,yn−1⟩=⟨yn,xn⟩ or ⟨xn−1,yn−1⟩=⟨yn−Fn,xn⟩.
6. Suppose that it was advantageous to cut it not from the edge, then it is necessary to cut the rectangles z×Fn and (Fn−1−z)×Fn, where 1≤z<Fn+1−Fn=Fn−1 using the set [F0,F1…Fn−1]. Then Fn−1 will not enter the partition, but 2⋅F2n−2<(2Fn−2+Fn−3)2+1=(Fn−2+Fn−1)2+1, so F21+F22+…+2⋅F2n−2<F20+F21+…+F2n−1=Fn−1⋅Fn=z⋅Fn+(Fn−1−z)⋅Fn. We came to a contradiction.
 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;

int fib[MAXN];

void build() {
	fib[0] = fib[1] = 1;
	for (int i = 2; i < MAXN; ++i)
		fib[i] = fib[i - 2] + fib[i - 1];
}

bool solve(int n, int x, int y) {
	if (n == 1) return true;
	if (fib[n - 1] <= y && y < fib[n])
		return false;
	if (fib[n] <= y)
		y -= fib[n];
	return solve(n - 1, y, x);
}

int main() {
	int t; cin >> t;
	build();
	while (t--) {
		int n, x, y; cin >> n >> x >> y;
		cout << (solve(n, --x, --y) ? "YES" : "NO") << 'n';
	}
}
```
[1811E - Living Sequence](../problems/E._Living_Sequence.md "Codeforces Round 863 (Div. 3)")

Idea: [Aris](https://codeforces.com/profile/Aris "Candidate Master Aris"), prepared: [Aris](https://codeforces.com/profile/Aris "Candidate Master Aris")

 **Tutorial**
### [1811E - Living Sequence](../problems/E._Living_Sequence.md "Codeforces Round 863 (Div. 3)")

Note that any number in the sequence can be made up of $9$ possible digits (all digits except $4$). Then let's find the first digit of the answer, notice that it is just $x$ or $x+1$, where $x \cdot 9^{l-1} \le k$ (where $l$ — the length of the number we're looking for) and $x$ — the maximum. Note that $x$ simply corresponds to a digit in the base-$9$ numeral system. 

Why is this so? Because without the first digit we can assemble any numbers with $9$ possible digits, and we can put the digits $0...x$ except $4$ in the first place. Thus, in the answer, the first digit will be $x$ if $x < 4$ and $x+1$ if $x \ge 4$.

Note that once the first digit is determined, the rest can be found the same way, since the prefix does not affect anything.

 **Solution**
```cpp
#include <iostream>
#include <cmath>
#include <cctype>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <unordered_set>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <random>
#include <cfloat>
#include <chrono>
#include <bitset>
#include <complex>
#include <immintrin.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int32_t num_tests;
    std::cin >> num_tests;

    for(int32_t t = 0; t < num_tests; t++) {
        int64_t k;
        std::cin >> k;

        std::vector<int32_t> digits;
        while(k > 0) {
            digits.push_back(k % 9);
            k /= 9;
        }
        std::reverse(digits.begin(), digits.end());

        for(int32_t i = 0; i < digits.size(); i++)
            std::cout << (char)(digits[i] < 4 ? (digits[i] + '0') : (digits[i] + '1'));
        std::cout << "n";
    }
    return 0;
}

```
[1811F - Is It Flower?](../problems/F._Is_It_Flower_.md "Codeforces Round 863 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), prepared: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1811F - Is It Flower?](../problems/F._Is_It_Flower_.md "Codeforces Round 863 (Div. 3)")

Note a few things:

* There are exactly $k^2$ vertices in the $k$-flower, since from each of the $k$ vertices of the main cycle comes another cycle of size $k$;
* in the $k$-flower, all vertices have degree $2$, except for the vertices of the main cycle, whose degrees are $4$;
* it follows that in $k$-flower $k^2 +k$ edges;

The listed properties do not take into account only the connectivity of the graph and the sizes of our $k$ cycles. To check connectivity we run a bfs or dfs from any vertex and check that all vertices have been visited. To check the cycle lengths, we cut out the edges of the main one and make sure that the graph has fell apart into components of size $k$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int sz(int v, vector<vector<int>> &g, vector<bool> &used){
    used[v] = true;
    int s = 1;
    for(int u: g[v]){
        if(!used[u]) s += sz(u, g, used);
    }
    return s;
}

void remove(vector<int> &from, int x){
    for(int &e: from){
        if(e == x){
            swap(e, from.back());
            from.pop_back();
            return;
        }
    }
}

void solve(int tc) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> sl(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        sl[--u].emplace_back(--v);
        sl[v].emplace_back(u);
    }
    int k = sqrt(n);
    if(n != k * k || m != n + k){
        cout << "NO";
        return;
    }
    for(int i = 0; i < n; ++i){
        if(sl[i].size() != 2 && sl[i].size() != 4){
            cout << "NO";
            return;
        }
    }
    vector<bool> used(n);
    if(sz(0, sl, used) != n){
        cout << "NO";
        return;
    }
    for(int i = 0; i < n; ++i){
        if(sl[i].size() == 2) continue;
        for(int j = 0; j < sl[i].size();){
            int u = sl[i][j];
            if(sl[u].size() > 2){
                remove(sl[i], u);
                remove(sl[u], i);
            }
            else{
                j++;
            }
        }
    }
    used = vector<bool>(n);
    for(int i = 0; i < n; ++i){
        if(!used[i] && sz(i, sl, used) != k){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

bool multi = true;

signed main() {
    cout.tie(nullptr);
    int t = 1;
    if (multi)cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
        cout << "n";
    }
    return 0;
}
```
[1811G1 - Vlad and the Nice Paths (easy version)](../problems/G1._Vlad_and_the_Nice_Paths_(easy_version).md "Codeforces Round 863 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), prepared: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1811G1 - Vlad and the Nice Paths (easy version)](../problems/G1._Vlad_and_the_Nice_Paths_(easy_version).md "Codeforces Round 863 (Div. 3)")

Let's use the dynamic programming. Let $dp[i][j]$ be the number of paths on the prefix $i$ of $j$ blocks of the same color. To make transitions in such dynamics, for the position $i$, we will iterate over the position $p$ in which the block started. Denote as $s$ the number of the same elements as $c_i$ and $c_p$ between them, then such a transition creates $dp[p-1][j-1] \cdot C_{k-2}^{s}$ combinations. This solution works in $O(n^3)$ complexity.

 **Solution**
```cpp
M = 10 ** 9 + 7


def pw(a, n):
    if n == 0:
        return 1
    b = pw(a, n // 2)
    return b * b % M * (a if n % 2 == 1 else 1) % M


def obr(x):
    return pw(x, M - 2)


def cnk(n, k):
    return fact[n] * obr(fact[k]) % M * obr(fact[n - k]) % M


def solve():
    n, k = map(int, input().split())
    c = [-1] + [int(x) for x in input().split()]
    if k == 1:
        print(1)
        return
    dp = [[0] * (n // k + 1) for i in range(n + 1)]  
# dp[i][j] = number for i prefix with j blocks
    dp[0][0] = 1
    for i in range(1, n + 1):
        for j in range(0, n // k + 1):
            if j > 0:
                sz = 1
                for s in range(i - 1, - 1, -1):
                    if c[s] == c[i]:
                        sz += 1
                        if sz >= k:
                            dp[i][j] += dp[s - 1][j - 1] * cnk(sz - 2, k - 2) % M
                            dp[i][j] %= M
            dp[i][j] += dp[i - 1][j]
            dp[i][j] %= M
    for j in range(n // k, -1, -1):
        if dp[n][j] > 0:
            print(dp[n][j])
            return


t = int(input())
fact = [1] * 101
for i in range(1, 101):
    fact[i] = fact[i - 1] * i % M
for _ in range(t):
    solve()
```
[1811G2 - Vlad and the Nice Paths (hard version)](../problems/G2._Vlad_and_the_Nice_Paths_(hard_version).md "Codeforces Round 863 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), prepared: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1811G2 - Vlad and the Nice Paths (hard version)](../problems/G2._Vlad_and_the_Nice_Paths_(hard_version).md "Codeforces Round 863 (Div. 3)")

To solve the hard version, let's modify the simple version solution. Note that the $j$ parameter can be discarded, since we only need paths of maximum length on each prefix. Now, as $dp[i]$, we denote a pair of the number of maximum paths and the number of blocks in them. For the position $i$, we will find the position closest to the left, from which we can start a block, and so we will find out what is the maximum for $i$. We will update $dp[i]$ until the maximum of the position being sorted is suitable for us.

 **Solution**
```cpp
from sys import stdin
input = lambda: stdin.readline().strip()


M = 10 ** 9 + 7
cnk = [[0] * (5000 + 1) for i in range(5000 + 1)]


def solve():
    n, k = map(int, input().split())
    c = [-1] + [int(x) for x in input().split()]
    if k == 1:
        print(1)
        return
    dp = [[0, 0] for i in range(n + 1)]  
# dp[i] = [number, max] for i prefix
    dp[0][0] = 1
    for i in range(1, n + 1):
        sz = 1
        for s in range(i - 1, - 1, -1):
            if c[s] == c[i]:
                sz += 1
                if sz == k:
                    dp[i][1] = dp[s - 1][1] + 1
                if sz >= k:
                    if dp[s - 1][1] < dp[i][1] - 1:
                        break
                    dp[i][0] += dp[s - 1][0] * cnk[sz - 2][k - 2] % M
                    dp[i][0] %= M
        if dp[i][1] < dp[i - 1][1]:
            dp[i] = [0, dp[i - 1][1]]
        if dp[i][1] == dp[i - 1][1]:
            dp[i][0] += dp[i - 1][0]
            dp[i][0] %= M
    print(dp[n][0])


for i in range(5000 + 1):
    cnk[i][0] = 1
for i in range(1, 5000 + 1):
    for j in range(1, i + 1):
        cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % M

t = int(input())
for _ in range(t):
    solve()
```
