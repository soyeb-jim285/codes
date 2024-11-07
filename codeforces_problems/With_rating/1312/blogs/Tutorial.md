# Tutorial

[1312A - Two Regular Polygons](../problems/A._Two_Regular_Polygons.md "Educational Codeforces Round 83 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1312A - Two Regular Polygons](../problems/A._Two_Regular_Polygons.md "Educational Codeforces Round 83 (Rated for Div. 2)")

The answer is "YES" if and only if $n$ is divisible by $m$ because if you number all vertices of the initial polygon from $0$ to $n-1$ clockwise then you need to take every vertex divisible by $\frac{n}{m}$ (and this number obviously should be integer) and there is no other way to construct the other polygon.

 **Solution (vovuh)**
```cpp
for i in range(int(input())):
    n, m = map(int, input().split())
    print('YES' if n % m == 0 else 'NO')
```
[1312B - Bogosort](../problems/B._Bogosort.md "Educational Codeforces Round 83 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1312B - Bogosort](../problems/B._Bogosort.md "Educational Codeforces Round 83 (Rated for Div. 2)")

Let's sort array $a$ in non-ascending order ($a_1 \ge a_2 \ge \dots \ge a_n$). 

In this case for each pair of indexes $i < j$ the condition $j - a_j \ne i - a_i$ holds.

 **Solution (Roms)**
```cpp
for t in range(int(input())):
    n = input()
    print(*sorted(map(int, input().split()))[::-1])
```
[1312C - Adding Powers](../problems/C._Adding_Powers.md "Educational Codeforces Round 83 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1312C - Adding Powers](../problems/C._Adding_Powers.md "Educational Codeforces Round 83 (Rated for Div. 2)")

This is the solution that doesn't involve masks. Let's reverse the process and try to get all zeroes from the array $a$: since all $a_i \le 10^{16}$ we can start from maximum $k^s \le 10^{16}$.

The key idea: since $k^s > \sum_{x=0}^{s-1}{k^x}$ then there should be no more than one position $pos$ such that $a_{pos} \ge k^s$ and we should decrease it by $k^s$. Now we can decrease $s$ by $1$ and repeat the same process.

If at any step there are at least two $a_{pos} \ge k^s$ or as result, we won't get array filled with $0$ then there is no way to build the array $a$.

 **Solution 1 (adedalic)**
```cpp
fun main() {
    val T = readLine()!!.toInt()
    testCases@for (tc in 1..T) {
        val (_, k) = readLine()!!.split(' ').map { it.toLong() }
        val a = readLine()!!.split(' ').map { it.toLong() }.toLongArray()

        var maxPower = 1L
        while (maxPower < 1e16.toLong())
            maxPower *= k

        while (maxPower > 0) {
            val positions = a.withIndex().filter { it.value >= maxPower }.map { it.index }
            if (positions.isNotEmpty()) {
                if (positions.size > 1) {
                    println("NO")
                    continue@testCases
                }
                a[positions[0]] -= maxPower
            }
            maxPower /= k
        }
        if (a.max()!! > 0L) {
            println("NO")
            continue@testCases
        }
        println("YES")
    }
}
```
 **Solution 2 (adedalic)**
```cpp
fun getMask(a: Long, k: Long): Long? {
    var (tmp, res) = listOf(a, 0L)
    var cnt = 0
    while (tmp > 0) {
        if (tmp % k > 1)
            return null
        res = res or ((tmp % k) shl cnt)
        tmp /= k
        cnt++
    }
    return res
}

fun main() {
    val T = readLine()!!.toInt()
    for (tc in 1..T) {
        val (n, k) = readLine()!!.split(' ').map { it.toLong() }
        val a = readLine()!!.split(' ').map { getMask(it.toLong(), k) }
        val b = a.filterNotNull()
        if (b.size < n) {
            println("NO")
            continue
        } else {
            val res = b.reduce { acc, l -> if (acc < 0 || (acc and l) > 0) -1 else acc or l }
            println(if (res < 0) "NO" else "YES")
        }
    }
}
```
[1312D - Count the Arrays](../problems/D._Count_the_Arrays.md "Educational Codeforces Round 83 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1312D - Count the Arrays](../problems/D._Count_the_Arrays.md "Educational Codeforces Round 83 (Rated for Div. 2)")

First of all, there will be exactly $n - 1$ distinct elements in our array. Let's choose them, there are ${m}\choose{n-1}$ ways to do that.

After that, there should be exactly one element that appears twice. There are $n - 1$ elements to choose from, but are all of them eligible? If we duplicate the maximum element, there will be no way to meet the fourth condition. So we should multiply the current answer by $n - 2$, not $n - 1$.

And finally, some elements will appear earlier than the maximum in our array, and some — later. The duplicated element will appear on both sides, but all other elements should appear either to the left or to the right, so there are $2^{n - 3}$ ways to choose their positions.

Thus the answer is ${{m}\choose{n - 1}} (n - 2)2^{n - 3}$. Note that you have to precompute all factorials and use their inverse elements to calculate ${m}\choose{n-1}$.

Note that there is a tricky case when $n = 2$: some binpow implementations go into infinite loop trying to compute $2^{-1}$, so you may have to handle it specifically.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 200043;
const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

int fact[N];

void precalc()
{
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
}

int C(int n, int k)
{
    return divide(fact[n], mul(fact[k], fact[n - k]));
}

int main() 
{
    precalc();
    int n, m;
    cin >> n >> m;
    int ans = 0;
    if(n > 2)
        ans = mul(C(m, n - 1), mul(n - 2, binpow(2, n - 3)));
    cout << ans << endl;
}
```
[1312E - Array Shrinking](../problems/E._Array_Shrinking.md "Educational Codeforces Round 83 (Rated for Div. 2)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1312E - Array Shrinking](../problems/E._Array_Shrinking.md "Educational Codeforces Round 83 (Rated for Div. 2)")

Let's look at the answer: by construction, each element in the final answer was the result of replace series of elements on the corresponding segment. So all we need to find is the minimal (by size) partition of the array $a$ on segments where each segment can be transformed in one element by series of replaces.

We can calculate it using standard prefix dynamic programming, or $dp2[len]$ is the size of such minimal partition of a prefix of length $len$. The transitions are standard: let's check all segments $[len, nxt)$ and if it can be replaced by one element let's relax $dp2[nxt]$.

Now we need to check for all segments of $a$ — can it be replaced by one element. Let's calculate another $dp[l][r]$ using the following fact: if there is a way to replace all segment as one element so the segment either has the length $1$ or it can be divided into two parts where the prefix can be replaced by one element, the suffix also can be replaced by one element and these elements are equal. It's exactly the transitions we need to check to calculate $dp[l][r]$.

The resulting complexity is $O(n^3)$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    out << "[";
    fore(i, 0, sz(v)) {
        if(i) out << ", ";
        out << v[i];
    }
    return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

const int N = 555;
int n, a[N];

inline bool read() {
    if(!(cin >> n))
        return false;
    fore(i, 0, n)
        cin >> a[i];
    return true;
}

int dp[N][N];

int calcDP(int l, int r) {
    assert(l < r);
    if(l + 1 == r)
        return dp[l][r] = a[l];
    if(dp[l][r] != 0)
        return dp[l][r];
    
    dp[l][r] = -1;
    fore(mid, l + 1, r) {
        int lf = calcDP(l, mid);
        int rg = calcDP(mid, r);
        if(lf > 0 && lf == rg)
            return dp[l][r] = lf + 1;
    }
    return dp[l][r];
}

int dp2[N];

inline void solve() {
    fore(i, 0, N)
        dp2[i] = INF;
    
    dp2[0] = 0;
    fore(i, 0, n) {
        fore(j, i + 1, n + 1) {
            if(calcDP(i, j) > 0)
                dp2[j] = min(dp2[j], dp2[i] + 1);
        }
    }
    cout << dp2[n] << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    
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
[1312F - Attack on Red Kingdom](../problems/F._Attack_on_Red_Kingdom.md "Educational Codeforces Round 83 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1312F - Attack on Red Kingdom](../problems/F._Attack_on_Red_Kingdom.md "Educational Codeforces Round 83 (Rated for Div. 2)")

This problem seems like a version of Nim with some forbidden moves, so let's try to apply Sprague-Grundy theory to it.

First of all, we may treat each castle as a separate game, compute its Grundy value, and then XOR them to determine who is the winner of the game. When analyzing the state of a castle, we have to know two things: the number of remaining soldiers in it and the type of the last attack performed on it. So, the state of the game can be treated as a pair.

We can compute Grundy values for each state in a straightforward way, but the constraints are too large to do it. Instead, we should try to search for a period: five consecutive rows (by row we mean a vector of Grundy values for the same number of remaining soldiers, but different types of last attacks) of Grundy values determine all of the values after them, so as soon as we get the same five rows of Grundy values that we already met, we can determine the period.

There are $15$ values stored in these five rows, so the period can be up to $4^{15}$ — but that's a really generous upper bound. Some intuition can help us to prove something like $10^5$ or $10^6$ as an upper bound, but it is better to check all cases with brute force and find out that the period is at most $36$.

After we've found the period of Grundy values, it's easy to get them in $O(1)$ for any castle. To count the number of winning moves for the first player, we can compute the XOR-sum of all castles, and for each castle check what happens if we make some type of attack on it: if the XOR-sum becomes $0$, then this move is winning.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 300043;
const int K = 5;

int x, y, z, n;
long long a[N];

typedef vector<vector<int> > state;
map<state, int> d;
int cnt;
int p;
vector<vector<int> > state_log;

int mex(const vector<int>& a)
{
    for(int i = 0; i < a.size(); i++)
    {
        bool f = false;
        for(auto x : a)
            if(x == i)
                f = true;
        if(!f)
            return i;
    }
    return a.size();
}

state go(state s)
{
    int f1 = mex({s[0][K - x], s[1][K - y], s[2][K - z]});
    int f2 = mex({s[0][K - x], s[2][K - z]});
    int f3 = mex({s[0][K - x], s[1][K - y]});
    state nw = s;
    nw[0].push_back(f1);
    nw[1].push_back(f2);
    nw[2].push_back(f3);
    for(int i = 0; i < 3; i++)
        nw[i].erase(nw[i].begin());
    return nw;
}

void precalc()
{
    d.clear();
    state cur(3, vector<int>(K, 0));
    cnt = 0;
    state_log.clear();
    while(!d.count(cur))
    {
        d[cur] = cnt;
        state_log.push_back({cur[0].back(), cur[1].back(), cur[2].back()});
        cur = go(cur);
        cnt++;
    }                   
    p = cnt - d[cur];
}

int get_grundy(long long x, int t)
{
    if(x < cnt)
        return state_log[x][t];
    else
    {
        int pp = cnt - p;
        x -= pp;
        return state_log[pp + (x % p)][t];
    }
}

void read()
{
    scanf("%d %d %d %d", &n, &x, &y, &z);
    for(int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
}                    

int check(int x, int y)
{
    return x == y ? 1 : 0;
}

void solve()
{
    precalc();
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans ^= get_grundy(a[i], 0);
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        ans ^= get_grundy(a[i], 0);
        res += check(ans, get_grundy(max(0ll, a[i] - x), 0));
        res += check(ans, get_grundy(max(0ll, a[i] - y), 1));
        res += check(ans, get_grundy(max(0ll, a[i] - z), 2));
        ans ^= get_grundy(a[i], 0);
    }
    printf("%dn", res);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        read();
        solve();
    }
}
```
[1312G - Autocompletion](../problems/G._Autocompletion.md "Educational Codeforces Round 83 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic") and [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1312G - Autocompletion](../problems/G._Autocompletion.md "Educational Codeforces Round 83 (Rated for Div. 2)")

First of all, the information given in the input is the structure of a trie built on $S$ and some other strings — so we can store this information in the same way as we store a trie.

Okay, now let's calculate the number of seconds required to type each string with dynamic programming: let $dp_i$ be the number of seconds required to arrive to the $i$-th vertex of the trie. For regular vertices, $dp_i = dp_{p_i} + 1$, where $p_i$ is the parent of vertex $i$; for vertices corresponding to strings from $S$, $dp$ values should be updated with the time required to autocomplete some of the parents to the current vertex.

To do these updates, let's calculate the answers for all strings in lexicographical order. We will run DFS on the trie and maintain a segment tree on the path from the root to the current vertex. In the segment tree, we will store the values of $dp_i + cost_i$, where $cost_i$ is the number of seconds required to autocomplete from $i$ to the current vertex. Obviously, if we are currently in a vertex representing a word from $S$, then we have to find the minimum in this segment tree — and that will be the cost to get to current vertex using autocompletion.

How to maintain $dp_i + cost_i$? Recall that we are running DFS on trie in lexicographical order. When we want to compute the answer for the first string, the value of $cost_i$ for all vertices is $1$, since our string will be the first in all autocompletion lists. And here's a trick to maintain these values for other strings: whenever we compute the answer for some string, add $1$ on the whole tree. For vertices that are ancestors of both current string and some next string, this $+1$ will stay and increase the cost to autocomplete the next string accordingly; but for vertices which are not on the path to some next string, the values of $dp_i + cost_i$ will be already deleted from the segment tree and replaced by new values — so this addition does not affect them.

Overall, this works in $O(n \log n)$, but it can be written in $O(n)$ with a vector instead of a segment tree (since all additions and minimum queries affect the whole structure).

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 1000043;

map<char, int> nxt[N];
bool term[N];
int n, k;
char buf[3];
int dp[N];
int dict[N];

int T[4 * N];
int f[4 * N];

void build(int v, int l, int r)
{
    T[v] = int(1e9);
    if(l != r - 1)
    {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
    }
}

int getVal(int v)
{
    return T[v] + f[v];
}

void push(int v, int l, int r)
{
    T[v] += f[v];
    if(l != r - 1)
    {
        f[v * 2 + 1] += f[v];
        f[v * 2 + 2] += f[v];
    }
    f[v] = 0;
}

void upd(int v, int l, int r)
{
    if(l != r - 1)
    {
        T[v] = min(getVal(v * 2 + 1), getVal(v * 2 + 2));
    }
}

int get(int v, int l, int r, int L, int R)
{
    if(L >= R)
        return int(1e9);
    if(l == L && r == R)
        return getVal(v);
    push(v, l, r);
    int m = (l + r) / 2;
    int ans = min(get(v * 2 + 1, l, m, L, min(m, R)), get(v * 2 + 2, m, r, max(L, m), R));
    upd(v, l, r);
    return ans;
}

void add(int v, int l, int r, int L, int R, int val)
{
    if(L >= R)
        return;
    if(l == L && r == R)
    {
        f[v] += val;
        return;
    }
    push(v, l, r);
    int m = (l + r) / 2;
    add(v * 2 + 1, l, m, L, min(m, R), val);
    add(v * 2 + 2, m, r, max(L, m), R, val);
    upd(v, l, r);
}

void setVal(int v, int l, int r, int pos, int val)
{
    if(l == r - 1)
    {
        f[v] = 0;
        T[v] = val;
        return;
    }
    push(v, l, r);
    int m = (l + r) / 2;
    if(pos < m)
        setVal(v * 2 + 1, l, m, pos, val);
    else
        setVal(v * 2 + 2, m, r, pos, val);
    upd(v, l, r);
}

void dfs(int v, int d, int last)
{
    dp[v] = last + 1;
    if(term[v])
        dp[v] = min(dp[v], get(0, 0, n + 1, 0, d));
    setVal(0, 0, n + 1, d, dp[v] + 1);
    if(term[v])
        add(0, 0, n + 1, 0, d + 1, 1);
    for(auto x : nxt[v])
        dfs(x.second, d + 1, dp[v]);
    setVal(0, 0, n + 1, d, int(1e9));
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int p;
        scanf("%d %s", &p, buf);
        char c = buf[0];
        nxt[p][c] = i + 1;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++)
    {
        scanf("%d", &dict[i]);
        term[dict[i]] = true;
    }

    build(0, 0, n + 1);
    dfs(0, 0, -1);
    for(int i = 0; i < k; i++)
        printf("%d ", dp[dict[i]]);
    puts("");
}
```
