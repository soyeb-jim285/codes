# Tutorial

[1980A - Problem Generator](../problems/A._Problem_Generator.md "Codeforces Round 950 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Candidate Master Vladosiya") Prepared by: [Vladosiya](https://codeforces.com/profile/Vladosiya "Candidate Master Vladosiya")

 **Tutorial**
### [1980A - Problem Generator](../problems/A._Problem_Generator.md "Codeforces Round 950 (Div. 3)")

It is necessary to have at least m problems of each difficulty level. If there are already at least m problems of difficulty level c, then there is no need to come up with more problems of this difficulty level. Otherwise, it is necessary to come up with m−cntc problems, where cntc is the number of problems of difficulty level c (if more problems of this difficulty level are created, the number will not be minimum).

 **Solution**
```cpp
def solve():
    n, m = map(int, input().split())
    a = input()
    ans = 0
    for ch in range(ord('A'), ord('H')):
        ans += max(0, m - a.count(chr(ch)))
    print(ans)
    
    
for _ in range(int(input())):
    solve()
```
[1980B - Choosing Cubes](../problems/B._Choosing_Cubes.md "Codeforces Round 950 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin") Prepared by: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1980B - Choosing Cubes](../problems/B._Choosing_Cubes.md "Codeforces Round 950 (Div. 3)")

Let x be the value of the cube with the number f.

Let's sort all the cubes by non-growth. Then let's look at the value of the k-th cube in order. Since the cubes are removed by non-growth, all cubes with large values will be removed, some (perhaps not all) cubes with the same value, and cubes with smaller values will not be removed.

If the value of the k-th cube is greater than x, then Dmitry's favorite cube will not be removed, because all the removed cubes will have more values. If it is less than x, then the favorite cube will always be removed, since the cube with the lower value will also be removed.

If the value of the k th cube is equal to x, then some cubes with this value will be removed. However, if there are several such cubes, then perhaps not all of them will be removed. If the k+1th cube is missing (for k=n) or if its value is less than x, then all cubes with this value will be removed, and the answer is YES. Otherwise, only a part of the cubes with the value x will be removed, and the answer is MAYBE, because cubes with the same values are indistinguishable when sorting.

 **Solution**
```cpp
def solve():
    n, f, k = map(int, input().split())
    f -= 1
    k -= 1
    a = list(map(int, input().split()))
    x = a[f]
    a.sort(reverse=True)
    if a[k] > x:
        print("NO")
    elif a[k] < x:
        print("YES")
    else:
        print("YES" if k == n - 1 or a[k + 1] < x else "MAYBE")
 
t = int(input())
for _ in range(t):
    solve()
```
[1980C - Sofia and the Lost Operations](../problems/C._Sofia_and_the_Lost_Operations.md "Codeforces Round 950 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin") Prepared by: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

 **Tutorial**
### [1980C - Sofia and the Lost Operations](../problems/C._Sofia_and_the_Lost_Operations.md "Codeforces Round 950 (Div. 3)")

First, in the array b1,b2,…,bn, the number dm must be present. Second, if ai=bi, we will not apply any operations to i. All extra operations can be applied to aj, where bj=dm, they will be overwritten by the operation dm. For all other i (ai≠bi) we must apply the operation dk=bi, so it remains to check that the multiset of such bi is included in the multiset d1,d2,…,dm.

This solution can be implemented using sorting and two pointers or std::map, resulting in a time complexity of O((n+m)logn). If you used std::unordered_map or dict, you were most likely hacked. Check out this [post](https://codeforces.com/blog/entry/62393).

 **Solution**
```cpp
#include <stdio.h>
#include <stdbool.h>
 
#define MAXN 200200
#define MAXM 200200
 
int n, m, k;
int arr[MAXN], brr[MAXN], drr[MAXM], buf[MAXN];
 
int cmp_i32(const void* pa, const void* pb) {
    return *(const int*)pa - *(const int*)pb;
}
 
void build() {
    k = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != brr[i])
            buf[k++] = brr[i];
    }
    qsort(buf, k, sizeof(*buf), cmp_i32);
}
 
bool check() {
    for (int i = 0; i < n; ++i)
        if (brr[i] == drr[m - 1])
            return true;
    return false;
}
 
bool solve() {
    if (!check()) return false;
    qsort(drr, m, sizeof(*drr), cmp_i32);
    int ib = 0, id = 0;
    while (ib < k && id < m) {
        if (buf[ib] == drr[id])
            ++ib, ++id;
        else if (buf[ib] < drr[id])
            return false;
        else ++id;
    }
    return ib == k;
}
 
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", arr + i);
        for (int i = 0; i < n; ++i)
            scanf("%d", brr + i);
        scanf("%d", &m);
        for (int j = 0; j < m; ++j)
            scanf("%d", drr + j);
        build();
        if (solve()) printf("YESn");
        else printf("NOn");
    }
}
```
[1980D - GCD-sequence](../problems/D._GCD-sequence.md "Codeforces Round 950 (Div. 3)")

Idea: [myav](https://codeforces.com/profile/myav "Pupil myav") Prepared by: [myav](https://codeforces.com/profile/myav "Pupil myav")

 **Tutorial**
### [1980D - GCD-sequence](../problems/D._GCD-sequence.md "Codeforces Round 950 (Div. 3)")

Let's loop through the initial array a, counting the GCD of neighbouring elements. If at some point, the GCD of the previous pair becomes greater than the GCD of the next pair, we remember the index i of the first element of the pair that gave the greater GCD and stop the loop.

Then consider the following cases: 

* the sequence of GCDs for array a was already non-decreasing. Then it is enough to remove the last element from it, the previous elements of the GCD-sequence will not be affected. The answer in this case is always YES.
* some element ai has been found such that GCD(ai−1,ai)>GCD(ai,ai+1). Then, since there is already at least one place in the original GCD-sequence where it ceases to be non-decreasing, we can try to fix it by removing the i−1-th, i-th or i+1-th element from the array a. Let's create 3 new arrays of length n−1, and in each of them remove one of the above elements. If at least one of these arrays has a non-decreasing GCD-sequence — the answer is YES, otherwise — NO.
 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
bool good(vector<int>&b){
    int g = __gcd(b[0], b[1]);
    for(int i = 1; i < int(b.size()) - 1; i++){
        int cur_gcd = __gcd(b[i], b[i + 1]);
        if(g > cur_gcd) return false;
        g = cur_gcd;
    }
    return true;
}
 
bool solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
 
    int g = -1;
    int to_del = -1;
    for(int i = 0; i < n - 1; i++){
        int cur_gcd = __gcd(a[i], a[i + 1]);
        if(cur_gcd < g){
            to_del = i;
            break;
        }
        g = cur_gcd;
    }
    if(to_del == -1) return true;
    vector<int>b0 = a, b1 = a, b2 = a;
    if(to_del > 0) b0.erase(b0.begin() + to_del - 1);
    b1.erase(b1.begin() + to_del);
    if(to_del < n - 1) b2.erase(b2.begin() + to_del + 1);
    return good(b0) || good(b1) || good(b2);
}
 
int main(){
    int t;
    cin >> t;
    while(t--){
        cout << (solve() ? "YES" : "NO") << "n";
    }
}
```
[1980E - Permutation of Rows and Columns](../problems/E._Permutation_of_Rows_and_Columns.md "Codeforces Round 950 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin") Prepared by: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1980E - Permutation of Rows and Columns](../problems/E._Permutation_of_Rows_and_Columns.md "Codeforces Round 950 (Div. 3)")

For each element, you can calculate its positions in both matrices. You can see that the rearrangement of rows does not affect the column positions of the elements being rearranged. Similarly, column rearrangement does not affect row positions. Since the permutation of rows affects the entire rows, for all elements that have the same position row in the original matrix, the position row in the resulting matrix must also match. Similarly, the columns must match.

In order to check the coincidence of rows and columns, let's count 4 arrays — the positions of rows and columns in the original and received matrices. Then you need to check that for all x with the same row value in the original matrix, the row values in the resulting matrix are the same. Similarly, the values of the columns should be the same.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
vi read_ints(int n) {
    vi res(n);
    for (int i = 0; i < n; ++i) {
        cin >> res[i];
    }
    return res;
}
 
vvi read_matrix(int n, int m) {
    vvi res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = read_ints(m);
    }
    return res;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vvi a = read_matrix(n, m), b = read_matrix(n, m);
    int nm = n * m;
    vi pos1i(nm), pos2i(nm), pos1j(nm), pos2j(nm);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = a[i][j] - 1;
            int y = b[i][j] - 1;
            pos1i[x] = pos2i[y] = i;
            pos1j[x] = pos2j[y] = j;
        }
    }
    vector<set<int>> pi(nm), pj(nm);
    for (int x = 0; x < nm; ++x) {
        int i1 = pos1i[x], i2 = pos2i[x];
        int j1 = pos1j[x], j2 = pos2j[x];
        pi[i1].insert(i2);
        pj[j1].insert(j2);
    }
    for (int x = 0; x < nm; ++x) {
        if (pi[x].size() > 1 || pj[x].size() > 1) {
            cout << "NOn";
            return;
        }
    }
    cout << "YESn";
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
[1980F1 - Field Division (easy version)](../problems/F1._Field_Division_(easy_version).md "Codeforces Round 950 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") Prepared by: [Vladosiya](https://codeforces.com/profile/Vladosiya "Candidate Master Vladosiya")

 **Tutorial**
### [1980F1 - Field Division (easy version)](../problems/F1._Field_Division_(easy_version).md "Codeforces Round 950 (Div. 3)")

Since Alice can only move down or to the right, if in the i-th row x cells belong to her, then in the (i−1)-th row she can have no more than x cells. The construction of the maximum plot can be represented as follows: we will go through the rows from bottom to top and keep track of how many cells we have collected in the row below. In the current row, we will collect either the same number of cells, or all the cells up to the leftmost fountain in the row, if there are fewer such cells.

There are three possible positions of the fountains relative to the boundary with Alice's plot:

* the fountain has no adjacent cells belonging to Alice's plot;
* the fountain has one adjacent cell belonging to Alice's plot;
* the fountain has two adjacent cells belonging to Alice's plot.

The area of Alice's plot changes only when removing the third type of fountain position, which we will call the corner. Since a corner has formed, in the row below Alice had more cells, and when removing this fountain, she will be able to take at least one cell with this fountain, and the answer for it will be 1. For the other two types of positions, removing the fountain will not change the size of the plot, and the answer for them will be 0 (you can proof it by yourself).

To ensure that the solution does not depend on the size of the field, we will sort the fountains in descending order of the x coordinate, and in case of equality of x, in ascending order of the y coordinate. We will iterate through the fountains in this order, keep track of the coordinates of the last corner, and update the answer when a new corner is found.

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
 
const ll inf = 1e9 + 1;
const ll M = 998244353;
const ld pi = atan2(0, -1);
const ld eps = 1e-6;
 
bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.x != b.x) return a.x > b.x;
    return a.y < b.y;
}
 
void solve(int tc){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(k);
    map<pair<int, int>, int> idx;
    for(int i = 0; i < k; ++i){
        cin >> a[i].x >> a[i].y;
        idx[a[i]] = i;
    }
    sort(all(a), cmp);
    vector<int> ans(k);
    int total = 0;
    int cur = m + 1;
    int last = n;
    for(auto e: a){
        if(cur > e.y) {
            ans[idx[e]] = 1;
            total += (cur - 1) * (last - e.x);
            cur = e.y;
            last = e.x;
        }
    }
    total += (cur - 1) * last;
    cout << total << "n";
    for(int e: ans) cout << e << " ";
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
[1980F2 - Field Division (hard version)](../problems/F2._Field_Division_(hard_version).md "Codeforces Round 950 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") Prepared by: [Vladosiya](https://codeforces.com/profile/Vladosiya "Candidate Master Vladosiya")

 **Tutorial**
### [1980F2 - Field Division (hard version)](../problems/F2._Field_Division_(hard_version).md "Codeforces Round 950 (Div. 3)")

First, read the editorial of the easy version.

Let's use the solution of the easy version to precalculate the stored information on the prefix.

The fountain will stop being a corner only when it is removed, because the leftmost corner on the prefix could not become further left as a result of removal.

To calculate the change in area, let's make an important observation: if fountain j is not a corner, then it either cannot become one, or will become one only after the removal of the last corner that comes before it in sorted order. It was the leftmost corner that came before fountain j, and the next corner in sorted order will be strictly higher.

Thus, we need to do the following: for each corner, calculate the area without considering it until the next corner, and this will be helped by the precalculation we did when calculating the area. Each fountain will be processed only once, so the time complexity is O(n).

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
 
const ll inf = 1e9 + 1;
const ll M = 998244353;
const ld pi = atan2(0, -1);
const ld eps = 1e-6;
 
bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.x != b.x) return a.x > b.x;
    return a.y < b.y;
}
 
void solve(int tc){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(k);
    map<pair<int, int>, int> idx;
    for(int i = 0; i < k; ++i){
        cin >> a[i].x >> a[i].y;
        idx[a[i]] = i;
    }
    idx[{0, 0}] = k++;
    a.emplace_back(0, 0);
    sort(all(a), cmp);
    vector<int> ans(k);
    vector<int> total(k + 1), cur(k + 1, m + 1), last(k + 1, n);
    for(int i = 1; i <= k; ++i){
        auto e = a[i - 1];
        total[i] = total[i - 1];
        cur[i] = cur[i - 1];
        last[i] = last[i - 1];
        if(cur[i] > e.y) {
            ans[idx[e]] = 1;
            total[i] += (cur[i] - 1) * (last[i] - e.x);
            cur[i] = e.y;
            last[i] = e.x;
        }
    }
    cout << total[k] << "n";
    for(int i = 1; i <= k; ++i){
        auto e = a[i - 1];
        if(ans[idx[e]] == 0)continue;
        int tot = total[i - 1];
        int cr = cur[i - 1];
        int lst = last[i - 1];
        for(int j = i + 1; j <= k; ++j){
            auto ee = a[j - 1];
            if(cr > ee.y){
                tot += (cr - 1) * (lst - ee.x);
                cr = ee.y;
                lst = ee.x;
            }
            if(ans[idx[ee]] == 1){
                ans[idx[e]] = tot - total[j];
                break;
            }
        }
    }
    ans.pop_back();
    for(int e: ans) cout << e << " ";
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
[1980G - Yasya and the Mysterious Tree](../problems/G._Yasya_and_the_Mysterious_Tree.md "Codeforces Round 950 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40") Prepared by: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

 **Tutorial**
### [1980G - Yasya and the Mysterious Tree](../problems/G._Yasya_and_the_Mysterious_Tree.md "Codeforces Round 950 (Div. 3)")

We will hang the tree on the vertex 1 and count for each vertex dv — xor on the path from it to the root. This can be done by depth-first traversal in O(n).

Now let's learn how to solve the problem in O(n) for each query. The first type of query can be executed straightforwardly. Notice that due to the properties of the xor operation, the values will only change for vertices at odd depth (the depth of the root is 0). At the same time, they will change trivially: they will be xored with y. To answer the second query, it is necessary to realize that the xor on a simple cycle v→lca(v,u)→u→v is equal to dv⊕du⊕x. Indeed, the path from lca(v, u) to the root will be counted twice, so it will turn into 0, and no other extra edges will be included in this xor. With due skill, you can try to speed up such a solution with AVX instructions, but the time constraints were chosen strictly.

For a complete solution to the problem, you can use the data structure prefix tree (trie). With its help, you can find in O(logx) for the number x such a y in the set, that x⊕y is maximal. Since dv change differently, you will have to use two tries — for vertices at even and odd heights. Operations of the first type can be accumulated in the variable wodd and added to the xor expression. In addition, you must not forget to remove dv from the necessary trie when answering the second query, and then insert it back. To do this, you can maintain a counter of terminal leaves in each vertex and use this information during descent.

Thus, the final asymptotic is O((n+m)log109).

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
struct trie {
    int l, c;
    vector<array<int, 2>> node;
    vector<int> cnt;
    trie(int l, int max_members) : l(l), c(0), node((l + 2) * max_members + 3), cnt((l + 2) * max_members + 3) {}
    void add(int x) {
        int cur = 0;
        for (int i = l; i >= 0; --i) {
            bool has_bit = (1 << i) & x;
            if (!node[cur][has_bit]) {
                node[cur][has_bit] = ++c;
            }
            cur = node[cur][has_bit];
            ++cnt[cur];
        }
    }
    void remove(int x) {
        int cur = 0;
        for (int i = l; i >= 0; --i) {
            bool has_bit = (1 << i) & x;
            if (!node[cur][has_bit]) {
                node[cur][has_bit] = ++c;
            }
            cur = node[cur][has_bit];
            --cnt[cur];
        }
    }
    int find_max(int x) {
        int cur = 0, ans = 0;
        for (int i = l; i >= 0; --i) {
            bool has_bit = (1 << i) & x;
            if (node[cur][!has_bit] && cnt[node[cur][!has_bit]]) {
                ans += 1 << i;
                cur = node[cur][!has_bit];
            }
            else {
                cur = node[cur][has_bit];
            }
        }
        return ans;
    }
};
 
const int N = 2e5 + 2;
int x[N];
bitset<N> dp;
vector<array<int, 2>> e[N];
 
void dfs(int c, int p) {
    for (auto [i, w] : e[c]) {
        if (i == p) {
            continue;
        }
        dp[i] = !dp[c];
        x[i] = x[c] ^ w;
        dfs(i, c);
    }
}
 
void solve() {
    int n, m, gx = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    for (int i = 1, u, v, w; i < n; ++i) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0);
    vector<trie> t(2, trie(30, n));
    for (int i = 1; i <= n; ++i) {
        t[dp[i]].add(x[i]);
    }
    while (m--) {
        char c;
        cin >> c;
        if (c == '^') {
            int y;
            cin >> y;
            gx ^= y;
        }
        else {
            int a, b;
            cin >> a >> b;
            t[dp[a]].remove(x[a]);
            int same_group = t[dp[a]].find_max(x[a] ^ b);
            int diff_group = t[1 - dp[a]].find_max(x[a] ^ b ^ gx);
            t[dp[a]].add(x[a]);
            cout << max(same_group, diff_group) << "n";
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```
