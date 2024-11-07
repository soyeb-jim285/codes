# Tutorial

[1207A - There Are Two Types Of Burgers](../problems/A._There_Are_Two_Types_Of_Burgers.md "Educational Codeforces Round 71 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1207A - There Are Two Types Of Burgers](../problems/A._There_Are_Two_Types_Of_Burgers.md "Educational Codeforces Round 71 (Rated for Div. 2)")

In this task you just can iterate over the numbers of hamburgers and chicken burgers you want to assemble, check that you have enough ingredients and update the answer.

If you want to sell x hamburgers and y chicken burgers then you need x beef patties, y chicken cutlets and 2(x+y) buns.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int t;
int b, p, f;
int h, c;

int main() {
    cin >> t;
    for(int tc = 0; tc < t; ++tc){
        cin >> b >> p >> f;
        cin >> h >> c;

        b /= 2;
        if(h < c){
            swap(h, c);
            swap(p, f);
        }

        int res = 0;

        int cnt = min(b, p);
        b -= cnt, p -= cnt;
        res += h * cnt; 
        
        cnt = min(b, f);
        b -= cnt, f -= cnt;
        res += c * cnt; 
            
        cout << res << endl;
    }
    return 0;
}                               
```
[1207B - Square Filling](../problems/B._Square_Filling.md "Educational Codeforces Round 71 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1207B - Square Filling](../problems/B._Square_Filling.md "Educational Codeforces Round 71 (Rated for Div. 2)")

It is quite obvious that we can't choose any submatrix that contains at least one zero in $A$. The contrary is also true — if a submatrix of $A$ consists of only ones, then there's no reason not to choose it (suppose there is an answer that does not choose it — then choosing this submatrix won't affect it).

So we may perform an operation on every submatrix of $B$ such that the corresponding submatrix in $A$ is filled with $1$'s, and check if our answer is correct.

 **Solution (BledDest)**
```cpp
n, m = map(int, input().split())
a = [[] for i in range(n)]
for i in range(n):
    a[i] = list(map(int, input().split()))

ans = []
for i in range(n - 1):
    for j in range(m - 1):
        if(a[i][j] * a[i][j + 1] * a[i + 1][j] * a[i + 1][j + 1] > 0):
            a[i][j] = 2
            a[i + 1][j] = 2
            a[i][j + 1] = 2
            a[i + 1][j + 1] = 2
            ans.append([i, j])

cnt1 = 0
for i in range(n):
    for j in range(m):
        if(a[i][j] == 1):
            cnt1 += 1

if(cnt1 != 0):
    print(-1)
else:
    print(len(ans))
    for x in ans:
        print(x[0] + 1, x[1] + 1)
```
[1207C - Gas Pipeline](../problems/C._Gas_Pipeline.md "Educational Codeforces Round 71 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**Tutorial is loading... **Solution (adedalic)**
```cpp
const val INF64 = 1e18.toLong()

fun main(args: Array<String>) {
    val tc = readLine()!!.toInt()
    for (t in 1..tc) {
        val (n, a, b) = readLine()!!.split(' ').map { it.toInt() }
        val s = readLine()!!

        val d = Array(n + 1) { arrayOf(INF64, INF64) }
        d[0][0] = b.toLong()

        for (pos in 0 until n) {
            if (s[pos] == '0') {
                d[pos + 1][0] = minOf(d[pos + 1][0], d[pos][0] + a + b)
                d[pos + 1][1] = minOf(d[pos + 1][1], d[pos][0] + 2 * (a + b))

                d[pos + 1][1] = minOf(d[pos + 1][1], d[pos][1] + a + 2 * b)
                d[pos + 1][0] = minOf(d[pos + 1][0], d[pos][1] + 2 * a + b)
            } else {
                d[pos + 1][1] = minOf(d[pos + 1][1], d[pos][1] + a + 2 * b)
            }
        }
        println(d[n][0])
    }
}
```
[1207D - Number Of Permutations](../problems/D._Number_Of_Permutations.md "Educational Codeforces Round 71 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1207D - Number Of Permutations](../problems/D._Number_Of_Permutations.md "Educational Codeforces Round 71 (Rated for Div. 2)")

Let's suppose that all $n!$ permutation are good. We counted the permutations giving the sequences where the first elements are sorted (we denote the number of such permutations as $cnt_1$) and the permutations giving the sequences where the second elements are sorted (we denote the number of such permutations as $cnt_2$). Then the answer is $n! - cnt_1 - cnt_2$, right? No, because we subtracted the number of sequences where first and second elements are sorted simultaneously (we denote this number as $cnt_{12}$) twice. So, the answer is $n! - cnt_1 - cnt_2 + cnt_{12}$.

How can we calculate the value of $cnt_1$? It's easy to understand that the elements having equal $a_i$ can be arranged in any order. So, $cnt_1 = c_1! ~ c_2! ~ \dots ~ c_n!$, where $c_x$ is the number of elements equal to $x$ among $a_i$. $cnt_2$ can be calculated the same way.

How can we calculate the value of $cnt_{12}$? First of all, there is a case where it is impossible to arrange the elements of the sequence so that the first elements and the second elements are sorted. To check that, we may sort the given sequence comparing two elements by $a_i$, and if $a_i$ are equal — by $b_i$. If the sequence of second elements in the resulting sequence is not sorted, then $cnt_{12} = 0$. Otherwise, equal elements of the given sequence can be arranged in any order. So $cnt_{12} = c_{s_1}! ~ c_{s_2}! ~ c_{s_k}!$, where $s_1$, $s_2$, ..., $s_k$ are the elements that appear in the given sequence of pairs at least once.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;
const int MOD = 998244353;

int mul(int a, int b){
    return (a * 1LL * b) % MOD;
}


int sum(int a, int b){
    return (a + b) % MOD;
}

int n;
pair<int, int> a[N];
int f[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d%d", &a[i].first, &a[i].second);

    f[0] = 1;
    for(int i = 1; i < N; ++i)
        f[i] = mul(i, f[i - 1]);

    int res = f[n];
    for(int c = 0; c < 2; ++c){
        int d = 1;
        sort(a, a + n);
        int l = 0;
        while(l < n){
            int r = l + 1;
            while(r < n && a[l].first == a[r].first) ++r;
            d = mul(d, f[r - l]);
            l = r;
        }
        res = sum(res, MOD - d);
        for(int i = 0; i < n; ++i) 
            swap(a[i].first, a[i].second);
    }       

    sort(a, a + n);
    int l = 0;
    int d = 1;
    while(l < n){
        int r = l + 1;
        while(r < n && a[l].first == a[r].first) ++r;
        map<int, int> m;
        for(int i = l; i < r; ++i) ++m[a[i].second];
        for(auto p : m) d = mul(d, f[p.second]);
        l = r;
    }
    for(int i = 1; i < n; ++i) 
        if(a[i - 1].second > a[i].second) d = 0;

    res = sum(res, d);
    printf("%dn", res);
    return 0;
}                               
```
[1207E - XOR Guessing](../problems/E._XOR_Guessing.md "Educational Codeforces Round 71 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic"), [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1207E - XOR Guessing](../problems/E._XOR_Guessing.md "Educational Codeforces Round 71 (Rated for Div. 2)")

Suppose all integers we input in some query have the same value in the $k$-th bit. Then no matter which $i$ is chosen by the jury, we can always deduce whether the $k$-th bit in $x$ is $0$ or $1$.

This leads us to a simple solution: divide $14$ bits of $x$ into two groups of size $7$. In the first query, submit $100$ integers having the same values in the bits from the first group, and deduce the values of these bits in $x$. In the second query, do the same for the second group. Be careful to avoid submitting the same integer twice.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    cout << "?";
    for(int i = 1; i <= 100; i++)
        cout << " " << i;
    cout << endl;
    cout.flush();
    int res1;
    cin >> res1;
    cout << "?";
    for(int i = 1; i <= 100; i++)
        cout << " " << (i << 7);
    cout << endl;
    cout.flush();
    int res2;
    cin >> res2;
    int x = 0;
    x |= (res1 & (((1 << 7) - 1) << 7));
    x |= (res2 & ((1 << 7) - 1));
    cout << "! " << x << endl;
    cout.flush();
    return 0;
}
```
[1207F - Remainder Problem](../problems/F._Remainder_Problem.md "Educational Codeforces Round 71 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1207F - Remainder Problem](../problems/F._Remainder_Problem.md "Educational Codeforces Round 71 (Rated for Div. 2)")

Let's notice that if we process the queries of type $2$ naively, then each such query consumes $O(\frac{N}{x})$ time (where $N$ is the size of the array). So queries with large $x$ can be processed naively.

For queries with small $x$ ($x \le K$), we may notice two things:

* there are only $O(K^2)$ possible queries;
* each number in the array affects only $K$ possible queries.

So, for small $x$, we may maintain the exact answer for each query and modify it each time we modify an element in the array.

If we process naively all queries with $x > \sqrt{N}$ and maintain the answers for all queries with $x \le \sqrt{N}$, we will obtain a solution having time complexity $O(q \sqrt{N})$. Note that, as in most problems related to sqrt-heuristics, it may be optimal to choose the constant that is not exactly $\sqrt{N}$, but something similar to it (but most solutions should pass without tuning the constant).

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 500043;
const int K = 750;

int a[N];
int sum[K][K];

int main()
{
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);
        if(t == 1)
        {
            a[x] += y;
            for(int i = 1; i < K; i++)
                sum[i][x % i] += y;
        }
        else
        {
            if(x >= K)
            {
                int ans = 0;
                for(int i = y; i <= 500000; i += x)
                    ans += a[i];
                printf("%dn", ans);
            }
            else
                printf("%dn", sum[x][y]);
        }
    }
    return 0;
}
```
[1207G - Indie Album](../problems/G._Indie_Album.md "Educational Codeforces Round 71 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1207G - Indie Album](../problems/G._Indie_Album.md "Educational Codeforces Round 71 (Rated for Div. 2)")

There is a common approach for the problem "you are given a lot of strings and texts, count the number of occurences of the strings in the texts" — build an Aho-Corasick automaton on the given strings and somehow process the texts with it. Let's see if it can handle this problem.

The names of the songs can be represented as a tree. We may build an Aho-Corasick on the strings given in the queries, then try to input the names of the album into the automaton character-by-character with DFS on the aforementioned tree (feeding a character to the automaton when we enter a node, and reverting the automaton to the previous state when we leave that node). Suppose that when we are in the vertex corresponding to the $v$-th song, the automaton is in state $c$. If $c$ is a terminal state corresponding to some string from the queries, it means that the string from the query is a suffix of the $v$-th song. But some other strings can also be the suffixes of the same song — to find all such strings, we can start ascending from the state $c$ to the root of Aho-Corasick automaton using suffix links or dictionary links. Since suffix links can be represented as the edges of some rooted tree, then we can build some data structure on this tree that allows adding an integer to all vertices on the path from the root to the given vertex (for example, we can use Fenwick tree over Euler tour of the tree). Then, to check whether some string $t$ from the query is a suffix of the song $v$, we may add $1$ to all vertices on the path to state $c$, and then check the value in the state corresponding to $t$.

Okay, what about counting the occurences of $t$ in $v$? Let's consider the path from the root to $v$ in the "song tree". Every vertex on this path corresponds to some prefix of the song $v$, so we can add $1$ on the path to every state corresponding to some prefix, and then extract the answer from the state corresponding to $t$.

In fact, that's all we have to do to obtain a solution. Build an automaton on strings from queries, a tree of suffix links over this automaton, and a data structure on this tree; for each vertex of the song tree, store all queries to it. Then run a DFS on the song tree. When we enter some vertex, input the corresponding character into the automaton and add $1$ to all states from the root of suffix link tree to the current state; when we have to process queries to the current vertex, extract the values from the data structure; and when we leave a vertex, subtract $1$ from all states from the root of suffix link tree to the current state, and revert to the previous state.

This solution has complexity of $O(T \log T)$, where $T$ is the total length of all strings in the input.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int AL = 26;
const int N = 400 * 1000 + 13;

struct node{
    int nxt[AL];
    node(){
        memset(nxt, -1, sizeof(nxt));
    }
    int& operator [](int x){
        return nxt[x];
    }
};

struct node_at{
    int nxt[AL];
    int p;
    char pch;
    int link;
    int go[AL];
    node_at(){
        memset(nxt, -1, sizeof(nxt));
        memset(go, -1, sizeof(go));
        link = p = -1;
    }
    int& operator [](int x){
        return nxt[x];
    }
};

int cntnm;
node trienm[N];

int cntqr;
node_at trieqr[N];

int add_string(string s){
    int v = 0;
    for (auto it : s){
        int c = it - 'a';
        if (trieqr[v][c] == -1){
            trieqr[cntqr] = node_at();
            trieqr[cntqr].p = v;
            trieqr[cntqr].pch = c;
            trieqr[v][c] = cntqr;
            ++cntqr;
        }
        v = trieqr[v][c];
    }
    return v;
}

int go(int v, int c);
 
int get_link(int v){
    if (trieqr[v].link == -1){
        if (v == 0 || trieqr[v].p == 0)
            trieqr[v].link = 0;
        else
            trieqr[v].link = go(get_link(trieqr[v].p), trieqr[v].pch);
    }
    return trieqr[v].link;
}
 
int go(int v, int c) {
    if (trieqr[v].go[c] == -1){
        if (trieqr[v][c] != -1)
            trieqr[v].go[c] = trieqr[v][c];
        else
            trieqr[v].go[c] = (v == 0 ? 0 : go(get_link(v), c));
    }
    return trieqr[v].go[c];
}

int add_letter(int v, int c){
    if (trienm[v][c] == -1){
        trienm[cntnm] = node();
        trienm[v][c] = cntnm;
        ++cntnm;
    }
    return trienm[v][c];
}

vector<int> g[N];
int tin[N], tout[N], T;

void dfs_init(int v){
    tin[v] = T++;
    for (auto u : g[v])
        dfs_init(u);
    tout[v] = T;
}

int f[N];

void upd(int v, int val){
    for (int i = tin[v]; i < N; i |= i + 1)
        f[i] += val;
}

int get(int x){
    int sum = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        sum += f[i];
    return sum;
}

int sum(int v){
    return get(tout[v] - 1) - get(tin[v] - 1);
}

int n, m;
int nm[N], qr[N];
vector<int> nms[N];
vector<int> reqs[N];
int ans[N];

void dfs(int v, int cur){
    upd(cur, 1);
    for (auto it : nms[v])
        for (auto q : reqs[it])
            ans[q] = sum(qr[q]);
    forn(i, AL) if (trienm[v][i] != -1)
        dfs(trienm[v][i], go(cur, i));
    upd(cur, -1);
}

int main(){
    cntqr = 0;
    trieqr[cntqr++] = node_at();
    
    cntnm = 0;
    trienm[cntnm++] = node();
    
    char buf[N];
    scanf("%d", &n);
    forn(i, n){
        int t;
        scanf("%d", &t);
        if (t == 1){
            scanf("%s", buf);
            nm[i] = add_letter(0, buf[0] - 'a');
        }
        else{
            int j;
            scanf("%d%s", &j, buf);
            --j;
            nm[i] = add_letter(nm[j], buf[0] - 'a');
        }
        nms[nm[i]].push_back(i);
    }
    
    scanf("%d", &m);
    forn(i, m){
        int j;
        scanf("%d%s", &j, buf);
        --j;
        reqs[j].push_back(i);
        qr[i] = add_string(buf);
    }
    
    for (int v = 1; v < cntqr; ++v)
        g[get_link(v)].push_back(v);
    
    T = 0;
    dfs_init(0);
    dfs(0, 0);
    
    forn(i, m)
        printf("%dn", ans[i]);
}
```
