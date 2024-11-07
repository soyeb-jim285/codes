# Tutorial

[1674A - Number Transformation](../problems/A._Number_Transformation.md "Codeforces Round 786 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1674A - Number Transformation](../problems/A._Number_Transformation.md "Codeforces Round 786 (Div. 3)")

The process in the statement can be rephrased as "multiply x by ba". x⋅ba will be divisible by x, so if y is not divisible by x, there is no answer. Otherwise, a=1 and b=yx can be used.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    x, y = map(int, input().split())
    if y % x != 0:
        print(0, 0)
    else:
        print(1, y // x)
```
[1674B - Dictionary](../problems/B._Dictionary.md "Codeforces Round 786 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1674B - Dictionary](../problems/B._Dictionary.md "Codeforces Round 786 (Div. 3)")

There are many different ways to solve this problem:

* generate all Berland words with two for-loops and store them in an array, then for each test case, go through the array of words to find the exact word you need;
* generate all Berland words with two for-loops and store them in a dictionary-like data structure (map in C++, dict in Python, etc), using words as keys and their numbers as values. This allows to search for the index of the given word quickly;
* for each test case, run two for-loops to iterate over the words, count the number of words we skipped, and stop at the word from the test case;
* try to invent some formulas that allow counting the number of words before the given one.
 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    string w = "aa";
    map<string, int> idx;
    int i = 1;
    for(w[0] = 'a'; w[0] <= 'z'; w[0]++)
        for(w[1] = 'a'; w[1] <= 'z'; w[1]++)
            if(w[0] != w[1])
                idx[w] = i++;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        cout << idx[s] << endl;
    }   
}

```
[1674C - Infinite Replacement](../problems/C._Infinite_Replacement.md "Codeforces Round 786 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1674C - Infinite Replacement](../problems/C._Infinite_Replacement.md "Codeforces Round 786 (Div. 3)")

Let's consider some cases.

If there are letters 'a' in string t, then the moves can be performed endlessly. If t itself is equal to "a", then the string won't change, so the answer is 1. Otherwise, the length of t is least 2, so string s will be increasing in length after each move, and the answer is -1.

If there are no letters 'a' in string t, then the resulting string is only determined by whichever letters 'a' we chose to replace with t. That's because once we replace a letter 'a' with string t, we can do nothing with the new letters anymore.

We can actually imagine that t is equal to "b", and the answer won't change. Now it's easy to see that the answer is equal to the number of strings of length n, consisting only of letters 'a' and 'b'. There are two options for each position, and there are n positions, so the answer is 2n.

Overall complexity: O(|s|+|t|) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
    s = input()
    t = input()
    if t == "a":
        print(1)
    elif t.count('a') != 0:
        print(-1)
    else:
        print(2**len(s))
        
```
[1674D - A-B-C Sort](../problems/D._A-B-C_Sort.md "Codeforces Round 786 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1674D - A-B-C Sort](../problems/D._A-B-C_Sort.md "Codeforces Round 786 (Div. 3)")

Let's look at elements an and an−1. After the first step, they will always move to positions b1 and bn (it's up to you to choose: an→b1 and an−1→bn or vice versa) because all remaining ai for i<n−1 will be placed between an and an−1.

After the second step, elements b1 and bn will always be placed at positions cn−1 and cn (it's also up to you to decide the exact order) because it's easy to see that you first take all bi for 1<i<n and only after that — b1 and bn.

In other words, elements an−1 and an are moved to positions cn−1 and cn. We can analogically prove that each pair (an−2i−1,an−2i) is moved to a pair of positions (cn−2i−1,cn−2i): you first take all elements aj for j>n−2i and place them at positions [b1,…,bi] and [bn−i+1,…,bn]; then you move an−2i and an−2i−1; finally you move all remaining elements from a between bi+1 and bn−i. Step 2 just does everything in "reverse" order to step 1.

It means that array c is basically array a, but you can swap elements in pairs (an−2i−1,an−2i) for i≥0. And to make a (c) sorted, we can try to sort each pair and check — is it enough to sort the whole array or not.

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        for (i in (n % 2) until n step 2) {
            if (a[i] > a[i + 1])
                a[i] = a[i + 1].also { a[i + 1] = a[i] }
        }
        var sorted = true
        for (i in a.indices)
            if (i > 0 && a[i - 1] > a[i])
                sorted = false
        println(if(sorted) "YES" else "NO")
    }
}
```
[1674E - Breaking the Wall](../problems/E._Breaking_the_Wall.md "Codeforces Round 786 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1674E - Breaking the Wall](../problems/E._Breaking_the_Wall.md "Codeforces Round 786 (Div. 3)")

Let's analyze three cases based on the distance between two sections we are going to break:

1. break two neighboring sections (i and i+1);
2. break two sections with another section between them (i and i+2);
3. break two sections with more than one section between them.

Why exactly these cases? Because the damage from the shots and the possibility to hit both sections with the same shot depends on the distance between them.

If there is more than one section between the two we want to break, then any shot hits only one of these sections, so each shot should be aimed at one of those sections, and we break them independently. Let's pick two sections with minimum durability and calculate the number of shots required to break them; if these sections are i and j, then the required number of shots is ⌈ai2⌉+⌈aj2⌉. It actually does not matter if the distance between them is less than 3; if it is so, these sections will be analyzed in one of the other cases.

Okay, now let's deal with two sections having exactly one section between them. We can iterate on all combinations of these sections (iterate on i from 1 to n−2 and pick sections i and i+2). Let's analyze how can we damage them. If we shoot at the section between them, we deal 1 damage to both sections; if we shoot at one of those sections, we deal 2 damage to it and 0 damage to the other section. So, each shot distributes 2 damage between these two sections the way we want to distribute it, and the number of shots required to break these two sections is ⌈ai+ai+22⌉.

The case when we try to break two adjacent sections is the trickiest one. Let's say that these sections are i and i+1, x=max(ai,ai+1), and y=min(ai,ai+1). If we target one of these sections, we deal 2 damage to it and 1 damage to the other section. Let's try to run the following algorithm: shoot at the section with higher durability, until both of them break. It can be slow, but we can see that after the first x−y shots, the durabilities of the sections become equal, and each pair of shots after that deals 3 damage to both sections. So, we can model the first x−y shots, subtract 2(x−y) from x and (x−y) from y, and then we'll need ⌈x+y3⌉ shots. The only case when this doesn't work is if we break both sections before we equalize their durabilities; it means that 2y≤x and we need to do only ⌈x2⌉ shots.

 **Solution (fcspartakm)**
```cpp
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>

#define forn(i, n) for(int i=0;i<n;++i)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define x first
#define y1 ________y1
#define y second
#define ft first
#define sc second
#define pt pair<int, int>

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;

using namespace std;

const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 200 * 1000 + 13;

int n;
int a[N];

inline void read() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }   
}

inline void solve() {   
    int ans = INF;
    for (int i = 0; i < n - 1; i++) {
        int cur = 0;
        int x = a[i], y = a[i + 1];
        if (x < y) {
            swap(x, y);
        }
        int cnt = min(x - y, (x + 1) / 2);
        cur += cnt;
        x -= 2 * cnt;
        y -= cnt;
        if (x > 0 && y > 0) {
            cur += (x + y + 2) / 3;
        }
        ans = min(ans, cur);    
    }

    for (int i = 0; i < n - 2; i++) {
        int cur = 0;
        int x = a[i], y = a[i + 2];
        if (x < y) {
            swap(x, y);
        }
        int cnt = (x - y + 1) / 2;
        cur += cnt;
        cur += y;
        ans = min(ans, cur);
    }
    
    sort(a, a + n);
    ans = min(ans, (a[0] + 1) / 2 + (a[1] + 1) / 2);
    cout << ans << endl;
}

int main () {
#ifdef fcspartakm
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    srand(time(NULL));
    cerr << setprecision(10) << fixed;
    
    read();
    solve();
 
    //cerr << "TIME: " << clock() << endl;
}
```
[1674F - Desktop Rearrangement](../problems/F._Desktop_Rearrangement.md "Codeforces Round 786 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1674F - Desktop Rearrangement](../problems/F._Desktop_Rearrangement.md "Codeforces Round 786 (Div. 3)")

I've seen a lot of data structures solutions for this problem, but author's solution doesn't use them and works in O(nm+q).

Firstly, let's change our matrix to a string s, because it will be easier to work with a string than with a matrix. The order of characters will be from top to bottom, from left to right (i. e. the outer cycle by columns, and the inner by rows). Then, let's calculate sum — the number of icons on the desktop (the number of '*' in s). Then the answer will be, obviously, the number of dots on the prefix of s of size sum.

Now let's deal with queries. It can be shown that one query changes our answer by no more than 1.

Let p=ny+x be the position of the cell that is being changed in s (zero-indexed). Then, if p<sum, there are two cases. If sp is '.', then we have one more icon on our prefix, so the answer decreases by one (because we filled one empty space in the good desktop). Otherwise, it increases by one (because this icon is outside our prefix).

Then let's change the corresponding character by the opposite. After that, we should move our right border (sum) accordingly to the new number of icons. Note that this border is exclusive. If sp becomes '*', then we will increase the variable sum. But before that, if ssum is '.', then there should be an icon, and it is not here yet, so the answer increases. Otherwise, our border will decrease. Then, if ssum−1 is '.', then the answer decreases (because there was a place for an icon, and now it is not needed anymore).

Time complexity: O(nm+q).

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

static char buf[1010];

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    vector<string> tmp(n);
    string s;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        tmp[i] = buf;
        sum += count(tmp[i].begin(), tmp[i].end(), '*');
    }
    
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            s += tmp[i][j];
        }
    }
    int res = count(s.begin(), s.begin() + sum, '.');
    int pos = sum;
    for (int i = 0; i < q; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x, --y;
        int p = y * n + x;
        if (p < pos) {
            if (s[p] == '.') {
                --res;
            } else {
                ++res;
            }
        }
        s[p] = (s[p] == '.' ? '*' : '.');
        if (s[p] == '*') {
            if (s[pos] == '.') {
                ++res;
            }
            ++pos;
        } else {
            if (s[pos - 1] == '.') {
                --res;
            }
            --pos;
        }
        printf("%dn", res);
    }
    
    return 0;
}
```
[1674G - Remove Directed Edges](../problems/G._Remove_Directed_Edges.md "Codeforces Round 786 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1674G - Remove Directed Edges](../problems/G._Remove_Directed_Edges.md "Codeforces Round 786 (Div. 3)")

Let's solve the problem in reverse.

Imagine we have already removed some edges, so that the conditions hold. When is some set of vertices considered cute? Since the graph is acyclic, we can topologically sort the vertices in the set. The vertices are reachable from each other, so there exists a path from the i-th vertex in the set to the (i+1)-st vertex. Thus, there exists a path that goes through all chosen vertices.

However, we can make this conclusion even stronger. In the optimal answer, not just the path goes from the i-th vertex to the (i+1)-st one, but a single edge. That can be shown by contradiction. Let there be some vertices v and u that are adjacent in the chosen cute set. There exists a path between them, but not a single edge. We want to show that this set is not optimal and can be made larger.

The vertices on that path don't belong to the set. If they did, they would be between v and u in the set (because of the topological order). We can add them to the set. Every vertex that can reach v, can reach them too, and every vertex that can be reached from u, can be reached from them. Thus, it will still be a cute set. Now every vertex from v to u has an edge between them and the size of the set is larger.

Thus, we showed that the maximum set in the answer is always some path in the graph.

So the task is to choose some path, then remove some edges so that this path still exists and the conditions hold. Note that if the conditions hold for some set of remaining edges, then we can remove any edge from it, and the conditions will still be met. Thus, we can only leave this path.

Let's look closer into the conditions. What they actually tell is the following. If a vertex has incoming edges, then remove at least one of them. The same for the outgoing edges.

Since we are looking for a path, it's enough to leave one outgoing edge for all vertices except the last one and leave one incoming edge for all vertices except the first one.

In order to achieve that, every vertex except the last one should have at least two outgoing edges and every vertex except the first one should have at least two incoming edges.

We can see that this condition is not only necessary, but sufficient as well. Just remove the outgoing edges which don't go to the next vertex and the incoming edges which don't go from the previous vertex.

Now we can wrap this up into the dynamic programming. Initialize the answer with 1, since you can always remove all edges, and get a set with one vertex.

Then let dpv be the longest path such that it starts in vertex v, all vertices in it have at least two incoming edges and all vertices except maybe the final one have at least two outgoing edges.

Initialize the dp for the vertices that can be the final in the path (have at least two incoming edges) with 1. Then update dpv for all v that can be internal vertices (have at least two outgoing and two incoming edges) with dpu+1 for all outgoing edges (v,u).

Finally, update the answer from the vertices that can be the first one in the path. For each vertex v that has at least two outgoing edges, take the value of dpu+1 for all outgoing edges (v,u).

Overall complexity: O(n+m).

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
const int INF = 1e9;
 
vector<int> in, out;
vector<vector<int>> g;
vector<int> dp;
 
int calc(int v){
    if (dp[v] != -1) return dp[v];
    if (in[v] >= 2 && out[v] >= 2){
        dp[v] = 1;
        for (int u : g[v])
            dp[v] = max(dp[v], calc(u) + 1);
    }
    else if (in[v] >= 2){
        dp[v] = 1;
    }
    else{
        dp[v] = -INF;
    }
    return dp[v];
}
 
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    g.resize(n);
    in.resize(n);
    out.resize(n);
    forn(i, m){
        int v, u;
        scanf("%d%d", &v, &u);
        --v, --u;
        g[v].push_back(u);
        ++in[u];
        ++out[v];
    }
    int ans = 1;
    dp.resize(n, -1);
    forn(v, n) if (out[v] >= 2){
        for (int u : g[v]){
            ans = max(ans, calc(u) + 1);
        }
    }
    printf("%dn", ans);
    return 0;
}

```
