# Tutorial_(en)

[1303A - Erasing Zeroes](../problems/A._Erasing_Zeroes.md "Educational Codeforces Round 82 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**Tutorial is loading... **Solution (Roms)**
```cpp
for t in range(int(input())):
    print(input().strip('0').count('0'))
```
[1303B - National Project](../problems/B._National_Project.md "Educational Codeforces Round 82 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1303B - National Project](../problems/B._National_Project.md "Educational Codeforces Round 82 (Rated for Div. 2)")

There are two conditions that should be met according to the statement. On the one hand, we should repair the whole highway, so we must spend at least $n$ days to do it. On the other hand, at least half of it should have high-quality pavement or at least $needG = \left\lceil \frac{n}{2} \right\rceil$ units should be laid at good days.

How to calculate the minimum number of days (name it as $totalG$) for the second condition to meet? Note that the first $totalG$ days can be represented as several (maybe zero) blocks of $g + b$ days, where exactly $g$ days in each block are good and some remaining days $1 \le rem \le g$. The $rem > 0$ because $totalG$ will not be minimum otherwise.

There are plenty of ways to calculate $totalG$. One of them is the following: Firstly, let's calculate the number of $g + b$ cycles we need: $totatG = \left\lfloor \frac{needG}{g} \right\rfloor \cdot (g + b)$. Now, if $needG \mod g > 0$ we just add it (since it's exactly the $rem$) or $totalG = totalG + (needG \mod g)$. But if $needG \mod g = 0$ we added to $totalG$ last $b$ block and should subtract it or $totalG = totalG - b$.

The answer is $\max(n, totalG)$.

 **Solution (adedalic)**
```cpp
fun main() {
    val t = readLine()!!.toInt()
    for (tc in 1..t) {
        val (n, g, b) = readLine()!!.split(' ').map { it.toLong() }
        
        val needG = (n + 1) / 2
        var totalG = needG / g * (b + g)
        totalG += if (needG % g == 0L) -b else needG % g
        println(maxOf(n, totalG))
    }
}
```
[1303C - Perfect Keyboard](../problems/C._Perfect_Keyboard.md "Educational Codeforces Round 82 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1303C - Perfect Keyboard](../problems/C._Perfect_Keyboard.md "Educational Codeforces Round 82 (Rated for Div. 2)")

The problem can be solved using a greedy algorithm. We will maintain the current layout of the keyboard with letters that have already been encountered in the string, and the current position on the layout.

If the next letter of the string is already on the layout, it must be adjacent to the current one, otherwise there is no answer.

If there was no such letter yet, we can add it to the adjacent free position, if both of them is occupied, then there is no answer.

At the end, you have to add letters that were not in the string $s$.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)

void solve() {
    string s;
    cin >> s;

    vector<bool> used(26);
    used[s[0] - 'a'] = true;
    string t(1, s[0]);
        
    int pos = 0;
    for (int i = 1; i < sz(s); i++) {
        if (used[s[i] - 'a']) {
            if (pos > 0 && t[pos - 1] == s[i]) {
                pos--;
            } else if (pos + 1 < sz(t) && t[pos + 1] == s[i]) {
                pos++;
            } else {
                cout << "NO" << endl;
                return;
            }
        } else {
            if (pos == 0) {
                t = s[i] + t;
            } else if (pos == sz(t) - 1) {
                t += s[i];
                pos++;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
        used[s[i] - 'a'] = true;
    }
        
    forn(i, 26) if (!used[i])
        t += char(i + 'a');
    cout << "YES" << endl << t << endl;
}

int main() {
    int tc;
    cin >> tc;
    
    forn(i, tc) solve();
}
```
[1303D - Fill The Bag](../problems/D._Fill_The_Bag.md "Educational Codeforces Round 82 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1303D - Fill The Bag](../problems/D._Fill_The_Bag.md "Educational Codeforces Round 82 (Rated for Div. 2)")

If $\sum\limits_{i=1}^{n} a_i \ge n$, then the answer is YES, because the just can divide all boxes to size $1$ and then fill the bag. Otherwise the answer is NO.

If the answer is YES, let's calculate the minimum number of divisions. Let's consider all boxes from small to large. Presume that now we consider boxes of size $2^i$. Then there are three cases: 

1. if in binary representation of $n$ the $i$-th bit is equal to $0$, then we don't need boxes of size $2^i$ and we can merge it into boxes of size $2^{i+1}$;
2. if in binary representation of $n$ the $i$-th bit is equal to $1$ and we have at most one box of size $2^i$, then we have to put it box in the bag and then merge the remaining boxes of size $2^i$ into boxes of size $2^{i+1}$;
3. if in binary representation of $n$ the $i$-th bit is equal to $1$ and we have not boxes of size $2^i$, then we have to divide the large box into box of size $2^i$ (let's presume that it's box of size $2^x$). After that we just continue this algorithm with box of size $2^x$.
 **Solution (Roms)**
```cpp
from math import log2

for t in range(int(input())):
    n, m = map(int, input().split())
    c = [0] * 61
    s = 0
    for x in map(int, input().split()):
        c[int(log2(x))] += 1
        s += x

    if s < n:
        print(-1)
        continue

    i, res = 0, 0
    while i < 60:
        if (1<<i)&n != 0:
            if c[i] > 0:
                c[i] -= 1
            else:
                while i < 60 and c[i] == 0:
                    i += 1
                    res += 1
                c[i] -= 1
                continue
        c[i + 1] += c[i] // 2
        i += 1

    print(res)
```
[1303E - Erase Subsequences](../problems/E._Erase_Subsequences.md "Educational Codeforces Round 82 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1303E - Erase Subsequences](../problems/E._Erase_Subsequences.md "Educational Codeforces Round 82 (Rated for Div. 2)")

Let's look at string $t$. Since we should get it using no more than two subsequences, then $t = a + b$ where $a$ is the first subsequence and $b$ is the second one. In the general case, $a$ can be empty. Let iterate all possible lengths of $a$ ($0 \le |a| < |s|$), so we can check the existence of solution for each pair $a$ and $b$.

If we'd fix $a$ and $b$ we need to check the following: is it true that $s$ contains $a$ and $b$ as subsequences and these subsequences don't intersect. Initially, we can invent the following dp: let $dp[len_s][len_a][len_b]$ be $1$ if the prefix of $s$ of length $len_s$ contains prefixes of $a$ and $b$ of length $len_a$ and $len_b$ as non-intersecting subsequences. The transitions are straingforward: if $dp[len_s][len_a][len_b] = 1$ we can either skip $s[len_s]$ ($0$-indexed) and update $dp[len_s + 1][len_a][len_b]$. If $s[len_s] = a[len_a]$ ($0$-indexed) then we can update $dp[len_s + 1][len_a + 1][len_b]$ and if $s[len_s] = b[len_b]$ then we can update $dp[len_s + 1][len_a][len_b + 1]$. But this dp has complexity $O(|s|^3)$ in general case.

But we can transform it in the next way: instead of the boolean value, we will make $len_s$ as a value of dp. In other words, we will maintain $dp[len_a][len_b]$ as minimal appropriate prefix $len_s$. But the problem now is to define transitions.

Let's note the next fact: suppose we have $len_s = dp[len_a][len_b]$ and we'd like to add next character to $a$ which is equal to $a[len_a]$. The idea is next: it's always optimal to choose the first occurrence of $a[len_a]$ in $s[len_s \dots |s|)$. It can be proved by contradiction: if the first occurrence is free then it's better to take it, or if the first occurrence will be occupied by $b$ then this will be handled by the other state $dp[len_a][len_b']$ with $len_b' > len_b$. 

The logic for increasing $len_b$ is analogical. In result, we need to precalculate array $nxt[pos][c]$ with the next occurrence of character $c$ in suffix $pos$ of $s$ one time before choosing $a$ and $b$ and use it each time to acquire $O(|s|^2)$ complexity.

The total complexity if $O(|s|^3)$ for each test case.

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

const int INF = int(1e9);
const li INF64 = li(1e18);

string s, t;

inline bool read() {
    if(!(cin >> s >> t))
        return false;
    for(auto &c : s)
        c -= 'a';
    for(auto &c : t)
        c -= 'a';
    return true;
}

vector< vector<int> > nxt;

bool calc(const string &a, const string &b) {
    vector< vector<int> > dp(sz(a) + 1, vector<int>(sz(b) + 1, INF));
    dp[0][0] = 0;
    fore(i, 0, sz(a) + 1) fore(j, 0, sz(b) + 1) {
        if(dp[i][j] > sz(s))
            continue;
        
        int len = dp[i][j];
        if(i < sz(a) && nxt[len][a[i]] < INF) {
            dp[i + 1][j] = min(dp[i + 1][j], nxt[len][a[i]] + 1);
        }
        if(j < sz(b) && nxt[len][b[j]] < INF) {
            dp[i][j + 1] = min(dp[i][j + 1], nxt[len][b[j]] + 1);
        }
    }
    return dp[sz(a)][sz(b)] < INF;
}

inline void solve() {
    nxt.assign(sz(s) + 1, vector<int>(26, INF));
    for(int i = sz(s) - 1; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i]] = i;
    }
    
    for(int i = 0; i < sz(t); i++) {
        if(calc(t.substr(0, i), t.substr(i, sz(t)))) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    
    int tc; cin >> tc;
    
    while(tc--) {
        read();
        solve();
        
#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}
```
[1303F - Number of Components](../problems/F._Number_of_Components.md "Educational Codeforces Round 82 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1303F - Number of Components](../problems/F._Number_of_Components.md "Educational Codeforces Round 82 (Rated for Div. 2)")

Note that because of the low constraints on the number of colors, the problem can be solved independently for each color. Now you can divide the queries into two types: add a cell to the field and delete it. You have to maintain the number of components formed by added cells. Cell deletions will occur after all additions because of the condition $c_i \le c_{i+1}$. 

The first part of the solution will be to calculate the number of components while adding new cells. This is a standard problem that can be solved using the DSU.

After that, we should note that if we consider the process of removing cells from the end, this process is similar to the process of adding. Therefore, we have to process delete requests from the end in the same way as add requests, only their contribution to the number of components will be opposite in sign.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a) * (a))
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)
#define forr(i, r, l) for (int i = int(r) - 1; i >= int(l); --i)

typedef pair<int, int> pt;

const int M = 310;
const int N = 2000 * 1000 + 13;

int n, m, q;
int a[M][M];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int p[M * M], rk[M * M];

int getp(int v) {
    return p[v] == v ? v : p[v] = getp(p[v]);
}

bool unite(int a, int b) {
    a = getp(a); b = getp(b);
    if (a == b) return false;
    if (rk[a] < rk[b]) swap(a, b);
    p[b] = a;
    rk[a] += rk[b];
    return true;
}

int dif[N];
vector<pt> add[N], del[N];

void recalc(const vector<pt>& ev, int coeff)  {
    forn(i, n) forn(j, m) a[i][j] = 0;
    forn(i, n * m) p[i] = i, rk[i] = 1;
        
    for (auto it : ev) {
        int cur = 1;
        int x = it.x / m, y = it.x % m;
        a[x][y] = 1;
        
        forn(k, 4) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (in(nx, ny) && a[nx][ny] == 1)
                cur -= unite(nx * m + ny, x * m + y);
        }
        
        dif[it.y] += cur * coeff;
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    int clrs = 1;
    forn(i, q) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        --x; --y;
        if (a[x][y] == c) continue;
        clrs = c + 1;
        add[c].pb(mp(x * m + y, i));
        del[a[x][y]].pb(mp(x * m + y, i));
        a[x][y] = c;
    }
    
    forn(x, n) forn(y, m)
        del[a[x][y]].pb(mp(x * m + y, q));
    
    forn(i, clrs) reverse(all(del[i]));
    
    forn(i, clrs) recalc(add[i], +1);
    forn(i, clrs) recalc(del[i], -1);
    
    int cur = 1;
    forn(i, q) {
        cur += dif[i];
        printf("%dn", cur);
    }
}
```
[1303G - Sum of Prefix Sums](../problems/G._Sum_of_Prefix_Sums.md "Educational Codeforces Round 82 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1303G - Sum of Prefix Sums](../problems/G._Sum_of_Prefix_Sums.md "Educational Codeforces Round 82 (Rated for Div. 2)")

Let's use centroid decomposition to solve the problem. We need to process all the paths going through each centroid somehow.

Consider a path from vertex $u$ to vertex $v$ going through vertex $c$, which is an ancestor of both $u$ and $v$ in the centroid decomposition tree. Suppose the sequence of numbers on path from $u$ to $c$ (including both these vertices) is $[a_1, a_2, \dots, a_k]$, and the sequence of numbers on path from $c$ to $v$ (including $v$, but excluding $c$) is $[b_1, b_2, \dots, b_m]$. Let $sum_a = \sum\limits_{i = 1}^{k} a_i$, $psum_a = \sum\limits_{i = 1}^{k} (k - i + 1) a_i$, and $psum_b = \sum\limits_{i = 1}^{m} (m - i + 1) b_i$. We can show that the sum of prefix sums of $[a_1, a_2, \dots, a_k, b_1, b_2, \dots, b_m]$ is equal to $psum_a + psum_b + sum_a \cdot m$.

Now, suppose we fix the second part of the path ($psum_b$ and $m$ are fixed), and we want to find the best first part for this second part. Each possible first part is represented by a linear function, and our goal is to find the maximum over all these linear functions in the point $m$, and add $psum_b$ to this maximum. This can be done with the help of convex hull or Li Chao tree.

The most difficult part of implementation is how to process each centroid's subtree. It's easy to obtain all "first parts" and "second parts" of paths going through the centroid, but pairing them up can be complicated — for each second part, we have to build a convex hull or Li Chao tree on all first parts going to this centroid, excluding those which go through the same child of the centroid as the "second part" we are considering. One of the best ways to implement this is the following. Suppose our centroid has $m$ children, $fp_i$ is the set of "first parts" going from the $i$-th child of the centroid, and $sp_i$ is the set of "second parts" going to the $i$-th child. We will create a new data structure (initially empty), process all second parts from $sp_1$, add all first parts from $fp_1$, process all second parts from $sp_2$, add all first parts from $fp_2$, and so on. After that, we will clear our data structure, process all second parts from $sp_m$, add all first parts from $fp_m$, process all second parts from $sp_{m - 1}$, add all first parts from $fp_{m - 1}$, and so on, until we add all first parts from $fp_1$. That way we will consider all possible first parts for each second part we are trying to use.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 150043;

typedef pair<long long, long long> func;

func T[4 * N];
bool usedT[4 * N];

void clear(int v, int l, int r)
{
    if(!usedT[v]) return;
    usedT[v] = false;
    T[v] = make_pair(0ll, 0ll);
    if(l < r - 1)
    {
        int m = (l + r) / 2;
        clear(v * 2 + 1, l, m);
        clear(v * 2 + 2, m, r);
    }
}

long long eval(func f, int x)
{
    return f.first * x + f.second;
}

long long get(int v, int l, int r, int x)
{
    long long ans = eval(T[v], x);
    if(l < r - 1)
    {
        int m = (l + r) / 2;
        if(m > x)
            ans = max(ans, get(v * 2 + 1, l, m, x));
        else
            ans = max(ans, get(v * 2 + 2, m, r, x));
    }
    return ans;
}

void upd(int v, int l, int r, func f)
{
    usedT[v] = true;
    int m = (l + r) / 2;
    bool need_swap = eval(f, m) > eval(T[v], m);
    if(need_swap)
        swap(T[v], f);
    if(l == r - 1)
        return;
    if(eval(f, l) > eval(T[v], l))
        upd(v * 2 + 1, l, m, f);
    else
        upd(v * 2 + 2, m, r, f);
}

long long ans = 0;

void update_ans(vector<vector<func> > heads, vector<vector<func> > tails)
{
    int n = heads.size();
    for(int i = 0; i < n; i++)
    {
        for(auto x : heads[i])
            ans = max(ans, get(0, 0, N, x.first) + x.second);
        for(auto x : tails[i])
            upd(0, 0, N, x);
    }
    clear(0, 0, N);
}

int a[N];
vector<int> g[N];
int n;
bool used[N];
int siz[N];

void dfs1(int x, int p = -1)
{
    if(used[x]) return;
    siz[x] = 1;
    for(auto to : g[x])
    {                    
        if(!used[to] && to != p)
        {
            dfs1(to, x);
            siz[x] += siz[to];
        }
    }
}

pair<int, int> c;
int S = 0;

void find_centroid(int x, int p = -1)
{
    if(used[x]) return;
    int mx = 0;
    for(auto to : g[x])
    {
        if(!used[to] && to != p)
        {
            find_centroid(to, x);
            mx = max(mx, siz[to]);
        }
    }
    if(p != -1)
        mx = max(mx, S - siz[x]);
    c = min(c, make_pair(mx, x));
}

void dfs_heads(int v, int p, int cnt, long long cursum, long long curadd, vector<func>& sink)
{
    if(used[v])
        return;
    cnt++;
    curadd += a[v];
    cursum += curadd;
    sink.push_back(make_pair(cnt, cursum));
    for(auto to : g[v])
        if(to != p)
            dfs_heads(to, v, cnt, cursum, curadd, sink);
}

void dfs_tails(int v, int p, int cnt, long long cursum, long long curadd, vector<func>& sink)
{
    if(used[v])
        return;
    cnt++;
    curadd += a[v];
    cursum += a[v] * 1ll * cnt;
    sink.push_back(make_pair(curadd, cursum));
    for(auto to : g[v])
        if(to != p)
            dfs_tails(to, v, cnt, cursum, curadd, sink);
}

void centroid(int v)
{
    if(used[v]) return;
    dfs1(v);
    S = siz[v];
    c = make_pair(int(1e9), -1);
    find_centroid(v);
    int C = c.second;
    used[C] = 1;
    vector<vector<func> > heads, tails;
    for(auto to : g[C])
        if(!used[to])
        {
            heads.push_back(vector<func>());
            dfs_heads(to, C, 1, a[C], a[C], heads.back());
            tails.push_back(vector<func>());
            dfs_tails(to, C, 0, 0, 0, tails.back());
        }
    heads.push_back(vector<func>({{1, a[C]}}));
    tails.push_back(vector<func>({{0, 0}}));
    update_ans(heads, tails);
    reverse(heads.begin(), heads.end());
    reverse(tails.begin(), tails.end());
    update_ans(heads, tails);
    for(auto to : g[C])
        centroid(to);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);    
    }
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    centroid(0);
    printf("%lldn", ans);
}
```
