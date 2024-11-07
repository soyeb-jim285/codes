# Tutorial

[1027A - Palindromic Twist](../problems/A._Palindromic_Twist.md "Educational Codeforces Round 49 (Rated for Div. 2)")

 **Tutorial**
### [1027A - Palindromic Twist](../problems/A._Palindromic_Twist.md "Educational Codeforces Round 49 (Rated for Div. 2)")

If some string can't be transformed to palindrom then it has some pair of positions (i,n−i+1) with different letters on them (as no such pair affects any other pair). Thus you need to check each pair for i from 1 to n2 and verify that the distance between the corresponding letters is either 0 or 2.

Overall complexity: O(T⋅n).

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;


int main() {
    int T;
    cin >> T;
    
    int n;
    string s;
    forn(_, T){
        cin >> n >> s;
        bool ok = true;
        forn(i, n){
            int k = abs(s[i] - s[n - i - 1]);
            if (k > 2 || k % 2 == 1){
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
```
[1027B - Numbers on the Chessboard](../problems/B._Numbers_on_the_Chessboard.md "Educational Codeforces Round 49 (Rated for Div. 2)")

 **Tutorial**
### [1027B - Numbers on the Chessboard](../problems/B._Numbers_on_the_Chessboard.md "Educational Codeforces Round 49 (Rated for Div. 2)")

Let's see the following fact: if we will decrease ⌈n22⌉ from all numbers written in cells with an odd sum of coordinates and write out the numbers obtained on the board from left to right from top to bottom, the sequence will looks like 1,1,2,2,…,⌈n22⌉,⌈n22⌉ for even n (for odd n there is only one number ⌈n22⌉ at the end of the sequence, but, in general, it does not matter).

Let's try to find out the answer for some query (x,y). Let cnt=(x−1)⋅n+y (1-indexed). There cnt is the position of our cell in order of the written sequence. The first approximation of the answer is ⌈cnt2⌉. But now we are remember that we decreased ⌈n22⌉ from all numbers written in cells with an odd sum of coordinates. So if x+y is even then the answer is ⌈cnt2⌉, otherwise the answer is ⌈cnt2⌉+⌈n22⌉. Note that you should be careful with integer overflow in C++, Java or similar languages. 64-bit datatype is quite enough.

Time complexity: O(q).

 **Solution (Vovuh)**
```cpp
import sys

lst = sys.stdin.readlines()
n, q = map(int, lst[0].split())

for i in range(q):
    x, y = map(int, lst[i + 1].split())
    cnt = (x - 1) * n + y
    ans = (cnt + 1) // 2
    if ((x + y) % 2 == 1): ans += (n * n + 1) // 2
    sys.stdout.write(str(ans) + 'n')
```
[1027C - Minimum Value Rectangle](../problems/C._Minimum_Value_Rectangle.md "Educational Codeforces Round 49 (Rated for Div. 2)")

 **Tutorial**
### [1027C - Minimum Value Rectangle](../problems/C._Minimum_Value_Rectangle.md "Educational Codeforces Round 49 (Rated for Div. 2)")

Let's work with the formula a bit:

P2s = 4(x+y)2xy = 4(2+xy+yx) = 8+4(xy+yx)

Let a=xy, then the formula becomes 8+4(a+1a). Considering x≥y, a=xy≥1, thus (a+1a) is strictly increasing and has its minimum at a=1.

So the solution will be to sort the list, extract the pairs of sticks of equal length and check only neighbouring pairs in sorted order for the answer.

Overall complexity: O(nlogn).

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;

using namespace std;

const int N = 1000 * 1000 + 13;

int n, m;
int a[N];
int b[N];

int main() {
    int T;
    scanf("%d", &T);
    forn(_, T){
        scanf("%d", &n);
        forn(i, n)
            scanf("%d", &a[i]);
        sort(a, a + n);
    
        m = 0;
        forn(i, n - 1){
            if (a[i] == a[i + 1]){
                b[m++] = a[i];
                ++i;
            }
        }
    
        int A = b[0], B = b[1];
        li P2 = (A + B) * li(A + B);
        li S = A * li(B);
    
        forn(i, m - 1){
            li p2 = (b[i] + b[i + 1]) * li(b[i] + b[i + 1]);
            li s = b[i] * li(b[i + 1]);
            if (s * P2 > S * p2){
                A = b[i];
                B = b[i + 1];
                S = s;
                P2 = p2;
            }
        }
    
        printf("%d %d %d %dn", A, A, B, B);
    }
}
```
[1027D - Mouse Hunt](../problems/D._Mouse_Hunt.md "Educational Codeforces Round 49 (Rated for Div. 2)")

 **Tutorial**
### [1027D - Mouse Hunt](../problems/D._Mouse_Hunt.md "Educational Codeforces Round 49 (Rated for Div. 2)")

Mouse jumps on a cycle at some point, no matter the starting vertex, thus it's always the most profitable to set traps on cycles. The structure of the graph implies that there are no intersecting cycles. Moreover, mouse will visit each vertex of the cycle, so it's enough to set exactly one trap on each cycle. The only thing left is to find the cheapest vertex of each cycle. This can be done by a simple dfs.

Overall complexity: O(n).

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define mp make_pair
#define pb push_back

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a) * (a))

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<li, li> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    out << "[";
    forn(i, sz(v)) {
        if(i) out << ", ";
        out << v[i];
    }
    return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n;
vector<int> a, c;

inline bool read() {
    if(!(cin >> n))
        return false;
    c.assign(n, 0);
    a.assign(n, 0);

    forn(i, n)
        assert(scanf("%d", &c[i]) == 1);
    forn(i, n) {
        assert(scanf("%d", &a[i]) == 1);
        a[i]--;
    }
    return true;
}

vector< vector<int> > cycles;

vector<char> used;
vector<int> path;

void dfs(int v) {
    path.push_back(v);
    used[v] = 1;

    int to = a[v];
    if(used[to] != 2) {
        if(used[to] == 1) {
            cycles.emplace_back();

            int id = sz(path) - 1;
            while(path[id] != to)
                cycles.back().push_back(path[id--]);
            cycles.back().push_back(to);
        } else
            dfs(to);
    }
    path.pop_back();
    used[v] = 2;
}

inline void solve() {
    used.assign(n, 0);

    forn(i, n) {
        if (!used[i])
            dfs(i);
    }

    li ans = 0;
    for(auto &cur : cycles) {
        int mn = c[cur[0]];
        for(int v : cur)
            mn = min(mn, c[v]);
        ans += mn;
    }
    cout << ans << endl;
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
[1027E - Inverse Coloring](../problems/E._Inverse_Coloring.md "Educational Codeforces Round 49 (Rated for Div. 2)")

 **Tutorial**
### [1027E - Inverse Coloring](../problems/E._Inverse_Coloring.md "Educational Codeforces Round 49 (Rated for Div. 2)")

You can notice that every coloring can be encoded by the two binary strings of length n. You firstly generate one string to put as a first row and then use the second string to mark if you put the first string as it is or inverting each color.

That way, you can also guess that the area of maximum rectangle of a single color you will get in you coloring is the product of maximum lengths of segments of a single color in both of the strings.

Let's consider the following dynamic programming solution:

dp[i][j][k] is the number of binary strings of length i, such the current last segment of a single color has length j and the maximum segment of a single color has length k.

The transitions are:

* dp[i+1][j+1][max(k,j+1)] += dp[i][j][k] — color the new tile the same as the previous one;
* dp[i+1][1][max(k,1)] += dp[i][j][k] — color the new tile the opposite from the previous one.

The starting state is dp[0][0][0]=1.

Let's sum the values of this dp to an array cnt[i] — the number of binary strings of length n such that the maximum segment of a single color in them has length i. You can also do another dp to calculate this not in O(n3) but in O(n2) using some partial sums in it.

Finally, you iterate over the first side of the resulting rectangle (the maximum length of segment of a single color in a first binary string) and multiply the number of ways to get it by the total number of ways to get the second side of the resulting rectangle, so that the area doesn't (k−1).

Overall complexity: O(n3) or O(n2).

 **Solution (PikMike) O(n^3)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 500 + 7;
const int MOD = 998244353;

int n, k;
int dp[2][N][N];
int cnt[N];
int pr[N];

void add(int &a, int b){
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int main() {
    scanf("%d%d", &n, &k);
    
    dp[0][0][0] = 1;
    forn(ii, n){
        int i = ii & 1;
        int ni = i ^ 1;
        memset(dp[ni], 0, sizeof(dp[ni]));
        forn(j, n + 1){
            forn(k, n + 1){
                add(dp[ni][j + 1][max(j + 1, k)], dp[i][j][k]);
                add(dp[ni][1][max(1, k)], dp[i][j][k]);
            }
        }
    }
    
    forn(i, n + 1)
        forn(j, n + 1)
            add(cnt[i], dp[n & 1][j][i]);
    
    forn(i, n + 1){
        add(pr[i + 1], pr[i]);
        add(pr[i + 1], cnt[i]);
    }
    
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        add(ans, cnt[i] * (long long)(pr[min(n + 1, (k - 1) / i + 1)]) % MOD);
    
    ans = (ans * (long long)((MOD + 1) / 2)) % MOD;
    printf("%dn", ans);
    
    return 0;
}
```
 **Solution (BledDest) O(n^2)**
```cpp
def norm(x):
    return (x % 998244353 + 998244353) % 998244353

n, k = map(int, input().split())

dp1 = [0]
dp2 = [0]

for i in range(n):
    l = [1]
    cur = 0
    for j in range(n + 1):
        cur += l[j]
        if(j > i):
            cur -= l[j - i - 1]
        cur = norm(cur)
        l.append(cur)
    dp1.append(l[n])
    dp2.append(norm(dp1[i + 1] - dp1[i]))

ans = 0
for i in range(n + 1):
    for j in range(n + 1):
        if(i * j < k):
            ans = norm(ans + dp2[i] * dp2[j])

ans = norm(ans * 2)

print(ans)
```
[1027F - Session in BSU](../problems/F._Session_in_BSU.md "Educational Codeforces Round 49 (Rated for Div. 2)")

 **Tutorial**
### [1027F - Session in BSU](../problems/F._Session_in_BSU.md "Educational Codeforces Round 49 (Rated for Div. 2)")

This problem has many approaches (as Hall's theorem, Kuhn algorithm (???) and so on), I will explain one (or two) of them.

Let's find the answer using binary search. It is obvious that if we can pass all the exams in k days we can also pass them in k+1 days.

For the fixed last day k let's do the following thing: firstly, if there exists some exam with the day of the first opportunity to pass it greater than k, then the answer for the day k is false.

Next, while there exist exams having only one possibility to pass them (because of the upper bound of the maximum possible day or constraints imposed by the other exams), we choose this day for this exam and continue (after choosing such day there can appear some new exams with the same property). Now there are no exams having only one day to pass them.

Let's take a look on the graph where vertices represent days and edges represent exams (the edge between some vertices u and v (u<v) exists iff there is an exam with the first day to pass it equal to u and the second day to pass it equal to v). Let's remove all the exams for which we identified the answer. Now let's take a look on the connected components of this graph and analyze the problem which we have now. Our problem is to choose exactly one vertex incident to each edge of the connected component such that no vertex is chosen twice (and we have to do this for all the connected components we have).

Let cntv be the number of vertices in the current connected component and cnte be the number of edges in the current connected component. The answer for the connected component is true iff cnte≤cntv, for obvious reasons. There is very easy constructive method to see how we can do this. If cnte<cntv then the current connected component is a tree. Let's remove some leaf of this tree and set it as the chosen vertex for the edge incident to this leaf (and remove this edge too). If cnte=cntv then let's remove all leaves as in the algorithm for the tree. For the remaining cycle let's choose any edge and any vertex incident to it, set this vertex as the chosen to this edge and remove them. Now we have a chain. Chain is a tree, so let's apply the algorithm for the tree to this chain.

So, if for some connected component c holds cntec>cntvc then the answer for the day k is false. Otherwise the answer is true.

Overall complexity O(nlogn) because of numbers compressing or using logarithmic data structures to maintain the graph.

Also there is another solution (which can be too slow, I don't know why it works). It is well-known fact that if we will apply Kuhn algorithm to the some bipartite graph in order of increasing indices of vertices of the left part, then the last vertex in the left part of this graph which is in the matching will be minimum possible. Oh, that's what we need! Let the left part of this graph consist of days and the right part consist of exams. The edge between some vertices u from the left part and v from the right part exists iff u is one of two days to pass the exam v. Let's apply Kuhn algorithm to this graph, considering days in increasing order. The first day when matching becomes n (all exams are in the matching) will be the answer. I don't know its complexity, really. Maybe it works too fast because of the special properties of the graph... If someone can explain in which time it works I will very happy!

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int N = 2 * 1000 * 1000 + 11;
const int INF = 1e9 + 1;

int n;
int a[N][2];
vector<int> s;
bool used[N];
bool exam[N];
vector<pair<int, int>> g[N];

bool deny(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (auto it : g[v]) {
        int to = it.first;
        int ex = it.second;
        if (exam[ex]) continue;
        if (used[to])
            return false;
        exam[ex] = true;
        if (!deny(to))
            return false;
    }
    return true;
}

int cntv, cnte;

void dfs(int v) {
    ++cntv;
    used[v] = true;
    for (auto it : g[v]) {
        int to = it.first;
        int ex = it.second;
        if (exam[ex]) continue;
        exam[ex] = true;
        ++cnte;
        if (!used[to])
            dfs(to);
    }
}

bool check(int day) {
    memset(used, false, sizeof(used));
    memset(exam, false, sizeof(exam));
    forn(i, s.size()) if (i > day) {
        if (!deny(i)) {
            return false;
        }
    }
    
    forn(i, s.size()) {
        if (!used[i]) {
            cntv = 0;
            cnte = 0;
            dfs(i);
            if (cntv < cnte)
                return false;
        }
    }
    
    return true;
}

int main() {
    scanf("%d", &n);
    forn(i, n) forn(j, 2) {
        scanf("%d", &a[i][j]);
        s.push_back(a[i][j]);
    }
    
    sort(s.begin(), s.end());
    s.resize(unique(s.begin(), s.end()) - s.begin());
    
    forn(i, n) {
        forn(j, 2) {
            a[i][j] = lower_bound(s.begin(), s.end(), a[i][j]) - s.begin();
        }
        g[a[i][0]].push_back(make_pair(a[i][1], i));
        g[a[i][1]].push_back(make_pair(a[i][0], i));
    }
        
    int l = 0, r = int(s.size()) - 1;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    for (int i = l; i <= r; ++i) {
        if (check(i)) {
            printf("%dn", s[i]);
            return 0;
        }
    }
    puts("-1");
}
```
 **Solution (Vovuh) Kuhn's Algorithm**
```cpp
#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(time(NULL));

const int N = 2 * 1000 * 1000 + 11;
const int INF = 1e9;

int n;
int a[N][2];

vector<int> nums;
int m;

vector<int> g[N];
int mt[N];
int used[N];
int T = 1;

bool try_kuhn(int v) {
    if (used[v] == T)
        return false;
    used[v] = T;
    
    for (auto to : g[v]) {
        if (mt[to] == -1) {
            mt[to] = v;
            return true;
        }
    }
    
    for (auto to : g[v]) {
        if (try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    
    return false;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%d", &a[i][j]);
            nums.push_back(a[i][j]);
        }
    }
    
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    m = nums.size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            a[i][j] = lower_bound(nums.begin(), nums.end(), a[i][j]) - nums.begin();
        }
    }
    
    for (int i = 0; i < n; ++i) {
        g[a[i][0]].push_back(i);
        g[a[i][1]].push_back(i);
    }

    memset(mt, -1, sizeof(mt)); 
    int match = 0;
    for (int i = 0; i < m; ++i) {
        if (try_kuhn(i)) {
            ++T;
            ++match;
            if (match == n) {
                printf("%dn", nums[i]);
                return 0;
            }
        }
    }
    
    puts("-1");
    
    return 0;
}
```
[1027G - X-mouse in the Campus](../problems/G._X-mouse_in_the_Campus.md "Educational Codeforces Round 49 (Rated for Div. 2)")

 **Tutorial**
### [1027G - X-mouse in the Campus](../problems/G._X-mouse_in_the_Campus.md "Educational Codeforces Round 49 (Rated for Div. 2)")

Some notes:

At first, there is x−1modm since (x,m)=1 (lets define GCD(a,b) as (a,b)). That means that for each v=0..m−1 there is exactly one u that u⋅x=v. So if we look at this problem as the graph then it consists of cycles (consider loops as cycles of length one). So we need to know number of cycles in this graph.

At second, (v,m)=(v⋅xmodm,m) since (x,m)=1, v⋅xmodm=v⋅x−m⋅k and (v,m)∣v and (v,m)∣m. So all v can be divided in groups by its (v,m). And we can calculate number of cylces in each group independently.

Let fix some GCD equal to g. All numbers v such that (v,m)=g can be represented as v=g⋅v′ and (v′,m)=1. Number of such v equals to φ(mg). Moreover gv′⋅x≡gv′⋅(xmodmg)modm. Here we can shift from v, x and m to v′, (xmodmg) and mg.

In result we need for each d∣m calculate number of cycles created by xmodd from numbers v, that 1≤v<d and (v,d)=1. Lets set x=xmodd.

Next step is to find minimal k>0 such that xk≡1modd, let's name it order of x or ord(x). Then for each 0≤i,j<k if i≠j then xi≢xj and v⋅xi≢v⋅xj, so each cycle will have length equal to ord(x) and number of cycles will be equal to φ(d)ord(xmodd).

Last step is calculate ord(x) for each d∣m. There is a fact that ord(x)∣φ(d) so can try to iterate over all divisors df of φ(d) and check xdf≡1 by binary exponentiation (It seems as O(divs(m)2logm) but it's faster and author's version work around 2 seconds. It doesn't pass but somebody can write better). But we'll speed it up. Let φ(d)=pa11pa22…pakk. So we can independently for each pi find its minimal power bi≤ai such that xφ(d)⋅pbi−aii≡1. We can just iterate over all pi and ai since ∑ai=O(logm).

Some words about finding φ(d) — its factorization differs from factorization of d just by lowering degrees of primes and adding factorizations of some (pi−1). But we can manually find factorization of (pi−1) with memorization (or even without it) since ∑√pi≤∏√pi=O(√m).

So our steps are next: factorize m, recursively iterate over all divisors of m, find φ(d) and ord(xmodd), and add to the answer φ(d)ord(xmodd).

Result complexity is O(√m+divs(m)⋅log2m).

And the last note is how to multiply a,b<1014 modulo mod≤1014. You can use binary multiplification which will give you extra logm what is not critically in this task (in C++, of course). Or you can use multiplification from hashes, which will work with 64 bit double, since it's only 1014.

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
typedef pair<li, li> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

li m, x;

inline bool read() {
    if(!(cin >> m >> x))
        return false;
    return true;
}

map< li, vector<pt> > dFact;
vector<pt> fact(li v) {
    if(dFact.count(v))
        return dFact[v];
    
    li oldv = v;
    vector<pt> fs;
    for(li d = 2; d * d <= v; d++) {
        int cnt = 0;
        while(v % d == 0)
            v /= d, cnt++;
        
        if(cnt > 0)
            fs.emplace_back(d, cnt);
    }
    if(v > 1)
        fs.emplace_back(v, 1), v = 1;
    return dFact[oldv] = fs;
}

vector<pt> merge(const vector<pt> &a, const vector<pt> &b) {
    vector<pt> ans;
    int u = 0, v = 0;
    while(u < sz(a) && v < sz(b)) {
        if(a[u].x < b[v].x)
            ans.push_back(a[u++]);
        else if(a[u].x > b[v].x)
            ans.push_back(b[v++]);
        else {
            ans.emplace_back(a[u].x, a[u].y + b[v].y);
            u++, v++;
        }
    }
    while(u < sz(a))
        ans.push_back(a[u++]);
    while(v < sz(b))
        ans.push_back(b[v++]);
    return ans;
}

li getPw(li a, li b) {
    li ans = 1;
    fore(i, 0, b)
        ans *= a;
    return ans;
}

li mul(li a, li b, li mod) {
    li m = li(ld(a) * b / mod);
    li rem = a * b - m * mod;
    while(rem < 0)
        rem += mod;
    while(rem >= mod)
        rem -= mod;
    return rem;
}

li binPow(li a, li k, li mod) {
    li ans = 1 % mod;
    while(k > 0) {
        if(k & 1)
            ans = mul(ans, a, mod);
        a = mul(a, a, mod);
        k >>= 1;
    }
    return ans;
}

li findOrder(li x, li mod, const vector<pt> &f) {
    li phi = 1;
    fore(i, 0, sz(f)) fore(k, 0, f[i].y)
        phi *= f[i].x;
        
    if(phi == 1 || x == 0)
        return 1;
    
    li ord = 1;
    fore(i, 0, sz(f)) {
        li basePw = phi;
        fore(k, 0, f[i].y)
            basePw /= f[i].x;
        
        li curV = binPow(x, basePw, mod);
        
        int curPw = -1;
        fore(k, 0, f[i].y + 1) {
            if(curV != 1)
                curPw = k;
            curV = binPow(curV, f[i].x, mod);
        }
        
        ord *= getPw(f[i].x, curPw + 1);
    }
    return ord;
}

vector<pt> fm;
vector<int> pw;

li calc(int pos, li dv) {
    if(pos >= sz(fm)) {
        vector<pt> cf = fm;
        fore(i, 0, sz(fm))
            cf[i].y = max(pw[i] - 1, 0);
        
        li phi = dv;
        fore(i, 0, sz(fm)) {
            if(pw[i] > 0) {
                cf = merge(cf, fact(fm[i].x - 1));
                phi -= phi / fm[i].x;
            }
        }
        li k = findOrder(x % dv, dv, cf);
        return phi / k;
    }
    
    li ans = 0;
    fore(i, 0, fm[pos].y + 1) {
        pw[pos] = i;
        ans += calc(pos + 1, dv);
        dv *= fm[pos].x;
    }
    return ans;
}

inline void solve() {
    fm = fact(m);
    
    pw.assign(sz(fm), 0);
    li ans = calc(0, 1);
    
    cout << ans << endl;
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
