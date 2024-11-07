# Tutorial

[1380A - Three Indices](../problems/A._Three_Indices.md "Educational Codeforces Round 91 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1380A - Three Indices](../problems/A._Three_Indices.md "Educational Codeforces Round 91 (Rated for Div. 2)")

A solution in $O(n^2)$: iterate on $j$, check that there exists an element lower than $a_j$ to the left of it, and check that there exists an element lower than $a_j$ to the right of it. Can be optimized to $O(n)$ with prefix/suffix minima.

A solution in $O(n)$: note that if there is some answer, we can find an index $j$ such that $a_{j - 1} < a_j$ and $a_j > a_{j + 1}$ (if there is no such triple, the array descends to some point and ascends after that, so there is no answer). So we only have to check $n - 2$ consecutive triples.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int n;
int a[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 1; i < n - 1; ++i) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			cout << "YES" << endl;
			cout << i << ' ' << i + 1 << ' ' << i + 2 << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
}
```
[1380B - Universal Solution](../problems/B._Universal_Solution.md "Educational Codeforces Round 91 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1380B - Universal Solution](../problems/B._Universal_Solution.md "Educational Codeforces Round 91 (Rated for Div. 2)")

Let's look at the contribution of each choice $c_i$ to the total number of wins $win(1) + win(2) + \dots + win(n)$ (we can look at "total" instead of "average", since "average" is equal to "total" divided by $n$). For example, let's look at the first choice $c_1$: in $win(1)$ we compare $c_1$ with $s_1$, in $win(2)$ — $c_1$ with $s_2$, in $win(3)$ — $c_1$ with $s_3$ and so on.

In the result, we compare $c_1$ with all $s_i$ once. So, to maximize the total sum, we need to choose $c_1$ that beats the maximum number of $s_i$ or, in other words, let's find the most frequent character in $s$ and choose $c_1$ that beats it.

Okay, we found the optimal $c_1$. But if we look at the contribution of any other $c_i$ we can note that we compare any $c_i$ with all $s_i$ once. So we can choose all $c_i$ equal to $c_1$ which is equal to the choice that beats the most frequent choice in $s$.

 **Solution (adedalic)**
```cpp
fun main() {
    val winBy = mapOf('R' to 'P', 'S' to 'R', 'P' to 'S')
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        val maxCnt = s.groupingBy { it }.eachCount().maxBy { it.value }!!.key
        println("${winBy[maxCnt]}".repeat(s.length))
    }
}
```
[1380C - Create The Teams](../problems/C._Create_The_Teams.md "Educational Codeforces Round 91 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1380C - Create The Teams](../problems/C._Create_The_Teams.md "Educational Codeforces Round 91 (Rated for Div. 2)")

At first, notice that if only $k < n$ programmers are taken, then the same or even better answer can be achieved if $k$ strongest programmers are taken.

Now let's sort the programmers in a non-increasing order and choose some assignment into the teams. For each team only the rightmost taken programmer of that team matters (the sorted sequence implies that the rightmost is the weakest).

Take a look at the team with the strongest weakest member. If the number of programmers in it is less than the position of the weakest member, then you can safely rearrange the programmers before him in such a way that none of parameters of later teams change and the weakest member in the first one only becomes stronger. After that you can get rid of the first team (as it takes exactly the prefix of all the programmers) and proceed to fix the later teams.

Thus, we can see that there is an optimal solution such that each team is a segment and all the teams together take some prefix of the programmers. So we can finally run a greedy solution that takes programmers from left to right and increases the answer if the conditions for the latest team hold.

Overall complexity: $O(n \log n)$.

 **Solution (Roms)**
```cpp
for _ in range(int(input())):
    n, x = map(int, input().split())
    a = sorted(list(map(int, input().split())), reverse=True)
    res, cur = 0, 1
    for s in a:
        if s * cur >= x:
            res += 1
            cur = 0
        cur += 1
    print(res)
    
```
[1380D - Berserk And Fireball](../problems/D._Berserk_And_Fireball.md "Educational Codeforces Round 91 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1380D - Berserk And Fireball](../problems/D._Berserk_And_Fireball.md "Educational Codeforces Round 91 (Rated for Div. 2)")

The first thing we need to do is to find the occurrences of $b_i$ in the sequence $[a_1, a_2, \dots, a_n]$ — these are the monsters that have to remain. Since both spells (Fireball and Berserk) affect consecutive monsters, we should treat each subsegment of monsters we have to delete separately.

Consider a segment with $x$ monsters we have to delete such that the last monster before it has power $l$, the first monster after the segment has power $r$, and the strongest monster on the segment has power $p$.

If $x \bmod k \ne 0$, then we have to use Berserk at least $x \bmod k$ times. Let's make the strongest monster on segment kill some other monster. If $x < k$, then the strongest monster should also be killed by one of the monsters bounding the segment, so if $l < p$ and $r < p$, there is no solution.

Okay, now the number of monsters is divisible by $k$. If it is more profitable to use Fireball, we use the required number of Fireballs to kill all of them. Otherwise, we have to kill the maximum possible number of monsters with Berserk and finish the remaining ones with Fireball. If $l > p$ or $r > p$, then one of the monsters just outside the segment can kill all the monsters inside the segment; otherwise, the strongest monster should kill adjacent monsters until exactly $k$ remain, and those $k$ monsters are finished with a single Fireball.

Now we know what we need to consider when processing a single segment; all that's left is to sum the minimum required mana over all such segments. Since the total length of these segments is at most $n - 1$ and we can process each segment in linear time, we have a solution with complexity $O(n)$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 9;

int n, m;
long long x, k, y;
int a[N];
int b[N];

bool upd(int l, int r, long long &res) {
    if (l > r) return true;
    bool canDel = false;
    int mx = *max_element(a + l, a + r + 1);
    int len = r - l + 1;
    if (l - 1 >= 0 && a[l - 1] > mx) canDel = true;
    if (r + 1 < n && a[r + 1] > mx) canDel = true;
    if (len < k && !canDel) return false;
    
    int need = len % k;
    res += need * y;
    len -= need;
    
    if (y * k >= x) {
        res += len / k * x;
    } else if(canDel) {
        res += len * y;
    } else {
        res += (len - k) * y + x;
    }
    
    return true;
}

int main(){
    scanf("%d %d", &n, &m);
    scanf("%lld %lld %lld", &x, &k, &y);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < m; ++i) scanf("%d", b + i);
    
    long long res = 0;
    int lst = -1, posa = 0, posb = 0;
    while (posb < m) {
        while(posa < n && a[posa] != b[posb]) ++posa;
        if (posa == n) {
            puts("-1");
            return 0;
        }
        
        if (!upd(lst + 1, posa - 1, res)) {
            puts("-1");
            return 0;
        }
        
        lst = posa;
        ++posb;
    }
    
    if (!upd(lst + 1, n - 1, res)) {
        puts("-1");
        return 0;
    }
    
    printf("%lldn", res);
    
    return 0;
}
```
[1380E - Merging Towers](../problems/E._Merging_Towers.md "Educational Codeforces Round 91 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms") and [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1380E - Merging Towers](../problems/E._Merging_Towers.md "Educational Codeforces Round 91 (Rated for Div. 2)")

First of all, let's try to find a simple way to evaluate the difficulty of a given set of towers. I claim that the difficulty is equal to the number of pairs of discs $(i, i + 1)$ that belong to different towers.

The beginning of the proof

* during each operation we can "merge" at most one such pair: if we move discs to the tower with disk $i$ on top of it, only the pair $(i - 1, i)$ can be affected;
* we can always take the first several $k$ discs belonging to the same tower and move them to the tower containing disc $k + 1$, thus merging exactly one pair in exactly one operation.

The end of the proof

After that, there are two main approaches: LCA and small-to-large merging. The model solution uses LCA, so I'll describe it.

For each pair $(i, i + 1)$, we have to find the first moment these discs belong to the same tower. To do so, let's build a rooted tree on $2m - 1$ vertices. The vertices $1$ to $m$ will be the leaves of the tree and will represent the original towers. The vertex $m + i$ will represent the tower created during the $i$-th query and will have two children — the vertices representing the towers we merge during the $i$-th query. The vertex $2m - 1$ is the root.

Now, if some vertex $x$ is an ancestor of vertex $y$, it means that the tower represented by vertex $x$ contains all the discs from the tower represented by vertex $y$. So, to find the first tower containing two discs $i$ and $i + 1$, we have to find the lowest common ancestor of the vertices representing the towers $t_i$ and $t_{i + 1}$. The easiest way to do it is to implement something like binary lifting, which allows us to solve the problem in $O(n \log m)$.

 **Solution 1 (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 200043;
const int L = 20;

vector<int> g[2 * N];
int p[2 * N];
int up[2 * N][L];
int idx[N];
int psum[N];
int cur[N];
int tin[2 * N];
int tout[2 * N];
int T = 0;

void dfs(int x, int y)
{
	tin[x] = T++;
	p[x] = y;
	up[x][0] = y;
	for(int i = 1; i < L; i++)
		up[x][i] = up[up[x][i - 1]][i - 1];
	for(auto z : g[x])
		dfs(z, x);
	tout[x] = T++;
}

bool is_ancestor(int x, int y)
{
	return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int lca(int x, int y)
{
	if(is_ancestor(x, y))
		return x;
	for(int i = L - 1; i >= 0; i--)
		if(!is_ancestor(up[x][i], y))
			x = up[x][i];
	return p[x];
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &idx[i]);
		idx[i]--;
	}
	for(int i = 0; i < m; i++)
		cur[i] = i;
	for(int i = 0; i < m - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		int nidx = m + i;
		g[nidx].push_back(cur[x]);
		g[nidx].push_back(cur[y]);
		cur[x] = nidx;
	}
	int root = m * 2 - 2;
	dfs(root, root);
	for(int i = 0; i < n - 1; i++)
	{
		int t = lca(idx[i], idx[i + 1]);
		if(t < m)
			psum[0]++;
		else
			psum[t - m + 1]++;
	}
	for(int i = 0; i < m - 1; i++)
		psum[i + 1] += psum[i];
	for(int i = 0; i < m; i++)
		printf("%dn", n - 1 - psum[i]);
}
```
 **Solution 2 (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n, m;
vector<int> p;
vector<vector<int>> val;
vector<int> who;

int getp(int a){
	return a == p[a] ? a : p[a] = getp(p[a]);
}

int main(){
	scanf("%d%d", &n, &m);
	p.resize(m);
	val.resize(m);
	who.resize(n);
	int ans = n - 1;
	forn(i, m)
		p[i] = i;
	forn(i, n){
		int x;
		scanf("%d", &x);
		--x;
		who[i] = x;
		ans -= (i && who[i] == who[i - 1]);
		val[who[i]].push_back(i);
	}
	printf("%dn", ans);
	forn(i, m - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		v = getp(v - 1), u = getp(u - 1);
		if (val[v].size() < val[u].size())
			swap(v, u);
		for (int x : val[u]){
			if (x) ans -= who[x - 1] == v;
			if (x < n - 1) ans -= who[x + 1] == v;
		}
		for (int x : val[u]){
			val[v].push_back(x);
			who[x] = v;
		}
		p[u] = v;
		printf("%dn", ans);
	}
	return 0;
}
```
[1380F - Strange Addition](../problems/F._Strange_Addition.md "Educational Codeforces Round 91 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1380F - Strange Addition](../problems/F._Strange_Addition.md "Educational Codeforces Round 91 (Rated for Div. 2)")

Let's solve the task as if there are no updates. This can be done with a pretty straightforward dp.

$dp_i$ is the number of pairs $(a, b)$ such that the result of the strange addition of $a$ and $b$ is the prefix of $c$ of length $i$. $dp_0 = 1$. From each state you can add a single digit to $a$ and to $b$ at the same time. You can either go to $dp_{i+1}$ and multiply the answer by the number of pairs of digits than sum up to $c_i$. Or go to $dp_{i+2}$ and multiply the answer by the number of pairs of digits than sum up to $c_i c_{i+1}$. Note that no pair of digits can sum up to a three-digit value, so it makes no sense to go further.

Let's optimize this dp with some data structure. Segment tree will work well. Let the node store the number of ways to split the segment $[l; r)$ into blocks of size $1$ or $2$ so that:

1. both the leftmost character and the rightmost character are not taken into any block;
2. the leftmost character is taken into some block and the rightmost character is not taken into any block;
3. the leftmost character is not taken into any block and the rightmost character is taken into some block;
4. both the leftmost and the rightmost characters are taken into some blocks.

This structure makes the merge pretty manageable. You should glue up the segments in such a way that all the middle characters are taken into some block: either in separate blocks in their own segments or into the same block of length $2$.

The answer will be in the root of the tree in a value such that both characters are taken.

The update in the segment tree will still work in $O(\log n)$.

Overall complexity: $O(n + m \log n)$.

 **Solution 1 (pikmike)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

const int MOD = 998244353;
const int N = 500 * 1000 + 13;

string s;

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int mul(int a, int b){
	return a * 1ll * b % MOD;
}

struct node{
	int val[4], len;
};

node merge(const node &a, const node &b, int l, int r){
	node c;
	int na = a.len == 1 ? 0 : 1;
	int nb = b.len == 1 ? 0 : 2;
	c.len = a.len + b.len;
	c.val[0] = mul(a.val[na], b.val[nb]);
	c.val[1] = mul(a.val[na], b.val[3]);
	c.val[2] = mul(a.val[3], b.val[nb]);
	c.val[3] = mul(a.val[3], b.val[3]);
	if (l == 1){
		na = a.len == 1 ? 2 : 0;
		nb = b.len == 1 ? 1 : 0;
		c.val[na + nb] = add(c.val[na + nb], mul(mul(a.val[0], b.val[0]), 19 - (l * 10 + r)));
		c.val[1 + na] = add(c.val[1 + na], mul(mul(a.val[0], b.val[1]), 19 - (l * 10 + r)));
		c.val[2 + nb] = add(c.val[2 + nb], mul(mul(a.val[2], b.val[0]), 19 - (l * 10 + r)));
		c.val[3] = add(c.val[3], mul(mul(a.val[2], b.val[1]), 19 - (l * 10 + r)));
	}
	return c;
}

node t[4 * N];

void build(int v, int l, int r){
	t[v].len = r - l;
	if (l == r - 1){
		t[v].val[0] = 1;
		t[v].val[3] = s[l] + 1;
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t[v] = merge(t[v * 2], t[v * 2 + 1], s[m - 1], s[m]);
}

void upd(int v, int l, int r, int x, int val){
	if (l == r - 1){
		s[l] = val;
		t[v].val[3] = s[l] + 1;
		return;
	}
	int m = (l + r) / 2;
	if (x < m)
		upd(v * 2, l, m, x, val);
	else
		upd(v * 2 + 1, m, r, x, val);
	t[v] = merge(t[v * 2], t[v * 2 + 1], s[m - 1], s[m]);
}

int main(){
	int n, m;

	scanf("%d%d", &n, &m);
	static char buf[N];
	scanf("%s", buf);
	s = buf;
	forn(i, n) s[i] -= '0';
	
	memset(t, 0, sizeof(t));
	build(1, 0, n);
	
	forn(i, m){
		int x, v;
		scanf("%d%d", &x, &v);
		--x;
		upd(1, 0, n, x, v);
		printf("%dn", t[1].val[3]);
	}
}
```
 **Solution 2 (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(5e5) + 9;
const int MOD = 998244353;

int mul(int a, int b) {
    return (a * 1LL * b) % MOD;
}

void add(int &a, int x) {
    a += x;
    a %= MOD;
}

int bp(int a, int n) {
    int res = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) res = mul(res, a);
        a = mul(a, a);
    }
    return res;
}

int inv(int a) {
    int ia = bp(a, MOD - 2);
    assert(mul(a, ia) == 1);
    return ia;
}

int n, m;
string s;
int dp[N][10];
int idp[N][10];
set <pair<int, int> > lr;
int res = 1;

void updRes(int l, int r, int c) {
    assert(l <= r);
    if (c == 1) {
        assert(!lr.count(make_pair(l, r)));
        lr.insert(make_pair(l, r));
        res = mul(res, dp[r - l + (r + 1 != n)][r + 1 == n? 1 : s[r + 1] - '0']);
    } else {
        assert(lr.count(make_pair(l, r)));
        lr.erase(make_pair(l, r));
        res = mul(res, inv(dp[r - l + (r + 1 != n)][r + 1 == n? 1 : s[r + 1] - '0']));
    }
}

void getLR(int &l, int &r, int pos) {
    l = r = -1;
    auto it = lr.lower_bound(make_pair(pos, n));
    if(it == lr.begin()) return;
    --it;
    if(!(it->first <= pos && pos <= it->second)) return;
    l = it->first, r = it->second;
}

char buf[N];
int main(){
    scanf("%d %dn", &n, &m);
    scanf("%s", buf);
    s = string(buf);
    for (int i = 0; i <= 9; ++i) {
        dp[0][i] = i + 1; //idp[0][i] = inv(dp[0][i]);
        dp[1][i] = 2 * (i + 1) + (9 - i); //idp[1][i] = inv(dp[1][i]);
    }
    for (int i = 2; i < N; ++i)
        for (int j = 0; j <= 9; ++j) {
            dp[i][j] = (2LL * dp[i - 1][j] + 8LL * dp[i - 2][j]) % MOD;
            //idp[i][j] = inv(dp[i][j]);
        }
    for (int i = 0; i < N; ++i) for(int j = 0; j < 10; ++j) assert(dp[i][j] != 0);
    for (int l = 0; l < n; ) {
        int r = l;
        while(r < n && s[r] == '1') ++r;
        res = mul(res, dp[r - l - (r == n)][r == n? 1 : s[r] - '0']);
        if (l != r) lr.insert(make_pair(l, r - 1));
        l = r + 1;
    }
    
    for (int i = 0; i < m; ++i) {
        int pos;
        char x;
        scanf("%d %cn", &pos, &x);
        --pos;
        if (x == '1') {
            if (s[pos] != '1'){ 
                int l1, r1, l2, r2;
                getLR(l1, r1, pos - 1);
                getLR(l2, r2, pos + 1);
                
                int l = pos, r = pos;
                if (l1 != -1) {
                    assert(r1 == pos - 1);
                    updRes(l1, r1, -1);
                    l = l1;
                } else {
                    res = mul(res, inv(dp[0][s[pos] - '0']));
                }
                
                if (l2 != -1) {
                    assert(l2 == pos + 1);
                    updRes(l2, r2, -1);
                    r = r2;
                } else {
                    if (pos + 1 != n) res = mul(res, inv(dp[0][s[pos + 1] - '0']));
                }
                
                s[pos] = x;
                updRes(l, r, 1);
            }
        } else {
            if (s[pos] != '1') {
                if (pos - 1 >= 0 && s[pos - 1] == '1') {
                    int l, r;
                    getLR(l, r, pos - 1);
                    updRes(l, r, -1);
                    s[pos] = x;
                    updRes(l, r, 1);
                } else {
                    res = mul(res, dp[0][x - '0']);
                    res = mul(res, inv(dp[0][s[pos] - '0']));
                    s[pos] = x;
                }
            } else {
                int l, r;
                getLR(l, r, pos);
                assert(l != -1 && r != -1);
                
                updRes(l, r, -1);
                s[pos] = x;
                if (l == r) {
                    res = mul(res, dp[0][s[pos] - '0']);
                    if (pos + 1 < n) res = mul(res, dp[0][s[pos + 1] - '0']);
                } else if (pos == l) {
                    res = mul(res, dp[0][s[pos] - '0']);
                    updRes(l + 1, r, 1);
                } else if (pos == r) {
                    if (pos + 1 != n) res = mul(res, dp[0][s[pos + 1] - '0']);
                    updRes(l, r - 1, 1);
                } else {
                    updRes(l, pos - 1, 1);
                    updRes(pos + 1, r, 1);
                }
            }
            
        }
        printf("%dn", res);
    }
}
```
[1380G - Circular Dungeon](../problems/G._Circular_Dungeon.md "Educational Codeforces Round 91 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**At first, let's say that the expected value is equal to the average of total earnings over all positions and is equal to the sum of earnings over all positions divided by n. So we can trasition to minimizing the sum.

Let's learn how to solve the task for some fixed k. Fix some arrangement and rotate the rooms so that the last room contains a mimic. So now you have cnt1 regular chests, then a single mimic, cnt2 regular chests, single mimic, …, cntk regular chests, single mimic. All cnti≥0 and k∑i=1cnti=n−k.

Take a look at some of these intervals of length cnti. The last chest in the interval is taken from cnti starting positions, the second-to-last is taken cnti−1 times and so on.

Now let's find the optimal way to choose cnti. Fix some values of cnti. Take a look at the smallest of these values and the largest of them. Let the values be x and y. If they differ by at least 2 (x≤y−2), then the smaller result can always be achieved by moving a regular chest from the larger one to the smaller one.

 **Proof**Consider two sequences of coefficients for both intervals: [1,2,…,x−1,x] and [1,2,…,y−1,y].

However, if you remove one chest, then they will be equal to [1,2,…,x−1,x,x+1] and [1,2,…,y−1].

If you only consider the difference between the numbers of both sequences, then you can see that only coefficient y got removed and coefficient x+1 was added. So you can rearrange the chests in such a way that all chests are assigned to the same value and only the chest that was assigned to y becomes assigned to x+1, thus decreasing the total value.

Now we have all cnti set now. The only thing left is to assign chests optimally. Write down the union of all the coefficient sequences from all the intervals n−k⋃i=1[1,…,cnti−1,cnti] and sort them in the non-decreasing order. It's easy to show that the chests should be sorted in the non-increasing order (really classical thing, you can try proving that by showing that any other arrangement can easily be improved once again).

That allows us to write a solution in O(n2). Sort all the chests in the beginning, after that for some k multiply the value of the i-th chest by ⌊ik⌋ and sum up the results.

Finally, let's speed this up with prefix sums. Notice that the first k values are multiplied by 0, the second k values — by 1 and so on. If n is not divisible by k, then the last block just has length smaller than k. Thus, we can calculate the answer for some k in O(nk). And that's equal to O(n∑k=1nk) = O(nlogn).

Overall complexity: O(nlogn).

 **Solution (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int MOD = 998244353;

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return a * 1ll * b % MOD;
}

int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

vector<int> pr;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> c(n);
	forn(i, n)
		scanf("%d", &c[i]);
	sort(c.begin(), c.end(), greater<int>());
	pr.push_back(0);
	forn(i, n)
		pr.push_back(add(pr.back(), c[i]));
	
	int invn = binpow(n, MOD - 2);
	for (int k = 1; k <= n; ++k){
		int ans = 0;
		for (int i = 0, j = 0; i < n; i += k, ++j)
			ans = add(ans, mul(j, add(pr[min(n, i + k)], -pr[i])));
		printf("%d ", mul(ans, invn));
	}
	puts("");
	
	return 0;
}
```
