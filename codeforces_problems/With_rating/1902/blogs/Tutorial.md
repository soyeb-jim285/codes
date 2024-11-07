# Tutorial

[1902A - Binary Imbalance](../problems/A._Binary_Imbalance.md "Educational Codeforces Round 159 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1902A - Binary Imbalance](../problems/A._Binary_Imbalance.md "Educational Codeforces Round 159 (Rated for Div. 2)")

If the string consists of all ones, then it's always impossible. Any operation will only add more ones to the string.

Otherwise, let's show that it's always possible.

If the string consists of all zeroes, no operations are required. Otherwise, there always exists a pair of adjacent zero and one. Applying an operation between them will increase the number of zeroes by one, and there still will exist a pair of adjacent zero and one. Thus, that operation can be performed infinitely many times. We can keep performing it until there are more zeroes than ones.

Overall complexity: O(n) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	s = input()
	print("NO" if s.count('1') == n else "YES")
```
[1902B - Getting Points](../problems/B._Getting_Points.md "Educational Codeforces Round 159 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1902B - Getting Points](../problems/B._Getting_Points.md "Educational Codeforces Round 159 (Rated for Div. 2)")

Firstly, let c be the total number of tasks in the term. Then c=⌈n7⌉=⌊n+67⌋.

Suppose, Monocarp will study exactly k days. How many points will he get? He gets k⋅l for attending lessons and, since he can complete at most 2 tasks per day, he will solve no more than min(c,2⋅k) tasks. So, in the best possible scenario he will get k⋅l+min(c,2k)⋅t points.

And, actually, it's possible to get exactly that many points. For example, Monocarp can study the last k days of the term: at the n-th day he will complete (c−1)-th and c-th tasks, at the (n−1)-th day — tasks (c−3) and (c−2) and so on. It's easy to see that all that tasks will be available at the day Monocarp completes them.

In total, we need to find the minimum k such that k⋅l+min(c,2k)⋅t≥P. We can analyze two cases, or perform a Binary Search on k.

 **Solution (adedalic)**
```cpp
fun main(args: Array<String>) {
    repeat(readln().toInt()) {
        val (n, p, l, t) = readln().split(' ').map { it.toLong() }
        val cntTasks = (n + 6) / 7
        
        fun calc(k: Long) = k * l + minOf(2 * k, cntTasks) * t
        var lf = 0L
        var rg = n
        while (rg - lf > 1) {
            val mid = (lf + rg) / 2
            if (calc(mid) >= p)
                rg = mid
            else
                lf = mid
        }
        println(n - rg)
    }
}
```
[1902C - Insert and Equalize](../problems/C._Insert_and_Equalize.md "Educational Codeforces Round 159 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms") и [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1902C - Insert and Equalize](../problems/C._Insert_and_Equalize.md "Educational Codeforces Round 159 (Rated for Div. 2)")

Let's start by learning how to calculate the function without the insertion.

Since $x$ can only be positive, we will attempt to make all elements equal to the current maximum value in the array. 

Pick some $x$. Now, how to check if it's possible to make every element equal to the maximum? Well, for one element, the difference between the maximum and the element should be divisible by $x$. So, for all elements, all differences should be divisible by $x$. Thus, the greatest common divisor of all differences should be divisible by $x$.

Among all values of $x$ that work, we should obviously pick the largest one. The answer is equal to $\sum\limits_{i=1}^n \frac{\mathit{max} - a_i}{x}$, so it decreases with the increase of $x$.

Thus, it only makes sense to make $x = \mathit{gcd}(\mathit{max} - a_1, \mathit{max} - a_2, \dots, \mathit{max} - a_n)$.

If you think about that from the perspective of the Euclid's algorithm of finding the gcd, you can rewrite it as $\mathit{gcd}(a_2 - a_1, a_3 - a_2, \dots, a_n - a_{n - 1}, \mathit{max} - a_n)$. Think about it on some small $n$. $\mathit{gcd}(a_3 - a_1, a_2 - a_1) = \mathit{gcd}((a_3 - a_1) - (a_2 - a_1), a_2 - a_1) = \mathit{gcd}(a_3 - a_2, a_2 - a_1)$. Basically, you can arbitrarily add or subtract the arguments of gcd from each other.

With that interpretation, it's clear that it never makes sense to make all elements equal to anything greater than the current maximum. $x$ will still be required to be divisible by all the adjacent differences, but you will be adding one more condition that can only decrease the gcd.

Let's return to the insertion. First, inserting a new element can never decrease the function. You will add one more constraint $a_{n+1} - a_n$ to the gcd. If you increase the maximum value in the array, all $n$ elements will need additional operations to become equal to it instead of the old maximum. If you don't change the maximum, $a_{n+1}$ itself will need some operations to become equal to the maximum.

Since $x$ can only decrease, let's try to not change it at all. So, we only add an element of form $a_i + x \cdot k$ for any integer $k$, if it doesn't appear in the array. Since all elements of the array are also of that form for any $i$, let's instead choose $a_i$ that is the maximum of the array. So, the form is $\mathit{max} + x \cdot k$.

If we choose a positive $k$, the maximum increases. Thus, the answer increases $k \cdot n$, since all elements will require $k$ extra operations. Obviously, it doesn't make sense to pick $k > 1$, since $\mathit{max} + x$ doesn't appear in the array already, and the number of extra operations for it is the minimum possible — just $n$.

If we choose a negative $k$, no other elements are affected. Thus, the answer only depends on the number of operations that $a_{n+1}$ will require. So, the best option is to choose the largest $k$ such that $\mathit{max} + x \cdot k$ doesn't appear in the array. Worst case, $k = -n$ if the elements are $[\mathit{max}, \mathit{max} - x, \mathit{max} - 2 \cdot x, \dots, \mathit{max} - (n - 1) \cdot x]$. The number of operations is equal to $-k$, so it's never larger than $n$. Thus, the negative $k$ is always at least as good or even better than the positive $k$.

If we change the value of $x$, we can only divide it by something. Thus, it becomes at least twice as small. Notice how it also at least doubles the current answer. The smallest possible current answer is $0 + 1 + 2 + \dots + (n - 1) = \frac{n \cdot (n - 1)}{2}$. For any $n > 2$, that is greater or equal to $n$. If we also consider that $a_{n+1}$ itself will require at least one extra operation, we can extend it to $n > 1$. So, changing $x$ is never better than not changing $x$.

Thus, we come to the final algorithm. Calculate $x = \mathit{gcd}(a_2 - a_1, a_3 - a_2, \dots, a_n - a_{n - 1})$. For $n = 1$, it's $0$, so we handle it separately — the answer can always be $1$. Then, initialize $k = -1$ and keep decreasing it by $1$ as long as $\mathit{max} - x \cdot k$ appears in the array. That can be checked with a structure like set, with a binary search over the sorted array or with two pointers. Finally, calculate the answer as $\sum\limits_{i=1}^n \frac{\mathit{max} - a_i}{x} - k$.

Overall complexity: $O(n \log n + \log A)$ per testcase.

 **Solution (awoo)**
```cpp
from math import gcd
 
for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	g = 0
	for i in range(n - 1):
		g = gcd(g, a[i + 1] - a[i])
	g = max(g, 1)
	a.sort()
	j = n - 1
	res = a[-1]
	while True:
		while j >= 0 and a[j] > res:
			j -= 1
		if j < 0 or a[j] != res:
			break
		res -= g
	print((a[-1] * (n + 1) - (sum(a) + res)) // g)
```
[1902D - Robot Queries](../problems/D._Robot_Queries.md "Educational Codeforces Round 159 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1902D - Robot Queries](../problems/D._Robot_Queries.md "Educational Codeforces Round 159 (Rated for Div. 2)")

Let's divide the path of the robot into three parts: 

1. points before the $l$-th operation;
2. points from the $l$-th to the $r$-th operations;
3. points after the $r$-th operation;

The first and the third parts are pretty simple to check because the reverse of the substring $(l, r)$ does not affect them. So we can precompute a dictionary $mp_{x, y}$ that stores all indices of operations in the initial sequence $s$ after which the robot stands at the point $(x, y)$. Then point $(x, y)$ lies on the first part if $mp_{x, y}$ contains at least one index among indices from $0$ to $l-1$. Similarly, for the third part, but we have to check indices from $r$ to $n$.

It remains to understand how the second part works. Reversing of the order of commands from $l$ to $r$ means that the robot first performs all commands from $1$ to $l-1$ in the original string, then the command $s_r$, then $s_{r-1}$, and so on, until the command $s_l$. So, it means that the points that the robot visits can be represented as follows: for an integer $k$ such that $l \le k \le r$, perform all commands from $1$ to $r$, except for the commands from $l$ to $k$.

Let $pos_i$ be the point where the robot stands after the $i$-th operation, and $\Delta_{i, j}$ be the total movement using operations from $i$ to $j$ (note that $\Delta_{i, j} = pos_j - pos_{i-1}$). Then we have to check whether there is such $i$ that $l \le i \le r$ and $pos_{l-1} + \Delta_{i, r} = (x, y)$. Using the aforementioned equality for $\Delta$, we can rewrite this as $pos_{l-1} + pos_r - pos_i = (x, y)$. As a result, our task is to check whether there is such $i$ that $l \le i \le r$ and $pos_i = pos_{l-1} + pos_r - (x, y)$. And we already know how to check that, using the dictionary $mp$ (you will need some sort of binary search or a function similar to lower_bound to find whether there is a moment from $l$ to $r$ when a point is visited).

If the point belongs to at least one of the parts of the path, then the answer is YES, otherwise the answer is NO.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define x first
#define y second
 
using pt = pair<int, int>;
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<pt> pos(n + 1);
  for (int i = 0; i < n; ++i) {
    pos[i + 1].x = pos[i].x + (s[i] == 'R') - (s[i] == 'L');
    pos[i + 1].y = pos[i].y + (s[i] == 'U') - (s[i] == 'D');
  }
  map<pt, vector<int>> mp;
  for (int i = 0; i <= n; ++i) mp[pos[i]].push_back(i);
  auto check = [&](pt p, int l, int r) {
  	if (!mp.count(p)) return false;
  	auto it = lower_bound(mp[p].begin(), mp[p].end(), l);
  	return it != mp[p].end() && *it <= r;
  };
  while (q--) {
  	int x, y, l, r;
  	cin >> x >> y >> l >> r;
  	int nx = pos[r].x + pos[l - 1].x - x, ny = pos[r].y + pos[l - 1].y - y;
  	bool f = check({x, y}, 0, l - 1)
  	       | check({nx, ny}, l, r - 1)
  	       | check({x, y}, r, n);
  	cout << (f ? "YES" : "NO") << 'n';
  }
}
```
[1902E - Collapsing Strings](../problems/E._Collapsing_Strings.md "Educational Codeforces Round 159 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1902E - Collapsing Strings](../problems/E._Collapsing_Strings.md "Educational Codeforces Round 159 (Rated for Div. 2)")

Let's suppose that when we calculate the collapse of two strings $a$ and $b$, we reverse the string $a$ first, so that instead of checking and removing the last letters of $a$, we do this to the first letters of $a$. Then, $|C(a,b)| = |a| + |b| - 2|LCP(a', b)|$, where $LCP(a', b)$ is the longest common prefix of $a'$ (the reversed version of $a$) and $b$.

Then the answer to the problem becomes $2n \sum\limits_{i=1}^{n} |s_i| - 2\sum\limits_{i=1}^{n}\sum\limits_{j=1}^{n} LCP(s_i', s_j)$.

We need some sort of data structure that allows us to store all strings $s_i'$ and for every string $s_j$, calculate the total LCP of it with all strings in the structure. There are many ways to implement it (hashing, suffix arrays, etc), but in our opinion, one of the most straightforward is using a trie.

Build a trie on all strings $s_i'$. Then, for every vertex of the trie, calculate the number of strings $s_i'$ that end in the subtree of that vertex (you can maintain it while building the trie: when you add a new string into it, increase this value by $1$ on every vertex you go through).

If you want to find the $LCP$ of two strings $s$ and $t$ using a trie, you can use the fact that it is equal to the number of vertices that are both on the path to $s$ and on the path to $t$ at the same time (except for the root vertex). This method can be expanded to querying the sum of $LCP$ of a given string $s$ and all strings in the trie as follows: try to find $s$ in the trie. While searching for it, you will descend in the trie and go through vertices that represent prefixes of $s$. For every such prefix, you need the number of strings in the trie that have the same prefix — and it is equal to the number of strings ending in the subtree of the corresponding vertex (which we already calculated). Don't forget that you shouldn't consider the root, since the root represents the empty prefix.

This solution works in $O(SA)$ or $O(S \log A)$, where $S$ is the total length of the strings given in the input and $A$ is the size of the alphabet.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = int(1e6) + 99;
 
int nxt;
int to[N][26];
int sum[N];
long long res;
 
void add(const string& s) {
    int v = 0;
    ++sum[v];
    for (auto c : s) {
        int i = c - 'a';
        if (to[v][i] == -1)
            to[v][i] = nxt++;
        v = to[v][i];
        ++sum[v];
    }
}
 
void upd(const string& s) {
    int curLen = s.size();
    int v = 0;
    
    for (auto c : s) {
        int i = c - 'a';
        if (to[v][i] == -1) {
            res += sum[v] * 1LL * curLen;
            break;
        } else {
            int nxtV = to[v][i];
            res += (sum[v] - sum[nxtV]) * 1LL * curLen;
            --curLen;
            v = nxtV;
        }
    }
}
 
void solve(int n, vector <string> v) {
    int sumSizes = 0;
    for (int i = 0; i < n; ++i)
        sumSizes += v[i].size();
        
    nxt = 1;
    memset(sum, 0, sizeof sum);
    memset(to, -1, sizeof to);
    
    for(int i = 0; i < n; ++i) 
        add(v[i]);
    for (int i = 0; i < n; ++i) {
        reverse(v[i].begin(), v[i].end());
        upd(v[i]);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <string> v(n);
    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    res = 0;
    solve(n, v);
    for(int i = 0; i < n; ++i)
        reverse(v[i].end(), v[i].end());
    solve(n, v);
    
    cout << res << endl;
    
    return 0;
}
```
[1902F - Trees and XOR Queries Again](../problems/F._Trees_and_XOR_Queries_Again.md "Educational Codeforces Round 159 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1902F - Trees and XOR Queries Again](../problems/F._Trees_and_XOR_Queries_Again.md "Educational Codeforces Round 159 (Rated for Div. 2)")

This problem requires working with XOR bases, so let's have a primer on them.

Suppose you want to solve the following problem: given a set of integers $x_1, x_2, \dots, x_k$ and another integer $y$, check whether it is possible to choose several (maybe zero) integers from the set such that their XOR is $y$. It can be solved with Gauss elimination method for systems of linear equations, but there are easier and faster methods, and we will describe one of them.

For the given set of integers, let's build an XOR base. An XOR base of a set of integers $X = \{x_1, x_2, \dots, x_k\}$ is another set of integers $A = \{a_1, a_2, \dots, a_m\}$ such that:

* every integer that can be expressed as the XOR of some integers from the set $X$ can also be expressed as the XOR of some integers from $A$, and vice versa;
* every integer in $A$ is non-redundant (i. e. if you remove any integer from $A$, the first property is no longer met).

For example, one of the XOR bases for $X = \{1, 2, 3\}$ is $A = \{1, 3\}$. $A = \{1, 2\}$ is also an XOR base of $X$, but $A = \{1, 2, 3\}$ is not since, for example, $2$ can be deleted.

Note that an XOR base is not necessarily a subset of the original set. For example, for $X = \{1, 2\}$, $A = \{1, 3\}$ is a valid XOR base.

Due to the laws of linear algebra, an XOR base of size $m$ supports $2^m$ integers (i. e. $2^m$ integers can be expressed using XOR of some numbers from the base). This means that since in our problem the integers are limited to $20$ bits, the maximum size of an XOR base we need is $20$.

Now let's talk about how we build, store and maintain the XOR base. We will use an array of $20$ integers, initially filled with zeroes (an array of all zeroes represents an empty XOR base). Let's call this array $b$. If some integer $b_i$ in this array is non-zero, it has to meet the following constraints:

* the $i$-th bit is set to $1$ in $b_i$;
* the $i$-th bit is set to $0$ in every integer $b_j$ such that $j < i$.

This is kinda similar to how the Gauss elimination method transforms a matrix representing the system of linear equations: it leaves only one row with non-zero value in the first column and puts it as the first row, then in the next non-zero column it leaves only one row with non-zero value (except for maybe the first row) and puts it as the second row, and so on.

Okay, we need to process two types of queries for XOR bases:

* add an integer and change the XOR base accordingly if needed;
* check that some integer is supported (i. e. can be represented) by the XOR base.

For both of those queries, we will use a special reduction process. In the model solution, it is the function reduce(b,x) that takes an array $b$ representing the XOR base and an integer $x$, and tries to eliminate bits set to $1$ from $x$. In this reduction process, we iterate on bits from $19$ (or the highest bit the number can have set to $1$) to $0$, and every time the bit $i$ we're considering is set to $1$, we try to make it $0$ by XORing $x$ with $b_i$. It can be easily seen that due to the properties of XOR base, XORing with $b_i$ is the only way to do it: if we XOR with any other number $b_j$ such that $j < i$, it won't affect the $i$-th bit; and if we XOR it with $b_j$ such that $j > i$, it sets the $j$-th bit to $1$ (and we have already ensured that it should be $0$).

If reduce(b,x) transforms $x$ to $0$, then $x$ is supported by the XOR base, otherwise it is not. And if we want to try adding $x$ to the base, we can simply reduce $x$, find the highest non-zero bit in the resulting integer $x'$, (let it be $i$), and assign $b_i$ to $x'$ (it is guaranteed that $b_i$ was zero, since otherwise we would have eliminated the $i$-th bit).

So, that's how we can work with XOR bases and process every query to them in $O(B)$, where $B$ is the number of bits in each integer.

Now let's go back to the original problem. Basically, for every query, we have to build a XOR base on some path in the tree. We can root the tree and then use LCA to split this path into two vertical paths, get XOR bases from those two paths, and merge them in $O(B^2)$. But how do we get an XOR base on a vertical path in something like $O(B^2)$?

To do this, for each vertex $v$, let's consider the following process. We go from $v$ to the root, maintain the XOR base of the integers we met, and every time we add something to the XOR base, we mark the current vertex as "interesting" for $v$. Our goal is to build a list of "interesting" vertices for $v$ in order from $v$ to the root. Since the size of each XOR base is up to $20$, the size of each such list is also up to $20$, so we can get the XOR base for a vertical path by simply iterating on that interesting list for the lower endpoint of the path.

Okay, the last part of the problem we have to solve is how to build these lists for all vertices in reasonable time. The key insight here is that if $p$ is the parent of $v$, then the list for $v$ will be very similar to the list for $p$:

* if $v$ is not supported by the XOR base of the list for $p$, then the list for $v$ is simply the list for $p$, with the vertex $v$ added;
* otherwise, $v$ eliminates one of the vertices from the list for $p$. We can find which one by building the XOR base for $v$ and the list of $p$; we need to add $a_v$ first, and then the values from all vertices in the list of $p$ in order "from bottom to top", and when an interesting vertex for $p$ adds nothing to the XOR base, it means that it is exactly the vertex we need to eliminate.

Combining all of these, we can get a solution that works in $O(nB^2)$ for preprocessing and in $O(B^2 + \log n)$ to answer each query.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 200043;
const int K = 20;
 
typedef array<int, K> base;
int a[N];
vector<int> g[N];
vector<int> path_up[N];
int tin[N], tout[N];
int T = 0;
int fup[N][K];
 
base make_empty()
{
    base b;
    for(int i = 0; i < K; i++)
        b[i] = 0;
    return b;
}
 
int reduce(const base& b, int x)
{
    for(int i = K - 1; i >= 0; i--)
        if(x & (1 << i))
            x ^= b[i];
    return x;
}   
 
bool add(base& b, int x)
{
    x = reduce(b, x);
    if(x != 0)
    {
        for(int i = K - 1; i >= 0; i--)
            if(x & (1 << i))
            {
                b[i] = x;
                return true;
            }
    }   
    return false;
}
 
bool check(const base& b, int x)
{
    return reduce(b, x) == 0;
}
 
vector<int> rebuild_path(const vector<int>& path, int v)
{
    base b = make_empty();
    vector<int> ans;
    if(add(b, a[v])) ans.push_back(v);
    for(auto x : path) if(add(b, a[x])) ans.push_back(x);
    return ans;
}
 
void dfs(int v, int u)
{
    tin[v] = T++;      
    if(u == v)
        path_up[v] = rebuild_path(vector<int>(0), v);
    else
        path_up[v] = rebuild_path(path_up[u], v);
    fup[v][0] = u;
    for(int i = 1; i < K; i++)
        fup[v][i] = fup[fup[v][i - 1]][i - 1];
    for(auto y : g[v])
        if(y != u)
            dfs(y, v);
    tout[v] = T++;   
}
 
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
int LCA(int x, int y)
{
    if(is_ancestor(x, y)) return x;
    for(int i = K - 1; i >= 0; i--)
        if(!is_ancestor(fup[x][i], y))
            x = fup[x][i];
    return fup[x][0];
}
 
bool query(int x, int y, int k)
{
    base b = make_empty();
    int z = LCA(x, y);
    for(auto v : path_up[x])
        if(!is_ancestor(v, y))
            add(b, a[v]);
    for(auto v : path_up[y])
        if(!is_ancestor(v, x))
            add(b, a[v]);
    add(b, a[z]);
    return check(b, k);            
}
 
int main()
{
    int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0, 0);
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		int x, y, k;
		scanf("%d %d %d", &x, &y, &k);
		--x;
		--y;
		if(query(x, y, k)) puts("YES");
		else puts("NO");
	}
}
```
