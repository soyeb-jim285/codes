# Tutorial_2

[1400A - String Similarity](../problems/A._String_Similarity.md "Educational Codeforces Round 94 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1400A - String Similarity](../problems/A._String_Similarity.md "Educational Codeforces Round 94 (Rated for Div. 2)")

There are many ways to solve this problem:

* let the answer be $s_1 s_3 s_5 \dots s_{2n-1}$, so it coincides with $s[1..n]$ in the first character, with $s[2..n+1]$ in the second character, and so on;
* copy the character $s_n$ $n$ times, since it appears in every substring we are interested in;
* find the character that occurs at least $n$ times in $s$, and build the answer by copying it $n$ times;
* and many others.
 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val c = readLine()!!.groupingBy { it }.eachCount().maxBy { it.value }!!.key
        println(c.toString().repeat(n))
    }
}
```
[1400B - RPG Protagonist](../problems/B._RPG_Protagonist.md "Educational Codeforces Round 94 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1400B - RPG Protagonist](../problems/B._RPG_Protagonist.md "Educational Codeforces Round 94 (Rated for Div. 2)")

Let's say (without loss of generality) that $s \le w$ (a sword is lighter than a war axe). If not, then we can swap swords and axes.

Now, let's iterate over the number of swords $s_1$ we will take ourselves. We can take at least $0$ and at most $\min(cnt_s, \frac{p}{s})$ swords.

If we have taken $s_1$ swords, then we can fill the remaining capacity with axes, i. e. we can take $w_1 = \min(cnt_w, \frac{p - s_1 \cdot s}{w})$ axes.

The last thing is to decide, what the follower will take: since swords are lighter, it's optimal to take as many swords as possible, i. e. to take $s_2 = \min(cnt_s - s_1, \frac{f}{s})$ swords and fill the remaining space with war axes, i. e. to take $w_2 = \min(cnt_w - w_1, \frac{f - s_2 \cdot s}{w})$ axes.

In other words, if we fix the number of swords $s_1$ we'll take $s_1 + s_2 + w_1 + w_2$ weapons in total.

The result complexity is $O(cnt_s)$.

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val (p, f) = readLine()!!.split(' ').map { it.toInt() }
        var (cntS, cntW) = readLine()!!.split(' ').map { it.toInt() }
        var (s, w) = readLine()!!.split(' ').map { it.toInt() }
        
        if (s > w) {
            s = w.also { w = s }
            cntS = cntW.also { cntW = cntS }
        }

        var ans = 0
        for (s1 in 0..minOf((p / s), cntS)) {
            val w1 = minOf(cntW, (p - s * s1) / w)
            val s2 = minOf(cntS - s1, f / s)
            val w2 = minOf(cntW - w1, (f - s * s2) / w)
            ans = maxOf(ans, s1 + s2 + w1 + w2)
        }
        println(ans)
    }
}
```
[1400C - Binary String Reconstruction](../problems/C._Binary_String_Reconstruction.md "Educational Codeforces Round 94 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1400C - Binary String Reconstruction](../problems/C._Binary_String_Reconstruction.md "Educational Codeforces Round 94 (Rated for Div. 2)")

At first, let's replace all elements of string $w$ by 1.

Now, let's consider all indices $i$ such that $s_i = 0$. If $s_i = 0$, then $w_{i - x}$ must be equal to 0 (if it exists) and $w_{i + x}$ must be equal to 0 (if it exists), so let's replace all such elements by 0.

And after let's perform the process described in statement on string $w$. If we get the string $s$, then we can print $w$ as the answer, otherwise the answer is $-1$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int t;
string s;
int x;

string f(string s) {
    string res = s;
    for (int i = 0; i < s.size(); ++i) {
        if (i - x >= 0 && s[i - x] == '1' || i + x < s.size() && s[i + x] == '1')
            res[i] = '1';
        else
            res[i] = '0';
    }
    return res;
}

int main() {    
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        cin >> s >> x;
        int n = s.size();
 
        string ns = string(n, '1');
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (i - x >= 0) ns[i - x] = '0';
                if (i + x < n) ns[i + x] = '0';
            }
        }
        if (f(ns) == s) cout << ns << endl;
        else cout << -1 << endl;
    }
    return 0;
}
```
[1400D - Zigzags](../problems/D._Zigzags.md "Educational Codeforces Round 94 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1400D - Zigzags](../problems/D._Zigzags.md "Educational Codeforces Round 94 (Rated for Div. 2)")

Let's iterate indices $j$ and $k$. For simplicity, for each $j$ we'll iterate $k$ in descending order.

To calculate the number of tuples for a fixed $(j, k)$ we just need the number of $i < j$ such that $a_i = a_k$ and the number of $l > k$ with $a_l = a_j$. We can maintain both values in two frequency arrays $cntLeft$ and $cntRight$, where $cntLeft[x]$ ($cntRight[x]$) is the number of $a_i = x$ for $i < j$ ($i > k$). It's easy to update $cntLeft$ ($cntRight$) when moving $j$ to $j + 1$ ($k$ to $k - 1$).

The time complexity is $O(n^2)$.

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() - 1 }.toIntArray()

        val cntLeft = IntArray(n) { 0 }
        val cntRight = IntArray(n) { 0 }

        var ans = 0L
        for (j in a.indices) {
            cntRight.fill(0)
            for (k in n - 1 downTo j + 1) {
                ans += cntLeft[a[k]] * cntRight[a[j]]
                cntRight[a[k]]++
            }
            cntLeft[a[j]]++
        }
        println(ans)
    }
}
```
[1400E - Clear the Multiset](../problems/E._Clear_the_Multiset.md "Educational Codeforces Round 94 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1400E - Clear the Multiset](../problems/E._Clear_the_Multiset.md "Educational Codeforces Round 94 (Rated for Div. 2)")

Let's solve the problem by dynamic programing. Let $dp_{i, j}$ be the minimum number of operations to delete all elements from $1$ to $i$, if we have $j$ "unclosed" operations of the first type. In each transition, we either advance to the right (and possibly "close" some operations of the second type, so we go from $dp_{i, j}$ to $dp_{i + 1, \min(a_{i + 1}, j)}$, adding $1$ to the answer if $j < a_{i + 1}$), or "open" a new operation of the second type (so we go from $dp_{i, j}$ to $dp_{i, j + 1}$, adding $1$ to the answer). This solution runs in $O(nA)$, which is too slow.

The observation that helps us to speed this up is that we have to use only values from the array $a$ as the second state of our dynamic programming. Let's prove it.

The proof begins here

Let's call an integer $i$ saturated if all occurrences of $i$ were deleted by operations of the first type. Also, let's denote $c_i$ as the number of elements equal to $i$ deleted by the operations of the first type (so, $i$ is saturated iff $a_i = c_i$).

Suppose $k$ is the minimum integer such that $c_k$ is not a value from the array $a$. Obviously, $k$ is not saturated. Since the number of operations of the first type covering some integer decreases only when we have to close them, it always decreases to some number in $a$, so it is impossible that $c_{k - 1} > c_k$. It is also impossible that $c_{k - 1} = c_k$, since $k$ is the minimum integer such that $c_k$ does not belong to array $a$. So, $c_{k - 1} < c_k$, it means that some number of operations of the first type started in integer $k$. We can either get rid of them altogether (if they end in $k$ as well), or shift them to $k + 1$, so $c_k$ belongs to the array $a$. That way, if in the optimal answer some value $c_k$ does not belong to $a$, we can reconstruct it so it is no longer the case.

The proof ends here

Overall, since we have only up $n$ disctict values of $j$, the solution runs in $O(n^2)$ (though it is possible to solve the problem faster).

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(5e3) + 9;

int n;
int a[N];
int dp[N][N];

int calc (int pos, int x) {
    int &res = dp[pos][x];
    if (res != -1) return res;
    
    if (pos == n) return res = 0;
    res = 1 + calc(pos + 1, n);
    res = min(res, calc(pos + 1, pos) + a[pos]);
    if (x != n) {
        if (a[x] >= a[pos])
            res = min(res, calc(pos + 1, pos));
        else {
            res = min(res, calc(pos + 1, pos) + a[pos] - a[x]);
            res = min(res, 1 + calc(pos + 1, x));
        }
    }
    
    return res;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    memset(dp, -1, sizeof(dp));       
    printf("%dn", calc(0, n));
    
    return 0;
}
```
[1400F - x-prime Substrings](../problems/F._x-prime_Substrings.md "Educational Codeforces Round 94 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest") and [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1400F - x-prime Substrings](../problems/F._x-prime_Substrings.md "Educational Codeforces Round 94 (Rated for Div. 2)")

The number of $x$-prime strings is relatively small, so is their total length (you may bruteforce all of them and check that the total length of $x$-prime strings never exceeds $5000$, we will need that bruteforce in the solution). Now we have the following problem: given a set of strings with total length up to $5000$ and a string with length up to $1000$, erase the minimum number of characters from that string so no string from the set appears there as a substring.

You may have already encountered the similar problem in some previous contests. The solution to this problem is dynamic programming — let $dp[x][y]$ be the minimum number of characters to erase, if we considered first $x$ characters, there were no occurrences of strings from the set in the resulting string... and the second state of dynamic programming ($y$) is a bit more complicated. We want to make sure that no string appears in the result as a substring, so $y$ should somehow handle that. Let $y$ be the longest suffix of the current string that coincides with some prefix of a string from the set. If some string from the set is a suffix of $y$, then the state is clearly bad — we have an occurrence of an $x$-prime string. Otherwise, there is no occurrence ending in the last character, since we considered the longest possible suffix that matches some prefix from the set. The transitions in $dp$ are the following — we either take the next character and recalculate $y$, or skip the next character and add $1$ to the number of removed characters.

If we maintain and recalculate $y$ naively, as a string, the solution will be too slow. There are only up to $5000$ different values of $y$, but their total length may be much greater, so we don't even have enough memory to store our dynamic programming values. Let's enumerate all strings that are prefixes of some $x$-prime string and map each of these strings to some integer, so the second state in dynamic programming can be an integer instead of a string. Then we have to mark the bad integers (which correspond to strings having some $x$-prime string as a suffix) and calculate the two-dimensional transition matrix $T$, where $T[x][a]$ is the integer corresponding to a string that we get, if we append the $x$-th string with character $a$, so the transitions in dynamic programming can be done in $O(1)$. There are many ways to precalculate this matrix and mark all of the bad integers, but the most efficient one is to use Aho-Corasick algorithm (the transition matrix $T$ is exactly the automaton that the Aho-Corasick algorithm builds). If you are not familiar with it, I recommend you to read about it here: [https://cp-algorithms.com/string/aho_corasick.html](https://codeforces.com/https://cp-algorithms.com/string/aho_corasick.html)

 **Solution (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int AL = 9;
const int N = 5000;
const int INF = 1e9;

string s;
int x;

struct node{
    int nxt[AL];
    int p;
    char pch;
    int link;
    int go[AL];
    bool term;
    node(){
        memset(nxt, -1, sizeof(nxt));
        memset(go, -1, sizeof(go));
        link = p = -1;
        term = false;
    }
    int& operator [](int x){
        return nxt[x];
    }
};

vector<node> trie;

void add_string(string s){
    int v = 0;
    for (auto it : s){
        int c = it - '1';
        if (trie[v][c] == -1){
            trie.push_back(node());
            trie[trie.size() - 1].p = v;
            trie[trie.size() - 1].pch = c;
            trie[v][c] = trie.size() - 1;
        }
        v = trie[v][c];
    }
    trie[v].term = true;
}

int go(int v, int c);
 
int get_link(int v){
    if (trie[v].link == -1){
        if (v == 0 || trie[v].p == 0)
            trie[v].link = 0;
        else
            trie[v].link = go(get_link(trie[v].p), trie[v].pch);
    }
    return trie[v].link;
}
 
int go(int v, int c) {
    if (trie[v].go[c] == -1){
        if (trie[v][c] != -1)
            trie[v].go[c] = trie[v][c];
        else
            trie[v].go[c] = (v == 0 ? 0 : go(get_link(v), c));
    }
    return trie[v].go[c];
}

string t;

void brute(int i, int sum){
    if (sum == x){
        bool ok = true;
        for (int l = 0; l < int(t.size()); ++l){
            int cur = 0;
            for (int r = l; r < int(t.size()); ++r){
                cur += (t[r] - '0');
                if (x % cur == 0 && cur != x)
                    ok = false;
            }
        }
        if (ok){
            add_string(t);
        }
        return;
    }
    for (int j = 1; j <= min(x - sum, 9); ++j){
        t += '0' + j;
        brute(i + 1, sum + j);
        t.pop_back();
    }
}

int main() {
    cin >> s >> x;
    trie.push_back(node());
    brute(0, 0);
    vector<vector<int>> dp(s.size() + 1, vector<int>(trie.size(), INF));
    dp[0][0] = 0;
    forn(i, s.size()) forn(j, trie.size()) if (dp[i][j] != INF){
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
        int nxt = go(j, s[i] - '1');
        if (!trie[nxt].term)
            dp[i + 1][nxt] = min(dp[i + 1][nxt], dp[i][j]);
    }
    printf("%dn", *min_element(dp[s.size()].begin(), dp[s.size()].end()));
    return 0;
}
```
[1400G - Mercenaries](../problems/G._Mercenaries.md "Educational Codeforces Round 94 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest") and [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1400G - Mercenaries](../problems/G._Mercenaries.md "Educational Codeforces Round 94 (Rated for Div. 2)")

We will use inclusion-exclusion formula to solve this problem (you may read about it here: [https://cp-algorithms.com/combinatorics/inclusion-exclusion.html](https://codeforces.com/https://cp-algorithms.com/combinatorics/inclusion-exclusion.html)). To put it simply, we are going to count the number of subsets that meet the restrictions on $[l_i, r_i]$, ignoring the edges (I'll call the pairs of mercenaries that hate each other "edges" for simplicity). This number is not the answer, since we counted some subsets that violate the conditions for the edges — so, for each edge, we count the number of subsets that violate the condition on that edge, and subtract it from the answer. But it means that if a subset violates the conditions on multiple edges, we subtracted it multiple times, so, for each pair of edges, we count the subsets that violate both edges in that pair and add them back, then remove the subsets violating the triples, and so on. The mathematical formula for the answer is $\sum \limits_{E \in S} f(E)$, where $S$ is the set containing all $2^m$ subsets of edges, and $f(E)$ is the number of subsets that meet the constraints on $[l_i, r_i]$, and violate the constraints for every edge $e \in E$.

Now we have to calculate $f(E)$ efficiently, since the outer loop already runs in $O(2^m)$. If we have to violate a set of edges, then we have a set of mercenaries that we should take (the "endpoints" of the edges), and the number of those mercenaries (let's denote it as $k$) is up to $40$. The size of the subset should meet the constraints on $[l_i, r_i]$ for each of those mercenaries, so let's intersect the segments $[l_i, r_i]$ for them (and if the intersection is empty, then there are no subsets that violate all of those edges). Let the intersection of those segments be $[L, R]$. The naive solution would be to iterate on the size of the subset and calculate the number of ways to compose a subset that contains some fixed mercenaries of given size (if the size is $s$, and $c_s$ is the number of mercenaries that are willing to be in a subset of size $s$, then we have to add ${{c_s - k} \choose {s - k}}$ to the answer). So, for each subset $E$, $f(E) = \sum \limits_{s = L}^{R} {{c_s - k} \choose {s - k}}$. This sum can be calculated in $O(1)$ as follows: note that $k$ is up to $40$, so for every possible value of $k$, precalculate the array of prefix sums of those binomial coefficients. This precalculation runs in $O(nm + n \log MOD)$, and each $f(E)$ can be calculated in $O(m \log m)$, so overall the complexity is $O(nm + n \log MOD + 2^m m \log m)$.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 300043;
const int MOD = 998244353;

int add(int x, int y)
{
    return ((x + y) % MOD + MOD) % MOD;
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
        if(y % 2 == 1)
            z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int fact[N];
int rfact[N];

void prepare_fact()
{
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = mul(i, fact[i - 1]);
    for(int i = 0; i < N; i++)
        rfact[i] = inv(fact[i]);
}

int c(int n, int k)
{
    if(n < 0 || n < k || k < 0)
        return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> l(n), r(n), a(m), b(m);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &l[i], &r[i]);
    for(int i = 0; i < m; i++)
        scanf("%d %d", &a[i], &b[i]);
    vector<int> cnt(n + 2);
    for(int i = 0; i < n; i++)
    {
        cnt[l[i]]++;
        cnt[r[i] + 1]--;
    }
    for(int i = 0; i < n + 1; i++)
        cnt[i + 1] += cnt[i];
    prepare_fact();
    vector<vector<int> > p(2 * m + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= 2 * m; j++)
            p[j][i] = add(p[j][i - 1], c(cnt[i] - j, i - j));
    int ans = 0;
    for(int mask = 0; mask < (1 << m); mask++)
    {
        int sign = 1;
        set<int> used;
        for(int i = 0; i < m; i++)
            if(mask & (1 << i))
            {
                sign = mul(sign, MOD - 1);
                used.insert(a[i] - 1);
                used.insert(b[i] - 1);
            }
        int L = 1, R = n;
        for(auto x : used)
        {
            L = max(L, l[x]);
            R = min(R, r[x]);
        }
        if(R < L) continue;
        ans = add(ans, mul(sign, add(p[used.size()][R], -p[used.size()][L - 1])));
    }
    printf("%dn", ans);
}
```
