# Tutorial

[1036A - Function Height](../problems/A._Function_Height.md "Educational Codeforces Round 50 (Rated for Div. 2)")

 **Tutorial**
### [1036A - Function Height](../problems/A._Function_Height.md "Educational Codeforces Round 50 (Rated for Div. 2)")

It is easy to see that the area of the plot is the sum of areas of all triangles in this plot. Each move increases area by one. We cannot obtain the answer less than $\lceil\frac{k}{n}\rceil$ but we always can obtain such an answer.

 **Solution (Vovuh)**
```cpp
n, k = map(int, input().split())
print((k + n - 1) // n)
```
[1036B - Diagonal Walking v.2](../problems/B._Diagonal_Walking_v.2.md "Educational Codeforces Round 50 (Rated for Div. 2)")

 **Tutorial**
### [1036B - Diagonal Walking v.2](../problems/B._Diagonal_Walking_v.2.md "Educational Codeforces Round 50 (Rated for Div. 2)")

There are several cases in this problem. If $n < m$ then let's swap them. Let $\%$ be the modulo operator. Firstly, if $n \% 2 \ne m \% 2$ then let's decrease $k$ and $n$ by one. Otherwise if $n \% 2 \ne k \% 2$ let's decrease $n$, $m$ by one and $k$ by two. Now if $k < n$ then the answer is -1, otherwise the answer is $k$. You can get more clear description of these cases if you will draw some cases on the paper.

 **Solution (Vovuh)**
```cpp
q = int(input())

for i in range(q):
    n, m, k = map(int, input().split())
    if (n < m): n, m = m, n
    if (n % 2 != m % 2):
        k -= 1
        n -= 1
    elif (n % 2 != k % 2):
        k -= 2
        n -= 1
        m -= 1
    print(-1 if k < n else k)
```
[1036C - Classy Numbers](../problems/C._Classy_Numbers.md "Educational Codeforces Round 50 (Rated for Div. 2)")

 **Tutorial**
### [1036C - Classy Numbers](../problems/C._Classy_Numbers.md "Educational Codeforces Round 50 (Rated for Div. 2)")

There are quite a few approaches to the problem. I'll describe the two of them which I actually implemented.

First approach - combinatoric one:

Problems of the form "count the number of beautiful numbers from $L$ to $R$" usually require counting the numbers on $[1; R]$ and $[1; L - 1]$ (or not inclusively $[1; R + 1)$ and $[1; L)$) and subtracting one from another. Let's try this thing here, counting $calc(R + 1) - calc(L)$ not inclusively.

Let's fix some prefix of the upper border number. We want to calculate the amount of numbers having the same prefix but being smaller in the next digit. If we count it for all prefixes (including the empty one), we will get the answer. 

And that is pretty easy. Let the prefix include $k$ non-zero digits, the length of the suffix be $x$ and the digit after the chosen prefix is $d$. If $d$ is zero then there the result is obviously zero. Otherwise we can either put $0$ or any of the $(d - 1)$ non-zero digits. Then the formula is:

$\sum \limits_{i = 0}^{3 - k} \binom{x - 1}{i} \cdot 9^i$ + $(d - 1) \cdot \sum \limits_{i = 0}^{3 - k - 1} \binom{x - 1}{i} \cdot 9^i$.

We choose $i$ positions from the suffix to put non-zero digits in them (any digit from $1$ to $9$) and fill the rest with zeros.

Overall complexity: $O(T \cdot \log n)$.

Second approach - precalc one:

This is a bit easier to implement. Actually, there are just about 700000 valid numbers, you can generate them all, put them into the array in sorted order and binary search for the given queries.

Overall complexity: $O(T \cdot \log ANSCNT)$.

 **Solution with combinatorics (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

long long C[20][20];
long long pw[4];

long long cnk(int n, int k){
    if (k < 0 || k > n) return 0;
    return C[n][k];
}

long long get(int n, int lft){
    long long tot = 0;
    forn(i, lft + 1)
        tot += cnk(n, i) * pw[i];
    return tot;
}

long long calc(long long x){
    string s = to_string(x);
    
    long long res = 0;
    int cur = 3;
    int n = s.size();
    
    forn(i, n){
        if (s[i] == '0') continue;
        res += get(n - i - 1, cur);
        --cur;
        if (cur == -1) break;
        res += get(n - i - 1, cur) * (s[i] - '1');
    }
    
    return res;
}

int main() {
    forn(i, 20){
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    pw[0] = 1, pw[1] = 9, pw[2] = 81, pw[3] = 729;
    int T;
    scanf("%d", &T);
    forn(i, T){
        long long L, R;
        scanf("%lld%lld", &L, &R);
        printf("%lldn", calc(R + 1) - calc(L));
    }
    return 0;
}
```
 **Solution with precalc (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

vector<long long> res;

void brute(int pos, int cnt, long long cur){
    if (pos == 18){
        res.push_back(cur);
        return;
    }
    
    brute(pos + 1, cnt, cur * 10);
    
    if (cnt < 3)
        for (int i = 1; i <= 9; ++i)
            brute(pos + 1, cnt + 1, cur * 10 + i);
}

int main() {
    brute(0, 0, 0);
    res.push_back(1000000000000000000);
    
    int T;
    scanf("%d", &T);
    forn(i, T){
        long long L, R;
        scanf("%lld%lld", &L, &R);
        printf("%dn", int(upper_bound(res.begin(), res.end(), R) - lower_bound(res.begin(), res.end(), L)));
    }
    return 0;
}
```
[1036D - Vasya and Arrays](../problems/D._Vasya_and_Arrays.md "Educational Codeforces Round 50 (Rated for Div. 2)")

 **Tutorial**
### [1036D - Vasya and Arrays](../problems/D._Vasya_and_Arrays.md "Educational Codeforces Round 50 (Rated for Div. 2)")

Let's prove that next greedy solution works: each step we will find prefixes of minimal length of arrays $A$ и $B$ such that its sums are equal and we will cut them forming next block. If we will get valid partition in result so it is an optimal solution, otherwise there is no solution. Since length of prefix proportional to its sum, so prefixes are minimal since its sums are minimal.

Let's prove this algorithm: let optimal solution have alternative partition. Since our solution cuts minimal possible prefixes, so (at some step) optimal solution cuts prefix with greater sum (and greater length). But this prefixes in optimal solutions contain smaller prefixes, found by greedy solution, so it can be divided on two parts — contradiction.

So we can keep prefixes and increase one which have smaller sum.

Result complexity is $O(n)$.

 **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 300 * 1000 + 9;

int n, m;
int a[N], b[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", a + i);
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) scanf("%d", b + i);
    
    long long sum = 0;
    for(int i = 0; i < n; ++i) sum += a[i];
    for(int i = 0; i < m; ++i) sum -= b[i];
    if(sum != 0){
        puts("-1");
        return 0;
    }
    
    int posa = 0, posb = 0;
    int res = 0;
    while(posa < n){
        ++res;
        long long suma = a[posa++], sumb = b[posb++];
                
        while(suma != sumb){
            if(suma < sumb) suma += a[posa++];
            else sumb += b[posb++];
        }
    }
    
    printf("%dn", res);
    return 0;
}
```
[1036E - Covered Points](../problems/E._Covered_Points.md "Educational Codeforces Round 50 (Rated for Div. 2)")

 **Tutorial**
### [1036E - Covered Points](../problems/E._Covered_Points.md "Educational Codeforces Round 50 (Rated for Div. 2)")

I won't tell all the small geometric details, just cover some major points.

The problem asks you the following thing. Sum up the total number of points covered by each segment and for each unique point subtract the number of segments covering it minus one. Let's reformulate it. For each segment add the number of points covered by it and subtract the number of points covered by it and by some already processed segment.

The first part is easy. Segment covers exactly $GCD(|x1 - x2|, |y1 - y2|) + 1$ points with integer coordinates. The proof left to the reader as an exercise.

The second part can be done in the following manner. Intersect the segment $i$ with all segments $j < i$, insert all the points of intersection into set and take its size. You can consider only integer points of intersection and use no floating-point numbers in your program.

Overall complexity: $O(n^2 \log n)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 1000 + 7;

struct seg{
    int x1, y1, x2, y2;
    seg(){};
};

struct line{
    long long A, B, C;
    line(){};
    line(seg a){
        A = a.y1 - a.y2;
        B = a.x2 - a.x1;
        C = -A * a.x1 - B * a.y1;
    };
};

int n;
seg a[N];

int get(seg a){
    int dx = a.x1 - a.x2;
    int dy = a.y1 - a.y2;
    return __gcd(abs(dx), abs(dy)) + 1;
}

long long det(long long a, long long b, long long c, long long d){
    return a * d - b * c;
}

bool in(int x, int l, int r){
    if (l > r) swap(l, r);
    return (l <= x && x <= r);
}

bool inter(seg a, seg b, int& x, int& y){
    line l1(a), l2(b);
    long long dx = det(l1.C, l1.B, l2.C, l2.B);
    long long dy = det(l1.A, l1.C, l2.A, l2.C);
    long long d = det(l1.A, l1.B, l2.A, l2.B);
    if (d == 0)
        return false;
    if (dx % d != 0 || dy % d != 0)
        return false;
    x = -dx / d;
    y = -dy / d;
    if (!in(x, a.x1, a.x2) || !in(y, a.y1, a.y2))
        return false;
    if (!in(x, b.x1, b.x2) || !in(y, b.y1, b.y2))
        return false;
    return true;
}

int main() {
    scanf("%d", &n);
    forn(i, n)
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    
    int ans = 0;
    int x, y;
    forn(i, n){
        ans += get(a[i]);
        set<pair<int, int>> pts;
        forn(j, i)
            if (inter(a[i], a[j], x, y))
                pts.insert({x, y});
        ans -= pts.size();
    }
    
    printf("%dn", ans);
    return 0;
}
```
[1036F - Relatively Prime Powers](../problems/F._Relatively_Prime_Powers.md "Educational Codeforces Round 50 (Rated for Div. 2)")

 **Tutorial**
### [1036F - Relatively Prime Powers](../problems/F._Relatively_Prime_Powers.md "Educational Codeforces Round 50 (Rated for Div. 2)")

Whoops, it seems, this problem can be done in a similar manner as in problem $C$.

Firstly, is some number $x$ has $GCD$ of the prime powers not equal to $1$, then you can take root $GCD$'th power from it. That is the same as dividing all powers by $GCD$.

Now it turned out, there are really a small amount of these numbers up to $10^{18}$ (if you take the squares out).

Actually, our solution wasn't that. Let's count the answer using inclusion-exclusion principle. For this Mobius function can be used. The answer is:

$\sum \limits_{i = 1}^{\infty} (\lfloor n^{\frac 1 i} \rfloor - 1) \cdot \mu_i$.

The power part is the amount of numbers, which raised to the $i$-th power becomes less ot equal to $n$. This turns zero for like $60$ iterations on $i$ for any $n$ up to $10^{18}$. However, calculating each log as it is will lead to a $O(T \cdot \log^2 n)$ solution, which might be too slow.

Let's process the queries in the decreasing order of $n$. $\sqrt n$ will be calculated naively each time (in $O(1)$ (or however complexity has the built-in function, $O(\log \log n)$ maybe) or $O(\log n)$). The rest powers will be initialized with their upper limits in the start (like $10^6$ for $3$, $10^3$ for $6$ and so on). Now proceeding to the next number will only decrease the current maximum number for each power. Subtract one until you reach the needed number and check in $\log n$. 

Overall complexity: $O(T \cdot (\log n + \log T))$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int K = 100;
const int N = 100 * 1000 + 13;
const long long INF64 = 3e18;

int mu[K];

void precalc(){
    static bool prime[K];
    static int lst[K];
    
    memset(prime, false, sizeof(prime));
    forn(i, K) lst[i] = i;
    
    for (int i = 2; i < K; ++i){
        if (lst[i] == i) mu[i] = 1;
        for (int j = 2 * i; j < K; j += i){
            lst[j] = min(lst[j], lst[i]);
            if (lst[j] == lst[i])
                mu[j] = 0;
            else
                mu[j] = -mu[i];
        }
    }
}

int mx[K];

long long binpow(long long a, int b){
    long long res = 1;
    while (b){
        if (b & 1){
            if (res < INF64 / a) res *= a;
            else return INF64;
        }
        if (b > 1){
            if (a < INF64 / a) a *= a;
            else return INF64;
        }
        b >>= 1;
    }
    return res;
}

long long calc(long long n){
    int pw = 63 - __builtin_clzll(n);
    for (int i = 3; i <= pw; ++i){
        if (mu[i] == 0) continue;
        while (binpow(mx[i], i) > n)
            --mx[i];
    }
    
    long long res = n - 1;
    for (int i = 2; i <= pw; ++i)
        res -= mu[i] * (mx[i] - 1);
    
    return res;
}

int get_sqrt(long long n){
    int l = 1, r = 1000000000;
    while (l < r - 1){
        int m = (l + r) / 2;
        if (m * 1ll * m <= n)
            l = m;
        else
            r = m;
    }
    return (r * 1ll * r <= n ? r : l);
}

long long ans[N];

int main() {
    precalc();
    int T;
    scanf("%d", &T);
    vector<pair<long long, int>> q;
    
    forn(i, T){
        long long n;
        scanf("%lld", &n);
        q.push_back({n, i});
    }
    
    sort(q.begin(), q.end(), greater<pair<long long, int>>());
    mx[3] = 1000000;
    mx[4] = 31622;
    mx[5] = 3981;
    for (int i = 6; i < K; ++i)
        mx[i] = 1000;
    
    forn(z, T){
        long long n = q[z].first;
        mx[2] = get_sqrt(n);
        ans[q[z].second] = calc(n);
    }
    
    forn(i, T)
        printf("%lldn", ans[i]);
    return 0;
}
```
[1036G - Sources and Sinks](../problems/G._Sources_and_Sinks.md "Educational Codeforces Round 50 (Rated for Div. 2)")

 **Tutorial**
### [1036G - Sources and Sinks](../problems/G._Sources_and_Sinks.md "Educational Codeforces Round 50 (Rated for Div. 2)")

Since the graph is acyclic, then for every vertex there exists a path to some sink, and to every vertex there exists a path from some source. So our problem can be reduced to the following: check that after running our algorithm, all vertices from the initial set of sources and sinks belong to the same strongly connected component. Let $C$ be the number of sources (or sinks) in the initial graph.

First of all, let's run DFS (or any other graph traversal) from every source to form a set of reachable sinks for every source. This part of solution has complexity of $O(C(n + m))$.

If $X$ is some set of sources of the original graph, let $f(X)$ be the set of sinks such that every sink from $f(X)$ is reachable from at least one source from $X$. It's easy to see that there exists some set $X$ such that $|X| \ne 0$, $|X| \ne C$ and $|X| \ge |f(X)|$, then the answer is NO — if we connected the sinks from $f(X)$ with the sources from $X$, then any sink not belonging to $f(X)$ would be unreachable from any sink belonging to $f(X)$. Checking every possible set $X$ can be done in $O(C^2 2^C)$ or in $O(C 2^C)$.

Let's prove that there is no such set $X$, then the answer is YES. Let $s$ be an arbitrary sink of the original graph. Also, if $S$ is some set of sinks, let $h(S)$ be the set of sources containing every source directly connected to some sink from $S$. We can use mathematical induction to prove that every source and every sink is reachable from $s$ in the resulting graph:

* Initially we state that $s$ is reachable from $s$ (quite obvious);
* If there is a set of sinks $S$ reachable from $s$, then either $|S| = C$ (and the whole graph is reachable from $s$), or the number of sinks reachable from $h(S)$ is at least $|S| + 1$, so some set of $|S| + 1$ sinks is reachable from $s$.

So in fact checking every possible subset of sources is enough.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1000043;

vector<int> g[N];
vector<int> gt[N];
vector<int> src;
vector<int> snk;
int reach[20];
int used[N];

void dfs(int x)
{
    if(used[x]) return;
    used[x] = 1;
    for(auto y : g[x]) dfs(y);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        g[x].push_back(y);
        gt[y].push_back(x);
    }
    for(int i = 0; i < n; i++)
    {
        if(g[i].empty())
            snk.push_back(i);
        if(gt[i].empty())
            src.push_back(i);
    }
    int cnt = src.size();
    for(int i = 0; i < cnt; i++)
    {
        memset(used, 0, sizeof used);
        dfs(src[i]);
        for(int j = 0; j < cnt; j++)
            if(used[snk[j]])
                reach[i] ^= (1 << j);
    }
    bool ok = true;
    for(int mask = 0; mask < (1 << cnt); mask++)
    {
        int res = 0;
        for(int j = 0; j < cnt; j++)
            if(mask & (1 << j))
                res |= reach[j];
        int cnt1 = __builtin_popcount(mask);
        int cnt2 = __builtin_popcount(res);
        if(cnt2 < cnt1 || (cnt2 == cnt1 && cnt1 != 0 && cnt1 != cnt))
            ok = false;
    }
    if(!ok)
        puts("NO");
    else
        puts("YES");
}
```
