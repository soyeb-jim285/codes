# Tutorial_(en)

[1009A - Game Shopping](../problems/A._Game_Shopping.md "Educational Codeforces Round 47 (Rated for Div. 2)")

 **Tutorial**
### [1009A - Game Shopping](../problems/A._Game_Shopping.md "Educational Codeforces Round 47 (Rated for Div. 2)")

Let's keep the variable $pos$ which will represent the number of games Maxim buy. Initially $pos = 0$. Assume that arrays $a$ and $c$ are 0-indexed. Then let's iterate over all $i = 0 \dots n - 1$ and if $pos < m$ and $a[pos] \ge c[i]$ make $pos := pos + 1$. So $pos$ will be the answer after this cycle.

 **Solution (Vovuh)**
```cpp
n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
pos = 0
for i in a:
	pos += (pos < len(b) and b[pos] >= i)
print(pos)
```
[1009B - Minimum Ternary String](../problems/B._Minimum_Ternary_String.md "Educational Codeforces Round 47 (Rated for Div. 2)")

 **Tutorial**
### [1009B - Minimum Ternary String](../problems/B._Minimum_Ternary_String.md "Educational Codeforces Round 47 (Rated for Div. 2)")

Let's notice that described swaps allows us to place any '1' character to any position of the string $s$ (relative order of '0' and '2' obviously cannot be changed). Let's remove all '1' characters from the string $s$ (and keep their count in some variable). Now more profitable move is to place all the '{1}' characters right before the first '2' character of $s$ (and if there is no '2' character in $s$, then place they after the end of the string).

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	string s;
	cin >> s;
	
	string ans;
	
	int cnt = 0;
	for (auto c : s) {
		if (c == '1') ++cnt;
		else ans += c;
	}
	
	int n = ans.size();
	int pos = -1;
	while (pos + 1 < n && ans[pos + 1] == '0') ++pos;
	ans.insert(pos + 1, string(cnt, '1'));
	
	cout << ans << endl;
	
	return 0;
}
```
[1009C - Annoying Present](../problems/C._Annoying_Present.md "Educational Codeforces Round 47 (Rated for Div. 2)")

 **Tutorial**
### [1009C - Annoying Present](../problems/C._Annoying_Present.md "Educational Codeforces Round 47 (Rated for Div. 2)")

Judging by constraints, you can guess that the greedy approach is the right one. 

Firstly, let's transition from maximizing the arithmetic mean to the sum, it's the same thing generally. 

Secondly, notice that each $x$ is being added to each element regardless of the chosen position. 

Finally, take a look at a function $f(d, i)$ — total sum obtained by applying change with $d$ to position $i$ and notice that it is non-strictly convex. Its maximum or minimum values can always be found in one of these positions: $\frac{n}{2}$ (method of rounding doesn't matter), $1$ and $n$.

Thus, the solution will look like this: for positive $d$ you apply the change to position $1$ and for non-positive $d$ — to position $\lfloor \frac{n}{2} \rfloor$. The impact of the change can be calculated with the formula of the sum of arithmetic progression.

Also, you should either do all of your calculations in long double (10-byte type) or maintain sum in long long (you can estimate it with $m \cdot n^2 \cdot MAXN \le 10^{18}$, so it fits) and divide it by $n$ in the end (then double will work).

Overall complexity: $O(m)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef long long li;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	li neg = ((n - 1) / 2) * li((n - 1) / 2 + 1);
	if (n % 2 == 0) neg += n / 2;
	li pos = n * li(n - 1) / 2;
	
	li ans = 0;
	forn(i, m){
		int x, d;
		scanf("%d%d", &x, &d);
		ans += x * li(n);
		if (d < 0)
			ans += neg * d;
		else
			ans += pos * d;
	}
	
	printf("%.15fn", double(ans) / n);
	return 0;
}
```
[1009D - Relatively Prime Graph](../problems/D._Relatively_Prime_Graph.md "Educational Codeforces Round 47 (Rated for Div. 2)")

 **Tutorial**
### [1009D - Relatively Prime Graph](../problems/D._Relatively_Prime_Graph.md "Educational Codeforces Round 47 (Rated for Div. 2)")

Even though $n$ is up to $10^5$, straightforward $O(n^2 \log n)$ solution will work. You iterate for $i$ from $1$ to $n$ in the outer loop, from $i + 1$ to $n$ in the inner loop and check $GCD$ each time. When $m$ edges are found, you break from both loops.

Here is why this work fast enough. The total number of pairs $(x, y)$ with $1 \le x, y \le n, gcd(x, y) = 1$ is $\varphi(1) + \varphi(2) + \dots + \varphi(n)$, where $\varphi$ is Euler's totient function. We also want to substract a single pair $(1, 1)$. And this sum grows so fast that after about $600$ iteratons $\varphi(1) + \varphi(2) + \dots + \varphi(600)$ will be greater than $100000$ for any $n$.

The only thing left is to check that $m$ is big enough to build a connected graph ($m \ge n - 1$) and small enough to fit all possible edges for given $n$ (the formula above).

Overall complexity: $O(n^2 \log n)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 100000;

pair<int, int> ans[N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	if (m < n - 1) {
		puts("Impossible");
		return 0;
	}
	
	int cur = 0;
	
	forn(i, n) for (int j = i + 1; j < n; ++j){
		if (cur == m)
			break;
		if (__gcd(i + 1, j + 1) == 1)
			ans[cur++] = make_pair(j, i);
	}
	
	if (cur != m){
		puts("Impossible");
		return 0;
	}
	
	puts("Possible");
	forn(i, m)
		printf("%d %dn", ans[i].first + 1, ans[i].second + 1);
	
	return 0;
}

```
[1009E - Intercity Travelling](../problems/E._Intercity_Travelling.md "Educational Codeforces Round 47 (Rated for Div. 2)")

 **Tutorial**
### [1009E - Intercity Travelling](../problems/E._Intercity_Travelling.md "Educational Codeforces Round 47 (Rated for Div. 2)")

Let's consider each kilometer of the journey separatedly and calculate the expected value of its difficulty (and then use linearity of expectation to obtain the answer).

The difficulty of each kilometer depends on the rest site right before it (or, if there were no rest sites, on the distance from Moscow to this kilometer). So when considering the difficulty of $i$-th kilometer (one-indexed), we may obtain a formula:

$diff_i = \frac{a_1}{2} + \frac{a_2}{2^2} + \dots + \frac{a_{i - 1}}{2^{i - 1}} + \frac{a_i}{2^{i - 1}}$. The denominator of the last summand is $2^{i - 1}$ because it represents the situation where the last rest was in Moscow, and its probability is exactly $\frac{1}{2^{i - 1}}$.

We can actually rewrite this as follows: $diff_1 = a_1$, $diff_{i + 1} = diff_i - \frac{a_i}{2^i} + \frac{a_{i + 1}}{2^i}$, thus calculating all that we need in linear time.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

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

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    int ans = 0;
    vector<int> pw2(1, 1);
    while(pw2.size() < n)
        pw2.push_back(mul(pw2.back(), 2));
    int cur = mul(pw2[n - 1], a[0]);
    for(int i = 0; i < n; i++)
    {
        ans = add(ans, cur);
        if(i < n - 1)
        {
            cur = add(cur, -mul(pw2[n - 2 - i], a[i]));
            cur = add(cur, mul(pw2[n - 2 - i], a[i + 1]));
        }
    }
    printf("%dn", ans);
}
```
[1009F - Dominant Indices](../problems/F._Dominant_Indices.md "Educational Codeforces Round 47 (Rated for Div. 2)")

 **Tutorial**
### [1009F - Dominant Indices](../problems/F._Dominant_Indices.md "Educational Codeforces Round 47 (Rated for Div. 2)")

In this problem we can use small-to-large merging trick (also known as DSU on tree): when building a depth array for a vertex, we firstly build depth arrays recursively for its children, then pull them upwards and merge them with small-to-large technique. In different blogs on this technique it was mentioned that this will require $O(n \log n)$ operations with structures we use to maintain depth arrays overall.

However, in this problem we may prove a better estimate: it will require $O(n)$ operations. That's because the size of depth array (if considering only non-zero elements) for a vertex is equal to the height of its subtree, not to the number of vertices in it. To prove that the number of operations is $O(n)$, one can use the intuitive fact that when we merge two depth arrays, all elements of the smaller array are "destroyed" in the process, so if the size of smaller array is $k$, then we require $O(k)$ operations to "destroy" $k$ elements.

The main problem is that we sometimes need to "pull" our depth arrays upwards, thus inserting a $1$ to the beginning of the array. Standard arrays don't support this operation, so we need to either use something like std::map (and the complexity will be $O(n \log n)$), or keep the depth arrays in reversed order and handle them using std::vector (and then complexity will be $O(n)$).

 **Solution (BledDest)**
```cpp
#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

// RJ? No, thanks

using namespace std;

const int N = 1000043;

struct state
{
	vector<int>* a;
	int cur_max;
	int sz()
	{
		return a->size();
	}
	void add(int i, int val)
	{
		(*a)[i] += val;
		if(make_pair((*a)[i], i) > make_pair((*a)[cur_max], cur_max))
			cur_max = i;
	}
};

state pull(state z)
{
	if(z.sz() == 0)
	{
		state c;
		c.a = new vector<int>(1, 1);
		c.cur_max = 0;
		return c;
	}
	else
	{
		state c;
		c.a = z.a;
		c.cur_max = z.cur_max;
		c.a->push_back(0);
		c.add(c.sz() - 1, 1);
		return c;
	}
}

state merge(state a, state b)
{
	if(a.sz() < b.sz())
		swap(a, b);
	state c;
	c.a = a.a;
	c.cur_max = a.cur_max;
	int as = c.sz();
	int bs = b.sz();
	for(int i = 0; i < bs; i++)
		a.add(as - i - 1, (*(b.a))[bs - i - 1]);
	return a;
}

state s[N];
int ans[N];
vector<int> g[N];

void dfs(int x, int p = -1)
{
	s[x].a = new vector<int>(0);
	s[x].cur_max = 0;
	for(auto y : g[x])
		if(y != p)
		{
			dfs(y, x);
			s[x] = merge(s[x], s[y]);
		}
	s[x] = pull(s[x]);
	ans[x] = s[x].sz() - s[x].cur_max - 1;
}

int main()
{
	int n;
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
	dfs(0);
	for(int i = 0; i < n; i++)
		printf("%dn", ans[i]);
	return 0;
}
```
[1009G - Allowed Letters](../problems/G._Allowed_Letters.md "Educational Codeforces Round 47 (Rated for Div. 2)")

 **Tutorial**
### [1009G - Allowed Letters](../problems/G._Allowed_Letters.md "Educational Codeforces Round 47 (Rated for Div. 2)")

The idea of solution is the following: we build the answer letter-by-letter; when choosing a character for some position, we try all possible characters and check that we can build the suffix after placing this character. But we need to somehow do this checking fast.

As in many previous Educational Rounds, in this round some participants' solutions were much easier to write and understand than our own model solution.

Authors' solution (uses network flows):

Let's build a flow network, where we have $6$ vertices representing the characters of the string and $2^6$ vertices representing the masks of characters. Add directed edges from the source to every node representing some character with capacity equal to the number of such characters in the original string; also add directed edges from every node representing some character to all vertices representing masks where this character is contained (with infinite capacity); and finally, add a directed edge from every "mask"-node to the sink with capacity equal to the number of positions where this mask of characters is allowed.

If we find maximum flow in this network, we can check that the answer exists, and if it exists, build some answer. Now let's try to build optimal answer by somehow rebuilding the flow in the network.

Suppose we are trying to place a character $x$ to position containing mask $m$. To check whether we can do it, we have to try rebuilding the flow in such a way that the edge from vertex corresponding to $x$ to vertex corresponding to $m$ has non-zero flow. If it is already non-zero, then we are done; otherwise we may cancel a unit of flow going through an edge from source to $x$-vertex, then cancel a unit of flow going through an edge from $m$-vertex to sink, decrease the capacity of these two edges by $1$ and check that there exists an augmenting path. If it exists, then returning the capacities back and adding one unit of flow through the path $source \rightarrow x \rightarrow m \rightarrow sink$ actually builds some answer where some character $x$ is placed on some position with mask $m$, so we may place it there; otherwise it's impossible.

When we finally decided to place $x$ on position $m$, we have to decrease the flow through $source \rightarrow x \rightarrow m \rightarrow sink$ and the capacities of edges $source \rightarrow x$ and $m \rightarrow sink$.

All this algorithm runs in $O(n \cdot 2^A \cdot A^2)$, where $A$ is the size of the alphabet.

Participants' solution (uses Hall's theorem):

Hall's theorem allows us to check that we may build the suffix of the answer much easier.

Each time we try to place some character, we need to iterate on all possible subsets of characters we still need to place and check that the number of positions that are suitable for at least one character in a subset is not less than the size of subset (just like in regular Hall's theorem). The key fact here is that if we have, for example, $3$ characters a yet to place, then we don't need to check any subset containing exactly $1$ or $2$ characters a, since the number of "suitable" positions for this subset won't become larger if we add all remaining characters a to a subset. So the subsets we have to consider are limited by the masks of possible characters, and there will be only $64$ of them.

 **Solution (Bleddest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define sz(a) ((int)(a).size())

struct edge
{
    int y;
    int c;
    int f;
    edge() {};
    edge(int y, int c, int f) : y(y), c(c), f(f) {};
};

const int N = 100;

vector<edge> e;
vector<int> g[N];
int edge_num[N][N];
int char_vertex[6];
int mask_vertex[N];
int used[N];
int cc = 0;
int s, t;

void add_edge(int x, int y, int c)
{
    edge_num[x][y] = sz(e);
    g[x].push_back(sz(e));
    e.push_back(edge(y, c, 0));
    edge_num[y][x] = sz(e);
    g[y].push_back(sz(e));
    e.push_back(edge(x, 0, 0));
}

int rem(int num)
{
    return e[num].c - e[num].f;
}

int dfs(int x, int mx)
{
    if(x == t) return mx;
    if(used[x] == cc) return 0;
    used[x] = cc;
    for(auto num : g[x])
    {
        if(rem(num))
        {
            int pushed = dfs(e[num].y, min(mx, rem(num)));
            if(pushed)
            {
                e[num].f += pushed;
                e[num ^ 1].f -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}

bool check(int ch, int mask)
{
    if((mask & (1 << ch)) == 0)
        return false;
    int cv = char_vertex[ch];
    int mv = mask_vertex[mask];
    int e1 = edge_num[s][cv];
    int e2 = edge_num[mv][t];
    if(e[e1].f == 0 || e[e2].f == 0)
        return false;
    e[e1].f--;
    e[e1 ^ 1].f++;
    vector<int> affected_edges;
    affected_edges.push_back(e1);
    for(auto x : g[cv])
    {
        if((x & 1) == 0 && e[x].f > 0)
        {
            affected_edges.push_back(x);
            e[x].f--;
            e[x ^ 1].f++;
            int y = e[x].y;
            for(auto x2 : g[y])
            {
                if((x2 & 1) == 0)
                {
                    affected_edges.push_back(x2);
                    e[x2].f--;
                    e[x2 ^ 1].f++;
                    break;
                }
            }
            break;
        }
    }
    if(e[e2].f < e[e2].c)
    {
        e[e1].c--;
        e[e2].c--;
        return true;
    }
    affected_edges.push_back(e2);
    e[e2].f--;
    e[e2 ^ 1].f++;
    for(auto x : g[mv])
    {
        if((x & 1) == 1 && e[x].f < 0)
        {
            affected_edges.push_back(x ^ 1);
            e[x].f++;
            e[x ^ 1].f--;
            int y = e[x].y;
            for(auto x2 : g[y])
            {
                if((x2 & 1) == 1)
                {
                    affected_edges.push_back(x2 ^ 1);
                    e[x2].f++;
                    e[x2 ^ 1].f--;
                    break;
                }
            }
            break;
        }
    }
    cc++;
    e[e1].c--;
    e[e2].c--;
    if(dfs(s, 1))
        return true;
    else
    {
        e[e1].c++;
        e[e2].c++;
        for(auto x : affected_edges)
        {
            e[x].f++;
            e[x ^ 1].f--;
        }
        return false;
    }
}

char buf[100043];
string allowed[100043];
int allowed_mask[100043];

int main()
{
    s = 70;
    t = 71;
    scanf("%s", buf);
    string z = buf;
    int n = sz(z);
    int m;
    scanf("%d", &m);
    for(int i = 0; i < n; i++)
    {
        allowed[i] = "abcdef";
        allowed_mask[i] = 63;
    }
    for(int i = 0; i < m; i++)
    {
        int idx;
        scanf("%d", &idx);
        --idx;
        scanf("%s", buf);
        allowed[idx] = buf;
        allowed_mask[idx] = 0;
        for(auto x : allowed[idx])
        {
            allowed_mask[idx] |= (1 << (x - 'a'));
        }
    }
    for(int i = 0; i < 6; i++)
        char_vertex[i] = i;
    for(int i = 0; i < (1 << 6); i++)
        mask_vertex[i] = i + 6;
    for(int i = 0; i < (1 << 6); i++)
        for(int j = 0; j < 6; j++)
            if(i & (1 << j))
                add_edge(char_vertex[j], mask_vertex[i], 100000);
    for(int i = 0; i < 6; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
            if(z[j] == 'a' + i)
                cnt++;
        add_edge(s, char_vertex[i], cnt);
    }
    for(int i = 0; i < (1 << 6); i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
            if(allowed_mask[j] == i)
                cnt++;
        add_edge(mask_vertex[i], t, cnt);
    }
    int flow = 0;
    while(true)
    {
        cc++;
        int p = dfs(s, 100000);
        if(p)
            flow += p;
        else
            break;
    }
    if(flow != n)
    {
        puts("Impossible");
        return 0;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 6; j++)
        {
            if(check(j, allowed_mask[i]))
            {
                printf("%c", j + 'a');
                break;
            }
        }
    puts("");
}
```
