# Tutorial

[1927A - Make it White](../problems/A._Make_it_White.md "Codeforces Round 923 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1927A - Make it White](../problems/A._Make_it_White.md "Codeforces Round 923 (Div. 3)")

To repaint all the black cells in white, it is necessary to select a segment from l to r that contains all the black cells.

Let's choose the entire strip as a segment (l=1,r=n). As long as the segment starts with a white cell, it can be left unpainted, i.e., l can be increased by one. Otherwise, we cannot exclude the cell from the segment. Similarly, we can exclude the last cell from the segment until it becomes black. After all exclusions, the answer will be r−l+1.

The selected segment contains all the black cells, as we have excluded only white cells. The segment is also minimal because reducing the segment from either side will result in one of the black cells remaining black.

 **Solution**
```cpp
from collections import deque
 
def solve():
    n = int(input())
    s = deque(input())
    while len(s) > 0 and s[0] == 'W':
        s.popleft()
    while len(s) > 0 and s[-1] == 'W':
        s.pop()
    print(len(s))
    
 
for _ in range(int(input())):
    solve()
```
[1927B - Following the String](../problems/B._Following_the_String.md "Codeforces Round 923 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1927B - Following the String](../problems/B._Following_the_String.md "Codeforces Round 923 (Div. 3)")

To build the desired string, we will move from left to right and add characters. In order to add a character at each step with the required number of occurrences, we will keep track of the number of times each character is added.

 **Solution**
```cpp
def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    cnt = [0] * 26
    s = ''
    for i in range(n):
        for j in range(26):
            if cnt[j] == a[i]:
                cnt[j] += 1
                s += chr(97 + j)
                break
    print(s)
 
 
for _ in range(int(input())):
    solve()
```
[1927C - Choose the Different Ones!](../problems/C._Choose_the_Different_Ones!.md "Codeforces Round 923 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1927C - Choose the Different Ones!](../problems/C._Choose_the_Different_Ones!.md "Codeforces Round 923 (Div. 3)")

Notice that elements with a value greater than k are not relevant to us. Let's divide the values into three categories:

1. Occurring only in array a;
2. occurring only in array b;
3. occurring in both arrays.

The answer will be NO if any of the following conditions are met:

* the number of values of the first type is greater than k2 (this implies that we cannot select all such elements);
* the number of values of the second type is greater than k2 (this implies that we cannot select all such elements);
* the total number of values of all three types is less than k (this implies that some values do not occur in either of the arrays).

Otherwise, the answer is YES.

 **Solution**
```cpp
def solve():
    n, m, k = map(int, input().split())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    cnt = [0] * (k + 1)
    for e in a:
        if e <= k:
            cnt[e] |= 1
    for e in b:
        if e <= k:
            cnt[e] |= 2
    c = [0] * 4
    for e in cnt:
        c[e] += 1
    if c[1] > k // 2 or c[2] > k // 2 or c[1] + c[2] + c[3] != k:
        print("NO")
    else:
        print("YES")
 
 
for _ in range(int(input())):
    solve()
```
[1927D - Find the Different Ones!](../problems/D._Find_the_Different_Ones!.md "Codeforces Round 923 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1927D - Find the Different Ones!](../problems/D._Find_the_Different_Ones!.md "Codeforces Round 923 (Div. 3)")

Before processing the requests, let's calculate the position pi of the nearest element to the left that is not equal to it (we will consider p1=−1). To do this in linear time, we will traverse the array from left to right. For the i-th element (1<i≤n), if ai≠ai−1, then pi=i−1, otherwise pi=pi−1 (all elements between pi−1 and i will be equal to ai by construction).

To answer a query, we will fix the right boundary as one of the positions for the answer. Then the best of all suitable positions for it is pr, as it is the maximum, and we just need to check that l≤pr. (Note that by fixing any other position, you may not find the answer for a segment of the form [1,1,1,…,1,2])

 **Solution**
```cpp
def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    p = [-1] * n
    for i in range(1, n):
        p[i] = p[i - 1]
        if a[i] != a[i - 1]:
            p[i] = i - 1
    for i in range(int(input())):
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        if p[r] < l:
            print("-1 -1")
        else:
            print(p[r] + 1, r + 1)
    
    
t = int(input())
for _ in range(t):
    solve()
    if _ + 1 != t:
        print()
```
[1927E - Klever Permutation](../problems/E._Klever_Permutation.md "Codeforces Round 923 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1927E - Klever Permutation](../problems/E._Klever_Permutation.md "Codeforces Round 923 (Div. 3)")

To construct a permutation, let's make an important observation: si cannot be equal to si+1 (i.e., they differ by at least 1). Since the array s can only contain two different values, it always has the form [x,x+1,x,x+1,…] or [x,x−1,x,x−1,…].

Let's construct a permutation of the first form.

* Since s1+1=s2, then a1+1=ak+1;
* since s2=s3+1, then a2=ak+2+1;
* since s3+1=s4, then a3+1=ak+3;
* ⋯
* since sk=sk+1+1, then ak=ak+k+1;
* ⋯

Thus, for all odd positions i, it must hold that ai+1=ai+k, and for even positions, ai=ai+k+1. To construct such a permutation, we will iterate through all positions i from 1 to k and fill the permutation in positions i,i+k,i+2⋅k,….

 **Solution**
```cpp
def solve():
    n, k = map(int, input().split())
    l, r = 1, n
    ans = [0] * n
    for i in range(k):
        for j in range(i, n, k):
            if i % 2 == 0:
                ans[j] = l
                l += 1
            else:
                ans[j] = r
                r -= 1
    print(*ans)
    
    
for _ in range(int(input())):
    solve()
```
[1927F - Microcycle](../problems/F._Microcycle.md "Codeforces Round 923 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1927F - Microcycle](../problems/F._Microcycle.md "Codeforces Round 923 (Div. 3)")

Let's use the disjoint sets union (DSU). We will add edges to the DSU in descending order of weight. At the same time, we will build a graph containing only the edges that, when added to the DSU, unite different sets. We will also remember the last edge that we did not add to the graph, as it will be the lightest edge of the desired cycle. To find the cycle itself, we will find a path in the constructed graph leading from one end of this edge to the other (due to the construction of the graph, it does not contain cycles, so we need to find a path in the tree).

 **Solution**
```cpp
#include <bits/stdc++.h>
 
#define int long long
#define pb emplace_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
typedef long double ld;
typedef long long ll;
 
using namespace std;
 
mt19937 rnd(time(nullptr));
 
const ll inf = 1e18;
const ll M = 998244353;
const ld pi = atan2(0, -1);
const ld eps = 1e-6;
 
struct dsu{
    vector<int> p, lvl;
 
    dsu(int n){
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        lvl.assign(n, 0);
    }
 
    int get(int i){
        if (p[i] == i) return i;
        return p[i] = get(p[i]);
    }
 
    bool unite(int a, int b){
        a = get(a);
        b = get(b);
        if(a == b) return false;
        if(lvl[a] < lvl[b]) swap(a, b);
        p[b] = a;
        if(lvl[a] == lvl[b]) lvl[a]++;
        return true;
    }
};
 
bool found;
vector<int> ans, path;
 
void dfs(int v, int p, vector<vector<int>> &g, int f){
    path.push_back(v);
    if(v == f){
        ans = path;
        found = true;
        return;
    }
    for(int u: g[v]){
        if(u != p) dfs(u, v, g, f);
        if (found) return;
    }
    path.pop_back();
}
 
void solve(int tc){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> sl(n);
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({w, {u, v}});
    }
    sort(rall(edges));
    dsu g(n);
    pair<int, int> fin;
    int best = INT_MAX;
    for(auto e: edges){
        if(!g.unite(e.y.x, e.y.y)){
            fin = e.y;
            best = e.x;
        }
        else{
            sl[e.y.x].push_back(e.y.y);
            sl[e.y.y].push_back(e.y.x);
        }
    }
    found = false;
    path.resize(0);
    dfs(fin.x, -1, sl, fin.y);
    cout << best <<  " " << ans.size() << "n";
    for(int e: ans) cout << e + 1 << " ";
}
 
bool multi = true;
 
signed main() {
    int t = 1;
    if (multi)cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
        cout << "n";
    }
    return 0;
}
```
[1927G - Paint Charges](../problems/G._Paint_Charges.md "Codeforces Round 923 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1927G - Paint Charges](../problems/G._Paint_Charges.md "Codeforces Round 923 (Div. 3)")

Let's use the method of dynamic programming. Let dp[i][j][k] be the minimum number of operations required for the distance from i to the farthest unpainted cell on the left to be j, and to the nearest unpainted cell on the right to be k (including itself).

We will update the values forward, that is, for all reachable states, we will find the states reachable from it and update the answer for them. In this case, we will move from the current i to i+1, recalculating j and k depending on the action: not spraying paint from i, spraying paint from i to the left, spraying paint from i to the right.

The problem could also have been solved in O(n2), however, the constraints did not require this.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn(i, n)
            cin >> a[i];
 
        vector<vector<vector<int>>> d(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX)));
        d[0][0][0] = 0;
 
        forn(i, n)
            forn(j, n)
                forn(k, n + 1)
                    if (d[i][j][k] < INT_MAX) {
                        int ai = a[i];
 
                        // Z
                        {
                            int ni = i + 1;
                            int nj = j > 0 ? j + 1 : (k == 0 ? 1 : 0);
                            int nk = max(0, k - 1);
                            d[ni][nj][nk] = min(d[ni][nj][nk], d[i][j][k]);
                        }
 
                        // L
                        {
                            int ni = i + 1;
                            int nj = j > 0 ? j + 1 : 0;
                            if (nj <= ai)
                                nj = 0;
                            int nk = max(0, k - 1);
                            d[ni][nj][nk] = min(d[ni][nj][nk], d[i][j][k] + 1);
                        }
 
                        // R
                        {
                            int ni = i + 1;
                            int nj = j > 0 ? j + 1 : 0;
                            int nk = max(ai - 1, k - 1);
                            d[ni][nj][nk] = min(d[ni][nj][nk], d[i][j][k] + 1);
                        }
                    }
 
        cout << *min_element(d[n][0].begin(), d[n][0].end()) << endl;
    }
}
```
