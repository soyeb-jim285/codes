# Tutorial

[1051A - Vasya And Password](../problems/A._Vasya_And_Password.md "Educational Codeforces Round 51 (Rated for Div. 2)")

 **Tutorial**
### [1051A - Vasya And Password](../problems/A._Vasya_And_Password.md "Educational Codeforces Round 51 (Rated for Div. 2)")

There are just a few general cases in the task to consider: 

1. If the password $s$ is already valid, nothing has to be changed, just print $s$.
2. Try to change exactly one character, iterate over all positions in $s$ and all three options for character (any digit, any lowercase or uppercase Latin letter). After the replacement the string is checked for the validity and printed if it turned out to be valid.
3. We weren't able to replace a substring of length 0 or 1, then the answer is at least 2. We can obtain it in a following manner: replace the first two characters to "a1" if the third character is an uppercase Latin letter, to "A1" if the third character is a lowercase Latin letter and to "aA" if the third character is a digit.
 **Solution (Ajosteen)**
```cpp
  
#include <bits/stdc++.h>

using namespace std;

string s;

bool ok(string t){
    int msk = 0;
    
    for(int i = 0; i < int(t.size()); ++i){
	    if(isupper(t[i])) msk |= 1;
	    if(islower(t[i])) msk |= 2;
	    if(isdigit(t[i])) msk |= 4;
	}
	
	return msk == 7;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
    	cin >> s;
    	if(ok(s)){
    	    cout << s << endl;
    	    continue;
    	}
    	bool fnd = false;
        for(int i = 0; i < int(s.size()); ++i){
            string t = s;
            
            t[i] = '1';
            if(ok(t)){
    	        cout << t << endl;
    	        fnd = true;
    	        break;
    	    }
            t[i] = 'a';
            if(ok(t)){
    	        cout << t << endl;
    	        fnd = true;
    	        break;
    	    }
    	    t[i] = 'A';
            if(ok(t)){
    	        cout << t << endl;
    	        fnd = true;
    	        break;
    	    }
        }
    	
    	if(fnd) continue;
    	
    	if(isupper(s[2])){
    	    s[0] = 'a';
    	    s[1] = '1';
    	    cout << s << endl;
    	    continue;
    	}
    	if(islower(s[2])){
    	    s[0] = 'A';
    	    s[1] = '1';
    	    cout << s << endl;
    	    continue;
    	}
    	if(isdigit(s[2])){
    	    s[0] = 'a';
    	    s[1] = 'A';
    	    cout << s << endl;
    	    continue;
    	}
	}
	return  0;
}


```
[1051B - Relatively Prime Pairs](../problems/B._Relatively_Prime_Pairs.md "Educational Codeforces Round 51 (Rated for Div. 2)")

 **Tutorial**
### [1051B - Relatively Prime Pairs](../problems/B._Relatively_Prime_Pairs.md "Educational Codeforces Round 51 (Rated for Div. 2)")

Numbers with the difference of $1$ are always relatively prime. That's the only thing I should mention for this editorial.

Overall complexity: $O(r - l)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

int main() {
	long long l, r;
	scanf("%lld%lld", &l, &r);
	puts("YES");
	forn(i, (r - l) / 2 + 1)
		printf("%lld %lldn", l + i * 2, l + i * 2 + 1);
}

```
[1051C - Vasya and Multisets](../problems/C._Vasya_and_Multisets.md "Educational Codeforces Round 51 (Rated for Div. 2)")

 **Tutorial**
### [1051C - Vasya and Multisets](../problems/C._Vasya_and_Multisets.md "Educational Codeforces Round 51 (Rated for Div. 2)")

Write down all the numbers, which appear exactly once, let there be $k$ of them. If $k$ is even, put the first $\frac{k}{2}$ of them into the first multiset and put the other $\frac{k}{2}$ into the second multiset. All the other numbers (which appear more than once) also go into the first multiset. The only nice numbers will be the initial $k$, thus the answer is valid.

If $k$ is odd and there is no number to appear more than twice, then the answer is "NO", as all the numbers to appear exactly twice don't change the difference of the amounts of the nice numbers at all. If there is a number to appear more than twice (let it be $x$), then let's firstly add $\lceil \frac{k}{2} \rceil$ of the numbers to appear exactly once to the first multiset, add $\lfloor \frac{k}{2} \rfloor$ others of them to the second multiset. Then the first occurrence of $x$ goes to the second multiset and all the other numbers go to the first multiset. It's easy to notice that multisets will contain equal number of the nice numbers after all the partitioning.

 **Solution (Ajosteen)**
```cpp
  
#include <bits/stdc++.h>

using namespace std;

const int N = 109;

int n;
int a[N];
map<int, int> m;
set <int> s[2];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		m[a[i]]++;
	}

	int pos = 0;
	for(auto p : m)
		if(p.second == 1){
			s[pos].insert(p.first);
			pos = 1 - pos;
		}
		
	if(s[0].size() == s[1].size()){
		string res(n, 'A');
		for(int i = 0; i < n; ++i)
			if(s[1].count(a[i]))
				res[i] = 'B';
		
		cout << "YES" << endl;
		for(auto c : res) cout << c;
		cout << endl;
		return 0;
	}
	else{
		assert(int(s[0].size()) - 1 == int(s[1].size()));
		string res(n, 'A');
		for(int i = 0; i < n; ++i)
			if(s[1].count(a[i]))
				res[i] = 'B';
		
		int id = -1;
		for(auto p : m)
			if(p.second >= 3){
				id = p.first;
				break;
			}
			
		if(id == -1){
			cout << "NO" << endl;
			return 0;
		}
		
		bool flag = false;
		for(int i = 0; i < n; ++i){
			if(a[i] == id)
				if(!flag){
					flag = true;
					res[i] = 'B';
				}
		}
		
		cout << "YES" << endl;
		for(auto c : res) cout << c;
		cout << endl;
		return 0;
	}
	return 0;
}
                             	
```
[1051D - Bicolorings](../problems/D._Bicolorings.md "Educational Codeforces Round 51 (Rated for Div. 2)")

 **Tutorial**
### [1051D - Bicolorings](../problems/D._Bicolorings.md "Educational Codeforces Round 51 (Rated for Div. 2)")

The problem is about counting the number of some combinatoric objects. Thus, dynamic programming is always the answer.

Let $dp[i][j][mask]$ be the number of beautiful bicolorings of the first $i$ columns such that $j$ components are already created and can't be modified and the colors of the $i$-th column are determined by $mask$ (its first bit is the color of the lower cell and its second bit the color of the upper cell). Component can be modified if the cell from the $i$-th column belongs to it.

The initial states are $dp[0][0][mask] = 1$ for each $mask = 0..3$ and $dp[i][j][mask] = 0$ for any other state.

You should iterate over the possible $nmask$ for the next column and recalculate the number of components. You can easily show that the current number of components and the last column is actually enough to get the new number of components. 

In my code I have some function $get(mask, nmask)$ to determine the added number of components while transitioning from $mask$ to $nmask$. These are just the couple of cases to handle carefully.

Then all the transitions are:

$dp[i + 1][j + get(mask, nmask)][nmask]$ += $dp[i][j][mask]$.

However, the last column won't contain the answer as it is, the number of components will be incorrect. Let's add some dummy column $n + 1$ equal to $mask \oplus 3$ for each $mask$. This will add all the real component to the total number. So the answer is the sum of $dp[n][k - get(mask, mask \oplus 3)][mask]$ over all $mask = 0..3$.

Overall complexity: $O(n^2 \cdot 4^m)$, where $m$ is the number of rows (2 for this problem).

 **Solution (PikMike)**
```cpp
  
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

const int N = 1000 + 7;
const int MOD = 998244353;

int dp[N][2 * N][4];

int add(int a, int b){
	return (a + b) % MOD;
}

bool full(int mask){
	return (mask == 0 || mask == 3);
}

int get(int mask, int nmask){
	int cnt = __builtin_popcount(mask ^ nmask);
	if (cnt == 0) return 0;
	if (cnt == 2) return (full(mask) ? 1 : 2);
	return (full(mask) ? 0 : 1);
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	forn(i, 4)
		dp[1][0][i] = 1;
	
	for (int i = 1; i < n; ++i){
		forn(j, k + 1){
			forn(mask, 4){
				forn(nmask, 4){
					dp[i + 1][j + get(mask, nmask)][nmask] = add(dp[i + 1][j + get(mask, nmask)][nmask], dp[i][j][mask]);
				}
			}
		}
	}
	
	int ans = 0;
	forn(mask, 4){
		int nw = get(mask, mask ^ 3);
		if (k >= nw)
			ans = add(ans, dp[n][k - nw][mask]);
	}
	
	printf("%dn", ans);
}        	
```
[1051E - Vasya and Big Integers](../problems/E._Vasya_and_Big_Integers.md "Educational Codeforces Round 51 (Rated for Div. 2)")

 **Tutorial**
### [1051E - Vasya and Big Integers](../problems/E._Vasya_and_Big_Integers.md "Educational Codeforces Round 51 (Rated for Div. 2)")

Let's use dynamic programming to solve the problem. Let $dp_x$ be the number of correct partitions for the long integer $a_x a_{x+1} \dots a_{n}$. 

It's easy to see that if we have two big integers without leading zeroes, we know the lengths of these integers, and these lengths are not equal, then we can determine which integer is greater in $O(1)$. 

We will calculate the answers in the following order: $dp_{|a|}, dp_{|a| - 1} \dots dp_1$. Suppose we want to calculate $dp_x$.

Let $L$ be the minimum position such that the number $a_x a_x+1 \dots a_L$ meets the following condition: $l \le a_x a_x+1 \dots a_L \le r$.

Let $R$ be the maximum position such that the number $a_x a_x+1 \dots a_R$ meets the following condition $l \le a_x a_x+1 \dots a_R \le r$.

Initially let's consider $L = x + |l|$ и $R = x + |r|$. $L$ will be less if $a_x a_{x + 1} ... a_{x + |l|} < l$. $R$ will be less if $a_x a_{x + 1} ... a_{x + |r|} > r$. 

To determine which of the numbers $a_x a_{x + 1} ... a_{x + |l|}$ and $l$ is greater let's calculate z-function for the string $l + \\
# + a$, where $\\#$ is any character that doesn't occur in $a$ and $l$. After calculating z-function we can easily find the first non-equal character in $a_x a_{x + 1} ... a_{x + |l|}$ and $l$, and this character will determine which number is greater. To compare $a_x a_{x + 1} ... a_{x + |r|}$ and $r$ we can act the same.

All that's left is to set $dp_x$ to the sum of $dp$ values from $L$ to $R$. This can be done by maintaining suffix sums.

There is a corner case, which applies when $a_x = 0$. If $l > 0$, then $dp_x = 0$ because we cannot afford any leading zeroes. Otherwise $dp_x = dp_{x + 1}$.

 **Solution (Ajosteen)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())

const int N = int(1e6) + 9;
const int MOD = 998244353;

int n;
string s, l, r;
int dp[N];
int sumDP[N];

int sum(int a, int b){
	a += b;
	if(a >= MOD) a -= MOD;
	return a;
}

vector <int> z_function(string s){
	int n = sz(s);
	vector <int> z(n);
	for(int i = 1, l = 0, r = 0; i < n; ++i){
		if(i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if(i + z[i] - 1 > r)
			l = i,  r = i + z[i] - 1;
	}
	return z;
}

//s[pos..] ? t
char cmp(vector <int> &zf, string &t, int pos){
	int len = sz(t);
	assert(pos + len + 1 < sz(zf));
	if(sz(s) - pos < len) return '<';
	
	int x = zf[len + 1 + pos];
	assert(x <= len);
	if(x == len) return '=';
	assert(pos + x < sz(s));
	assert(s[pos + x] != t[x]);
	if(s[pos + x] < t[x]) return '<';
	return '>';
}

int main() {
	//freopen("input.txt", "r", stdin);
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> s >> l >> r;
	n = int(s.size());
	vector <int> zl = z_function(l + "#" + s);
	vector <int> zr = z_function(r + "#" + s);
	
	sumDP[n] = dp[n] = 1;
	for(int i = n - 1; i >= 0; --i){
		if(s[i] == '0'){
			if(l == "0") dp[i] = dp[i + 1];		
			else dp[i] = 0;
			sumDP[i] = sum(dp[i], sumDP[i + 1]);
			continue;
		}
		
		int L = sz(l) + i;
		char cl = cmp(zl, l, i);
		if(cl == '<') ++L;
		
		int R = sz(r) + i;
		char cr = cmp(zr, r, i);
		if(cr == '>') --R;

	 	int cur = 0;
	 	if(L <= R && L <= n){
	 		R = min(R, n);
	 		cur = sumDP[L];
	 		if(R != n) cur = sum(cur, MOD - sumDP[R + 1]);
	 	}
	 	dp[i] = cur;
	 	sumDP[i] = sum(dp[i], sumDP[i + 1]);
	}
	
	cout << dp[0] << endl;
	return 0;
}

```
[1051F - The Shortest Statement](../problems/F._The_Shortest_Statement.md "Educational Codeforces Round 51 (Rated for Div. 2)")

 **Tutorial**
### [1051F - The Shortest Statement](../problems/F._The_Shortest_Statement.md "Educational Codeforces Round 51 (Rated for Div. 2)")

Firstly let's find any spanning tree and root it at any vertex. For each vertex we calculate the distance to the root (let it be $h_v$ for vertex $v$). There are no more than $21$ edges that don't belong to the tree. For each of these edges, let's run Dijkstra's algorithm from some vertex incident to this edge.

Suppose we are answering a query $u$ $v$. If the shortest path between these vertices passes only along the edges of the tree, then it can be calculated by the formula $h_v + h_u - 2h_{lca(u, v)}$, where $lca(u, v)$ is the lowest common ancestor of vertices $u$ and $v$. You may use any fast enough algorithm you know to calculate $lca(u, v)$.

Otherwise there exists at least one vertex such that we ran Dijkstra's algorithm from it, and it belongs to the shortest path. Just iterate on every vertex for which we ran Dijkstra and update the answer with the value of $d_u + d_v$, where $d_x$ is the shortest path to the vertex $x$ from the fixed vertex.

 **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 300 * 1000 + 9;
const int LOGN = 19;
const int M = 21;
const long long INF64 = 1e18;

int n, m, q;
vector <pair<int, int> > g[N];
int p[LOGN][N];
int tin[N], tout[N], T;
long long h[N];
set <pair<int, int> > badEdges;
long long d[M + M][N];
bool u[N];

void dfs(int v, int pr){
	tin[v] = T++;
	p[0][v] = pr;
	u[v] = true;
	for(int i = 1; i < LOGN; ++i)
		p[i][v] = p[i - 1][ p[i - 1][v] ];
		
	for(auto e : g[v]){
		int to = e.first, len = e.second;
		if(!u[to]){
			h[to] = h[v] + len;
			dfs(to, v);
			
			if(v < to)
				badEdges.erase(make_pair(v, to));
			else
				badEdges.erase(make_pair(to, v));			
		}
	}	
		
	tout[v] = T;
}

bool isAncestor(int a, int b){
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int getLCA(int a, int b){
	if(isAncestor(a, b)) return a;
	if(isAncestor(b, a)) return b;
	
	for(int i = LOGN - 1; i >= 0; --i)
		if(!isAncestor(p[i][a], b))
			a = p[i][a];
	
	return p[0][a];
}

void dij(int st, long long d[N]){
	set<pair<long long, int> > q;
	for(int i = 0; i < n; ++i) d[i] = INF64;
	d[st] = 0;
	q.insert(make_pair(d[st], st));
	
	while(!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());
		
		for(auto e : g[v]){
			int to = e.first, len = e.second;
			if(d[to] > d[v] + len){
				q.erase(make_pair(d[to], to));
				d[to] = d[v] + len;
				q.insert(make_pair(d[to], to));
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	
	scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
    	int u, v, w;
    	scanf("%d %d %d", &u, &v, &w);
    	--u, --v;
    	g[u].push_back(make_pair(v, w));
       	g[v].push_back(make_pair(u, w));
    }
	
    for(int v = 0; v < n; ++v)
    	for(auto e : g[v])
    		if(v < e.first)
    			badEdges.insert(make_pair(v, e.first));

    dfs(0, 0);

    int cpos = 0;
    for(auto e : badEdges)
    	dij(e.first, d[cpos++]);
    scanf("%d", &q);
    for(int tc = 0; tc < q; ++tc){
    	int u, v;
    	scanf("%d %d", &u, &v);
    	--u, --v;
    	int lca = getLCA(u, v);
    	long long ans = h[u] + h[v] - 2 * h[lca];
    	for(int i = 0; i < badEdges.size(); ++i)
    		ans = min(ans, d[i][u] + d[i][v]);
    		
    	printf("%lldn", ans);
    }	
    return 0;
}
```
[1051G - Distinctification](../problems/G._Distinctification.md "Educational Codeforces Round 51 (Rated for Div. 2)")

 **Tutorial**
### [1051G - Distinctification](../problems/G._Distinctification.md "Educational Codeforces Round 51 (Rated for Div. 2)")

Let's firstly try to come up with some naive solution.

Suppose we have a list $S$ and want to calculate $f(S)$ for it. Let's sort this list, comparing the pairs by their values of $a_i$, and then process them one-by-one. We will divide this list into some parts (we will call them components) with the following process: when processing the first pair in the sorted order, let's iterate on the next pairs (also in the sorted order) and add them to the first pair's component until the following condition is met: $a_y - a_x > y - x$, where $x$ is the index of the first pair we added, and $y$ is the index of the pair we are currently trying to add to $x$'s component (remember that we consider all these pairs in the sorted order).

What is the meaning of this condition? $a_y - a_x \le y - x$ means that the number of pairs between $x$ and $y$ (including these two) is not less that the number of integers in $[a_x, a_y]$ — and while this condition is met, we can use the first operation in order to make a pair having $a_i = z$ for every $z \in [x, y]$. And the first time when the condition $a_y - a_x > y - x$ is met, we obviously cannot "expand" the segment in such a way. It means that the $a$-value of $y$ will always be greater than $a$-value of $x$, and $y$ won't belong to the same component with $x$ (and will start creating its own component instead).

These components we form have one special property. Suppose we "expanded" the component so that there are no two equal values of $a_i$ in it. Then we may reorder the pairs in this component as we wish (to do so, we may "contract" the component using the second operation, and then "expand" it again). Of course, the best course of action is to sort the pairs in the component by their values of $b_i$ in descending order. After doing this for every component, we will obtain an optimal configuration such that all values of $a_i$ are distinct, and it's easy to calculate the answer.

Okay, now we need to do it fast. The following will help us:

* DSU;
* Some implicit logarithmic data structure (the operations we need are "count the sum of elements less than $x$" and "count the number of elements greater than $y$"; your implementation might use other operations);
* Small-to-large merging.

DSU will help us maintain the components. A data structre will be built for each component containing the values of $b_i$ in it; it will help us to maintain the sum of $opt(i) b_i$, where $opt(i)$ is the optimal index of $b_i$ in this component. Depending on your implementation, you may or may not need to store the minimum value of $a_i$ in the component. When inserting some element having $b_i = b$ into some component, the elements having $b_i > b$ don't change their position, the new element will be added right after them, and the remaining elements will be shifted to the right; so the sum of $opt(i) b_i$ can be maintained if we query the number of elements greater than $b$ and the sum of elements less than $b$.

Okay, but we still don't know how we create the components and how we determine if two components are to merge. We will keep these components in "expanded" form; that is, when processing a pair $(a_i, b_i)$, let's find the leftmost unoccupied position after $a_i$ (or $a_i$, if it is not occupied) and occupy it with the new pair, creating a new component for it. If the newly occupied index is $pos$, let's try to merge new component with components occupying $pos - 1$ and $pos + 1$ (if there are any); to merge two components, do the required operations in DSU and unite the data structures built in these components with small-to-large method.

All this works in $O(n \log^2 n)$, the most time-consuming part is merging the data structures.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long li;

mt19937 rnd(time(NULL));

struct node
{
	int x;
	int y;
	li sum;
	int siz;
	node* l;
	node* r;
	node() {};
	node(int x, int y, li sum, int siz, node* l, node* r) : x(x), y(y), sum(sum), siz(siz), l(l), r(r) {};
};

typedef node* treap;
typedef pair<treap, treap> ptt;

int getSiz(treap t)
{
	return (t ? t->siz : 0);
}

li getSum(treap t)
{
	return (t ? t->sum : 0);
}

treap fix(treap t)
{
	if(!t) return t;
	t->sum = getSum(t->l) + t->x + getSum(t->r);
	t->siz = getSiz(t->l) + 1 + getSiz(t->r);
	return t;
}

ptt split(treap t, int l)
{
	t = fix(t);
	if(!t) return make_pair(t, t);
	if(t->x < l)
	{
		auto z = split(t->r, l);
		t->r = z.x;
		return make_pair(fix(t), z.y);
	}
	else
	{
		auto z = split(t->l, l);
		t->l = z.y;
		return make_pair(z.x, fix(t));
	}
}

treap merge(treap a, treap b)
{
	a = fix(a);
	b = fix(b);
	if(!a) return b;
	if(!b) return a;
	if(a->y > b->y)
	{
		a->r = merge(a->r, b);
		return fix(a);
	}
	else
	{
		b->l = merge(a, b->l);
		return fix(b);
	}
}

struct comp
{
	li cur_sum;
	int beg;
	li treap_sum;
	treap t;
	
	void upd()
	{
		cur_sum = treap_sum + beg * 1ll * getSum(t);
	}
	
	void insert(int bi)
	{
		ptt p = split(t, bi);
		treap_sum += getSum(p.x) + getSiz(p.y) * 1ll * bi;
		t = merge(p.x, merge(new node(bi, rnd(), bi, 1, NULL, NULL), p.y));
		upd();
	}
	
	void fill_treap(treap t)
	{
		if(!t) return;
		insert(t->x);
		fill_treap(t->l);
		fill_treap(t->r);
	}
};

comp merge(comp a, comp b)
{
	if(getSiz(a.t) < getSiz(b.t))
		swap(a, b);
	a.beg = min(a.beg, b.beg);
	a.fill_treap(b.t);
	delete b.t;
	a.upd();
	return a;
}

set<int> free_pos;

const int N = 400043;

int p[N];
int siz[N];
comp cc[N];

li start_sum = 0;
li end_sum = 0;

int get(int x)
{
	return (p[x] == x ? x : (p[x] = get(p[x])));
}

void merge(int x, int y)
{
	x = get(x);
	y = get(y);
	if(x == y) return;
	if(siz[x] < siz[y]) swap(x, y);
	end_sum -= cc[x].cur_sum;
	end_sum -= cc[y].cur_sum;
	p[y] = x;
	siz[x] += siz[y];
	cc[x] = merge(cc[x], cc[y]);
	end_sum += cc[x].cur_sum;
}

void process(int ai, int bi)
{
	start_sum += ai * 1ll * bi;
	int pos = *free_pos.lower_bound(ai);
	free_pos.erase(pos);
	siz[pos] = 1;
	p[pos] = pos;
	cc[pos].beg = pos;
	cc[pos].insert(bi);
	end_sum += cc[pos].cur_sum;
	if(!free_pos.count(pos - 1))
		merge(pos, pos - 1);
	if(!free_pos.count(pos + 1))
		merge(pos, pos + 1);
	printf("%lldn", end_sum - start_sum);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
  	for(int i = 0; i < N; i++)
  		free_pos.insert(i);
	for(int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		process(a, b);
    }
    return 0;
}
```
