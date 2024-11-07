# Tutorial_(en)

[1765A - Access Levels](../problems/A._Access_Levels.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo")

 **Tutorial**
### [1765A - Access Levels](../problems/A._Access_Levels.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Suppose two documents $i$ and $j$ belong to the same access group, and the access level for the document $i$ is greater than the access level for document $j$. Then, every developer which has the access to the document $i$, has the access to the document $j$ as well; so, for every $d \in [1, n]$, the condition $a_{d,i} \le a_{d,j}$ must hold.

We can build a directed graph where the arc $i \rightarrow j$ represents that this condition holds for the (ordered) pair of documents $(i, j)$. Every access group should be a path in this graph — so, our problem now requires us to cover a directed graph with the minimum number of vertex-disjoint paths.

Let's assume that the graph is acyclic. Then every path is acyclic as well, so the number of vertices in a path is equal to the number of arcs in a path, plus one. Let $k$ be the number of paths, $v$ be the number of vertices, and $e$ be the total number of arcs used in the paths. It's easy to see that $k + e = v$; so, by maximizing the total number of arcs in the paths, we minimize the number of paths.

So, we need to choose the maximum number of arcs so that each vertex belongs to only one path among those formed by these arcs. It is equivalent to the combination of the following two conditions:

* each vertex should have at most one incoming chosen arc;
* each vertex should have at most one outgoing chosen arc.

Now our problem can be solved with network flows or bipartite matching. For example, one of the solutions is to create a bipartite graph where each vertex of the original graph is represented by two vertices, one for each part; and an arc $i \rightarrow j$ from the original graph is converted to the edge connecting the vertex $i$ in the left part and the vertex $j$ in the right part. It's easy to see that every matching in this graph fulfills the aforementioned two conditions, thus giving us a correct decomposition of an acyclic directed graph into vertex-disjoint paths — so, in order to minimize the number of such paths, we need to find the maximum matching. All that's left is to actually find these paths and convert them into the access groups/levels for the documents, and set access levels for the developers, which is pretty easy and straightforward to implement.

But wait, what if the graph is not acyclic? Fortunately, a cycle can exist only between two documents with identical access requirements. We can deal with these in one of two ways:

* compress all identical documents into one vertex;
* or use the document index as the tiebreak if two documents are completely identical otherwise.

Even the most basic implementation of bipartite matching with Kuhn's algorithm will yield a solution in $O(m^3 + m^2n)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n, m, m2;
vector<vector<char>> g;

int T;
vector<int> mt;
vector<int> used;

bool try_kuhn(int v){
    if (used[v] == T)
        return false;
    used[v] = T;
    forn(u, m2) if (g[v][u] && (mt[u] == -1 || try_kuhn(mt[u]))){
        mt[u] = v;
        return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    vector<string> b(m, string(n, '0'));
    forn(i, n){
        string t;
        cin >> t;
        forn(j, m) b[j][i] = t[j];
    }
    
    vector<string> nw = b;
    sort(nw.begin(), nw.end());
    nw.resize(unique(nw.begin(), nw.end()) - nw.begin());
    m2 = nw.size();
    g.assign(m2, vector<char>(m2, 0));
    forn(i, m2) forn(j, m2) if (i != j){
        bool in = true;
        forn(k, n) in &= nw[i][k] >= nw[j][k];
        if (in) g[i][j] = 1;
    }
    
    mt.assign(m2, -1);
    used.assign(m2, -1);
    T = 0;
    int k = m2;
    forn(i, m2) if (try_kuhn(i)){
        ++T;
        --k;
    }
    
    vector<int> nxt(m2, -1);
    vector<char> st(m2, true);
    forn(i, m2) if (mt[i] != -1){
        nxt[mt[i]] = i;
        st[i] = false;
    }
    
    vector<int> gr(m2), req(m2);
    int t = 0;
    forn(i, m2) if (st[i]){
        int v = i;
        int pos = 2;
        while (v != -1){
            gr[v] = t;
            req[v] = pos;
            ++pos;
            v = nxt[v];
        }
        ++t;
    }
    assert(t == k);
    
    vector<int> num(m);
    forn(i, m) num[i] = lower_bound(nw.begin(), nw.end(), b[i]) - nw.begin();
    
    printf("%dn", k);
    forn(i, m) printf("%d ", gr[num[i]] + 1);
    puts("");
    forn(i, m) printf("%d ", req[num[i]]);
    puts("");
    forn(i, n){
        vector<int> l(k, 1);
        forn(j, m2) if (nw[j][i] == '1')
            l[gr[j]] = max(l[gr[j]], req[j]);
        forn(j, k)
            printf("%d ", l[j]);
        puts("");
    }
    return 0;
}
```
[1765B - Broken Keyboard](../problems/B._Broken_Keyboard.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh"), preparation: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1765B - Broken Keyboard](../problems/B._Broken_Keyboard.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

There are many ways to solve this problem. Basically, we need to check two conditions.

The first one is the condition on the number of characters: $n \bmod 3 \ne 2$, since after the first key press, we get the remainder $1$ modulo $3$, after the second key press, we get the remainder $0$ modulo $3$, then $1$ again, then $0$ — and so on, and we cannot get the remainder $2$.

Then we need to check that, in each pair of characters which appeared from the same key press, these characters are the same — that is, $s_2 = s_3$, $s_5 = s_6$, $s_8 = s_9$, and so on.

 **Solution (vovuh)**
```cpp
for _ in range(int(input())):
    n = int(input())
    s = input()
    print('YES' if n % 3 != 2 and not False in [s[i * 3 + 1] == s[i * 3 + 2] for i in range(n // 3)] else 'NO')
```
[1765C - Card Guessing](../problems/C._Card_Guessing.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Idea: [DStepanenko](https://codeforces.com/profile/DStepanenko "Expert DStepanenko"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading... **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)

using namespace std;

const int MOD = 998244353;

int add(int a, int b){
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int mul(int a, int b){
    return a * 1ll * b % MOD;
}

int binpow(int a, int b){
    int res = 1;
    while (b){
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    
    vector<int> fact(4 * n + 1);
    fact[0] = 1;
    fore(i, 1, fact.size()) fact[i] = mul(fact[i - 1], i);
    vector<int> rfact(4 * n + 1);
    rfact.back() = binpow(fact.back(), MOD - 2);
    for (int i = int(fact.size()) - 2; i >= 0; --i)
        rfact[i] = mul(rfact[i + 1], i + 1);
    
    auto cnk = [&](int n, int k){
        return mul(fact[n], mul(rfact[k], rfact[n - k]));
    };
    
    vector<vector<int>> sv(n + 1, vector<int>(5));
    forn(i, n + 1) forn(t, 5) sv[i][t] = mul(binpow(cnk(n, i), t), rfact[t]);
    
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(4 * n + 1, vector<int>(5)));
    forn(ii, n + 1){
        int i = ii & 1;
        int ni = i ^ 1;
        dp[ni] = vector<vector<int>>(4 * n + 1, vector<int>(5));
        for (int t = 1; t <= 4; ++t)
            dp[ni][ii * t][t] = mul(n - ii, sv[ii][t]);
        forn(j, k + 1) for (int p = 1; p <= 4; ++p) if (dp[i][j][p]){
            dp[ni][j][p] = add(dp[ni][j][p], dp[i][j][p]);
            for (int t = 1; p + t <= 4; ++t)
                dp[ni][j + ii * t][p + t] = add(dp[ni][j + ii * t][p + t], mul(dp[i][j][p], sv[ii][t]));
        }
    }
    
    int ans = 0;
    forn(sum, k + 1){
        ans = add(ans, mul(mul(mul(
            sum < k ? 1 : 4 * n - k, 
            dp[(n & 1) ^ 1][sum][4]), 
            mul(binpow(4 * n - sum, MOD - 2), mul(rfact[4 * n], fact[4 * n - sum]))), 
            mul(fact[4], fact[sum]))
        );
    }
    
    printf("%dn", ans);
    return 0;
}
```
[1765D - Watch the Videos](../problems/D._Watch_the_Videos.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [DmitryKlenov](https://codeforces.com/profile/DmitryKlenov "Expert DmitryKlenov")

 **Tutorial**
### [1765D - Watch the Videos](../problems/D._Watch_the_Videos.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

In this solution, we assume that the sequence $a_1, a_2, \dots, a_n$ is sorted (if it is not — just sort it before running the solution).

Suppose we download and watch the videos in some order. The answer to the problem is $n + \sum a_i$, reduced by $1$ for every pair of adjacent videos that can fit onto the hard disk together (i. e. their total size is not greater than $m$), because for every such pair, we can start downloading the second one while watching the first one. So, we need to order the videos in such a way that the number of such pairs is the maximum possible.

Suppose we want to order them so that every pair of adjacent videos is "good". We need to pick the ordering that minimizes the maximum sum of adjacent elements. There are multiple ways to construct this ordering; one of them is $[a_n, a_1, a_{n-1}, a_2, a_{n - 2}, a_3, \dots]$, and the maximum sum of adjacent elements will be $\max_{i=1, 2i \ne n}^{n} a_i + a_{n + 1 - i}$.

Proof that this ordering is optimal starts here

Suppose $j$ is such value of $i$ that $a_i + a_{n + 1 - i}$ is the maximum, and $j < n + 1 - j$. Let's prove that we cannot make the maximum sum of adjacent elements less than $a_j + a_{n + 1 - j}$. There are at most $j - 1$ values in $a$ which are less than $a_j$ (let's call them Group A), and at least $j$ values that are not less than $a_j$ (let's call them Group B). If we want each sum of adjacent elements to be less than $a_j + a_{n + 1 - j}$, we want the elements of Group B to be adjacent only to the elements of the Group A. The elements of Group B have at least $2j - 2$ links to the neighbors (since at most two of them will have only one neighbor), the elements of Group A have at most $2(j - 1)$ links to the neighbors, but we cannot link Group A with Group B without any outside links since it will disconnect them from all other elements of the array. So, we cannot get the maximum sum less than $a_j + a_{n + 1 - j}$.

Proof that this ordering is optimal ends here

Okay, now what if we cannot make all pairs of adjacent elements "good"? We can run binary search on the number of pairs that should be "bad". Let this number be $k$, then if we need to make at most $k$ pairs "bad", we can check that it's possible by removing $k$ maximum elements from $a$ and checking that now we can make the array "good". So, in total, our solution will work in $O(n \log n)$.

 **Solution (DmitryKlenov)**
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

#define N 200000

int a[N], n, s;

bool can(int x) {
    int l = x - 1, r = n - 1;
    while (l < r) {
        if (a[r] > s - a[l]) return false;
        ++l;
        if (l < r) {
            if (a[l] > s - a[r]) return false;
            --r;
        }
    }
    return true;
}


int main() {
    long long sum = 0;
    scanf("%d %dn", &n, &s);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    sort(a, a + n, greater<int>());

    int l = 1, r = n;
    while (l < r) {
        int m = (l + r) >> 1;
        if (can(m)) r = m;
        else l = m + 1;
    }

    long long ans = sum + r;
    cout << ans << endl;

    return 0;
}
```
[1765E - Exchange](../problems/E._Exchange.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1765E - Exchange](../problems/E._Exchange.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

If $a > b$, then Monocarp can go infinite by obtaining just one gold coin: exchanging it for silver coins and then buying it back will earn him $a-b$ silver coins out of nowhere. So, the answer is $1$ no matter what $n$ is.

If $a \le b$, then it's suboptimal to exchange gold coins for silver coins and then buy the gold coins back. Monocarp should earn the minimum possible number of gold coins so that they all can be exchanged into at least $n$ silver coins; so, the number of gold coins he needs is $\lceil \frac{n}{a} \rceil$.

One small note: you shouldn't use the functions like ceil to compute a fraction rounded up, since you may get some computation errors related to using floating-point numbers (and possibly getting precision loss). Instead, you should calculate $\lceil \frac{n}{a} \rceil$ as $\lfloor \frac{n + a - 1}{a} \lfloor$ (this works for non-negative $n$ and positive $a$), and every programming language provides an integer division operator which discards the fractional part and thus doesn't use floating-point computations at all.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

void solve() 
{
    int n, a, b;
    cin >> n >> a >> b;
    int x = (n + a - 1) / a;
    if(a > b) x = 1;
    cout << x << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
}
```
[1765F - Chemistry Lab](../problems/F._Chemistry_Lab.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Idea: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo"), preparation: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo")

 **Tutorial**
### [1765F - Chemistry Lab](../problems/F._Chemistry_Lab.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Let's start without picking the contracts. Buy them all and at least learn to calculate the answer.

Obviously, $k$ doesn't really matter for the answer. Linearity of expectation, it will be just something multiplied by $k$.

Imagine there's just one contract. Since we can't really mix it with anything, and the probability that the customer picks exactly that concentration is $0$, the answer is $0$.

What about two contracts? If you draw them as points $(x_i, c_i)$ on the grid, then all solutions, that can be obtained from a mix of them, are a segment. Basically, the formula is exactly the parametric equation for the segment, and that's how you could come to this conclusion. The expected cost is some integral, which is basically an area below the segment.

Three contracts? As a reasonable conclusion, now it's a triangle on these points. To show that, let's fix one of these points $A$, opposite to some base of the triangle $BC$. Pick a percentage of the solution $A$, then draw a segment from $A$ to that percentage of $BC$. If you fix the percentages of $B$ and $C$ (the point on the segment $BC$), then you can basically continuously gravitate this point towards $A$ along the drawn segment by increasing the concentration of $A$ and decreasing the concentrations of $B$ and $C$, while keeping their proportion to each other the same. The union of all options covers the entire triangle and can never go outside it.

Ok, let's make an educated guess about more contracts and try to show that. All solutions, that can be obtained with a mix of several solutions, are insides of a convex hull of the set of points. Let the set of points be convex already. If it isn't, we can say that the answer is the union of all convex subsets of it, which is equal to the convex hull. To prove it for the convex set, we can choose any three consecutive points on it and contract them into a segment, with the proof for the triangle. Continue until we reach two points.

All solutions are a convex hull, but we only care about the ones with the maximum cost. That would be the set of the highest intersection points of the convex hull and the vertical lines for all concentrations. Which is known as an upper envelope of the convex hull. The expected cost is the area below that upper envelope.

So we learned to calculate the answer for a fixed set of solutions. Let's learn how to pick them.

We want to directly construct that upper envelope. Let me first tell you a direct but a slow solution.

Do dynamic programming. Sort the solutions first in the increasing order of their concentration, second in the increasing order of their cost per litre. Now do $dp[i][j]$ — the maximum answer if the last point in the upper envelope is $j$ and the second last is $i$. To transition, iterate over the next point $k$ in that upper envelope and check if the triple $(i, j, k)$ is clockwise. To update the answer, add the newly added area below the segment $(j, k)$, which is a trapezoid, multiplied by $k$, and subtract the cost of the contract $k$. That would be $O(n^3)$.

Now for the funny transition. Basically, we can just not care that the points we pick give us an upper envelope. If we picked a set of points, which is not convex, then we can safely remove some points (pay less money for the contracts) and our calculated area can never decrease from that (since we still are picking points in the increasing order of $x$ and $y$).

Thus, we can remove the second to last point in the dp and only store the last one. That is enough to recalculate the area.

Overall complexity: $O(n^2)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef long long li;

const li INF64 = 1e18;

struct base{
    int x, w, c;
};

li area(const base &a, const base &b){
    return (a.c + b.c) * li(abs(a.x - b.x));
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<base> a(n);
    forn(i, n) scanf("%d%d%d", &a[i].x, &a[i].w, &a[i].c);
    sort(a.begin(), a.end(), [](const base &a, const base &b){ return a.x > b.x; });
    vector<li> dp(n, -INF64);
    li ans = 0;
    forn(i, n){
        dp[i] = max(dp[i], -a[i].w * 200ll);
        for (int j = i + 1; j < n; ++j)
            dp[j] = max(dp[j], dp[i] + area(a[i], a[j]) * k - a[j].w * 200ll);
        ans = max(ans, dp[i]);
    }
    printf("%.15Lfn", ans / (long double)(200));
    return 0;
}
```
[1765G - Guess the String](../problems/G._Guess_the_String.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1765G - Guess the String](../problems/G._Guess_the_String.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

We will design a randomized solution which spends $1.5$ queries on average to guess $2$ characters.

First of all, let's ask $p_2$ to learn which character is $s_2$. Depending on whether it is 0 or 1, the details of the solution might change, but the general idea stays the same. We will assume that it is 0.

We will divide the string into blocks of $2$ characters and guess it block by block. Suppose a block contains the characters $s_{i - 1}$ and $s_i$. If we want to guess it using less than $2$ queries, we should start with querying the $i$-th position (if we start by querying the position $i-1$, we won't know anything about the $i$-th position).

Suppose our query has returned a number greater than $1$. Then we successfully obtained the full information about the block in one query. So, let's analyze the bad case: what if we got $0$ or $1$ as the result of the query?

If we used prefix function, the result equal to $1$ shows us that the block is 10 — 00 will give the result of at least $2$, and neither 01 nor 11 can give $1$ as the result. But if the result is $0$, then it could mean either 01 or 11, and we need a second query to find out the exact combination.

If we used antiprefix function, every character gets inverted; so, the result equal to $1$ tells us that the block is 01, and the result equal to $0$ tells us that the block is either 10 or 00.

So, one type of query cannot distinguish 01 from 11, and the other type cannot distinguish 10 from 00. If we pick the type of query randomly, with probability of $\frac{1}{2}$ we will obtain the information about the whole block in just one query; so, this method will spend $1.5$ queries per block of $2$ characters on average.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

mt19937 rnd(42);
uniform_int_distribution<int> d(1, 2);

int ask(int t, int i)
{
    cout << t << " " << i + 1 << endl;
    int x;
    cin >> x;
    return x;
}

void giveAnswer(const string& s)
{
    cout << 0 << " " << s << endl;
    int x;
    cin >> x;
    assert(x == 1);
}

void guessOne(string& s, int i)
{
    int res = ask(1, i);
    if(res == 0)
        s[i] = '1';
    else
        s[i] = s[res - 1];
}

char inv(char c)
{
    if(c == '0') return '1';
    return '0';
}

void guessTwo(string& s, int i)
{
    if(s[1] == '0')
    {
        if(d(rnd) == 1)
        {
            int res = ask(1, i);
            if(res >= 2)
            {
                s[i] = s[res - 1];
                s[i - 1] = s[res - 2];
            }
            else if(res == 1)
            {
                s[i] = '0';
                s[i - 1] = '1';
            }
            else
            {
                s[i] = '1';
                guessOne(s, i - 1);
            }
        }
        else
        {
            int res = ask(2, i);
            if(res >= 2)
            {
                s[i] = inv(s[res - 1]);
                s[i - 1] = inv(s[res - 2]);
            }
            else if(res == 1)
            {
                s[i] = '1';
                s[i - 1] = '0';
            }
            else
            {
                s[i] = '0';
                guessOne(s, i - 1);
            }
        }
    }
    else
    {
        if(d(rnd) == 1)
        {
            int res = ask(1, i);
            if(res >= 2)
            {
                s[i] = s[res - 1];
                s[i - 1] = s[res - 2];
            }
            else if(res == 1)
            {
                s[i] = '0';
                guessOne(s, i - 1);
            }
            else
            {
                s[i] = '1';
                s[i - 1] = '1';
            }
        }
        else
        {
            int res = ask(2, i);
            if(res >= 2)
            {
                s[i] = inv(s[res - 1]);
                s[i - 1] = inv(s[res - 2]);
            }
            else if(res == 1)
            {
                s[i] = '1';
                guessOne(s, i - 1);
            }
            else
            {
                s[i] = '0';
                s[i - 1] = '0';
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string s(n, '0');
        for(int j = 1; j < n; j += 2)
        {
            if(j == 1) guessOne(s, j);
            else guessTwo(s, j);
        }
        if(n % 2 == 1) guessOne(s, n - 1);
        giveAnswer(s);
    }
}
```
[1765H - Hospital Queue](../problems/H._Hospital_Queue.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1765H - Hospital Queue](../problems/H._Hospital_Queue.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Let's solve the problem separately for each patient.

Let's assume that we are solving a problem for a patient with the number $s$. Let's iterate through the positions in the queue from the end, and the current position is $i$. 

Why do we try to construct the queue from the end, and not from its beginning? This allows us to handle the constraint on $p_i$ for each patient easier. If we try to form the queue starting from the beginning, we have to be very careful with these constraints on $p_i$, since placing a patient on some position might make it impossible to continue the order, but it's very difficult to understand when it concerns us. On the other hand, if we go from the end to the beginning, each patient that we can place on the current position can be placed on any of the positions we consider later as well, so our actions won't "break" the correct order; any order we build while maintaining all of the constraints for its suffix is correct. That's why this problem is easier to solve if we construct the queue backwards.

Now, all we need to do is try not to place patient $s$ as long as possible. So, we can maintain all patients we can place (such a patient $x$ that $x$ is not placed yet, $p_x \ge i$ and there is no such patient $y$, that $x$ should be in the queue before $y$, but $y$ is not placed yet) now in any data structure, and when choosing who to place on each position, we delay placing patient $s$ as long as possible.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    g[y - 1].push_back(x - 1);
  }
    
  vector<int> ans(n, -1);
  for (int s = 0; s < n; ++s) {
    vector<int> deg(n);
    for (int i = 0; i < n; ++i) 
      for (int j : g[i]) ++deg[j];
    priority_queue<pair<int, int>> q;
    for (int v = 0; v < n; ++v)
      if (deg[v] == 0 && v != s)
        q.push({a[v], v});
    for (int i = n; i > 0; --i) {
      if (q.empty() || q.top().first < i) {
        if (deg[s] == 0 && i <= a[s])
          ans[s] = i;
        break;
      }
      int v = q.top().second;
      q.pop();
      for (int u : g[v]) {
        --deg[u];
        if (deg[u] == 0 && u != s)
          q.push({a[u], u});
      }
    }
  }
  
  for (int &x : ans) cout << x << ' ';
}
 
```
[1765I - Infinite Chess](../problems/I._Infinite_Chess.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Idea: [DmitryKlenov](https://codeforces.com/profile/DmitryKlenov "Expert DmitryKlenov"), preparation: [dmitryme](https://codeforces.com/profile/dmitryme "Unrated, dmitryme")

 **Tutorial**Tutorial is loading... **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const string al = "KQRBN";

const int INF = 1e9;

struct mv{ int dx, dy; };
struct piece{ int x, y, t; };
struct seg{ int l, r; };
struct pos{ int x, y; };

bool operator <(const pos &a, const pos &b){
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

vector<vector<mv>> mvs({
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}},
    {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1}},
    {{-1, 0}, {0, 1}, {1, 0}, {0, -1}},
    {{-1, -1}, {1, -1}, {1, 1}, {-1, 1}},
    {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}}
});

int main() {
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    swap(sx, sy), swap(fx, fy);
    --sx, --fx;
    
    int k;
    cin >> k;
    vector<piece> a(k);
    forn(i, k){
        string t;
        cin >> t >> a[i].x >> a[i].y;
        swap(a[i].x, a[i].y);
        --a[i].x;
        a[i].t = al.find(t[0]);
    }
    
    sort(a.begin(), a.end(), [](const piece &a, const piece &b){
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    
    vector<int> base({sy, fy});
    forn(i, k) base.push_back(a[i].y);
    vector<int> ys;
    for (int y : base) for (int i = y - 16; i <= y + 16; ++i)
        ys.push_back(i);
    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
    
    vector<vector<char>> tk(8, vector<char>(ys.size()));
    forn(i, k){
        a[i].y = lower_bound(ys.begin(), ys.end(), a[i].y) - ys.begin();
        tk[a[i].x][a[i].y] = true;
    }
    sy = lower_bound(ys.begin(), ys.end(), sy) - ys.begin();
    fy = lower_bound(ys.begin(), ys.end(), fy) - ys.begin();
    
    vector<vector<char>> bad = tk;
    
    forn(i, k){
        int x = a[i].x, y = a[i].y;
        if (a[i].t == 0 || a[i].t == 4){
            for (auto it : mvs[a[i].t]){
                int nx = x + it.dx;
                int ny = y + it.dy;
                if (0 <= nx && nx < 8)
                    bad[nx][ny] = true;
            }
        }
        else{
            for (auto it : mvs[a[i].t]){
                for (int nx = x + it.dx, ny = y + it.dy; ; nx += it.dx, ny += it.dy){
                    if (nx < 0 || nx >= 8) break;
                    if (ny < 0 || ny >= int(ys.size())) break;
                    if (tk[nx][ny]) break;
                    bad[nx][ny] = true;
                }
            }
        }
    }
    
    vector<vector<int>> d(8, vector<int>(ys.size(), INF));
    vector<vector<pos>> p(8, vector<pos>(ys.size()));
    set<pair<int, pos>> q;
    d[sx][sy] = 0;
    q.insert({0, {sx, sy}});
    while (!q.empty()){
        int x = q.begin()->second.x;
        int y = q.begin()->second.y;
        q.erase(q.begin());
        if (x == fx && y == fy){
            cout << d[x][y] << endl;
            return 0;
        }
        for (int ny : {y - 1, y, y + 1}){
            if (ny < 0 || ny >= int(ys.size())) continue;
            int dy = max(1, abs(ys[y] - ys[ny]));
            for (int nx = max(0, x - 1); nx <= min(7, x + 1); ++nx) if (!bad[nx][ny]){
                int nd = d[x][y] + dy;
                if (d[nx][ny] > nd){
                    q.erase({d[nx][ny], {nx, ny}});
                    d[nx][ny] = nd;
                    p[nx][ny] = {x, y};
                    q.insert({d[nx][ny], {nx, ny}});
                }
            }
        }
    }
    
    cout << -1 << endl;
    return 0;
}
```
[1765J - Hero to Zero](../problems/J._Hero_to_Zero.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1765J - Hero to Zero](../problems/J._Hero_to_Zero.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

The order of operations is interchangeable, so we assume that we perform mass operations first, and operations affecting single elements last.

Suppose $p_i$ is the value we subtract from the $i$-th row using the operations affecting the whole row, and $q_j$ is the value we subtract from the $j$-th column using the operations affecting the whole column. Then the number of coins we have to pay is $S - (n-1) \cdot (\sum p_i + \sum q_j)$, since every such operation "saves" us exactly $n-1$ coins by decreasing the sum in the matrix by $n$ using only one coin.

Obviously, we want to maximize $\sum p_i + \sum q_j$, but if we subtract too much, some elements of the matrix may become negative (and it will be impossible to set them to zero using single element operations). So, for every $i \in [1, n]$ and $j \in [1, n]$, the condition $p_i + q_j \le c_{i,j}$ must hold.

Now let's take a look at how the Hungarian algorithm for assignment problem works. We can notice that the potentials in the Hungarian algorithm have the same constraints as the values $p_i$ and $q_j$ in our problem, and the sum of those potentials is maximized. So, if we apply the Hungarian algorithm to the matrix $c$, we can use the potentials as the values $p_i$ and $q_j$.

But the matrix is too large, so what should we do? We can use the fact that the maximum possible sum of potentials is equal to the optimal solution of the assignment problem, so we should solve the assignment problem in some other way. And in this particular way of constructing the matrix $c$ (where $c_{i,j} = |a_i - b_j|$), the solution of the assignment problem is simple: we need to reorder the elements of both arrays $a$ and $b$ so that the value of $\sum |a_i - b_i|$ is minimized, and it's easy to see (and to prove using exchange argument method) that sorting both arrays will give us the optimal solution.

All that's left is to calculate the sum of elements in the matrix, and that can be done if for every element in $a$, we calculate the number of elements in $b$ which are less than it, the number of elements in $b$ which are greater than it, and the sum of elements of $b$ greater than it (to quickly compute the sum of $|a_i - b_j|$ for every $j \in [1, n]$). All these values can be obtained with the help of binary search, two pointers method or some data structures.

The complexity of the solution is $O(n \log n)$.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long total = 0;
    for(int i = 0; i < n; i++)
    {
        total += n * 1ll * (a[i] + b[i]);
        total -= a[i] * 2ll * (b.end() - lower_bound(b.begin(), b.end(), a[i]));
        total -= b[i] * 2ll * (a.end() - upper_bound(a.begin(), a.end(), b[i]));
    }
    for(int i = 0; i < n; i++)
        total -= (n - 1) * 1ll * abs(a[i] - b[i]);
    cout << total << endl;
}
```
[1765K - Torus Path](../problems/K._Torus_Path.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic"), preparation: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**Tutorial is loading... **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int n;
vector< vector<int> > a;

bool read() {
    if (!(cin >> n))
        return false;
    a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    return true;
}

void solve() {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += accumulate(a[i].begin(), a[i].end(), 0LL);
    
    int mn = a[0][n - 1];
    for (int i = 0; i < n; i++)
        mn = min(mn, a[i][n - 1 - i]);
    
    cout << sum - mn << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    
    if(read()) {
        solve();
        
#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}
```
[1765L - Project Manager](../problems/L._Project_Manager.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo")

 **Tutorial**
### [1765L - Project Manager](../problems/L._Project_Manager.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

First, notice that the answer can't be that large. Even the worst case: one developer works one day of the week, responsible for a $2 \cdot 10^5$ part project, the first $2 \cdot 10^5$ of his workdays are holidays. It's just $7 \cdot (2 \cdot 10^5 + 2 \cdot 10^5)$.

Thus, we'd like to iterate over time and complete project parts exactly as they are due. If we manage to deduce the parts that have to be completed during the current day, the complexity will be limited by the total number of parts plus the maximum time.

To determine that, I propose to maintain the following data structures. First, maintain $7$ vectors of maps: for each day of the week, maintain pairs (the developer, the number of projects they are currently the blocking person for). Each developer is only counted in days they work at and only if they have a non-zero number of projects. Second, maintain $n$ vectors of sets: for each developer, maintain the projects they are currently the blocking person for.

To process a day, extract all pairs from the map for the current day of the week. All these developers will complete a part of a project. The index of that project is the first element in the corresponding set. Update all maps and sets and proceed. If the number of projects for any developers becomes zero, remove them from the maps.

If the current day is a holiday, just skip it.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
    cin.tie(0);
    iostream::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> ds(n, vector<char>(7));
    forn(i, n){
        int t;
        cin >> t;
        forn(_, t){
            string s;
            cin >> s;
            ds[i][find(days, days + 7, s) - days] = true;
        }
    }
    vector<int> h(m);
    forn(i, m) cin >> h[i];
    vector<vector<int>> a(k);
    forn(i, k){
        int p;
        cin >> p;
        a[i].resize(p);
        forn(j, p){
            cin >> a[i][j];
            --a[i][j];
        }
    }
    int j = 0;
    vector<int> ans(k, -1), lst(k);
    int done = 0;
    vector<map<int, int>> cur(7);
    vector<set<int>> wk(n);
    forn(i, k) forn(j, 7) if (ds[a[i][0]][j])
        ++cur[j][a[i][0]];
    forn(i, k)
        wk[a[i][0]].insert(i);
    for (int d = 1;; ++d){
        if (j < m && h[j] == d){
            ++j;
            continue;
        }
        int wd = (d - 1) % 7;
        vector<int> now, sv;
        for (auto it : cur[wd]) now.push_back(it.first);
        for (int x : now){
            forn(i, 7){
                auto it = cur[i].find(x);
                if (it != cur[i].end()){
                    if (it->second == 1)
                        cur[i].erase(it);
                    else
                        --it->second;
                }
            }
            int y = *wk[x].begin();
            sv.push_back(y);
            wk[x].erase(wk[x].begin());
        }
        forn(i, now.size()){
            int y = sv[i];
            ++lst[y];
            if (lst[y] == int(a[y].size())){
                ans[y] = d;
                ++done;
                continue;
            }
            wk[a[y][lst[y]]].insert(y);
            forn(j, 7) if (ds[a[y][lst[y]]][j])
                ++cur[j][a[y][lst[y]]];
        }
        if (done == k) break;
    }
    forn(i, k) cout << ans[i] << " ";
    cout << endl;
}
```
[1765M - Minimum LCM](../problems/M._Minimum_LCM.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**Tutorial is loading... **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a = 1;
    for (int g = 2; g * g <= n; ++g) {
      if (n % g == 0) {
        a = n / g;
        break;
      }
    }
    cout << a << ' ' << n - a << 'n';
  }
}
 
```
[1765N - Number Reduction](../problems/N._Number_Reduction.md "2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**Tutorial is loading... **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int t;
  cin >> t;
  while (t--) {
    string x;
    cin >> x;
    int k;
    cin >> k;
    int n = x.size();
    vector<vector<int>> pos(10);
    for (int i = 0; i < n; ++i)
      pos[x[i] - '0'].push_back(i);
    for (int i = 0; i < 10; ++i)
      reverse(pos[i].begin(), pos[i].end());
    string ans;
    int lst = 0, len = n - k;
    for (int i = 0; i < len; ++i) {
      for (int d = (i == 0); d <= 9; ++d) {
        while (!pos[d].empty() && pos[d].back() < lst)
          pos[d].pop_back();
        if (!pos[d].empty() && pos[d].back() - lst <= k) {
          ans += d + '0';
          k -= pos[d].back() - lst;
          lst = pos[d].back() + 1;
          break;
        }
      }
    }
    cout << ans << 'n';
  }
}
 
```
