# Tutorial_(en)

[1255A - Изменение громкости](https://codeforces.com/contest/1255/problem/A "Codeforces Round 601 (Div. 2)")

Author: [UncleGrandpa](https://codeforces.com/profile/UncleGrandpa "Мастер UncleGrandpa"). Prepared by [UncleGrandpa](https://codeforces.com/profile/UncleGrandpa "Мастер UncleGrandpa")

 **Tutorial**
### [1255A - Изменение громкости](https://codeforces.com/contest/1255/problem/A "Codeforces Round 601 (Div. 2)")

Notice that if at some moment we increase the volume and at some moment we decrease the volume, we can remove those two actions and replace them with at most two new actions that are both increasing or decreasing (for instance, $+5$ $-1$ can be replaced with $+2$ $+2$; $+2$ and $-2$ can be replaced with nothing and $+2$ and $-1$ can be replaced with $+1$). We can see that replacing like this will not make the volume goes below zero at any moment. So, we will increase the volume all the time, or decrease all the time.

Assume that we only increase the volume. It can be proved that for any set consists of only $1$s and $2$s and the sum of its elements is greater than or equal to $5$, it has a subset which its elements sums to $5$. This means that if we use $+1$ and $+2$ to increase the volume by at least $5$, we can replace some of those actions with a $+5$. Hence, it is optimal to increase the volume by $5$ until the gap between $a$ and $b$ is less than $5$, then the remaining job is trivial.

[1255B - Замки для холодильников](https://codeforces.com/contest/1255/problem/B "Codeforces Round 601 (Div. 2)")

Author: [I_love_tigersugar](https://codeforces.com/profile/I_love_tigersugar "Гроссмейстер I_love_tigersugar") ft. [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Штаб, MikeMirzayanov"). Prepared by [UncleGrandpa](https://codeforces.com/profile/UncleGrandpa "Мастер UncleGrandpa")

 **Tutorial**
#### Modelize the problem

We modelize the problem as graph, where each fridge is a vertex and each chain is an edge between two vertexes. The problem is now equivalent to: Given a graph with n vertexes, each vertex has a value ai≥0. We have to add m edges to the graph such that each vertex is connected to at least two different vertexes and the total cost of edges added is minimum. The cost of an edge is the sum of value of its two end-points. 

#### Observe some basic properties of graph

Now, each edge added will increase the sum of degree of all vertexes by 2. So adding m edges will make the sum of degree equal to 2×m. Since each vertexes must be connected to at least 2 other vertexes, the minimum sum of degree is 2×n.

 * Case 1: 2×m<2×n⇔m<n

In this case, it is obvious that the answer is −1.

 * Case 2: 2×m=2×n⇔m=n

In this case, it is easy to see that the degree of each vertex will be exactly 2. As a result, no matter what edges we add, the result is still 2×(a1+a2+...+an). But please take note that if n=2, then the answer will be −1 since for each vertex we have at most 1 different vertex to connect to. 

 * Case 3(Of the original, pre-modified version of the problem): 2×m>2×n⇔m>n

Please read this [excellent answer](https://codeforces.com/blog/entry/71562?#comment-559266) by [Um_nik](https://codeforces.com/profile/Um_nik "Легендарный гроссмейстер Um_nik"). All credit goes to him for the excellent proof. 

[1255C - League of Leesins](https://codeforces.com/contest/1255/problem/C "Codeforces Round 601 (Div. 2)")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Штаб, MikeMirzayanov"). Prepared by [UncleGrandpa](https://codeforces.com/profile/UncleGrandpa "Мастер UncleGrandpa") 

 **Tutorial**
### [1255C - League of Leesins](https://codeforces.com/contest/1255/problem/C "Codeforces Round 601 (Div. 2)")

There will be exactly $2$ numbers that appear only once in the input and they are the first and the last element of the permutation. Let $p_1$ be any of them and start with the only triple that contains $p_1$. If $x, y$ are the other members of the mentioned triple, there exists a unique triple that contains $x, y$ but not $p_1$. We can easily find that triple by searching through every triple that contains $x$ (and there are at most $3$ such triples). By repeating doing this, we can get a list $r$ that $r_i = perm(p_i, p_{i+1}, p_{i+2})$.

From $r$, we can construct a permutation that satisfies the problem. Assume we know $p_1$ and $p_2$, then we can find the rest of the permutation easily. To determine which number is $p_2$, we can use the fact $p_2$ is the only number that only appears in $r_1$ and $r_2$.

[1254A - Кормление куриц](../problems/A._Feeding_Chicken.md "Codeforces Round 601 (Div. 1)") 

Author: [I_love_tigersugar](https://codeforces.com/profile/I_love_tigersugar "Гроссмейстер I_love_tigersugar"). Prepared by [I_love_tigersugar](https://codeforces.com/profile/I_love_tigersugar "Гроссмейстер I_love_tigersugar")

 **Tutorial**
### [1254A - Кормление куриц](../problems/A._Feeding_Chicken.md "Codeforces Round 601 (Div. 1)")

First, we will try to solve the problem when our rectangle is an array (or an $1 \cdot n$ rectangle).

Let $r$ be the number of rice cells. It's not hard to see that the difference between the maximum and the minimum number of cells with rice assigned to a chicken is either $0$, when $r$ $mod$ $k = 0$, or $1$ otherwise. Turns out, there is an easy way to assign: for the first $r$ $mod$ $k$ chicken, we will assign to the current chicken a prefix of the current array that contains exactly $\lceil r/k \rceil$ rice cells, and delete that prefix. The same for the others $k - (r$ $mod$ $k)$ chicken, we will assign to the current chicken a prefix of the current array that contains exactly $\lfloor r/k \rfloor$ rice cells.

Notice that there exists a path that goes through every cell exactly once and every two consecutive cells on the path share a side. One such path is $(1, 1), (1, 2), ... (1,c), (2,c), (2, c-1), ..., (2, 1), (3, 1), (3, 2), ...$ By thinking the path as an array, we can assign regions on the path according to the above paragraph. Such an assignment is also a valid assignment for the original rectangle.

 **Source code**
```cpp
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

const string SYMBOLS = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890";

#define MAX  111
char board[MAX][MAX], res[MAX][MAX];
int numRow, numCol, numChicken;

void process(void) {
    memset(board, 0, sizeof board);
    memset(res, 0, sizeof res);

    scanf("%d%d%d", &numRow, &numCol, &numChicken);
    FOR(i, 1, numRow) scanf("%s", board[i] + 1);

    bool leftToRight = true;
    vector<pair<int, int>> cells;
    FOR(i, 1, numRow) {
        if (leftToRight) {
            FOR(j, 1, numCol) cells.push_back(make_pair(i, j));
        } else {
            FORD(j, numCol, 1) cells.push_back(make_pair(i, j));
        }
        leftToRight ^= 1;
    }

    int totRice = 0;
    FOR(i, 1, numRow) FOR(j, 1, numCol) if (board[i][j] == 'R') totRice++;
    int avg = totRice / numChicken;
    int diff = totRice % numChicken == 0 ? 0 : 1;

    REP(i, numChicken) {
        int cntRice = 0;
        while (true) {
            int x = cells.back().fi, y = cells.back().se;
            cells.pop_back();
            res[x][y] = SYMBOLS[i];
            if (board[x][y] == 'R') {
                totRice--;
                cntRice++;
            }
            if (cntRice < avg) continue;
            if (avg * (numChicken - i - 1) <= totRice && totRice <= (avg + diff) * (numChicken - i - 1)) break;
        }
    }
    while (!cells.empty()) {
        int x = cells.back().fi, y = cells.back().se;
        cells.pop_back();
        res[x][y] = SYMBOLS[numChicken - 1];
    }

    FOR(i, 1, numRow) {
        FOR(j, 1, numCol) printf("%c", res[i][j]); printf("n");
    }
}

int main(void) {
    int t; scanf("%d", &t);
    REP(love, t) process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
```
[1254B1 - Отправьте коробки Алисе (упрощенная версия)](../problems/B1._Send_Boxes_to_Alice_(Easy_Version).md "Codeforces Round 601 (Div. 1)")

Author: [MofK](https://codeforces.com/profile/MofK "Международный гроссмейстер MofK"). Prepared by [UncleGrandpa](https://codeforces.com/profile/UncleGrandpa "Мастер UncleGrandpa")

 **Tutorial**The problem asked you to move chocolate pieces between adjacent boxes so that the number of chocolate pieces in all boxes is divisible by k (k>1).

#### How to solve the problem for a specific k

Now, it's clear that we will divide the array into segments, such that the sum of each segment is divisible by k, and move all chocolate pieces in that segment to a common box. Here we take notice of 2 things: 

 * First, in each segment, let A be the array of all position with 1, then the position that we move all the 1 to is the median of that array A (easy to prove).
* Second, the sum of each segment should be all equal to k. It's easy to see that if there exists some segment of sum x∗k, then separating them into x segments of sum k will improve the result.

With that two observations, we can iterate from 1 to n, push each position with value 1 into a temp array, and whenever the size of array become k, we add to our result the sum of |ai−median| and clear the array.

#### Knowing how to solve for a specific k, how to solve the problem?

It is clear that k must be a divisor of the total number of chocolate pieces. So we iterate through all possible k and minimize our answer with the number of steps to make all numbers divisible by k. A number ≤105 has at most 128 divisors, and each calculation take O(n) so the solution should pass easily. 

 **Source code**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000006;
int n;
int a[maxn];
vector <int> v;

long long cost(int p) {
    long long ret = 0;
    for (int i = 0; i < v.size(); i += p) {
        int median = v[(i + i + p - 1) / 2];
        for (int j = i; j < i + p; ++j)
            ret += abs(v[j] - median);
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 1) v.push_back(i);
    }
    if (v.size() == 1) {
        cout << -1 << endl;
        return 0;
    }
    long long ans = 1e18;
    int tmp = v.size(), p = 2;
    while (p * p <= tmp) {
        if (tmp % p == 0) {
            ans = min(ans, cost(p));
            while (tmp % p == 0)
                tmp /= p;
        }
        ++p;
    }
    if (tmp > 1)
        ans = min(ans, cost(tmp));
    cout << ans << endl;
    return 0;
}
```
[1254B2 - Отправьте коробки Алисе (усложнённая версия)](../problems/B2._Send_Boxes_to_Alice_(Hard_Version).md "Codeforces Round 601 (Div. 1)")

Author: [MofK](https://codeforces.com/profile/MofK "Международный гроссмейстер MofK"). Prepared by [MofK](https://codeforces.com/profile/MofK "Международный гроссмейстер MofK") and [UncleGrandpa](https://codeforces.com/profile/UncleGrandpa "Мастер UncleGrandpa")

 **Tutorial**The problem E2 is different from the problem E1 in some ways. Now all Ai is at most 106, and so is the number n. That makes our solution on E1 simply not usable in this problem. 

#### A cute observation:

Let Si be the sum of a1+a2+...+ai. Now we see that:

 * if we move a chocolate piece from box i to box i+1, it is equivalent to decrease Si by 1.
* if we move a chocolate piece from box i+1 to box i, it is equivalent to increase Si by 1.

Wow, now each moving steps only affect one number. Next, we can see that if every ai is divisible by k, then so is every Si. Thus, our problem is now transformed to: Given an array S. At each turn, you can choose one Si and increase (or decrease) it by one (except for Sn). Find the minimum number of steps to make all Si divisible by k.

#### How to solve the problem for a specific k

An intuitive approach is to try to increase (or decrease) each Si to the nearest multiple of k. If such a configuration can be achieved then it will obviously be the best answer. The only concern is that: is there any scenario when there exists some i such that Si>Si+1, which is indeed a violation? Fortunately, the answer is no. We can enforce the solution to iterate each Si from 1 to n−1 and always choose to decrease if there is a tie. This way, the sequence S will remain non-decreasing throughout the process.

So, the solution is as follows. Just iterate from 1 to n−1 and for each i, add to our result min(Si%k,k−Si%k).

#### Knowing how to solve for a specific k, how to solve the problem?

Again, like E1, it is clear that k must be a divisor of the total number of chocolate pieces. But now the total number of chocolate pieces is at most 1012, which an iteration through all divisors will not be fast enough to fit in 1 second. (In fact, we did make just one single test case to block this solution. Nevertheless, on random testcases it runs super fast).

But if you have solved the problem to this phase already, you can easily realize that we only need to consider prime k, because if k is composite then picking any prime divisors of it will lead to either a better result or an equal result.

That's it, there will be at most 12 distinct prime divisors. Each calculation takes O(n). So the solution will also pass easily.

 **Source code**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000006;
int n;
long long a[maxn];
long long s[maxn];

long long cost(long long mod) {
    long long ret = 0;
    for (int i = 1; i <= n; ++i)
        ret += min(s[i] % mod, mod - s[i] % mod);
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    if (s[n] == 1) {
        cout << -1 << endl;
        return 0;
    }
    long long ans = 1e18;
    long long tmp = s[n], p = 2;
    while (p * p <= tmp) {
        if (tmp % p == 0) {
            ans = min(ans, cost(p));
            while (tmp % p == 0)
                tmp /= p;
        }
        ++p;
    }
    if (tmp > 1)
        ans = min(ans, cost(tmp));
    cout << ans << endl;
    return 0;
}
```
[1254C - Упорядочьте точки](../problems/C._Point_Ordering.md "Codeforces Round 601 (Div. 1)")

Author: [ngkan](https://codeforces.com/profile/ngkan "Мастер ngkan"). Prepared by [ngkan](https://codeforces.com/profile/ngkan "Мастер ngkan")

 **Tutorial**
### [1254C - Point Ordering](../problems/C._Point_Ordering.md "Codeforces Round 601 (Div. 1)")

Let's start by choosing vertices $1$ and $2$ as pivots.

Recall that if the cross product of two vectors $\vec{A}$ and $\vec{B}$ is positive, point $B$ lies to the left of $\vec{A}$; if the product is negative, point $B$ lies to the right of $\vec{A}$; and if the product is zero, the 3 points $(0,0)$, $A$, $B$ are collinear.

With $n-2$ queries of type 2, we can know which vertices lie to the left or to the right of edge $1-2$ and then solve the two sides separately.

Consider the left side and there are $a$ vertices lie to the left, we can use $a$ queries of type 1 to calculate the distance from those vertices to edge $1-2$ (the distance from vertex $X$ to edge $1-2$ is twice the area of the triangle forms by $1$, $2$, $X$, divides by the length of edge $1-2$). 

Let Y be the farthest from $1-2$ (there can be at most 2 such vertices). We can use $a-1$ queries of type 2 to see if the others vertices lie between $1, Y$ or between $Y, 2$, then sort them counter-clockwise with the asked distances. 

So we will use $n-2$ queries to calculate the distances from vertices $3, 4, .. n$ to edge $1-2$ and at most $n - 3$ for the latter step. This solution uses at most $3n-7$ queries.

Another solution is to find the vertex that is consecutive to $1$ in $n-2$ queries and do the same as the solution above.

 **Source code**
```cpp
#include <bits/stdc++.h>
using namespace std;

int n;

void check_if_zero(long long x){
    if (x == 0) exit(0);
}

long long get_area(int a,int b,int c){
    long long result;
    cout << 1 << ' ' << a << ' ' << b << ' ' << c << endl;
    cin >> result;
    check_if_zero(result);
    assert(result > 0);
    return result;
}

int get_sign(int o,int a,int b){
    int result;
    cout << 2 << ' ' << o << ' ' << a << ' ' << b << endl;
    cin >> result;
    check_if_zero(result);
    assert(abs(result) == 1);
    return result;
}

vector <int> lef, rig;

void divide(){
    for(int i=3;i<=n;i++){
        int sign = get_sign(1, 2, i);

        if (sign == 1)
            lef.push_back(i);
        else
            rig.push_back(i);
    }
}

long long area12[1005];

void _do(vector<int> &lst){
    if (lst.size() <= 1)
        return;

    long long best = 0;
    for(auto v: lst){
        area12[v] = get_area(1, 2, v);
        if (area12[v] > area12[best])
            best = v;
    }

    vector <int> l, r;
    for(auto v: lst){
        if (v == best)
            continue;

        if (get_sign(1, best, v) == 1)
            l.push_back(v);
        else
            r.push_back(v);
    }

    sort(l.begin(), l.end(), [&](int x,int y){
        return area12[x] > area12[y];
    });
    sort(r.begin(), r.end(), [&](int x,int y){
        return area12[x] < area12[y];
    });

    lst.clear();
    for(auto v: r)  lst.push_back(v);
    lst.push_back(best);
    for(auto v: l)  lst.push_back(v);
}

void answer(){
    cout << 0 << ' ' << 1 << ' ';
    for(auto v: rig)  cout << v << ' ';
    cout << 2 << ' ';
    for(auto v: lef)  cout << v << ' ';
    cout << endl;
}

int main(){
    cin >> n;
    assert(n >= 3);

    divide();   // n-2 queries
    _do(lef);
    _do(rig);   //  2*(n-2) - 1 or 2*(n-2) - 2 queries
    answer();
}
```
[1254D - Запросы на дереве](../problems/D._Tree_Queries.md "Codeforces Round 601 (Div. 1)")

Author: [I_love_tigersugar](https://codeforces.com/profile/I_love_tigersugar "Гроссмейстер I_love_tigersugar") Prepared by [I_love_tigersugar](https://codeforces.com/profile/I_love_tigersugar "Гроссмейстер I_love_tigersugar")

 **Tutorial**
### [1254D - Запросы на дереве](../problems/D._Tree_Queries.md "Codeforces Round 601 (Div. 1)")

Disclaimer: Our other authors and testers have found better solutions; our best complexity is $O(n \times log^{2}(n))$. However, since this solution is the theoretically worst complexity that we intended to accept, I decided to write about it. Feel free to share your better solution in the comment section :)

Consider two distinct vertices $u$, $v$, the number of vertices $r$ such that the path from $r$ to $u$ passes through $v$ is $n - |Tree(v, u)|$, where $Tree(v, u)$ is the subtree we get by cutting the first edge on the path from $v$ to $u$, then keep the part with vertex $u$. If $u = v$ then this value will be $n$. By linearity of expectation, we can see that adding $d$ to $a[v]$ will add to the expected value of $a[u]$ an amount equal to $\frac{1}{n} \times d \times (n - |Tree(v, u)|)$. Note that this value is the same for all $u$ that lies on the same "subtree branch" of $v$. To update it efficiently, we can split the vertices into $2$ groups: those which has degree greater than $T$ (there are no more than $\frac{n}{T}$ of them), and those which does not. When we update a "light" vertex $v$, we iterate over the neighbors of $v$ and update the subtrees accordingly. When we get the value of a vertex $v$, we already have the sum of contributions from all "light" vertices to $v$, hence we can iterate over all "heavy" vertices and calculate the contribution from each of them to $v$. 

If we use range-update point-query data structures such as Fenwick Trees then the complexity will be $O(Q \times log(n) \times (\frac{n}{T} + T)) = O(Q \times \sqrt{n} \times log(n))$ if we choose $T = O(\sqrt{n})$.

 **Source code**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 150005;
const int mod = 998244353;
const int heavy = 300;
int n, m, q;
vector <int> adj[maxn];
int dad[maxn];
int sz[maxn];
vector <int> pos[maxn];
int tour[2*maxn];
vector <int> heavy_vector;
int weight[2*maxn];
 
int pw(int x, int y) {
    int r = 1;
    while (y) {
        if (y & 1) r = 1LL * r * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return r;
}
 
void dfs(int u) {
    tour[++m] = u;
    pos[u].push_back(m);
    sz[u] = 1;
    for (auto v: adj[u]) {
        if (v == dad[u]) continue;
        dad[v] = u;
        dfs(v);
        sz[u] += sz[v];
        tour[++m] = u;
        pos[u].push_back(m);
    }
}
 
int fwt[2*maxn];
void upd(int l, int r, int d) {
    for (int p = l; p <= m; p += p & -p) fwt[p] = (fwt[p] + d) % mod;
    ++r;
    for (int p = r; p <= m; p += p & -p) fwt[p] = (fwt[p] + mod - d) % mod;
}
int get(int p) {
    int ret = 0;
    for (; p; p -= p & -p) ret = (ret + fwt[p]) % mod;
    return ret;
}
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> q;
    int inv_n = pw(n, mod - 2);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(1);
    for (int i = 1; i <= n; ++i) if (adj[i].size() >= heavy)
        heavy_vector.push_back(i);
 
    while (q--) {
        int type, v;
        cin >> type >> v;
        if (type == 1) {
            int d;
            cin >> d;
            weight[v] = (weight[v] + d) % mod;
            if (adj[v].size() < heavy) {
                for (auto u: adj[v]) if (u != dad[v])
                    upd(pos[u][0], pos[u].back(), 1LL * d * (n - sz[u]) % mod * inv_n % mod);
                if (v == 1) continue;
                upd(1, pos[v][0] - 1, 1LL * d * sz[v] % mod * inv_n % mod);
                upd(pos[v].back() + 1, m, 1LL * d * sz[v] % mod * inv_n % mod);
            }
        }
        else {
            int ans = (weight[v] + get(pos[v][0])) % mod;
            for (auto u: heavy_vector) {
                if (u == v) continue;
                auto it = lower_bound(pos[u].begin(), pos[u].end(), pos[v][0]);
                if (it == pos[u].begin() || it == pos[u].end())
                    ans = (ans + 1LL * weight[u] * sz[u] % mod * inv_n) % mod;
                else {
                    int p = tour[*(--it) + 1];
                    ans = (ans + 1LL * weight[u] * (n - sz[p]) % mod * inv_n) % mod;
                }
            }
            cout << ans << 'n';
        }
    }
    return 0;
}
```
[1254E - Отправьте дерево Чарли](../problems/E._Send_Tree_to_Charlie.md "Codeforces Round 601 (Div. 1)")

Author: [MofK](https://codeforces.com/profile/MofK "Международный гроссмейстер MofK") Prepared by: [MofK](https://codeforces.com/profile/MofK "Международный гроссмейстер MofK")

 **Tutorial**
### [1254E - Отправьте дерево Чарли](../problems/E._Send_Tree_to_Charlie.md "Codeforces Round 601 (Div. 1)")

Let's solve an easier version of this problem first: when all $a_i$ is equal to $0$. Let $P[1..n-1]$ be some order of edges. If $n=2$ then the answer is clearly $1$. Otherwise, consider any leaf $u$ and its neighbor $v$. The label of $u$ in the end will depend solely on the relative position of the edge $(u, v)$ compared to other edges incident to $v$ in $P$. We can also prove that if that relative position is fixed then the final configuration will be the same. Therefore, if we add $u$ to the tree, the answer will be multiplied by $deg(v)$. It follows that the answer in this case will be $\displaystyle\prod_{u=1}^{n} deg(u)!$. We can also see that each configuration can be obtained by ordering the edges incident to $u$ for each vertex $u$.

Now, let's consider some constraint of the form $a[u] = v$. If $u = v$ then clearly there's no such configuration. Otherwise, it will create some conditions of the orderings in each vertex. Formally, let $B(u)$ be the ordering of edges incident to $u$, and $u, t_1, \ldots, t_k, v$ be the path from $u$ to $v$, we have the following conditions:

* $(u, t_1)$ is the first edge in $B(u)$.
* $(t_i, t_{i-1})$ must be followed immediately by $(t_i, t_{i+1})$ in $B(t_i)$, for all $1 \le i \le k$.
* $(v, t_k)$ is the last edge in $B(v)$.

Another thing to note is that in the final configuration, the sum of distance between $u$ and the vertex that contains label $u$ will be exactly $2n-2$ because each swap increases the sum by exactly $2$. Therefore, we can quit immediately upon finding out that the sum is larger than $2n-2$, and by that we ensure the total number of conditions will be $O(n)$.

Now, we can solve each vertex independently. For each vertex, there will be no possible configurations iff at least one of the following holds:

* Some edge follows or is followed by more than one edge.
* The conditions create some cycles.
* The conditions create a path from the first edge to the last edge, but there exists some edge not in it.

Otherwise, the conditions create some chains. We then multiply the answer by $k!$, where $k$ is the number of such chains, excluding those that contain the first edge or the last edge.

Time complexity: $O(n)$.

 **Source code**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 500005;

int n;
vector <int> adj[maxn];
int a[maxn];
int dad[maxn];
int h[maxn];
vector <pair <int, int> > conditions[maxn];
int nxt[maxn], prv[maxn], seen[maxn];

void no(int ncase) {
    cerr << ncase << endl;
    cout << 0 << endl;
    exit(0);
}

void dfs(int u) {
    for (auto v: adj[u]) if (v != dad[u]) {
        dad[v] = u;
        h[v] = h[u] + 1;
        dfs(v);
    }
}

int cnt; ///total distance, must not be more than 2n-2

void go(int u, int v) {
    if (u == v) no(0);
    vector <int> from_u, to_v;
    ///naive LCA works here as long as we exit upon finding a conflict
    from_u.push_back(n + 1); ///first edge (fake)
    to_v.push_back(n + 2); ///last edge (fake)
    while (h[u] > h[v]) {
        from_u.push_back(u);
        u = dad[u];
    }
    while (h[v] > h[u]) {
        to_v.push_back(v);
        v = dad[v];
    }
    while (u != v) {
        from_u.push_back(u);
        u = dad[u];
        to_v.push_back(v);
        v = dad[v];
    }
    from_u.push_back(u);
    from_u.insert(from_u.end(), to_v.rbegin(), to_v.rend());
    for (int i = 1; i + 1 < from_u.size(); ++i)
        conditions[from_u[i]].push_back({from_u[i-1], from_u[i+1]});
    cnt += from_u.size() - 3;
    if (cnt > 2 * n - 2) no(0); ///important break
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        adj[i].push_back(n + 1); ///first edge (fake)
        adj[i].push_back(n + 2); ///last edge (fake)
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];

    if (n == 1) {
        cout << 1 << endl;
        exit(0);
    }

    dfs(1);
    for (int i = 1; i <= n; ++i) if (a[i] != 0) go(i, a[i]);

    ///answer 0 if:
    ///1. there are 2 or more incoming/outgoing
    ///conditions to/from an edge, or
    ///2. there is a cycle, or
    ///3. first (n+1) is connected to last (n+2),
    ///but does not contain all other edges.
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        ///check case 1
        for (auto edge: conditions[i]) {
            int u = edge.first, v = edge.second;
            if (nxt[u] && nxt[u] != v) no(1);
            if (prv[v] && prv[v] != u) no(1);
            nxt[u] = v;
            prv[v] = u;
        }
        ///check case 2
        for (auto u: adj[i]) if (!seen[u]) {
            seen[u] = 1;
            int cur = nxt[u];
            while (cur) {
                if (cur == u) no(2);
                if (seen[cur]) break;
                seen[cur] = 1;
                cur = nxt[cur];
            }
        }
        ///check case 3
        if (nxt[n+1]) {
            int cur = n + 1, all = 1;
            while (cur) {
                if (cur == n + 2) break;
                ++all;
                cur = nxt[cur];
            }
            if (cur == n + 2 && all < adj[i].size()) no(3);
        }
        ///all good - for now
        int free = 0;
        for (auto u: adj[i]) if (u <= n && !prv[u]) ///fake edges doesn't count
            ++free;
        if (prv[n+2]) --free; ///connected to last edge => not free
        for (int j = 1; j <= free; ++j) ans = 1ll * ans * j % mod;
        ///reset
        for (auto u: adj[i]) nxt[u] = prv[u] = seen[u] = 0;
    }

    ///no conflicts
    cout << ans << endl;
    return 0;
}
```
