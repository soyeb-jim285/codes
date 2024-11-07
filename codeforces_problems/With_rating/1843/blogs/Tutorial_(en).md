# Tutorial_(en)

[1843A - Sasha and Array Coloring](../problems/A._Sasha_and_Array_Coloring.md "Codeforces Round 881 (Div. 3)")

Idea: [Sokol080808](https://codeforces.com/profile/Sokol080808 "Master Sokol080808"), prepared: [molney](https://codeforces.com/profile/molney "Master molney")

 **Tutorial**
### [1843A - Sasha and Array Coloring](../problems/A._Sasha_and_Array_Coloring.md "Codeforces Round 881 (Div. 3)")

First, there exists an optimal answer, in which there are no more than two elements of each color.

Proof: let there exist an optimal answer, in which there are more elements of some color than 2. Then, take the median among the elements of this color and paint in another new color in which no other elements are painted. Then the maximum and minimum among the original color will not change, and in the new color the answer is 0, so the answer remains the same.

Also, if there are two colors with one element each, they can be combined into one, and the answer will not decrease.

It turns out that the numbers are paired (probably except for one; we'll assume it's paired with itself). Sort the array, and then the answer is $\sum_{pair_i < i} a_i - \sum_{i < pair_i} a_i$ ($pair_i$ is the number that is paired with $i$-th). Therefore, in the first summand you should take $\lfloor \frac{n}{2} \rfloor$ the largest, and in the second $\lfloor \frac{n}{2} \rfloor$ of the smallest elements of the array.

Total complexity: $O(n \log n)$ for sorting.

 **Solution**
```cpp
def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    ans = 0
    for i in range(n // 2):
        ans += a[-i-1] - a[i]
    print(ans)
    
    
t = int(input())
for _ in range(t):
    solve()
```
 **Rate the problem*** Didn't solve 


[*25*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*289*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*84*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*36*](https://codeforces.com/data/like?action=like "I like this")
[1843B - Long Long](../problems/B._Long_Long.md "Codeforces Round 881 (Div. 3)")

Idea: [EJIC_B_KEDAX](https://codeforces.com/profile/EJIC_B_KEDAX "Master EJIC_B_KEDAX"), prepared: [molney](https://codeforces.com/profile/molney "Master molney")

 **Tutorial**
### [1843B - Long Long](../problems/B._Long_Long.md "Codeforces Round 881 (Div. 3)")

We can delete all zeros from the array, and it won't affect on answer.

Maximum sum is $\sum_{i=1}^n |a_i|$. Minimum number of operations we should do — number of continuous subsequences with negative values of elements.

Total complexity: $O(n)$

 **Solution**
```cpp
T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    
    sum = 0
    cnt = 0
    open = False
    for x in a:
        sum += abs(x)
        if x < 0 and not open:
            open = True
            cnt += 1
        if x > 0:
            open = False
 
    print(sum, cnt)
```
 **Rate the problem*** Didn't solve 

 
[*44*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*284*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*70*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*29*](https://codeforces.com/data/like?action=like "I like this")
[1843C - Sum in Binary Tree](../problems/C._Sum_in_Binary_Tree.md "Codeforces Round 881 (Div. 3)")

Idea: [Sokol080808](https://codeforces.com/profile/Sokol080808 "Master Sokol080808"), prepared: [molney](https://codeforces.com/profile/molney "Master molney")

 **Tutorial**
### [1843C - Sum in Binary Tree](../problems/C._Sum_in_Binary_Tree.md "Codeforces Round 881 (Div. 3)")

It is easy to notice that the children of the vertex with number $u$ have numbers $2 \cdot u$ and $2 \cdot u + 1$. So, the ancestor of the vertex $u$ has the number $\lfloor \frac{u}{2} \rfloor$. Note that based on this formula, the size of the path from the root to the vertex with number $n$ equals $\lfloor \log_2 n \rfloor$. Therefore with given constraints we can write out the path to the root explicitly and calculate the sum of vertex numbers on it in $O(\log n)$.

Total complexity: $O(\log n)$ for the test case.

 **Solution**
```cpp
t = int(input())
for _ in range(t):
    n = int(input())
    s = 0
    while n >= 1:
        s += n
        n //= 2
    print(s)
```
 **Rate the problem*** Didn't solve 

 
[*16*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*303*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*129*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*53*](https://codeforces.com/data/like?action=like "I like this")
[1843D - Apple Tree](../problems/D._Apple_Tree.md "Codeforces Round 881 (Div. 3)")

Idea: [EJIC_B_KEDAX](https://codeforces.com/profile/EJIC_B_KEDAX "Master EJIC_B_KEDAX"), prepared: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1843D - Apple Tree](../problems/D._Apple_Tree.md "Codeforces Round 881 (Div. 3)")

Let $cnt_v$ be the number of vertices from which an apple can fall if it is in the vertex $v$. Then the answer to the query is $cnt_v \cdot cnt_u$.

Note that the value of $cnt_v$ is equal to the number of leaves in the subtree of vertex $v$. Then, these values can be computed using the DFS or BFS. The value $cnt$ for a vertex will be equal to $1$ if this vertex is a leaf, otherwise it will be equal to the sum of these values for all children of the vertex.

Total complexity: $O(n + q)$.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<vector<int>> g;
vector<ll> cnt;
 
void dfs(int v, int p) {
    if (g[v].size() == 1 && g[v][0] == p) {
        cnt[v] = 1;
    } else {
        for (auto u : g[v]) {
            if (u != p) {
                dfs(u, v);
                cnt[v] += cnt[u];
            }
        }
    }
}
 
void solve() {
    int n, q;
    cin >> n;
 
    g.assign(n, vector<int>());
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    cnt.assign(n, 0);
    dfs(0, -1);
 
    cin >> q;
    for (int i = 0; i < q; i++) {
        int c, k;
        cin >> c >> k;
        c--; k--;
 
        ll res = cnt[c] * cnt[k];
        cout << res << 'n';
    }
}
 
signed main() {
    int tests;
    cin >> tests;
    while (tests--) {
        solve();
    }
 
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*66*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*394*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*53*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*39*](https://codeforces.com/data/like?action=like "I like this")
[1843E - Tracking Segments](../problems/E._Tracking_Segments.md "Codeforces Round 881 (Div. 3)")

Idea: [meowcneil](https://codeforces.com/profile/meowcneil "Master meowcneil"), prepared: [meowcneil](https://codeforces.com/profile/meowcneil "Master meowcneil")

 **Tutorial**
### [1843E - Tracking Segments](../problems/E._Tracking_Segments.md "Codeforces Round 881 (Div. 3)")

Let's use a binary search for an answer. It will work, because if some segment was good, then after one more change it will not be no longer good, and if all segments were bad, then if you remove the last change, they will remain bad.

To check if there is a good segment for the prefix of changes, you can build the array obtained after these changes, and then count the prefix sums in $O(n)$. After that, you can go through all the segments and check for $O(1)$ for a segment whether it is a good or not.

Total complexity: $O((n + m) \cdot \log q)$.

 **Solution**
```cpp
def solve():
    n, m = map(int, input().split())
    segs = []
    for i in range(m):
        l, r = map(int, input().split())
        l -= 1
        segs.append([l, r])
    q = int(input())
    ord = [0] * q
    for i in range(q):
        ord[i] = int(input())
        ord[i] -= 1
    l = 0
    r = q + 1
    while r - l > 1:
        M = (l + r) // 2
        cur = [0] * n
        for i in range(M):
            cur[ord[i]] = 1
        pr = [0] * (n + 1)
        for i in range(n):
            pr[i+1] = pr[i] + cur[i]
        ok = False
        for i in segs:
            if(pr[i[1]] - pr[i[0]] > (i[1] - i[0]) // 2):
                ok = True
                break
        if ok:
            r = M
        else:
            l = M
    if r == q + 1:
        r = -1
    print(r)
 
tc = int(input())
for T in range(tc):
    solve()
```
 **Rate the problem*** Didn't solve 

 
[*145*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*466*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*28*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*18*](https://codeforces.com/data/like?action=like "I like this")
[1843F1 - Omsk Metro (simple version)](../problems/F1._Omsk_Metro_(simple_version).md "Codeforces Round 881 (Div. 3)")

Idea: [EJIC_B_KEDAX](https://codeforces.com/profile/EJIC_B_KEDAX "Master EJIC_B_KEDAX"), prepared: [Sokol080808](https://codeforces.com/profile/Sokol080808 "Master Sokol080808")

 **Tutorial**
### [1843F1 - Omsk Metro (simple version)](../problems/F1._Omsk_Metro_(simple_version).md "Codeforces Round 881 (Div. 3)")

Let $\mathrm{mx}$ be the maximal sum on the path subsegment, $\mathrm{mn}$ — the minimal sum on the path subsegment. Then it is said that a subsegment with sum $x$ exists if and only if $\mathrm{mn} \leq x \leq \mathrm{mx}$.

Proof: Let us fix the subsegment with the minimum sum and the subsegment with the maximum sum. Now, we want to go from the first segment to the second one by consecutively removing or adding elements from the ends of the segment. Note that, due to the fact that $x \in \{-1, 1\}$, for each such action, the sum on the segment will change by exactly $1$. In other words, no matter how we go from one segment to another, the sum will remain a discretely continuous value. Then, since this function takes values of the minimum and maximum sum, it also takes all values from the segment between them (by the intermediate value theorem). Thus, the set of all possible sums on the subsegments is the interval of integers between the minimum and maximum sum, from which the original assumption follows.

Now, we have turned the problem down to finding the subsegment with the minimum and maximum sum on the path in the tree. Let $\mathrm{mx}_u$ be the maximum sum on the subsegment on the path from $1$ to $u$, $\mathrm{suf}_u$ — the maximum sum on the suffix of the path from $1$ to $u$, $p_u$ — the ancestor of vertex $u$, $x_u$ — its weight. Then $\mathrm{suf}_u = \max({0, \mathrm{suf}_{p_u} + x_u})$, $\mathrm{mx}_u = \max({\mathrm{mx}_{p_u}, \mathrm{suf}_u})$. Thus, we have learned to calculate the necessary values for a vertex immediately at the moment of its addition, which allows us to solve the problem online (but it is not required in the problem itself). The values for the minimum are counted in the same way.

Total complexity: $O(n)$.

 **Solution**
```cpp
class info:
    mn_suf = 0
    mx_suf = 0
    mn_ans = 0
    mx_ans = 0
 
def solve():
    n = int(input())
    
    start = info()
    start.mx_suf = start.mx_ans = 1
    
    st = [start]
    for i in range(n):
        com = input().split()
        if (com[0] == '+'):
            v = int(com[1]) - 1
            x = int(com[2])
 
            pref = st[v]
            cur = info()
 
            cur.mn_suf = min(0, pref.mn_suf + x)
            cur.mx_suf = max(0, pref.mx_suf + x)
            cur.mn_ans = min(pref.mn_ans, cur.mn_suf)
            cur.mx_ans = max(pref.mx_ans, cur.mx_suf)
 
            st.append(cur)
        else:
            v = int(com[2]) - 1
            x = int(com[3])
 
            if st[v].mn_ans <= x <= st[v].mx_ans:
                print("Yes")
            else:
                print("No")
 
t = int(input())
for testCase in range(t):
    solve()
```
 **Rate the problem*** Didn't solve 

 
[*50*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*314*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*3*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*14*](https://codeforces.com/data/like?action=like "I like this")
[1843F2 - Omsk Metro (hard version)](../problems/F2._Omsk_Metro_(hard_version).md "Codeforces Round 881 (Div. 3)")

Idea: [EJIC_B_KEDAX](https://codeforces.com/profile/EJIC_B_KEDAX "Master EJIC_B_KEDAX"), prepared: [Sokol080808](https://codeforces.com/profile/Sokol080808 "Master Sokol080808")

 **Tutorial**
### [1843F2 - Omsk Metro (hard version)](../problems/F2._Omsk_Metro_(hard_version).md "Codeforces Round 881 (Div. 3)")

Similarly to the problem F1, we need to be able to find a subsegment with maximum and minimum sum, but on an arbitrary path in the tree. To do this, we will use the technique of binary lifts. For each lift, we will store the maximum/minimum sum on the prefix and suffix, the sum of the subsegment and the maximum sum on the subsegment, as in the problem about the maximum sum on a subsegment of an array. Then, such values are easily can be recalculated by analogy with the recalculation from the problem F1. It is also worth noting that such binary lifts can also be constructed online, but this was not required in the problem.

Then, all that remains is to go up from the ends of the path to their LCA, and then combine the answers of the vertical paths into the answer for the whole path.

Total complexity: $O(n \log n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
struct info {
    int sum, minPrefL, maxPrefL, minPrefR, maxPrefR, minSeg, maxSeg;
 
    info(int el = 0) {
        sum = el;
        minSeg = minPrefL = minPrefR = min(el, 0);
        maxSeg = maxPrefL = maxPrefR = max(el, 0);
    }
};
 
struct question {
    int u, v, x;
};
 
info merge(info& a, info& b) {
    info res;
    res.sum = a.sum + b.sum;
    res.minPrefL = min(a.minPrefL, a.sum + b.minPrefL);
    res.maxPrefL = max(a.maxPrefL, a.sum + b.maxPrefL);
    res.minPrefR = min(a.minPrefR + b.sum, b.minPrefR);
    res.maxPrefR = max(a.maxPrefR + b.sum, b.maxPrefR);
    res.minSeg = min({a.minSeg, b.minSeg, a.minPrefR + b.minPrefL});
    res.maxSeg = max({a.maxSeg, b.maxSeg, a.maxPrefR + b.maxPrefL});
    return res;
}
 
const int MAXN = 200100;
const int lg = 17;
 
int up[lg + 1][MAXN];
info ans[lg + 1][MAXN];
int d[MAXN];
 
void solve() {
    int n;
    cin >> n;
 
    for (int i = 0; i <= lg; i++) up[i][0] = 0;
    ans[0][0] = info(1);
    d[0] = 0;
 
    int cur = 0;
    for (int q = 0; q < n; q++) {
        char c;
        cin >> c;
        if (c == '+') {
            int v, x;
            cin >> v >> x;
            v--;
            cur++;
 
            d[cur] = d[v] + 1;
 
            up[0][cur] = v;
            for (int j = 0; j <= lg - 1; j++) up[j + 1][cur] = up[j][up[j][cur]];
 
            ans[0][cur] = info(x);
            for (int j = 0; j <= lg - 1; j++) ans[j + 1][cur] = merge(ans[j][cur], ans[j][up[j][cur]]);
        } else {
            int u, v, x;
            cin >> u >> v >> x;
            u--; v--;
            
            if (d[u] < d[v]) swap(u, v);
 
            int dif = d[u] - d[v];
            info a, b;
            for (int i = lg; i >= 0; i--) {
                if ((dif >> i) & 1) {
                    a = merge(a, ans[i][u]);
                    u = up[i][u];
                }
            }
 
            if (u == v) {
                a = merge(a, ans[0][u]);
            } else {
                for (int i = lg; i >= 0; i--) {
                    if (up[i][u] != up[i][v]) {
                        a = merge(a, ans[i][u]);
                        u = up[i][u];
                        b = merge(b, ans[i][v]);
                        v = up[i][v];
                    }
                }
 
                a = merge(a, ans[1][u]);
                b = merge(b, ans[0][v]);
            }
 
            swap(b.minPrefL, b.minPrefR);
            swap(b.maxPrefL, b.maxPrefR);
 
            info res = merge(a, b);
            if (res.minSeg <= x && x <= res.maxSeg) {
                cout << "Yesn";
            } else {
                cout << "Non";
            }
        }
    }
}
 
int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        solve();
    }
}
```
 **Rate the problem*** Didn't solve 

 
[*90*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*189*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*6*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*21*](https://codeforces.com/data/like?action=like "I like this")
