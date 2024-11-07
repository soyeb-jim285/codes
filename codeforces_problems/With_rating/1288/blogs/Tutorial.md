# Tutorial

[1288A - Deadline](../problems/A._Deadline.md "Educational Codeforces Round 80 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1288A - Deadline](../problems/A._Deadline.md "Educational Codeforces Round 80 (Rated for Div. 2)")

At first, let's note that if xx is integer and xx and yy are non-negative then x+⌈y⌉=⌈x+y⌉x+⌈y⌉=⌈x+y⌉. So, instead of looking at x+⌈dx+1⌉x+⌈dx+1⌉ we can consider ⌈x+dx+1⌉⌈x+dx+1⌉.

It's easier since the function x+dx+1=(x+1)+d(x+1)−1x+dx+1=(x+1)+d(x+1)−1 is more common function and it can be proven that it's concave upward. It means that this function has a unique minimum and, moreover, we can calculate it: f(x)=x+dx+1f(x)=x+dx+1 has minimum value in x0=d−−√−1x0=d−1 and f(x0)=2d−−√−1f(x0)=2d−1.

Since the ceiling function is monotonically increasing so we can assume that ⌈f(x)⌉≤⌈f(x+1)⌉⌈f(x)⌉≤⌈f(x+1)⌉ for all x≥d−−√x≥d.

So we can just iterate xx from 00 to ⌊d−−√⌋⌊d⌋ and check the unequation ⌈f(x)⌉≤n⌈f(x)⌉≤n. The total complexity is equal to O(Td−−√)O(Td).

There is a simple optimization: because of the monotone ceiling we can prove that we need to check only ⌊d−−√−1⌋⌊d−1⌋ and ⌈d−−√−1⌉⌈d−1⌉.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	int tt = clock();
#endif
	
	int T; cin >> T;
	while(T--) {
		int n, d;
		cin >> n >> d;
		
		int x, MAG = (int)sqrt(d) + 10;
		for(x = 0; x < MAG; x++) {
			if(x + (d + x) / (x + 1) <= n)
				break;
		}
		cout << (x < MAG ? "YES" : "NO") << endl;
	}

	return 0;
}
```
[1288B - Yet Another Meme Problem](../problems/B._Yet_Another_Meme_Problem.md "Educational Codeforces Round 80 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1288B - Yet Another Meme Problem](../problems/B._Yet_Another_Meme_Problem.md "Educational Codeforces Round 80 (Rated for Div. 2)")

Let's perform some conversions:

a⋅b+a+b=conc(a,b)a⋅b+a+b=conc(a,b)

a⋅b+a+b=a⋅10|b|+ba⋅b+a+b=a⋅10|b|+b, where |b||b| is the length of decimal representation of bb.

a⋅b+a=a⋅10|b|a⋅b+a=a⋅10|b|

b+1=10|b|b+1=10|b|

Thus, bb always look like 99…9999…99. So, the answer is a∗(|b+1|−1)a∗(|b+1|−1).

 **Solution (Roms)**
```cpp
for t in range(int(input())):
	a, b = map(int, input().split())
	print(a * (len(str(b + 1)) - 1))
```
[1288C - Two Arrays](../problems/C._Two_Arrays.md "Educational Codeforces Round 80 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1288C - Two Arrays](../problems/C._Two_Arrays.md "Educational Codeforces Round 80 (Rated for Div. 2)")

Let's consider the following sequence:

a1,a2,…,am,bm,bm−1,…,b1a1,a2,…,am,bm,bm−1,…,b1.

It's sequence of length 2m2m sorted in non-descending order, where each element of each sequence is an integer between 11 and nn.

We can find the number of such sequences by simple combinatorics — it's combination with repetitions. So the answer is (n+2m−12m)=(n+2m−1)!(2m)!(n−1)!(n+2m−12m)=(n+2m−1)!(2m)!(n−1)!.

 **Solution (Roms)**
```cpp
from math import factorial as fact
mod = 10**9 + 7

def C(n, k):
	return fact(n) // (fact(k) * fact(n - k))

n, m = map(int, input().split())
print(C(n + 2*m - 1, 2*m) % mod)
```
[1288D - Minimax Problem](../problems/D._Minimax_Problem.md "Educational Codeforces Round 80 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1288D - Minimax Problem](../problems/D._Minimax_Problem.md "Educational Codeforces Round 80 (Rated for Div. 2)")

We will use binary search to solve the problem. Suppose we want to know if the answer is not less than xx.

Each array can be represented by a mm-bit mask, where the ii-th bit is 11 if the ii-th element of the array is not less than xx, or 00 if the ii-th element is less than xx. If we want to verify that the answer is not less than xx, we have to choose two arrays such that bitwise OR of their masks is 2m−12m−1.

Checking all pairs of arrays is too slow. Instead, we can treat the arrays represented by the same masks as equal — so we will have no more than 2m2m distinct arrays, and we can iterate over 4m4m pairs. Overall, the solution works in O(logA(4m+nm))O(log⁡A(4m+nm)).

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int> > a;
int a1, a2;

bool can(int mid)
{
    vector<int> msk(1 << m, -1);
    for(int i = 0; i < n; i++)
    {
        int cur = 0;
        for(int j = 0; j < m; j++)
            if(a[i][j] >= mid)
                cur ^= (1 << j);
        msk[cur] = i;
    }
    if(msk[(1 << m) - 1] != -1)
    {
        a1 = a2 = msk[(1 << m) - 1];
        return true;
    }
    for(int i = 0; i < (1 << m); i++)
        for(int j = 0; j < (1 << m); j++)
            if(msk[i] != -1 && msk[j] != -1 && (i | j) == (1 << m) - 1)
            {
                a1 = msk[i];
                a2 = msk[j];
                return true;
            }
    return false;
}

int main()
{
    scanf("%d %d", &n, &m);
    a.resize(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    int lf = 0;
    int rg = int(1e9) + 43;
    while(rg - lf > 1)
    {
        int m = (lf + rg) / 2;
        if(can(m))
            lf = m;
        else
            rg = m;            
    }
    assert(can(lf));
    printf("%d %dn", a1 + 1, a2 + 1);
}
```
[1288E - Messenger Simulator](../problems/E._Messenger_Simulator.md "Educational Codeforces Round 80 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1288E - Messenger Simulator](../problems/E._Messenger_Simulator.md "Educational Codeforces Round 80 (Rated for Div. 2)")

So I have two slightly different approaches to the problem. There is a straightforward (no brain) one and a bit smarter one.

The minimum place is the same in both solutions. For the ii-th friend it's just ii if he never moves and 11 otherwise.

Obtaining the maximum place is trickier.

For the first approach, take a look what happens with some friend ii after he gets moved to the first position. Or what's more useful — what happens after he gets moved to the first position and before he gets moved again afterwards (or the queries end). Notice how every other friend is to the right of him initially. Thus, if anyone sends a message, then the position of the friend ii increases by one. However, if that friend moves again, nothing changes. That should remind of a well-known problem already. You are just required to count the number of distinct values on some segments. The constraints allow you to do whatever you want: segtree with vectors in nodes, Mo, persistent segtree (I hope ML is not too tight for that).

Unfortunately, for each friend we have missed the part before his first move. In that case for each ii you need to count the number of distinct values greater than ii, as only friends with greater index will matter. Luckily, you can do it in a single BIT. Let jj-th its value be set to zero if the friend jj hasn't sent messages and one otherwise. Let's process messages from left to right. If the friend sends a message for the first time, then update the BIT with 11 in his index and update his answer with the suffix sum of values greater than his index.

Finally, there are also friends, who haven't sent messages at all. As we have built the BIT already, the only thing left is to iterate over these friends and update the answers for them with a suffix sum.

Overall complexity: O((n+m)log2m)O((n+m)log2⁡m)/O((n+m)m−−√)O((n+m)m)/O((n+m)logm)O((n+m)log⁡m). The attached solutions are O((n+m)m−−√)O((n+m)m) and O((n+m)log2m)O((n+m)log2⁡m).

The second solution requires a small observation to be made. Notice that for each friend you can only check his position right before his moves and at the end of the messages. That works because the position can decrease only by his move, so it's either increases or stays the same between the moves.

So let's learn to simulate the process quickly. The process we are given requires us to move someone to the first position and then shift some friends. Let's not shift! And let's also reverse the list, it's more convenient to append instead of prepending. So initially the list is n,n−1,…,1n,n−1,…,1 and the message moves a friend to the end of the list.

Allocate n+mn+m positions in a BIT, for example. Initially the first nn positions are taken, the rest mm are free (mark them with ones and zeroes, respectively). For each friend his position in this BIT is known (initially they are posi=n−i+1posi=n−i+1, because we reversed the list). On the jj-th message sent count the number of taken positions to the right of posa[j]posa[j], set 00 in posa[j]posa[j], update posa[j]:=j+nposa[j]:=j+n and set 11 in posa[j]posa[j].

And don't forget to update each friend's maximum after all the messages are sent, that is the number of taken positions to the right of his final one as well.

Overall complexity O((n+m)log(n+m))O((n+m)log⁡(n+m)).

 **Solution 1 (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define x first 
#define y second

using namespace std;

const int N = 300 * 1000 + 13;
const int P = 550;

typedef pair<int, int> pt;

int n;
int a[N];
vector<int> pos[N];
pt ans[N];

int cnt[N];
int tot;

void add(int x){
	++cnt[x];
	if (cnt[x] == 1) ++tot;
}

void rem(int x){
	if (cnt[x] == 1) --tot;
	--cnt[x];
}

int f[N];

void upd(int x){
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		++f[i];
}

int get(int x){
	int res = 0;
	for (int i = x; i < N; i |= i + 1)
		res += f[i];
	return res;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	forn(i, m){
		scanf("%d", &a[i]);
		--a[i];
	}
	forn(i, m){
		pos[a[i]].push_back(i);
	}
	
	vector<pt> qr;
	forn(i, n){
		for (int j = 1; j < int(pos[i].size()); ++j)
			qr.push_back(make_pair(pos[i][j - 1] + 1, pos[i][j] - 1));
		if (!pos[i].empty())
			qr.push_back(make_pair(pos[i].back() + 1, m - 1));
	}
	
	sort(qr.begin(), qr.end(), [](const pt &a, const pt &b){
		if (a.x / P != b.x / P)
			return a.x < b.x;
		if ((a.x / P) & 1)
			return a.y < b.y;
		return a.y > b.y;
	});
	
	forn(i, n) ans[i] = {i, i};
	forn(i, m) ans[a[i]].x = 0;
	
	int L = 0, R = -1;
	forn(i, qr.size()){
		int l = qr[i].x;
		int r = qr[i].y;
		if (r < l) continue;
		
		int x = a[qr[i].x - 1];
		while (L < l) rem(a[L++]);
		while (L > l) add(a[--L]);
		while (R > r) rem(a[R--]);
		while (R < r) add(a[++R]);
		
		ans[x].y = max(ans[x].y, tot);
	}
	forn(i, m){
		if (i == pos[a[i]][0]){
			ans[a[i]].y = max(ans[a[i]].y, a[i] + get(a[i]));
			upd(a[i]);
		}
	}
	forn(i, n) if (pos[i].empty()){
		ans[i].y = max(ans[i].y, i + get(i));
	}
	
	forn(i, n) printf("%d %dn", ans[i].x + 1, ans[i].y + 1);
	return 0;
}
```
 **Solution 2 (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define x first 
#define y second

using namespace std;

const int N = 300 * 1000 + 13;

typedef pair<int, int> pt;

int n;
int a[N];
vector<int> pos[N];
pt ans[N];
int prv[N];

vector<int> t[4 * N];

void build(int v, int l, int r){
	if (l == r - 1){
		t[v].push_back(prv[l]);
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t[v].resize(r - l);
	merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(), t[v].begin());
}

int get(int v, int l, int r, int L, int R, int val){
	if (L >= R)
		return 0;
	if (l == L && r == R)
		return lower_bound(t[v].begin(), t[v].end(), val) - t[v].begin();
	int m = (l + r) / 2;
	return get(v * 2, l, m, L, min(m, R), val) + get(v * 2 + 1, m, r, max(m, L), R, val);
}

int f[N];

void upd(int x){
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		++f[i];
}

int get(int x){
	int res = 0;
	for (int i = x; i < N; i |= i + 1)
		res += f[i];
	return res;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	forn(i, m){
		scanf("%d", &a[i]);
		--a[i];
	}
	forn(i, m){
		pos[a[i]].push_back(i);
	}
	
	vector<pt> qr;
	forn(i, n){
		for (int j = 1; j < int(pos[i].size()); ++j)
			qr.push_back(make_pair(pos[i][j - 1] + 1, pos[i][j] - 1));
		if (!pos[i].empty())
			qr.push_back(make_pair(pos[i].back() + 1, m - 1));
	}
	
	forn(i, n) ans[i] = {i, i};
	forn(i, m) ans[a[i]].x = 0;
	
	forn(i, n){
		int cur = -1;
		for (auto it : pos[i]){
			prv[it] = cur;
			cur = it;
		}
	}
	build(1, 0, m);
	
	forn(i, qr.size()){
		int l = qr[i].x;
		int r = qr[i].y;
		if (r < l) continue;
		int x = a[qr[i].x - 1];
		int cnt = get(1, 0, m, l, r + 1, l);
		ans[x].y = max(ans[x].y, cnt);
	}
	
	forn(i, m){
		if (i == pos[a[i]][0]){
			ans[a[i]].y = max(ans[a[i]].y, a[i] + get(a[i]));
			upd(a[i]);
		}
	}
	forn(i, n) if (pos[i].empty()){
		ans[i].y = max(ans[i].y, i + get(i));
	}
	
	forn(i, n) printf("%d %dn", ans[i].x + 1, ans[i].y + 1);
	return 0;
}
```
 **Solution 3 (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 600 * 1000 + 13;

int f[N];

void upd(int x, int val){
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		f[i] += val;
}

int get(int x){
	int res = 0;
	for (int i = x; i < N; i |= i + 1)
		res += f[i];
	return res;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> mn(n);
	iota(mn.begin(), mn.end(), 0);
	vector<int> mx = mn;
	
	vector<int> a(m);
	forn(i, m){
		scanf("%d", &a[i]);
		--a[i];
		mn[a[i]] = 0;
	}
	
	vector<int> pos(n);
	forn(i, n) pos[i] = n - i - 1;
	forn(i, n) upd(i, 1);
	
	forn(i, m){
		mx[a[i]] = max(mx[a[i]], get(pos[a[i]] + 1));
		upd(pos[a[i]], -1);
		pos[a[i]] = i + n;
		upd(pos[a[i]], 1);
	}
	forn(i, n){
		mx[i] = max(mx[i], get(pos[i] + 1));
	}
	
	forn(i, n) printf("%d %dn", mn[i] + 1, mx[i] + 1);
	return 0;
}
```
[1288F - Red-Blue Graph](../problems/F._Red-Blue_Graph.md "Educational Codeforces Round 80 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1288F - Red-Blue Graph](../problems/F._Red-Blue_Graph.md "Educational Codeforces Round 80 (Rated for Div. 2)")

A lot of things in this problem may tell us that we should try thinking about a flow solution. Okay, let's try to model the problem as a flow network.

First of all, our network will consist of vertices and edges of the original graph. We somehow have to denote "red", "blue" and "colorless" edges; we will do it as follows: each edge of the original graph corresponds to a bidirectional edge with capacity 11 in the network; if the flow goes from the left part to the right part along the edge, it is red; if the flow goes from right to left, it is a blue edge; and if there is no flow along the edge, it is colorless.

Okay, we need to impose some constraints on the vertices. Consider some vertex vv from the left part. Each red edge incident to it transfers one unit of flow from it to some other vertex, and each blue edge incident to it does the opposite. So, the difference between the number of blue and red edges incident to vv is the amount of excess flow that has to be transfered somewhere else. If vv is colorless, there are no constraints on the colors of edges, so this amount of excess flow does not matter — to model it, we can add a directed edge from source to vv with infinite capacity, and a directed edge from vv to sink with infinite capacity. What if vv is red? At least one unit of flow should be transfered to it; so we add a directed edge from the source to vv with infinite capacity such that there should be at least one unit of flow along it. And if vv is blue, we need to transfer at least one unit of excess flow from it — so we add a directed edge from vv to the sink with infinite capacity such that there is at least one unit of flow along it. The colors of the vertices in the right part can be modeled symmetrically.

How to deal with edges such that there should be some flow along them? You may use classic "flows with demands" approach from here: [https://cp-algorithms.com/graph/flow_with_demands.html](https://codeforces.com/https://cp-algorithms.com/graph/flow_with_demands.html). Or you can model it with the help of the costs: if the flow along the edge should be between ll and rr, we can add two edges: one with capacity ll and cost kk (where kk is a negative number with sufficiently large absolute value, for example, −109−109), and another with capacity r−lr−l and cost 00.

Okay, now we know how to find at least one painting. How about finding the cheapest painting that meets all the constraints? One of the simplest ways to do it is to impose costs on the edges of the original graph: we can treat each edge of the original graph as a pair of directed edges, one going from left to right with capacity 11 and cost rr, and another going from right to left with capacity 11 and cost bb.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 443;

int n1, n2, m, r, b;
string s1, s2;
int u[N];
int v[N];

struct edge
{
    int y, c, f, cost;
    edge() {};
    edge(int y, int c, int f, int cost) : y(y), c(c), f(f), cost(cost) {};
};

int bal[N][N];
int s, t, oldS, oldT, V;
vector<int> g[N];
vector<edge> e;

void add(int x, int y, int c, int cost)
{
    g[x].push_back(e.size());
    e.push_back(edge(y, c, 0, cost));
    g[y].push_back(e.size());
    e.push_back(edge(x, 0, 0, -cost));
}

int rem(int num)
{
    return e[num].c - e[num].f;
}   

void add_LR(int x, int y, int l, int r, int cost)
{
    int c = r - l;
    if(l > 0)
    {
        add(s, y, l, cost);
        add(x, t, l, cost);
    }
    if(c > 0)
    {
        add(x, y, c, cost);
    }
}

int p[N];
int d[N];
int pe[N];
int inq[N];

bool enlarge()
{
    for(int i = 0; i < V; i++)
    {
        d[i] = int(1e9);
        p[i] = -1;
        pe[i] = -1;
        inq[i] = 0;
    }
    d[s] = 0;
    queue<int> q;
    q.push(s);
    inq[s] = 1;
    while(!q.empty())
    {
        int k = q.front();
        q.pop();
        inq[k] = 0;
        for(auto z : g[k])
        {
            if(!rem(z)) continue;
            if(d[e[z].y] > d[k] + e[z].cost)
            {
                p[e[z].y] = k;
                pe[e[z].y] = z;
                d[e[z].y] = d[k] + e[z].cost;
                if(!inq[e[z].y])
                {
                    q.push(e[z].y);
                    inq[e[z].y] = 1;
                }
            }
        }
    }
    if(p[t] == -1)
        return false;
    int cur = t;
    while(cur != s)
    {
        e[pe[cur]].f++;
        e[pe[cur] ^ 1].f--;
        cur = p[cur];
    }
    return true;
}

void add_edge(int x, int y)
{
    add(x, y + n1, 1, r);
    add(y + n1, x, 1, b);
}

void impose_left(int x)
{
    if(s1[x] == 'R')
    {
        add_LR(oldS, x, 1, m, 0);
    }
    else if(s1[x] == 'B')
    {
        add_LR(x, oldT, 1, m, 0);
    }
    else
    {
        add(oldS, x, m, 0);
        add(x, oldT, m, 0);
    }
}

void impose_right(int x)
{
    if(s2[x] == 'R')
    {
        add_LR(x + n1, oldT, 1, m, 0);
    }
    else if(s2[x] == 'B')
    {
        add_LR(oldS, x + n1, 1, m, 0);
    }
    else
    {
        add(oldS, x + n1, m, 0);
        add(x + n1, oldT, m, 0);
    }
}

void construct_bal()
{
    for(int i = 0; i < n1; i++)
    {
        for(auto z : g[i])
        {
            if(e[z].y >= n1 && e[z].y < n1 + n2)
                bal[i][e[z].y - n1] += e[z].f;
        }
    }
}

void find_ans()
{
    int res = 0;
    string w = "";
    for(auto x : g[s])
        if(rem(x))
        {
            cout << -1 << endl;
            return;
        }
    for(int i = 0; i < m; i++)
    {
        if(bal[u[i]][v[i]] > 0)
        {
            bal[u[i]][v[i]]--;
            res += r;
            w += "R";
        }
        else if(bal[u[i]][v[i]] < 0)
        {
            bal[u[i]][v[i]]++;
            res += b;
            w += "B";
        }
        else w += "U";
    }
    cout << res << endl << w << endl;
}

int main()
{                       
    cin >> n1 >> n2 >> m >> r >> b;
    cin >> s1;
    cin >> s2;
    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }

    oldS = n1 + n2;
    oldT = oldS + 1;
    s = oldT + 1;
    t = s + 1;
    V = t + 1;

    for(int i = 0; i < n1; i++)
        impose_left(i);
    for(int i = 0; i < n2; i++)
        impose_right(i);
    for(int i = 0; i < m; i++)
        add_edge(u[i], v[i]);
    add(oldT, oldS, 100000, 0);
    while(enlarge());
    construct_bal();
    find_ans();
}
```
