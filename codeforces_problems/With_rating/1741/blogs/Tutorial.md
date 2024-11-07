# Tutorial

[1741A - Compare T-Shirt Sizes](../problems/A._Compare_T-Shirt_Sizes.md "Codeforces Round 826 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1741A - Compare T-Shirt Sizes](../problems/A._Compare_T-Shirt_Sizes.md "Codeforces Round 826 (Div. 3)")

Let $sa$, $sb$ are the last characters of lines $a$ and $b$ respectively. And $|a|, |b|$ are the sizes of these strings.

1. $sa \neq sb$: then the answer depends only on $sa$ and $sb$ and is uniquely defined as the inverse of $sa$ to $sb$ ("<" if $sa > sb$, ">" if $sa < sb$, since the characters S, M, L are in reverse order in the alphabet).
2. $sa = sb$:
	* $|a| = |b|$. Then the answer is "=". This also covers the case $sa = sb = $M;
	* $sa = sb =$S. Then the larger the size of the string, the smaller the size of the t-shirt. That is, the answer is "<" if $|a| > |b|$ and ">" if $|a| < |b|$;
	* $sa = sb =$L. Then the larger the size of the string, the smaller the size of the t-shirt. That is, the answer is "<" if $|a| < |b|$ and ">" if $|a| > |b|$;
 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back
 
 
void ct(char c) {
    cout << c << 'n';
}
 
void solve() {
    string a,b; cin >> a >> b;
    char ca = a.back();
    char cb = b.back();
    if (ca == cb) {
        if (sz(a) == sz(b)) cout << '=';
        else if (ca == 'S') {
            cout << (sz(a) < sz(b) ? '>' : '<');
        } else {
            cout << (sz(a) < sz(b) ? '<' : '>');
        }
    }else cout << (ca < cb ? '>' : '<');
    cout << 'n';
}
 
int main() {
    int t;
    cin >> t;
 
    forn(tt, t) {
        solve();
    }
}
```
[1741B - Funny Permutation](../problems/B._Funny_Permutation.md "Codeforces Round 826 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1741B - Funny Permutation](../problems/B._Funny_Permutation.md "Codeforces Round 826 (Div. 3)")

We cannot make a funny permutation only when $n = 3$, because one of the neighboring elements of $3$ must be equal to $2$. Any permutation made in this way will not satisfy the conditions: 

* The permutation [$3, 2, 1$] will have a fixed point $p_2 = 2$.
* The permutation [$1, 3, 2$] will have a fixed point $p_1 = 1$.
* The permutation [$2, 3, 1$] will not have a neighbor equal to $p_3 + 1 = 1 + 1 = 2$ for $p_3 = 1$.

For the remaining values of $n$, make the following observations: 

* For $n = 2$, the only funny permutation is [$2, 1$].
* When $n \ge 4$, permutations of the form [$3, \dots, n, 2, 1$] will always be funny because all elements $p_i$ will have a neighbor equal to $p_i - 1$ or $p_i + 1$, and the permutation will have no fixed points ($p_{n-1} = 2$, $p_n = 1$, and for $3 \le i \le n - 2$ will always be true $p_i = i + 2$).
 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n == 3){
        cout << -1 << endl;
    }
    else{
        for(int i = 3; i <= n; i++) cout << i << ' ';
        cout << 2 << ' ' << 1 << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
```
[1741C - Minimize the Thickness](../problems/C._Minimize_the_Thickness.md "Codeforces Round 826 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1741C - Minimize the Thickness](../problems/C._Minimize_the_Thickness.md "Codeforces Round 826 (Div. 3)")

Let's iterate over the length of the first segment of the split. Having fixed it, we actually fixed the sum that needs to be collected on all other segments. Since each element must belong to exactly one segment, we can build other segments greedily. If we have found a solution, we will remember the length of the longest segment in it and try to update the answer. We have $n$ possible lengths of the first segment, for each of which we greedily built the answer for $n$. Thus, the asymptotics of the solution will be $O(n^2)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2020;

int n;
int arr[MAXN];

int go(int i, int sum) {
	if (i == n) return 0;
	for (int j = i + 1, cur = 0; j <= n; ++j) {
		cur += arr[j - 1];
		if (cur > sum) return n;
		if (cur == sum) return max(j - i, go(j, sum));
	}
	return n;
}

int solve() {
	int ans = n;
	for (int len = 1, sum = 0; len < n; ++len) {
		sum += arr[len - 1];
		ans = min(ans, go(0, sum));
	}
	return ans;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		cout << solve() << endl;
	}
}
```
[1741D - Masha and a Beautiful Tree](../problems/D._Masha_and_a_Beautiful_Tree.md "Codeforces Round 826 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

 **Tutorial**
### [1741D - Masha and a Beautiful Tree](../problems/D._Masha_and_a_Beautiful_Tree.md "Codeforces Round 826 (Div. 3)")

Let some vertex be responsible for a segment of leaves $[l..r]$. Then her left son is responsible for the segment $[l..\frac{l+r-1}{2}]$, and the right for the segment $[\frac{l+r+1}{2}..r]$. Note that if we do not apply the operation to this vertex, then it will not be possible to move some element from the right son's segment to the left son's segment. It remains to understand when we need to apply the operation to the vertex. Let the maximum on the segment $[l..r]$ be $max$, the minimum on the same segment is $min$. Then if $min$ lies in the right son, and $max$ in the left, then we should obviously apply the operation, for the reason described above. In the case when $min$ lies in the left son, and $max$ in the right, the application of the operation will definitely not allow you to get a solution. Let's continue to act in a similar way recursively from the children of the current vertex. At the end, we should check whether we have received a sorted permutation. The above solution works for $O(nm)$, since there are $n$ levels in the tree and at each level, vertexes are responsible for $m$ sheets in total. You can optimize this solution to $O(m)$ if you pre-calculate the maximum and minimum for each vertex.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAXM = 300300;

int n, m;
int arr[MAXM];

int solve(int l, int r) {
	if (r - l == 1) return 0;
	int mid = (l + r) >> 1;
	int mal = *max_element(arr + l, arr + mid);
	int mar = *max_element(arr + mid, arr + r);
	int ans = 0;
	if (mal > mar) {
		++ans;
		for (int i = 0; i < (mid - l); ++i)
			swap(arr[l + i], arr[mid + i]);
	}
	return solve(l, mid) + solve(mid, r) + ans;
}

int solve() {
	int ans = solve(0, m);
	if (is_sorted(arr, arr + m))
		return ans;
	return -1;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> m;
		for (int i = 0; i < m; ++i)
			cin >> arr[i];
		cout << solve() << endl;
	}
}
```
[1741E - Sending a Sequence Over the Network](../problems/E._Sending_a_Sequence_Over_the_Network.md "Codeforces Round 826 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1741E - Sending a Sequence Over the Network](../problems/E._Sending_a_Sequence_Over_the_Network.md "Codeforces Round 826 (Div. 3)")

Let's introduce the dynamics. $dp[i] = true$ if on the prefix $i$ the answer is Yes. 

Then in this sequence $b$ the numbers corresponding to the sizes of the segments from the partition $a$ into subsegments will be called interesting.

A number at position $i$ in the sequence $b$, if it is interesting, is either to the right or to the left of the segment. 

* If it is to the left of the segment, it can only be interesting if $dp[i-1] = true$. Then $dp[i + b[i]] = true$.
* If it is on the right side of the segment, then if $dp[i - b[i] - 1] = true$, then $dp[i] = true$.

The answer for the whole sequence is Yes if $dp[n] = true$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back



void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<bool> dp(n+1, false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
        if (i + a[i] <= n && dp[i-1]) dp[i + a[i]] = true;
        if (i - a[i] - 1 >= 0 && dp[i - a[i] - 1]) dp[i] = true;
    }
    cout << (dp[n] ? "YES" : "NO") << 'n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
```
[1741F - Multi-Colored Segments](../problems/F._Multi-Colored_Segments.md "Codeforces Round 826 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1741F - Multi-Colored Segments](../problems/F._Multi-Colored_Segments.md "Codeforces Round 826 (Div. 3)")

Let's go through the segments $2$ times: in non-decreasing coordinates of the left end, and then — in non-increasing coordinates of the right end. To walk a second time, just multiply the coordinates of the left and right borders by $-1$, and then swap them and walk from left to right.

Going through the segments in non-decreasing coordinates of the left end, you need to find for each segment a segment that starts not to the right of the current one and ends as far to the right as possible. If the coordinate of its right end is not less than the coordinate of the left end of the current segment, then it intersects with it, otherwise the distance between them is equal to the distance between the coordinate of the left end of the current segment and the maximum coordinate of the right end of the segment starting to the left of ours.

Note that it is enough for us to store no more than $2$ segments: for each color we will store the maximum right coordinate of the segment of this color, which has already been considered. If we store the $2$ colors with the largest right coordinates, then one of them is definitely not equal to the current one. When considering a segment, we add it to the list, and if the size of the list becomes $3$, then we leave $2$ of optimal elements.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int n;

vector<int> calc(vector<vector<int>> a) {
    vector<pair<int, int>> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        l[i] = {a[i][0], i};
        r[i] = {a[i][1], i};
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    vector<vector<pair<int, int>>> suf(n);
    vector<pair<int, int>> curr;
    for (int i0 = n - 1; i0 >= 0; --i0) {
        int xr = r[i0].first;
        int i = r[i0].second;
        int xl = a[i][0];
        int c = a[i][2];
        if (curr.empty()) {
            curr.emplace_back(xl, c);
        } else if (curr.size() == 1) {
            if (curr[0].second == c) {
                curr[0].first = min(curr[0].first, xl);
            } else {
                curr.emplace_back(xl, c);
            }
        } else {
            if (curr[0].second == c) {
                curr[0].first = min(curr[0].first, xl);
            } else if (curr[1].second == c) {
                curr[1].first = min(curr[1].first, xl);
            } else {
                curr.emplace_back(xl, c);
            }
        }
        sort(curr.begin(), curr.end());
        if (curr.size() == 3) {
            curr.pop_back();
        }
        suf[i0] = curr;
    }
    vector<int> ans(n, 1e9);
    int j = 0;
    for (int i0 = 0; i0 < n; ++i0) {
        int xl = l[i0].first, i = l[i0].second;
        int xr = a[i][1], c = a[i][2];
        while (j < n && r[j].first < xl) {
            j++;
        }
        if (j < n) {
            vector<pair<int, int>> s = suf[j];
            if (s[0].second != c) {
                ans[i] = min(ans[i], max(0, s[0].first - xr));
            } else if (s.size() == 2) {
                ans[i] = min(ans[i], max(0, s[1].first - xr));
            }
        }
    }
    return ans;
}

const int K = 1e9 + 1;

void solve() {
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3)), b(n, vector<int>(3));
    vector<pair<int, int>> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
            if (j == 2) {
                b[i][j] = a[i][j];
            } else {
                b[i][1 - j] = K - a[i][j];
            }
        }
    }
    vector<int> ans1 = calc(a), ans2 = calc(b);
    for (int i = 0; i < n; ++i) {
        cout << min(ans1[i], ans2[i]) << ' ';
    }
    cout << 'n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    for (int it = 0; it < t; ++it) {
        solve();
    }
    return 0;
}
```
[1741G - Kirill and Company](../problems/G._Kirill_and_Company.md "Codeforces Round 826 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1741G - Kirill and Company](../problems/G._Kirill_and_Company.md "Codeforces Round 826 (Div. 3)")

To begin with, let's learn how to find possible sets of friends for the vertex, whom he can give a ride, in the form of masks. Let's use a breadth first search, every time we find the shortest path to the vertex $u$ with the previous vertex $v$, we will add the masks of the vertex $v$ to the masks of the vertex $u$, updating them with friends living in $u$.

Now, according to the resulting sets, you need to get the best combination of them. We will find it using the knapsack problem, we will use masks as weights, and the total weight will be the bitwise OR of the selected set.

 **Solution**
```cpp
from collections import deque
 
 
def solve():
    n, m = map(int, input().split())
    sl = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        sl[u] += [v]
        sl[v] += [u]
    f = int(input())
    h = [int(x) - 1 for x in input().split()]
    mask = [0] * n
    k = int(input())
    p = [int(x) - 1 for x in input().split()] + [-1]
    for i in range(k):
        mask[h[p[i]]] += 1 << i
    vars = [set() for _ in range(n)]
    dist = [-1] * n
    dist[0] = 0
    vars[0].add(mask[0])
    q = deque([0])
    while len(q) > 0:
        v = q.popleft()
        for u in sl[v]:
            if dist[u] == -1:
                dist[u] = dist[v] + 1
                q.append(u)
            if dist[u] == dist[v] + 1:
                for msk in vars[v]:
                    vars[u].add(msk | mask[u])
    backpack = [False] * (1 << k)
    backpack[0] = True
    j = 0
    for i in range(f):
        if i == p[j]:
            j += 1
            continue
        nw = backpack.copy()
        for msk in range(1 << k):
            if not backpack[msk]:
                continue
            for var in vars[h[i]]:
                nw[msk | var] = True
        backpack, nw = nw, backpack
    mn = k
    for msk in range(1 << k):
        if not backpack[msk]:
            continue
        ans = 0
        for b in range(k):
            if msk & (1 << b) == 0:
                ans += 1
        mn = min(mn, ans)
    print(mn)
 
 
t = int(input())
for _ in range(t):
    solve()
```
