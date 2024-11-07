# Tutorial

[1511A - Review Site](../problems/A._Review_Site.md "Educational Codeforces Round 107 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1511A - Review Site](../problems/A._Review_Site.md "Educational Codeforces Round 107 (Rated for Div. 2)")

Notice that the answer depends only on the number of the reviewers of the third type who upvote the movie. Optimally we would want every single reviewer of the third type to upvote. We can achieve it with the following construction: send all reviewers of the first type to the first server, all reviewers of the second type to the second server and all reviewers of the third type to the first server. Since there are no downvotes on the first server, all reviewers of the third type will upvote.

Thus, the answer is the total number of reviewers of the first and the third type.

Overall complexity: $O(n)$ per testcase.

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()!!.toInt()
        println(readLine()!!.split(' ').count { it != "2" })
    }
}
```
[1511B - GCD Length](../problems/B._GCD_Length.md "Educational Codeforces Round 107 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1511B - GCD Length](../problems/B._GCD_Length.md "Educational Codeforces Round 107 (Rated for Div. 2)")

The easiest way to force some gcd to be of some fixed length is to use the divisibility rules for $2$, $5$ or $10$: if the number produced by the last $y$ digits $x$ is divisible by $2^y$, then $x$ is also divisible by $2^y$ (same goes for $5^y$ and $10^y$).

One of the possible constructions is the following: let $x=1\underbrace{0..0}_{a-c}\underbrace{0..0}_{c-1}$ and $y=1\underbrace{1..1}_{b-c}\underbrace{0..0}_{c-1}$. Since $10..0$ and $11..1$ are pairwise prime, gcd is $10^{c-1}$.

Overall complexity: $O(1)$ per testcase.

 **Solution (awoo)**
```cpp
for t in range(int(input())):
	a, b, c = map(int, input().split())
	print("1" + "0" * (a - 1), "1" * (b - c + 1) + "0" * (c - 1))
```
[1511C - Yet Another Card Deck](../problems/C._Yet_Another_Card_Deck.md "Educational Codeforces Round 107 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1511C - Yet Another Card Deck](../problems/C._Yet_Another_Card_Deck.md "Educational Codeforces Round 107 (Rated for Div. 2)")

Let's look at one fixed color. When we search a card of such color, we take the card with minimum index and after we place it on the top of the deck it remains the one with minimum index.

It means that for each color we take and move the same card — one card for each color. In other words, we need to keep track of only $k$ cards, where $k$ is the number of colors ($k \le 50$). As a result, if $pos_c$ is the position of a card of color $c$ then we can simulate a query in the following way: for each color $c$ such that $pos_c < pos_{t_j}$ we increase $pos_c$ by one (since the card will move down) and then set $pos_{t_j} = 1$. Complexity is $O(n + qk)$.

But, if we look closely, we may note that we don't even need array $pos_c$. We can almost manually find the first card of color $t_j$ and move it to the first position either by series of swaps or, for example, using rotate function (present in C++) and it will work fast.

Why? Let's look at one color $c$. For the first time it will cost $O(n)$ operations to search the corresponding card and move it to the position $1$. But after that, at any moment of time, the position of the card won't exceed $k$, since all cards before are pairwise different (due to the nature of queries). So, all next moves the color $c$ costs only $O(k)$ time.

As a result, the complexity of such almost naive solution is $O(kn + qk)$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector<int> a(n);
  for (int& x : a) scanf("%d", &x);
  while (q--) {
    int x;
    scanf("%d", &x);
    int p = find(a.begin(), a.end(), x) - a.begin();
    printf("%d ", p + 1);
    rotate(a.begin(), a.begin() + p, a.begin() + p + 1);
  }
}
```
[1511D - Min Cost String](../problems/D._Min_Cost_String.md "Educational Codeforces Round 107 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1511D - Min Cost String](../problems/D._Min_Cost_String.md "Educational Codeforces Round 107 (Rated for Div. 2)")

Consider all possible strings of length $2$ on the alphabet of size $k$ (there are $k^2$ of them). Let $cnt_i$ be the number of occurrences of the $i$-th of them in the string $s$. The cost of the string $s$ by definition is $\sum \limits_{i} \frac{cnt_i(cnt_i - 1)}{2}$. Now, let's suppose there are two strings $i$ and $j$ such that $cnt_i - cnt_j \ge 2$. Then, if we somehow reduce the number of occurrences of the string $i$ by $1$ and increase the number of occurrences of the string $j$ by $1$, the cost will decrease. So, in the optimal answer all the strings of length $2$ should appear the same number of times (and if it's impossible, the difference in the number of appearances should not be greater than $1$).

Let's suppose that $k^2 = n - 1$, then our goal is to build a string where each string of length $2$ on the alphabet of $k$ characters appears exactly once. The construction of this string can be modeled using Eulerian cycles: build a directed graph with $k$ vertices, where each vertex represents a character, each arc represents a string of length $2$, and for every pair of vertices $(i, j)$, there is an arc from $i$ to $j$ (it's possible that $i = j$!). Then, by finding the Eulerian cycle in this graph (it always exists since the graph is strongly connected and, for each vertex, its in-degree is equal to its out-degree), we find a string of length $k^2 + 1$ such that all its substrings are different (so each string of length $2$ appears there once as a substring).

Okay, what about the cases $k^2 > n - 1$ and $k^2 < n - 1$? Since the string we build for the case $k^2 = n - 1$ represents a cycle, we can make it "cyclical" and repeat the required number of times, then cut last several characters if it's too big. For example, if $n = 8$, $k = 2$, then the string for $k = 2$ is abbaa (it's not the only one, but we can use it). We can expand this string to abbaabbaa (by repeating the last $k^2$ characters), and delete the last character so its length is $8$.

By the way, in this problem, you don't have to implement the algorithm that finds Eulerian cycles. The graph where we want to find the Eulerian cycle has a very special structure, and there are many different constructive ways to find the cycle in it. But if you can't use them, you always can rely on the straightforward solution that explicitly searches for the Eulerian cycle.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n, k;
int cur[26];
vector<int> path;

void dfs(int v) {
  while (cur[v] < k) {
    int u = cur[v]++;
    dfs(u);
    path.push_back(u);
  }
}

int main() {
  scanf("%d%d", &n, &k);
  dfs(0);
  printf("a");
  for (int i = 0; i < n - 1; ++i)
    printf("%c", path[i % path.size()] + 'a');
}
```
[1511E - Colorings and Dominoes](../problems/E._Colorings_and_Dominoes.md "Educational Codeforces Round 107 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1511E - Colorings and Dominoes](../problems/E._Colorings_and_Dominoes.md "Educational Codeforces Round 107 (Rated for Div. 2)")

There are different solutions to this problem involving combinatorics and/or dynamic programming, but, in my opinion, it's a bit easier to look at the problem from the perspective of probability theory.

Let's suppose a coloring is already chosen. Then it can be covered with dominoes greedily: red and blue cells are independent from each other, and, for example, red cells can be analyzed as a set of "strips" of them of different length. Let's say that we cover each "strip" from left to right, so, in each "strip", the first domino covers the cells $1$ and $2$, the second domino — the cells $3$ and $4$, and so on.

Let's calculate the average value of the coloring, that is, the expected value of the coloring if it is chosen randomly. Let it be $E$, then the answer is $2^w E$.

By linearity of expectation, $E$ can be calculated as $\sum\limits_{d \in D} p_d$, where $D$ is the set of all places we can use for a domino, and $p_d$ is the probability that there is a domino in place $d$ in our domino covering (which we construct greedily). Each domino covers two adjacent cells, so we can iterate on pairs of adjacent cells, and for each pair, find the probability that this pair is covered. Let's suppose that we want to cover the cells $(x, y)$ and $(x, y + 1)$ with a domino. Then:

* both of these cells should be red;
* the length of the red "strip" before these cells should be even (otherwise the cell $(x, y)$ will be paired with the cell $(x, y - 1)$).

The only thing we need to know in order to calculate the probability of these two conditions being true is the number of white cells before the cell $(x, y)$ — which can be easily maintained. Knowing the number of white cells before $(x, y)$, we can either use dynamic programming to calculate the required probability, or do the math on several easy examples and try to notice the pattern:

* if there are $0$ white cells before the current one, the probability of that pair being covered with a domino (let's call it $P_0$) is $\frac{1}{4}$ (both these cells should be red);
* if there is $1$ white cell before the current one, the probability of that pair being covered with a domino (let's call it $P_1$) is $\frac{1}{4} - \frac{1}{8}$ (the cells $(x, y)$ and $(x, y + 1)$ should be red, but the cell before them should not be red);
* $P_2$ is $\frac{1}{4} - \frac{1}{8} + \frac{1}{16}$ (either the chosen two cells are red and the cell before them is not red, or all four cells are red);
* $P_3$ is $\frac{1}{4} - \frac{1}{8} + \frac{1}{16} - \frac{1}{32}$, and so on.

So, knowing the number of white cells before $(x, y)$ and $(x, y + 1)$, we easily calculate the probability of this pair being covered by a domino. By summing up the probabilities over all pairs of adjacent white cells (don't forget the vertical ones!), we get the average (or expected) value of the coloring. All that's left is to multiply it by $2^w$.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 300043;
const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while(x >= MOD)
        x -= MOD;
    while(x < 0)
        x += MOD;
    return x;                         
}

int sub(int x, int y)
{
    return add(x, MOD - y);
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

int divide(int x, int y)
{
    return mul(x, inv(y));
}

string s[N];
int p[N];
int n, m;
char buf[N];

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", buf);
        s[i] = buf;
    }
    p[0] = divide(1, 2);
    for(int i = 1; i < N; i++)
        if(i % 2 == 1)
            p[i] = sub(p[i - 1], divide(1, binpow(2, i)));
        else
            p[i] = add(p[i - 1], divide(1, binpow(2, i)));
    int ans = 0;
    int w = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(s[i][j] != '*')
                w = add(w, 1);
    for(int i = 0; i < n; i++)
    {
        int c = 0;
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == '*')
                c = 0;
            else
                c++;
            if(c > 0)
                ans = add(ans, p[c]);
        }
    }
    for(int j = 0; j < m; j++)
    {
        int c = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i][j] == '*')
                c = 0;
            else
                c++;
            if(c > 0)
                ans = add(ans, p[c]);
        }
    }
    ans = mul(ans, binpow(2, w));
    cout << ans << endl;
}
```
[1511F - Chainword](../problems/F._Chainword.md "Educational Codeforces Round 107 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1511F - Chainword](../problems/F._Chainword.md "Educational Codeforces Round 107 (Rated for Div. 2)")

Let's use a trie to store the given words. Now let's imagine a procedure that checks if some string of length $m$ can be represented as a concatenation of some of these words. If the words were prefix-independent — no word was a prefix of another word, that task would be solvable with a greedy algorithm.

We could iterate over a string and maintain the current vertex of the trie we are in. Append a current letter. If there is no such transition in a trie, it can't be represented. If the vertex we go to is a terminal, jump to the root of the trie. Otherwise, just go to that vertex. 

However, since the words aren't prefix-independent, we have a terminal on a path to other terminals. Thus, we can't immediately decide if we should jump to the root or just go.

Let's handle this with dynamic programming. $dp[i][v]$ — can we put $i$ letters in such a way that the vertex of a trie we are in is $v$.

Is building a chainword letter by letter that different from this process? Apparently, it isn't. Consider $dp[i][v][u]$ — how many ways are there to put $i$ letters in a string so that the first hint is in a vertex $v$ and the second hint is in a vertex $u$. For the transition we can try all $26$ letters to put and jump to the corresponding vertices.

That obviously, is too slow. The intuition tells us that this dp should be calculated with some kind of matrix exponentiation (since $m \le 10^9$). That dp can be rewritten as a matrix pretty easily. However, its size is up to $1681 \times 1681$ (the maximum number of vertices in a trie squared).

Some say that there is a way to compute the $m$-th power of such a huge matrix fast enough with Berlekamp–Massey, but I unfortunately am not familiar with it.

Thus, we'll have to reduce the size of our matrix. First, notice that the only reachable states $(v, u)$ are such that the word that is written on a path from the root to $v$ is a suffix of a word that is written on a path from the root to $u$ or vice versa.

Look at it the other way: if we build a trie on the reversed words, then one of the vertices will be an ancestor of another one. Now it's easy to estimate the number of states as the sum of depths of all vertices. However, since we look at ordered pairs of $(v, u)$, we should more or less double that amount. That should be $241$ states at max.

This can probably pass with an optimal enough implementation. We can do better, though. Let's merge the states $(v, u)$ and $(u, v)$ into one state. The intuition is basically that you can swap the hints at will. That makes the pairs unordered: now there are up to $161$ pairs. That surely will work fast enough.

The way to generate all the possible states is the following: run a dfs/bfs, starting from $(0, 0)$ that makes all valid transition and record all the states that can be visited.

While preparing the tests, I only managed to get up to $102$ states and I would really love to hear an approach to either prove a tighter bound or to generate a test closer to the bound of $161$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int MOD = 998244353;
const int K = 161;
const int AL = 26;

struct node{
	int nxt[AL];
	bool term;
	node(){
		memset(nxt, -1, sizeof(nxt));
		term = false;
	};
	int& operator [](const int x){
		return nxt[x];
	}
};

vector<node> trie;

int tot;

void add(const string &s){
	int cur = 0;
	int d = 1;
	for (const char &c : s){
		++d;
		if (trie[cur][c - 'a'] == -1){
			trie[cur][c - 'a'] = trie.size();
			trie.push_back(node());
			tot += d;
		}
		cur = trie[cur][c - 'a'];
	}
	trie[cur].term = true;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int mul(int a, int b){
	return a * 1ll * b % MOD;
}

typedef array<array<int, K>, K> mat;

mat operator *(const mat &a, const mat &b){
	mat c;
	forn(i, K) forn(j, K) c[i][j] = 0;
	forn(i, K) forn(j, K) forn(k, K)
		c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
	return c;
}

mat binpow(mat a, long long b){
	mat res;
	forn(i, K) forn(j, K) res[i][j] = i == j;
	while (b){
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

map<pair<int, int>, int> num;
queue<pair<int, int>> q;

int get(int v, int u){
	if (v > u) swap(v, u);
	if (!num.count({v, u})){
		int k = num.size();
		assert(k < K);
		num[{v, u}] = k;
		q.push({v, u});
	}
	return num[{v, u}];
}

int main() {
	int n;
	long long m;
	cin >> n >> m;
	trie = vector<node>(1, node());
	tot = 1;
	forn(i, n){
		string s;
		cin >> s;
		add(s);
	}
	q.push({0, 0});
	num[q.front()] = 0;
	mat init;
	forn(i, K) forn(j, K) init[i][j] = 0;
	while (!q.empty()){
		int v = q.front().first;
		int u = q.front().second;
		q.pop();
		int x = get(v, u);
		forn(c, AL){
			int tov = trie[v][c];
			int tou = trie[u][c];
			if (tov == -1 || tou == -1) continue;
			++init[x][get(tov, tou)];
			if (trie[tov].term) ++init[x][get(0, tou)];
			if (trie[tou].term) ++init[x][get(tov, 0)];
			if (trie[tov].term && trie[tou].term) ++init[x][0];
		}
	}
	init = binpow(init, m);
	printf("%dn", init[0][0]);
	return 0;
}
```
[1511G - Chips on a Board](../problems/G._Chips_on_a_Board.md "Educational Codeforces Round 107 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1511G - Chips on a Board](../problems/G._Chips_on_a_Board.md "Educational Codeforces Round 107 (Rated for Div. 2)")

The model solution is $O(N \sqrt{N \log N})$, where $N = \max(n, m, q)$, but it seems that there are faster ones. I'll explain the model solution nevertheless.

It's easy to see (using simple Nim theory) that the answer for a query $i$ is B iff the xor of $c_j - L_i$ for all chips such that $L_i \le c_j \le R_i$ is equal to $0$. Let's calculate this xor for every query. This number contains at most $18$ bits, and we will process these bits differently: we will choose some number $K$ and use one solution to calculate $K$ lowest bits, and another solution to compute $18 - K$ highest bits. One idea is common in both solutions: we split each query into two queries — a query $(L_i, R_i)$ can be represented as a combination of two queries $Q(L_i, L_i)$ and $Q(R_i + 1, L_i)$, where $Q(x, y)$ is the xor of all numbers $c_j - y$ such that $c_j \ge x$. After converting the queries, for every $x \in [1, m]$, store each query of the form $Q(x, y)$ in some sort of vector (or any other data structure). We will use an approach similar to sweep line: iterate on $x$ and solve the queries for the current $x$. These ideas will be used both for the solution calculating $K$ lowest bits and for the solution calculating $18 - K$ highest bits.

How to find $K$ lowest bits in each query? Iterate on $x$ from $m$ to $1$ and maintain the number of occurrences of each number $c_i$ we met so far. Then, at a moment we want to calculate $Q(x, y)$, simply iterate on all of the values of $c_i$ and process each value in $O(1)$ (if the number of occurrences of some value $z$ is odd, update the current answer to the query by xoring the number with $z - y$, otherwise just skip it). And since we are interested only in $K$ lowest bits, for each $c_i$, we need only the remainder $c_i \mod 2^K$, so the number of different values is $O(2^K)$. Thus, this part of the solution runs in $O(n + m + 2^Kq)$.

Okay, what about $18 - K$ highest bits in each query? We can see that, for every number $c_i$, the highest bits of $c_i - x$ don't change too often when we iterate on $x$: there will be about $\frac{m}{2^K}$ segments where the highest bits of $c_i - x$ have different values. We can build a data structure that allows use to process two queries: xor all numbers on a segment with some value and get the value in some position (Fenwick trees and segment trees can do it). Then, we again iterate on $x$ from $m$ to $1$. When we want to process a number $c_i$, we find the segments where the highest bits of $c_i - x$ have the same value and perform updates on these segments in our data structure. When we process a query of the form $Q(x, y)$, we simply get the value in the position $y$ from our data structure. This part of the solution works in $O(n \frac{m}{2^K} \log m + m + q)$.

By choosing $K$ optimally, we can combine these two parts into a solution with complexity of $O(N \sqrt{N \log N})$.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 200043;
const int K = 10;
const int Z = 1 << K;

int rem[Z];
int t[N];

int get(int r)
{
    int result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        result ^= t[r];
    return result;
}

void change(int i, int delta)
{
    for (; i < N; i = (i | (i + 1)))
        t[i] ^= delta;
}

int get(int l, int r)
{
    return get(r) - get(l - 1);
}

int ans[N];
int c[N];
int cnt[N];
int n, m;
int ls[N];
int rs[N];
vector<int> qs[N];
vector<int> qs2[N];

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
        cnt[c[i]]++;
    }
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        ls[i] = l;                                                                         
        rs[i] = r;
        qs[l].push_back(i);
        qs2[r + 1].push_back(i);
    }
    for(int i = m; i >= 1; i--)
    {
        for(int j = 0; j < cnt[i]; j++)
        {
            rem[i % (1 << K)]++;
            int r = i;
            while(true)
            {
                int l = r - Z + 1;
                l = max(1, l);
                if(l > r)
                    break;
                int diff = i - l;
                diff >>= K;
                change(l, diff);
                change(r + 1, diff);
                r -= Z;
            }
        }
        for(auto x : qs[i])
        {
            int cur = (get(i)) << K;
            for(int k = 0; k < Z; k++)
            {
                int dist = (k - i) % Z;
                if(dist < 0)
                    dist += Z;
                if(rem[k] & 1)
                    cur ^= dist;
            }
            ans[x] ^= cur;
        }
        for(auto x : qs2[i])
        {
            int cur = (get(ls[x])) << K;
            for(int k = 0; k < Z; k++)
            {
                int dist = (k - ls[x]) % Z;
                if(dist < 0)
                    dist += Z;
                if(rem[k] & 1)
                    cur ^= dist;
            }
            ans[x] ^= cur;
        }
    }
    for(int i = 0; i < q; i++)
        if(ans[i] == 0)
            printf("B");
        else
            printf("A");
}
```
