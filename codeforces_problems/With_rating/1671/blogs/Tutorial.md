# Tutorial

[1671A - String Building](../problems/A._String_Building.md "Educational Codeforces Round 127 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1671A - String Building](../problems/A._String_Building.md "Educational Codeforces Round 127 (Rated for Div. 2)")

Every character in strings aa, aaa, bb and bbb has at least one character adjacent to it that is the same. So, if there is an isolated character in our string (a character that has no neighbors equal to it), we cannot build it.

It's easy to see that in the other case, we can build the string: we can split it into blocks of consecutive equal characters, and since there are no isolated characters, each block will have at least 2 characters, so it can be formed from strings of length 2 and/or 3 consisting of equal characters.

So, the problem is reduced to checking if each character has a neighbor equal to it.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    s = input()
    ans = True
    n = len(s)
    for j in range(n):
        if (j == 0 or s[j] != s[j - 1]) and (j == n - 1 or s[j] != s[j + 1]):
            ans = False
    print('YES' if ans else 'NO')

```
[1671B - Consecutive Points Segment](../problems/B._Consecutive_Points_Segment.md "Educational Codeforces Round 127 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1671B - Consecutive Points Segment](../problems/B._Consecutive_Points_Segment.md "Educational Codeforces Round 127 (Rated for Div. 2)")

We can see that the answer is YES if and only if there are no more than two gaps of length 1 between the given points. If there is no gap, the answer is obviously YES. If there is only one gap of length 1, we can just move the left (or the right) part of the set to this gap. When there are two gaps, we can move the part before the first gap to the right and the part after the second gap to the left. Of course, if there is a gap of length at least 3 (or multiple gaps with the total length 3), we can't move the points from the left and the right part to satisfy the middle gap.

Time complexity: O(n).

 **Solution (vovuh)**
```cpp
for i in range(int(input())):
    n = int(input())
    x = list(map(int, input().split()))
    print('YES' if x[-1] - x[0] - n + 1 <= 2 else 'NO')
```
[1671C - Dolce Vita](../problems/C._Dolce_Vita.md "Educational Codeforces Round 127 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh") and [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1671C - Dolce Vita](../problems/C._Dolce_Vita.md "Educational Codeforces Round 127 (Rated for Div. 2)")

Firstly, note that if we want to buy as many packs as possible, then it's optimal to buy the cheapest packs. In other words, if we sort all packs, we'll always buy a prefix of array a.

Next, note that each day we buy some number of packs i∈[1,n], so, instead of iterating through the days, we can iterate through the number of packs i and for each i calculate the number of days we'll buy exactly i packs. 

Since the prices increasing and at day k+1 the price is ai+k, then exists last day ki+1 such that as days 1,2,…,ki+1 we could buy i packs and at days ki+2,ki+3,… we can't. And we can find ki as maximum possible integer solution to inequation (a1+ki)+⋯+(ai+ki)≤x or ki=⌊x−(a1+⋯+ai)i⌋.

We can calculate all ki using prefix sums a1+⋯+ai in linear time. As a result, we buy 

* n packs in days (0,k1+1]; n⋅(k1+1) in total;
* n−1 packs in days (k1+1,k2+1]; (n−1)⋅(k2−k1) in total;
* n−2 packs in days (k2+1,k3+1]; (n−2)⋅(k3−k2) in total and so on.

The resulting complexity is O(nlogn) because of sort.

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, x) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.sorted()

        var sum = a.sumOf { it.toLong() }
        var prevDay = -1L
        var ans = 0L
        for (i in n - 1 downTo 0) {
            val curDay = if (x - sum >= 0) (x - sum) / (i + 1) else -1
            ans += (i + 1) * (curDay - prevDay)
            prevDay = curDay
            sum -= a[i]
        }
        println(ans)
    }
}
```
[1671D - Insert a Progression](../problems/D._Insert_a_Progression.md "Educational Codeforces Round 127 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh") and [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1671D - Insert a Progression](../problems/D._Insert_a_Progression.md "Educational Codeforces Round 127 (Rated for Div. 2)")

Observe the cost of inserting a single element. Notice that inserting any value between the minimum of the sequence and the maximum of the sequence is free.

Why is this true? The argument is similar to the algorithm of finding some x such that f(x)=0 for a continous function f if you know some x1 such that f(x1)<0 and x2 such that f(x2)>0.

As a more general idea, it's free to insert some value s into a segment [l;r] such that al≤s and s≤ar (WLOG assume al≤ar). Let's find the position that is free. If r−l=1, then you can insert s between al and ar, since it's free. Otherwise, you can choose an arbitrary position l<i<r. s will be either between ai and al or between ai and ar (or both of them). Descend into the one that holds to continue the search. Since the lenght decreases, at some point you will reach the segment of length 1.

How does that help? Well, you can insert 1 somewhere, then insert x somewhere. The rest of insertions will be free.

Now it's an algorithmic problem. First, consider all options to insert both 1 and x between the same pair of elements. Next, assume you insert 1 somewhere before x. Iterate from left to right, maintaning the lowest price to insert 1. Try to insert x at the current position and 1 into the cheapest position before it. Then update the lowest price for inserting 1. After you finish, reverse the sequence and solve the problem again — that will be the same as inserting x before 1.

Overall complexity: O(n) per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;


int main() {
    int t;
    scanf("%d", &t);
    forn(_, t){
        int n, x;
        scanf("%d%d", &n, &x);
        vector<int> a(n);
        forn(i, n) scanf("%d", &a[i]);
        long long ans = 1e18;
        long long cur = 0;
        forn(i, n - 1){
            cur += abs(a[i] - a[i + 1]);
        }
        forn(_, 2){
            long long mn = abs(a[0] - 1);
            ans = min(ans, cur + abs(a[0] - x) + (x - 1));
            forn(i, n - 1){
                ans = min(ans, cur + mn - abs(a[i] - a[i + 1]) + abs(a[i] - x) + abs(a[i + 1] - x));
                ans = min(ans, cur - abs(a[i] - a[i + 1]) + abs(a[i] - x) + abs(a[i + 1] - 1) + (x - 1));
                mn = min(mn, 0ll - abs(a[i] - a[i + 1]) + abs(a[i] - 1) + abs(a[i + 1] - 1));
            }
            ans = min(ans, cur + mn + abs(a.back() - x));
            reverse(a.begin(), a.end());
        }
        printf("%lldn", ans);
    }
    return 0;
}
```
[1671E - Preorder](../problems/E._Preorder.md "Educational Codeforces Round 127 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1671E - Preorder](../problems/E._Preorder.md "Educational Codeforces Round 127 (Rated for Div. 2)")

In terms of preorder strings, the operation "swap two children of some vertex" means "swap two substrings of equal length in some specific location". This operation can be inverted by applying it an additional time, so for every positive integer k, all of the strings of length 2k−1 are split into equivalence classes in such a way that two strings from the same class can be transformed into each other, and two strings from different classes cannot. For each vertex, the set of its possible preorder strings is one of these classes.

Let's calculate the answer for the problem recursively: let dpv be the number of preorder strings for the vertex v. For a leaf, the number of its preorder strings is 1. For a vertex x with children y and z, one of the two holds:

* if the equivalence class for vertex y is different from the equivalence class for vertex z, then we have to pick a string from the class of vertex y, pick a string from the class of vertex z, and choose the order in which we take them. So, dpx=dpy⋅dpz+dpz⋅dpy=2⋅dpy⋅dpz;
* if the equivalence class for y is the same as the equivalence class for z, then swapping y and z doesn't do anything, so we pick a string from the equivalence class of y, and then a string from the equivalence class of z. So, dpx=dpy⋅dpz=dp2y.

The only thing we don't know is how to determine if two vertices represent the same equivalence class. The model solution uses hashing for this, but there's a much simpler method: for each vertex v, let tv be the lexicographically smallest string that can be a preorder string of v. If a vertex x has children y and z, then tx=min(ty+sx+tz,tz+sx+ty), and we can calculate these strings recursively since the total length is O(n2n) — each of 2n−1 characters will be present in O(n) strings.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

mt19937 rnd(42);

const int MOD = 998244353;
const int K = 3;

int add(int x, int y, int mod = MOD)
{
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}   

int sub(int x, int y, int mod = MOD)
{
    return add(x, -y, mod);
}   

int mul(int x, int y, int mod = MOD)
{
    return (x * 1ll * y) % mod;
}

int binpow(int x, int y, int mod = MOD)
{
    int z = 1;
    while(y > 0)
    {
        if(y % 2 == 1) z = mul(z, x, mod);
        y /= 2;
        x = mul(x, x, mod);
    }   
    return z;
}

bool prime(int x)
{
    for(int i = 2; i * 1ll * i <= x; i++)
        if(x % i == 0)
            return false;
    return true;    
}   

int get_base()
{
    int x = rnd() % 10000 + 4444;
    while(!prime(x)) x++;
    return x;
}   

int get_modulo()
{
    int x = rnd() % int(1e9) + int(1e8);
    while(!prime(x)) x++;
    return x;
}   

typedef array<int, K> hs;

hs base, modulo;

void generate_hs()
{
    for(int i = 0; i < K; i++)
    {
        base[i] = get_base();
        modulo[i] = get_modulo();
    }
}   

hs operator+(const hs& a, const hs& b)
{
    hs c;
    for(int i = 0; i < K; i++)
    {
        c[i] = add(a[i], b[i], modulo[i]);    
    }
    return c;
}

hs operator-(const hs& a, const hs& b)
{
    hs c;
    for(int i = 0; i < K; i++)
    {
        c[i] = sub(a[i], b[i], modulo[i]);    
    }
    return c;
}

hs operator*(const hs& a, const hs& b)
{
    hs c;
    for(int i = 0; i < K; i++)
    {
        c[i] = mul(a[i], b[i], modulo[i]);    
    }
    return c;
}

hs operator^(const hs& a, const hs& b)
{
    hs c; 
    for(int i = 0; i < K; i++)
    {
        c[i] = binpow(a[i], b[i], modulo[i]);    
    }
    return c;
}

hs char_hash(char c)
{
    hs res;
    for(int i = 0; i < K; i++)
        res[i] = c - 'A' + 1;
    return res;
}

const int N = 18;
const int V = 1 << N;
string s;
char buf[V + 43];
int n;
int ans[V + 43];
hs vertex_hash[V + 43];

bool is_leaf(int x)
{
    return (x * 2 + 1) >= ((1 << n) - 1);
}

void rec(int x)
{
    vertex_hash[x] = char_hash(s[x]);
    ans[x] = 1;
    if(is_leaf(x)) 
    {
        return;
    }
    rec(x * 2 + 1);
    rec(x * 2 + 2);
    vertex_hash[x] = vertex_hash[x] + (base ^ vertex_hash[2 * x + 1]) + (base ^ vertex_hash[2 * x + 2]);
    ans[x] = mul(ans[2 * x + 1], ans[2 * x + 2]);
    if(vertex_hash[2 * x + 1] != vertex_hash[2 * x + 2])
        ans[x] = mul(ans[x], 2);
}
 
int main() 
{
    generate_hs();
    scanf("%d", &n);
    scanf("%s", buf);
    s = buf;
    rec(0);
    cout << ans[0] << endl;
}
```
[1671F - Permutation Counting](../problems/F._Permutation_Counting.md "Educational Codeforces Round 127 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1671F - Permutation Counting](../problems/F._Permutation_Counting.md "Educational Codeforces Round 127 (Rated for Div. 2)")

A lot of solutions which were written during the contest use Berlekamp-Messey or some other algorithms related to analyzing linear recurrences, but the model solution is based on other principles.

First of all, if the number of inversions is at most 11, it means that most elements of the permutation will stay at their own places, and those which don't stay at their places can't be too far away from them.

Let's denote a block [l,r] in a permutation as a segment of indices [l,r] such that:

* all elements less than l are to the left of the block;
* all elements greater than r are to the right of the block;
* all elements from [l,r] belong to the block.

Let's say that a block is non-trivial if it contains at least two elements.

Suppose we split a permutation into the maximum number of blocks. Then, for each block, we can see that:

* if its length is b, it has at least b−1 inversions (to prove it, you can use the fact that the number of inversions is equal to the number of swaps of adjacent elements required to sort the permutation; and if we cannot split the block into other blocks, it means that we have to swap each pair of adjacent elements in it at least once to sort it)
* if the block is non-trivial, it has at least one i such that pi>pi+1.

From these two facts, we can see that:

* there will be at most 11 non-trivial blocks;
* there will be at most 22 elements in total belonging to non-trivial blocks;
* the maximum possible length of a block is 12.

The main idea of the solution is to calculate the following dynamic programming: dpi,j,a,b is the number of ways to split j elements into i non-trivial blocks such that there are exactly b inversions in them and exactly a pairs pi>pi+1. Then, to get the answer for the test case "n k x", we can iterate on the number of non-trivial blocks and the number of elements in them, and choose the elements belonging to that blocks with a binomial coefficient.

The only thing that's left is how to calculate this dynamic programming efficiently. There are a few ways to do it, but the model solution uses a table cnta,b,c — the number of different non-trivial blocks of length a with b elements pi>pi+1 and c inversions — to handle transitions. This table is not very big, so you can run an exhaustive search for 2-3 minutes to calculate it and then just paste its results into the source code of your program. Note that you have to make sure that you consider only the blocks which cannot be split any further.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

const int K = 13;
const int MOD = 998244353;

int n, k, x;

int cnt[K][K][K];
int dp[K][2 * K][K][K];

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}   

int sub(int x, int y)
{
    return add(x, -y);
}   

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
    int z = 1;
    while(y > 0)
    {
        if(y % 2 == 1) z = mul(z, x);
        y /= 2;
        x = mul(x, x);
    }   
    return z;
}

void precalc()
{
    cnt[2][1][1] = 1;
    cnt[3][1][2] = 2;
    cnt[3][2][3] = 1;
    cnt[4][1][3] = 3;
    cnt[4][1][4] = 1;
    cnt[4][2][3] = 1;
    cnt[4][2][4] = 4;
    cnt[4][2][5] = 3;
    cnt[4][3][6] = 1;
    cnt[5][1][4] = 4;
    cnt[5][1][5] = 2;
    cnt[5][1][6] = 2;
    cnt[5][2][4] = 4;
    cnt[5][2][5] = 12;
    cnt[5][2][6] = 12;
    cnt[5][2][7] = 9;
    cnt[5][2][8] = 3;
    cnt[5][3][5] = 2;
    cnt[5][3][6] = 4;
    cnt[5][3][7] = 6;
    cnt[5][3][8] = 6;
    cnt[5][3][9] = 4;
    cnt[5][4][10] = 1;
    cnt[6][1][5] = 5;
    cnt[6][1][6] = 3;
    cnt[6][1][7] = 4;
    cnt[6][1][8] = 3;
    cnt[6][1][9] = 1;
    cnt[6][2][5] = 10;
    cnt[6][2][6] = 28;
    cnt[6][2][7] = 35;
    cnt[6][2][8] = 35;
    cnt[6][2][9] = 30;
    cnt[6][2][10] = 17;
    cnt[6][2][11] = 8;
    cnt[6][3][5] = 1;
    cnt[6][3][6] = 13;
    cnt[6][3][7] = 29;
    cnt[6][3][8] = 41;
    cnt[6][3][9] = 44;
    cnt[6][3][10] = 45;
    cnt[6][3][11] = 30;
    cnt[6][4][7] = 1;
    cnt[6][4][8] = 4;
    cnt[6][4][9] = 7;
    cnt[6][4][10] = 7;
    cnt[6][4][11] = 11;
    cnt[7][1][6] = 6;
    cnt[7][1][7] = 4;
    cnt[7][1][8] = 6;
    cnt[7][1][9] = 6;
    cnt[7][1][10] = 6;
    cnt[7][1][11] = 2;
    cnt[7][2][6] = 20;
    cnt[7][2][7] = 55;
    cnt[7][2][8] = 80;
    cnt[7][2][9] = 95;
    cnt[7][2][10] = 101;
    cnt[7][2][11] = 94;
    cnt[7][3][6] = 6;
    cnt[7][3][7] = 50;
    cnt[7][3][8] = 118;
    cnt[7][3][9] = 186;
    cnt[7][3][10] = 230;
    cnt[7][3][11] = 260;
    cnt[7][4][7] = 3;
    cnt[7][4][8] = 18;
    cnt[7][4][9] = 48;
    cnt[7][4][10] = 85;
    cnt[7][4][11] = 113;
    cnt[7][5][10] = 2;
    cnt[7][5][11] = 4;
    cnt[8][1][7] = 7;
    cnt[8][1][8] = 5;
    cnt[8][1][9] = 8;
    cnt[8][1][10] = 9;
    cnt[8][1][11] = 11;
    cnt[8][2][7] = 35;
    cnt[8][2][8] = 96;
    cnt[8][2][9] = 155;
    cnt[8][2][10] = 207;
    cnt[8][2][11] = 250;
    cnt[8][3][7] = 21;
    cnt[8][3][8] = 145;
    cnt[8][3][9] = 358;
    cnt[8][3][10] = 616;
    cnt[8][3][11] = 859;
    cnt[8][4][7] = 1;
    cnt[8][4][8] = 26;
    cnt[8][4][9] = 124;
    cnt[8][4][10] = 313;
    cnt[8][4][11] = 567;
    cnt[8][5][9] = 3;
    cnt[8][5][10] = 16;
    cnt[8][5][11] = 53;
    cnt[9][1][8] = 8;
    cnt[9][1][9] = 6;
    cnt[9][1][10] = 10;
    cnt[9][1][11] = 12;
    cnt[9][2][8] = 56;
    cnt[9][2][9] = 154;
    cnt[9][2][10] = 268;
    cnt[9][2][11] = 389;
    cnt[9][3][8] = 56;
    cnt[9][3][9] = 350;
    cnt[9][3][10] = 898;
    cnt[9][3][11] = 1654;
    cnt[9][4][8] = 8;
    cnt[9][4][9] = 126;
    cnt[9][4][10] = 552;
    cnt[9][4][11] = 1404;
    cnt[9][5][9] = 4;
    cnt[9][5][10] = 48;
    cnt[9][5][11] = 204;
    cnt[9][6][11] = 1;
    cnt[10][1][9] = 9;
    cnt[10][1][10] = 7;
    cnt[10][1][11] = 12;
    cnt[10][2][9] = 84;
    cnt[10][2][10] = 232;
    cnt[10][2][11] = 427;
    cnt[10][3][9] = 126;
    cnt[10][3][10] = 742;
    cnt[10][3][11] = 1967;
    cnt[10][4][9] = 36;
    cnt[10][4][10] = 448;
    cnt[10][4][11] = 1887;
    cnt[10][5][9] = 1;
    cnt[10][5][10] = 43;
    cnt[10][5][11] = 357;
    cnt[10][6][11] = 6;
    cnt[11][1][10] = 10;
    cnt[11][1][11] = 8;
    cnt[11][2][10] = 120;
    cnt[11][2][11] = 333;
    cnt[11][3][10] = 252;
    cnt[11][3][11] = 1428;
    cnt[11][4][10] = 120;
    cnt[11][4][11] = 1302;
    cnt[11][5][10] = 10;
    cnt[11][5][11] = 252;
    cnt[11][6][11] = 5;
    cnt[12][1][11] = 11;
    cnt[12][2][11] = 165;
    cnt[12][3][11] = 462;
    cnt[12][4][11] = 330;
    cnt[12][5][11] = 55;
    cnt[12][6][11] = 1;    
}

int inv[K];

int C(int n, int k)
{
    if(n < 0 || n < k || k < 0) return 0;
    int res = 1;
    for(int i = n; i > n - k; i--)
        res = mul(res, i);
    for(int i = 1; i <= k; i++)
        res = mul(res, inv[i]);
    return res;
}

void prepare()
{
    for(int i = 1; i < K; i++)
        inv[i] = binpow(i, MOD - 2);
    precalc();
    dp[0][0][0][0] = 1;
    for(int i = 0; i < K; i++)
        for(int j = 0; j < 2 * K; j++)
            for(int a = 0; a < K - 2; a++)
                for(int b = 0; b < K - 2; b++)
                {
                    if(dp[i][j][a][b] == 0) continue;
                    for(int add_cnt = 2; add_cnt < K; add_cnt++)
                        for(int add_desc = 1; add_desc <= K - 2; add_desc++)
                            for(int add_inv = 1; add_inv <= K - 2; add_inv++)
                            {
                                if(j + add_cnt >= 2 * K || a + add_desc > K - 2 || b + add_inv > K - 2) continue;
                                int& nw = dp[i + 1][j + add_cnt][a + add_desc][b + add_inv];
                                nw = add(nw, mul(dp[i][j][a][b], cnt[add_cnt][add_desc][add_inv]));    
                            }
                }       
}

void solve() 
{
    scanf("%d %d %d", &n, &k, &x);
    if(k == 0 && x == 0)
    {
        puts("1");
        return;
    }
    int ans = 0;
    for(int i = 1; i < K; i++)
        for(int j = 1; j < 2 * K; j++)
            if(dp[i][j][x][k] != 0)
            {
                ans = add(ans, mul(dp[i][j][x][k], C(n - j + i, i)));        
            }
    printf("%dn", ans);
}

int main()
{
    prepare();
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
        solve();
}
```
