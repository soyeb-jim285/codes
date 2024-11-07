# Tutorial

[1065A - Vasya and Chocolate](../problems/A._Vasya_and_Chocolate.md "Educational Codeforces Round 52 (Rated for Div. 2)")

 **Tutorial**
### [1065A - Vasya and Chocolate](../problems/A._Vasya_and_Chocolate.md "Educational Codeforces Round 52 (Rated for Div. 2)")

Number of chocolate bars Vasya can buy without offer is cnt=⌊sc⌋.

Number of "bundles" with a bars x=⌊cnta⌋.

Then number of additional bars add=x⋅b.

In result, total number of bars is add+cnt.

 **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, a, b, c;
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> s >> a >> b >> c;
        
        s /= c;
        int x = s / a;
        s %= a;
        long long res = x * 1LL * (a + b);
        res += s;
        
        cout << res << endl;
    }
    return 0;
}
```
[1065B - Vasya and Isolated Vertices](../problems/B._Vasya_and_Isolated_Vertices.md "Educational Codeforces Round 52 (Rated for Div. 2)")

 **Tutorial**
### [1065B - Vasya and Isolated Vertices](../problems/B._Vasya_and_Isolated_Vertices.md "Educational Codeforces Round 52 (Rated for Div. 2)")

Vasya can decrease number of isolated vertices up to 2 using one edge and pairing them. So minimum number of isolated vertices is max(0,n−2m).

To calculate maximum number of isolated vertices let's keep number of non-isolated vertices knowing that each pair connected by edge (i.e. size of clique). Let we have size of clique cur and rem edges remained unassigned at current step. If rem=0 then answer is n−cur. Otherwise we need to increase clique with one vertex. Maximum number of edges we can add to connect this vertex is add=min (rem,cur). So, subtract it from rem and increase cur by one. Repeat this step while rem greater than zero. Answer is n−cur.

One corner case is next: if cur=1, then answer is n, not n−cur.

 **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;
    long long cur = 1;
    long long rem = m;
    while(rem > 0){
        long long d = min(cur, rem);
        rem -= d;
        ++cur;
    }
    assert(rem == 0);
    
    long long res = n;
    if(cur > 1) res = n - cur;
    
    cout << max(0ll, n - m * 2) << ' ' << res << endl;
    return 0;
}
```
[1065C - Make It Equal](../problems/C._Make_It_Equal.md "Educational Codeforces Round 52 (Rated for Div. 2)")

 **Tutorial**
### [1065C - Make It Equal](../problems/C._Make_It_Equal.md "Educational Codeforces Round 52 (Rated for Div. 2)")

Let's iterate over height pos of slice in decreasing order. All we need to know is a number of towers with height more than pos (name it c) and sum of its heights sum.

Current slice on height pos is good if k≥sum−c⋅pos. Let's greedily decrease value pos while slice on pos is good keeping correct values c and sum. When we found minimal good slice we can perform it increasing answer by one and "changing tower heights" just by setting new value to sum equal to c⋅pos.

Finish algorithm when pos becomes equal to minimal height of towers and make final slice.

 **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 9;

int n, k, h;
int need = int(1e9);
int cnt[N];

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        h = max(h, x);
        need = min(need, x);
        ++cnt[x];
    }
    
    int pos = N - 1;
    int res = 0;
    long long sum = 0;
    int c = 0;
    while(true){
        long long x = sum - c * 1LL * (pos - 1);
        if(x > k){
            ++res;
            h = pos;
            sum = pos * 1LL * c;
        }   
    
        --pos;
        if(pos == need) break;
        c += cnt[pos];
        sum += cnt[pos] * 1LL * pos;
    }
    
    if(h != need) ++res;
    
    cout << res << endl;
}
```
[1065D - Three Pieces](../problems/D._Three_Pieces.md "Educational Codeforces Round 52 (Rated for Div. 2)")

 **Tutorial**
### [1065D - Three Pieces](../problems/D._Three_Pieces.md "Educational Codeforces Round 52 (Rated for Div. 2)")

There are a lot of different solutions for the problem. Most of them have the similar structure.

The first part is to find the shortest distance between the states (x1,y1,p1) and (x2,y2,p2), where x and y are the coordinates of the square and p is the current piece. This can be done with 0-1 bfs, Floyd or Dijkstra. Just represent the triple as a single integer by transforming it to (x⋅n⋅3+y⋅3+p) and do everything on that graph.

The second part is to write some dp to go from i-th square with piece p1 to (i+1)-th square with piece p2. The value of this dp[n][3] is a pair (moves, replacements). It is easy to see that you can always choose the minimum of two such pairs while updating.

Overall complexity may vary. We believe, O(n4) is achievable. However, the particular solution I coded works in O(n6).

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef pair<int, int> pt;

const int N = 12;
const int M = 305;
const int INF = 1e9;

int n;
int a[N][N];
pt pos[N * N];
pt dist[M][M];

pt operator +(const pt &a, const pt &b){
    return mp(a.x + b.x, a.y + b.y);
}

int dx[] = {-2, -1, 1, 2,  2,  1, -1, -2};
int dy[] = { 1,  2, 2, 1, -1, -2, -2, -1};

bool in(int x, int y){
    return (0 <= x && x < n && 0 <= y && y < n);
}

int get(int x, int y, int p){
    return x * n * 3 + y * 3 + p;
}

pt dp[N * N][3];

int main() {
    scanf("%d", &n);
    forn(i, n) forn(j, n){
        scanf("%d", &a[i][j]);
        --a[i][j];
        pos[a[i][j]] = mp(i, j);
    }
    
    forn(i, M) forn(j, M) dist[i][j] = mp(INF, INF);
    forn(i, M) dist[i][i] = mp(0, 0);
    
    forn(x, n) forn(y, n){
        forn(i, 8){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (in(nx, ny))
                dist[get(x, y, 0)][get(nx, ny, 0)] = mp(1, 0);
        }
        
        for (int i = -n + 1; i <= n - 1; ++i){
            int nx = x + i;
            int ny = y + i;
            if (in(nx, ny))
                dist[get(x, y, 1)][get(nx, ny, 1)] = mp(1, 0);
            ny = y - i;
            if (in(nx, ny))
                dist[get(x, y, 1)][get(nx, ny, 1)] = mp(1, 0);
        }
        
        forn(i, n){
            int nx = x;
            int ny = i;
            dist[get(x, y, 2)][get(nx, ny, 2)] = mp(1, 0);
            nx = i;
            ny = y;
            dist[get(x, y, 2)][get(nx, ny, 2)] = mp(1, 0);
        }
        
        forn(i, 3) forn(j, 3){
            if (i != j){
                dist[get(x, y, i)][get(x, y, j)] = mp(1, 1);
            }
        }
    }
    
    forn(k, M) forn(i, M) forn(j, M)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    forn(i, N * N) forn(j, 3) dp[i][j] = mp(INF, INF);
    dp[0][0] = dp[0][1] = dp[0][2] = mp(0, 0);
    forn(i, n * n - 1) forn(j, 3) forn(k, 3)
        dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + dist[get(pos[i].x, pos[i].y, j)][get(pos[i + 1].x, pos[i + 1].y, k)]);
    
    pt ans = mp(INF, INF);
    ans = min(ans, dp[n * n - 1][0]);
    ans = min(ans, dp[n * n - 1][1]);
    ans = min(ans, dp[n * n - 1][2]);
    
    printf("%d %dn", ans.x, ans.y);
    return 0;
}
```
[1065E - Side Transmutations](../problems/E._Side_Transmutations.md "Educational Codeforces Round 52 (Rated for Div. 2)")

 **Tutorial**
### [1065E - Side Transmutations](../problems/E._Side_Transmutations.md "Educational Codeforces Round 52 (Rated for Div. 2)")

Let's take a look at any operation. You can notice that each letter can only go from position i to n−i−1 (0-indexed). Then, doing some operation twice is the same as doing that operation zero times.

Now consider some set of operations l1,l2,…,lk, sorted in increasing order. Actually, they do the following altogether. Replace segment [lk−1..lk) with the reversed segment ((n−lk−1)..(n−lk−1−1)] and vice versa. Then replace segment [lk−3..lk−2) with the reversed segment ((n−lk−2−1)..(n−lk−3−1)] and vice versa. And continue until you reach the first pair. Segment [0..l1) might also be included in the answer when the parity is right.

Moreover, every subset of segments [0..l1),[l1,l2),…[lk−1,lk) is achievable. So for each segment you can either swap it or not. Let's translate it to math language.

Let cnti be the number of such pairs of strings x and y that x≤y. Why is there such an order? You want to consider only unique strings, thus, you need to pick exactly one of equal strings from each component. Let it be the smallest one.

Then for each segment of the set you have cntlen pairs to choose from, where len is the length of that segment.

And that part of the formula is:

cntb1⋅m∏i=1cntbi−bi−1.

However, the part covered by zero segments is left. There are ALn−2bm possible strings up there.

cnti is actually a number of all pairs of strings of length i plus the number of all pairs of equal strings of length i divided by 2. cnti=AL2i+ALi2.

Overall complexity: O(mlogn).

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;
const int MOD = 998244353;

int n, m, A;
int b[N];

int add(int a, int b){
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int mul(int a, int b){
    return (a * 1ll * b) % MOD;
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

int cnt(int x){
    int base = binpow(A, x);
    return mul(add(mul(base, base), base), (MOD + 1) / 2);
}

int main() {
    scanf("%d%d%d", &n, &m, &A);
    forn(i, m)
        scanf("%d", &b[i]);
    
    int ans = binpow(A, n - b[m - 1] * 2);
    ans = mul(ans, cnt(b[0]));
    forn(i, m - 1)
        ans = mul(ans, cnt(b[i + 1] - b[i]));
    
    printf("%dn", ans);
    return 0;
}
```
[1065F - Up and Down the Tree](../problems/F._Up_and_Down_the_Tree.md "Educational Codeforces Round 52 (Rated for Div. 2)")

 **Tutorial**
### [1065F - Up and Down the Tree](../problems/F._Up_and_Down_the_Tree.md "Educational Codeforces Round 52 (Rated for Div. 2)")

Let's calculate answer in two steps. At first, let's calculate for each vertex v drev(v) — what we can gain if we must return from subtree of v in the end. We need only pair of values: minimal possible depth we can acquire to move up from subtree of v and maximal number of different leaves we can visit. 

Note, that this two values are independent since we must return from v and if for some child to of v we can return from it, it's profitable to visit to and return. But if we can't return from to so we are prohibited to descent to to. So, drev(v).second (number of visited leaves) is just a sum of all drev(to).second if drev(to).first≤hv. Also note that we can always reorder all children in such way that last visited vertex to will have minimal drev(to).first. So drev(to).first (minimal possible depth) is a minimum over all drev(to).first.

At second, let's calculate d(v) — maximal number of different leaves we can visit if we don't need to return from subtree of v. It can be calculated quite easy using array drev(v). We just need to choose child to we will not return from, so from vertex to we will take value d(to) and from other childen (which we can return from) value drev(v).second.

Result complexity is O(n).

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}

template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    out << "[";
    fore(i, 0, v.size()) {
        if(i) out << ", ";
        out << v[i];
    }
    return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);

const int N = 1000 * 1000 + 555;

int n, k;
vector<int> g[N];

inline bool read() {
    if(!(cin >> n >> k))
        return false;
    fore(i, 1, n) {
        int p; assert(scanf("%d", &p) == 1);
        p--;
        
        g[p].push_back(i);
        g[i].push_back(p);
    }
    return true;
}

int h[N];
pt drev[N];

void calcRev(int v, int p) {
    drev[v] = pt(INF, 0);
    for(int to : g[v]) {
        if(to == p) continue;
        
        h[to] = h[v] + 1;
        calcRev(to, v);
        
        if(drev[to].x <= h[v]) {
            drev[v].x = min(drev[v].x, drev[to].x);
            drev[v].y += drev[to].y;
        }
    }
    
    if(p >= 0 && g[v].size() == 1)
        drev[v] = pt(h[v] - k, 1);
}

int d[N];

void calcAns(int v, int p) {
    d[v] = (p >= 0 && g[v].size() == 1);
    for(int to : g[v]) {
        if(to == p) continue;
        calcAns(to, v);
        
        int tmp = drev[v].y;
        if(drev[to].x <= h[v])
            tmp -= drev[to].y;
        
        d[v] = max(d[v], tmp + d[to]);
    }
}

inline void solve() {
    h[0] = 0;
    calcRev(0, -1);
    calcAns(0, -1);
    cout << d[0] << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
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
[1065G - Fibonacci Suffix](../problems/G._Fibonacci_Suffix.md "Educational Codeforces Round 52 (Rated for Div. 2)")

 **Tutorial**
### [1065G - Fibonacci Suffix](../problems/G._Fibonacci_Suffix.md "Educational Codeforces Round 52 (Rated for Div. 2)")

Suppose we added all the suffixes of F(n) into a trie. Then we can find k-th suffix by descending the trie, checking the sizes of subtrees to choose where to go on each iteration.

The model solution actually does that, but computes the sizes of subtrees without building the whole trie. Recall that if we insert all suffixes of a string into the trie, then the size of subtree of some vertex is equal to the number of occurences of the string denoted by this vertex in the original string.

Since in our problem the strings are recurrent, we may use prefix automaton to count the number of occurences. To calculate the number of occurences of string s in F(x), let's build prefix function for s, and an automaton Ap,c which tells the value of prefix function, if the previous value was p, and we appended c to the string (the same approach is used in KMP substring search algorithm). Then, let's build another automaton that will help us work with Fibonacci string: Fp,x — what will be the value of prefix function, if we append F(x) to the string? For x=0 and x=1, this automaton can be easily built using Ap,0 and Ap,1; and for x>1, we may build Fp,x using the automatons for x−2 and x−1. We also have to keep track of the number of occurences, that can be done with another automaton on fibonacci strings.

There is a corner case when we need to stop descending the trie; to handle it, we need to check whether some string is a suffix of F(n), but that can be easily made by checking if F0,n=|s|.

Each step in trie forces us to do up to three (depending on your implementation) queries like "count the number of occurences of some string in F(n)", so overall the solution works in O(nm2).

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long li;

const li INF64 = li(1e18);

li add(li x, li y)
{
    return min(x + y, INF64);
}

const int N = 243;

int A1[N][2];
li A2[N][N];
int A3[N][N];
int n, m;
li k;
int z;
int p[N];

void build(const string& s)
{
    z = (int)(s.size());
    p[0] = 0;
    for(int i = 1; i < z; i++)
    {
        int j = p[i - 1];
        while(j > 0 && s[j] != s[i])
            j = p[j - 1];
        if(s[j] == s[i])
            j++;
        p[i] = j;
    }
    for(int i = 0; i <= z; i++)
        for(int j = 0; j < 2; j++)
        {
            if(i < z && s[i] == char('0' + j))
                A1[i][j] = i + 1;
            else if(i == 0)
                A1[i][j] = 0;
            else
                A1[i][j] = A1[p[i - 1]][j];
        }
    for(int i = 0; i <= z; i++)
        for(int j = 0; j < 2; j++)
        {
            A3[i][j] = A1[i][j];
            A2[i][j] = (A3[i][j] == z ? 1 : 0);
        }
    for(int i = 2; i <= n; i++)
        for(int j = 0; j <= z; j++)
        {
            A3[j][i] = A3[A3[j][i - 2]][i - 1];
            A2[j][i] = add(A2[j][i - 2], A2[A3[j][i - 2]][i - 1]);
        }
}

int main()
{
    cin >> n >> k >> m;
    string cur = "";
    for(int i = 0; i < m; i++)
    {
        if(cur != "") build(cur);
        li x = 0;
        if(cur != "" && A3[0][n] == i)
            x = 1;
        if(k == 1 && x == 1)
            break;
        k -= x;
        build(cur + '0');
        li x1 = A2[0][n];
        if(k > x1)
        {
            cur += '1';
            k -= x1;
        }
        else
            cur += '0';
    }
    cout << cur << endl;
    return 0;
}
```
