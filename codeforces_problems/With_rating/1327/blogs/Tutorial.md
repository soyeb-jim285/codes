# Tutorial

[1327A - Sum of Odd Integers](../problems/A._Sum_of_Odd_Integers.md "Educational Codeforces Round 84 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1327A - Sum of Odd Integers](../problems/A._Sum_of_Odd_Integers.md "Educational Codeforces Round 84 (Rated for Div. 2)")

First of all, notice that the sum of the first $k$ odd integers is $k^2$. If $k^2 > n$ then the answer obviously "NO". And if $n \% 2 \ne k \% 2$ then the answer is "NO" also ($\%$ is modulo operation). Otherwise, the answer is always "YES" and it seems like this: $[1, 3, 5, \dots, 2(k-1)-1, rem]$, where $rem = n - \sum\limits_{i=1}^{k-1} (2i-1)$. It is obviously greater than $2(k-1)-1$ because $k^2 \le n$ and it is obviously odd because the parity of $n$ and $k$ is the same.

 **Solution (vovuh)**
```cpp
for i in range(int(input())):
    n, k = map(int, input().split())
    print('YES' if k * k <= n and n % 2 == k % 2 else 'NO')
```
[1327B - Princesses and Princes](../problems/B._Princesses_and_Princes.md "Educational Codeforces Round 84 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1327B - Princesses and Princes](../problems/B._Princesses_and_Princes.md "Educational Codeforces Round 84 (Rated for Div. 2)")

Simulate the process without adding the new entry. For this you can just maintain an array $taken$, $i$-th value of which is true if the $i$-th prince is married and false otherwise.

Now observe that there are two possible outcomes: 

1. Every daughter is married — the answer is optimal.
2. There is a daughter who isn't married. That means that there is a free prince as well. Marry them to each other because doing that won't affect any other marriages and add a new one to the answer.

Overall complexity: $O(n + m)$.

 **Solution (pikmike)**
```cpp
from sys import stdin, stdout

t = int(stdin.readline())
for _ in range(t):
    n = int(stdin.readline())
    used = [False for i in range(n)]
    v = -1
    for i in range(n):
        l = [int(x) - 1 for x in stdin.readline().split()][1:]
        for j in l:
            if not used[j]:
                used[j] = True
                break
        else:
            v = i
    if v == -1:
        stdout.write("OPTIMALn")
    else:
        u = used.index(False)
        stdout.write("IMPROVEn" + str(v + 1) + " " + str(u + 1) + "n")
```
[1327C - Game with Chips](../problems/C._Game_with_Chips.md "Educational Codeforces Round 84 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1327C - Game with Chips](../problems/C._Game_with_Chips.md "Educational Codeforces Round 84 (Rated for Div. 2)")

Note that $2nm$ is a fairly large number of operations. Therefore, we can first collect all the chips in one cell, and then go around the entire board.

Let's calculate the required number of operations.

First, let's collect all the chips in the $(1, 1)$ cell. To do this, let's do $n-1$ operations $U$ so that all the chips are in the first row, then do $m-1$ operations $L$. After such operations, wherever the chip is initially located, it will end up in the $(1, 1)$ cell.

After that, we need to go around the entire board. Let's do it in such a way that the rows with odd numbers are be bypassed from left to right, and the even ones — from right to left. We also need $n-1$ operations $D$ to move from one row to the next one.

In total, we got $(n-1) + (m-1) + n * (m-1) + (n-1) = nm + n + m - 3$ operations, which is completely suitable for us.

 **Solution (Ne0n25)**
```cpp
n, m, _ = map(int, input().split())

print(2 * (n - 1) + (n + 1) * (m - 1))
print("U" * (n - 1) + "L" * (m - 1), end="")
for i in range(n):
    if i != 0:
        print("D", end="")
    if i % 2 == 0:
        print("R" * (m - 1), end="")
    else:
        print("L" * (m - 1), end="")
```
[1327D - Infinite Path](../problems/D._Infinite_Path.md "Educational Codeforces Round 84 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1327D - Infinite Path](../problems/D._Infinite_Path.md "Educational Codeforces Round 84 (Rated for Div. 2)")

Let's look at the permutation as at a graph with $n$ vertices and edges $(i, p_i)$. It's not hard to prove that the graph consists of several cycles (self-loops are also considered as cycles). So, the sequence $i, p[i], p[p[i]], \dots$ is just a walking on the corresponding cycle.

Let's consider one cycle $c_1, c_2, \dots, c_m$. In permutation $p$ we have $p[c_i] = c_{(i + 1) \mod m}$. But since $p^2 = p \times p$ or $p^2[i] = p[p[i]]$, so $p^2[c_i] = c_{(i + 2) \mod m}$ and in general case, $p^k[c_i] = c_{(i + k) \mod m}$.

Now, walking with step $k$ we can note, that the initial cycle $c$ split up on $GCD(k, m)$ cycles of length $\frac{m}{GCD(k, m)}$. Looking at the definition of infinite path we can understand that all we need to do is to check that at least one of $GCD(k, m)$ cycles have all vertices of the same color. We can check it in $O(m)$ time for the cycle $c$ and fixed $k$.

The final observation is next: for $k_1$ and $k_2$ such that $GCD(k_1, m) = GCD(k_2, m)$ the produced cycles will have the same sets of vertices and differ only in the order of walking, so we can check only one representative for each $GCD(k, m)$, i.e. we can take only such $k$ which divide $m$.

We can handle each cycle of $p$ separately. So, using the approximation that the number of divisors of $n$ is $O(n^{\frac{1}{3}})$, we get $O(n^{\frac{4}{3}})$ time complexity.

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

int n;
vector<int> p, c;

inline bool read() {
    if(!(cin >> n))
        return false;
    p.resize(n);
    c.resize(n);
    
    fore(i, 0, n) {
        cin >> p[i];
        p[i]--;
    }
    fore(i, 0, n)
        cin >> c[i];
    return true;
}

inline void solve() {
    vector<int> used(n, 0);
    
    int ans = INF;
    fore(st, 0, n) {
        if(used[st])
            continue;
        
        vector<int> cycle;
        int v = st;
        while(!used[v]) {
            used[v] = 1;
            cycle.push_back(v);
            v = p[v];
        }
        
        fore(step, 1, sz(cycle) + 1) {
            if(sz(cycle) % step != 0)
                continue;
            
            fore(s, 0, step) {
                bool eq = true;
                for(int pos = s; pos + step < sz(cycle); pos += step) {
                    if(c[cycle[pos]] != c[cycle[pos + step]])
                        eq = false;
                }
                if(eq) {
                    ans = min(ans, step);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
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
[1327E - Count The Blocks](../problems/E._Count_The_Blocks.md "Educational Codeforces Round 84 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1327E - Count The Blocks](../problems/E._Count_The_Blocks.md "Educational Codeforces Round 84 (Rated for Div. 2)")

Presume that we want to calculate the number of blocks of length $len$. Let's divide this blocks into two types:

1. blocks which first element is a first element of integer, or blocks which last element is a last element of integer (for example blocks $111$ and $0$ in integer $11173220$);
2. other blocks.

At first let's calculate the number of blocks of first type. We can choose $2$ positions of this block (at the start of end of the integer). Now we can choose $10$ digit for this block. After that we can chose $9$ digits of adjacent block (if these blocks contain the same digit then we length of blocks which we want calculate greater than $len$, so we have only $9$ variations of digit in adjacent block). Finally, the can chose the remaining digit $10^{n-len-1}$ ways.

So, the total number of block of first type is $2 \cdot 10 \cdot 9 \cdot 10^{n-len-1}$.

Now let's calculate the number of blocks of second type. We can choose $n - len - 1$ positions of this block (all position except the start and end of integer). Now we can choose 10 digit for this block. After that we can chose $9^2$ digits of adjacent block ($9$ for block to the left and $9$ for block to the right). Finally, the can chose the remaining digit $10^{n−len−2}$ ways.

So, the total number of block of second type is $(n - len - 1) \cdot 10 \cdot 9^2 \cdot 10^{n-len-2}$.

That's almost all. We have one corner case. If $len = n$, then we number of blocks is always $10$.

 **Solution (Roms)**
```cpp
MOD = 998244353
p = [1] * 200005
for i in range(1, 200005):
    p[i] = (p[i - 1] * 10) % MOD

n = int(input())
for i in range(1, n):
    res = 2 * 10 * 9 * p[n - i - 1]
    res += (n - 1 - i) * 10 * 9 * 9 * p[n - i - 2]
    print(res % MOD, end = ' ')
print(10)
```
[1327F - AND Segments](../problems/F._AND_Segments.md "Educational Codeforces Round 84 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1327F - AND Segments](../problems/F._AND_Segments.md "Educational Codeforces Round 84 (Rated for Div. 2)")

We will solve the problem for each bit separately, and then multiply the results.

Obviously, if the position is covered by a segment with the value $1$, then we have no choice, and we must put $1$ there. For segments with the value $0$, there must be at least one position that they cover and its value is $0$.

So we can write the following dynamic programming: $dp_i$ — the number of arrays such that the last $0$ was exactly at the position $i$, and all $0$-segments to the left of it contain at least one zero.

It remains to determine which states $j$ we can update from. The only restriction we have is that there should not be any segment $(l, r)$ with the value $0$, such that $j < l$ and $r < i$. Since in this case, this segment will not contain any zero values. For each position $i$, we may precalculate the rightmost position $f_i$ where some segment ending before $i$ begins, and while calculating $dp_i$, we should sum up only the values starting from position $f_i$. This can be done with prefix sums.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)

typedef pair<int, int> pt;

const int MOD = 998244353;
const int N = 500 * 1000 + 13;

int n, k, m;
pair<pt, int> q[N];

int ones[N];
int mx[N], sum[N];

int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
    return x;
}

int calc(int t) {
    memset(ones, 0, sizeof(ones));
    memset(mx, -1, sizeof(mx));
    
    forn(i, m) {
        int l = q[i].x.x, r = q[i].x.y;
        if (q[i].y & (1 << t)) {
            ones[l]++;
            ones[r + 1]--;
        } else {
            mx[r] = max(mx[r], l);
        }
    }
    
    int j = -1;
    forn(i, n) {
        int cur = 0;
        if (!ones[i]) {
            cur = sum[i];
            if (j == -1) cur = add(cur, 1);
            else cur = add(cur, -sum[j]);
        }
        
        sum[i + 1] = add(sum[i], cur);
        ones[i + 1] += ones[i];
        j = max(j, mx[i]);
    }
    
    return add(sum[n], j != -1 ? -sum[j] : 1);
}

int main() {
    scanf("%d%d%d", &n, &k, &m);
    forn(i, m) {
        scanf("%d%d%d", &q[i].x.x, &q[i].x.y, &q[i].y);
        --q[i].x.x; --q[i].x.y;
    }
    
    int ans = 1;
    forn(i, k) ans = (ans * 1ll * calc(i)) % MOD;
    printf("%dn", ans);
}
```
[1327G - Letters and Question Marks](../problems/G._Letters_and_Question_Marks.md "Educational Codeforces Round 84 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1327G - Letters and Question Marks](../problems/G._Letters_and_Question_Marks.md "Educational Codeforces Round 84 (Rated for Div. 2)")

Suppose we want to calculate the value of some already fixed string (we should be able to do so at least to solve the test cases without question marks). How can we do it? We can use some substring searching algorithms to calculate $F(S, t_i)$, but a better solution is to build an Aho-Corasick automaton over the array $[t_1, t_k]$, and then for each node calculate the sum of costs of all strings ending in that node (these are the strings represented by that node and the strings represented by other nodes reachable by suffix links). After that, process $S$ by the automaton and calculate the sum of the aforementioned values over all states that were reached. Building an Aho-Corasick automaton can be done in $O(\sum \limits_{i = 1}^{k} |t_i|)$, and processing the string $S$ — in $O(|S|)$.

Okay, what if we've got some question marks in our string? The first solution that comes to mind is to calculate $dp[i][mask][c]$ — we processed $i$ first positions in $S$, used a $mask$ of characters for question marks, and the current state of the automaton is $c$; then $dp[i][mask][c]$ denotes the maximum value of first $i$ characters of $S$ we could have got. But it's $O(L|S|2^KK)$, where $L = \sum \limits_{i = 1}^{k} |t_i|$ and $K$ is the size of the alphabet, which is too slow.

To speed it up, we can see that there are only $14$ positions in our string where we actually choose something in our dynamic programming. All substrings not containing question marks can be skipped in $O(1)$ as follows: for each substring of $S$ bounded by two question marks (or bounded by one question mark and one of the ends of $S$) and each state of the automaton $x$, we may precalculate the resulting state of the automaton and the change to the value of the string, if we process this substring by the automaton with the initial state $x$. This precalculation is done in $O(L|S|)$ overall, and using this, we may skip the states of dynamic programming such that $i$ is not a position with a question mark, so our complexity becomes $O(L2^KK + L|S|)$.

A note about the model solution: it's a bit more complicated because we wanted to increase the constraints to $|S| \le 8 \cdot 10^6$, but then we decided that it would be too complicated to code, so the main function still contains some parts of the code that were used to improve its complexity. We will post a clearer version of the model solution soon.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 8000043;
const int K = 15;
const int M = 1043;

int k;
char buf[N], buf2[M];
vector<string> t;
vector<int> c;
string s;

map<char, int> nxt[M];
int lnk[M];
int p[M];
char pchar[M];
map<char, int> go[M];
int term[M];
int ts = 1;
int A[M][K];
int F[M][K];
int dp[M];

int get_nxt(int x, char c)
{
    if(!nxt[x].count(c))
    {
        p[ts] = x;
        pchar[ts] = c;
        nxt[x][c] = ts++;
    }
    return nxt[x][c];
}

void add_string(int i)
{
    int cur = 0;
    for(auto x : t[i])
    {
        cur = get_nxt(cur, x);
    }
    term[cur] += c[i];
}

int get_go(int x, char c);

int get_lnk(int x)
{
    if(lnk[x] != -1)
        return lnk[x];
    if(x == 0 || p[x] == 0)
        return lnk[x] = 0;
    return lnk[x] = get_go(get_lnk(p[x]), pchar[x]);
}

int get_dp(int x)
{
    if(dp[x] != -1)
        return dp[x];
    dp[x] = term[x];
    if(get_lnk(x) != x)
        dp[x] += get_dp(get_lnk(x));
    return dp[x];
}

int get_go(int x, char c)
{
    if(go[x].count(c))
        return go[x][c];
    if(nxt[x].count(c))
        return go[x][c] = nxt[x][c];
    if(x == 0)
        return go[x][c] = 0;
    return go[x][c] = get_go(get_lnk(x), c);
}

void build_skip(const string& s, vector<int>& sA, vector<long long>& sF)
{                     
    sA = vector<int>(ts);
    for(int i = 0; i < ts; i++)
        sA[i] = i;
    sF = vector<long long>(ts);
    for(auto c : s)
    {
        int ci = int(c - 'a');
        for(int i = 0; i < ts; i++)
        {
            sF[i] += F[sA[i]][ci];
            sA[i] = A[sA[i]][ci];
        }
    }
}

long long solve(const string& s)
{
    long long BAD = (long long)(-1e18);

    vector<int> pos;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '?')
            pos.push_back(i);
    int cntQ = pos.size();
    vector<vector<int> > skip_A(cntQ + 1);
    vector<vector<long long> > skip_F(cntQ + 1);
    build_skip(s.substr(0, pos[0]), skip_A[0], skip_F[0]);
    for(int i = 1; i < cntQ; i++)
        build_skip(s.substr(pos[i - 1] + 1, pos[i] - pos[i - 1] - 1), skip_A[i], skip_F[i]);
    build_skip(s.substr(pos.back() + 1, s.size() - pos.back() - 1), skip_A[cntQ], skip_F[cntQ]);

    vector<vector<long long> > dp(1 << (K - 1), vector<long long>(ts, BAD));
    vector<int> used(1 << K);
    dp[0][skip_A[0][0]] = skip_F[0][0];
    queue<int> q;
    q.push(0);
    used[0] = 1;
    long long ans = BAD;
    while(!q.empty())
    {
        int k = q.front();
        q.pop();
        int step = __builtin_popcount(k);
        if(step == cntQ)
        {
            for(int i = 0; i < ts; i++)
                ans = max(ans, dp[k][i]);
            continue;
        }
        for(int i = 0; i < K - 1; i++)
        {
            if(k & (1 << i)) continue;
            int nk = (k ^ (1 << i));
            if(used[nk] == 0)
            {
                used[nk] = 1;
                q.push(nk);
            }
            for(int j = 0; j < ts; j++)
            {
                if(dp[k][j] == BAD)
                    continue;
                int nj = get_go(j, char('a' + i));
                int newSt = skip_A[step + 1][nj];
                long long add = get_dp(nj) + skip_F[step + 1][nj];
                dp[nk][newSt] = max(dp[nk][newSt], dp[k][j] + add);
            }
        }
    }
    return ans;
}

int main()
{
    scanf("%d", &k);
    t.resize(k);
    c.resize(k);
    for(int i = 0; i < k; i++)
    {
        scanf("%s %d", buf2, &c[i]);
        t[i] = buf2;
    }    
    scanf("%s", buf);
    s = buf;

    for(int i = 0; i < k; i++)
        add_string(i);
    for(int i = 0; i < ts; i++)
    {
        lnk[i] = -1;
        dp[i] = -1;
    }
    for(int i = 0; i < ts; i++)
    {
        get_lnk(i);
        for(char c = 'a'; c <= 'o'; c++)
            get_go(i, c);
    }
    for(int i = 0; i < ts; i++)
        get_dp(i);                               
    for(int i = 0; i < ts; i++)
    {
        for(int j = 0; j < K; j++)
        {
            A[i][j] = get_go(i, char('a' + j));
            F[i][j] = dp[A[i][j]];
        }
    }   
    int n = s.size();
    vector<int> leftQ(n, -1);
    vector<int> rightQ(n, -1);
    for(int i = 0; i < n; i++)
    {
        if(i != 0)
            leftQ[i] = leftQ[i - 1];
        if(s[i] == '?')
            leftQ[i] = i;
    }
    for(int i = n - 1; i >= 0; i--)
    {
        if(i != n - 1)
            rightQ[i] = rightQ[i + 1];
        if(s[i] == '?')
            rightQ[i] = i;
    }
    vector<int> bad(n, 0);
    
    if(leftQ.back() == -1)
        bad = vector<int>(n, 1);

    long long ans = 0;
    int curSt = 0;
    string news = "";
    for(int i = 0; i < n; i++)
    {
        int ci = (s[i] == '?' ? 14 : int(s[i] - 'a'));
        if(bad[i])
            ans += F[curSt][ci];
        curSt = A[curSt][ci];
        if(!bad[i])
            news.push_back(s[i]);
        else if(i != 0 && !bad[i - 1])
            news.push_back('o');
    }                    
    if(!news.empty())
        ans += solve(news);
    printf("%lldn", ans);
}
```
