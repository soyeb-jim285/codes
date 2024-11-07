# Tutorial

[1574A - Regular Bracket Sequences](../problems/A._Regular_Bracket_Sequences.md "Educational Codeforces Round 114 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1574A - Regular Bracket Sequences](../problems/A._Regular_Bracket_Sequences.md "Educational Codeforces Round 114 (Rated for Div. 2)")

There are many ways to solve this problem. The model solution does the following thing:

* start with the sequence ()()()()...;
* merge the first $4$ characters into one sequence to get (())()()...;
* merge the first $6$ characters into one sequence to get ((()))()...;
* and so on.
 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    n = int(input())
    for j in range(n):
        print("()" * j + "(" * (n - j) + ")" * (n - j))
```
[1574B - Combinatorics Homework](../problems/B._Combinatorics_Homework.md "Educational Codeforces Round 114 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1574B - Combinatorics Homework](../problems/B._Combinatorics_Homework.md "Educational Codeforces Round 114 (Rated for Div. 2)")

Let's start with a simple assumption. For some fixed values $a, b, c$, the values of $m$ that the answers exist for, make up a range. So there's the smallest possible number of adjacent equal pairs one can construct and the largest one — everything in-between exists as well.

The largest number is simple — put all A's, then all B's, then all C's. So this value is $(a - 1) + (b - 1) + (c - 1)$.

The smallest number is trickier. Let's instead investigate when it's equal to $0$. WLOG, assume $a \le b \le c$. Imagine the following construction. There are $c$ letters C which separate blocks of letters A and B. There are $c-1$ ($c+1$ if you consider the ones to the sides of all letters C, but we want the smallest value, so we shouldn't consider them) such blocks, thus it's possible that each block contains no more than one letter A and no more than one letter B. So letters A and B will never produce adjacent pairs.

If there are empty blocks, then there are adjacent letters C. So the condition to still have no empty blocks is to have at least $c-1$ letters A and B in total. If $c - 1 > a + b$, then any extra letter C can only be put adjacent to another letter C, thus producing an extra pair (at least one extra pair, but since we are examining the lower bound, we can always do exactly one). That means that the lower bound is $c - 1 - (a + b)$.

Now for the proof of the fact that every value in-between is also achievable. Since we have a construction for $m = 0$, let's try modifying it. Let's reduce the test to $m = 0$ the following way. While $m > 0$, decrease the count of the letter that appears the most by $1$ and decrease $m$ by $1$. Now build the string for $m = 0$ with the reduced values. After that put the letters back, placing them next to the last occurrence of the same letter (there is at least one occurrence of each letter, the proof is trivial). That increases $m$ by $1$ and the count of this letter by $1$. Thus, we'll return to the initial test.

Overall complexity: $O(1)$ per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	a, b, c, m = map(int, input().split())
	a, b, c = sorted([a, b, c])
	print("YES" if c - (a + b + 1) <= m <= a + b + c - 3 else "NO")
```
[1574C - Slay the Dragon](../problems/C._Slay_the_Dragon.md "Educational Codeforces Round 114 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1574C - Slay the Dragon](../problems/C._Slay_the_Dragon.md "Educational Codeforces Round 114 (Rated for Div. 2)")

It is enough to consider two cases: whether we will increase the strength of the hero who will kill the dragon or not.

If you do not increase the hero's strength, then you have to choose such $i$ that $a_i \ge x$. Obviously, among such $i$, you have to choose with the minimum value $a_i$, because the strength of defending heroes is equal to $\sum\limits_{j=1}^n a_j - a_i$. It remains to increase the total strength of the remaining heroes to $y$. So the required number of coins is equal to $\max(0, y - (\sum\limits_{j=1}^n a_j - a_i))$.

If you increase the hero's strength, then you have to choose the maximum value of $a_i$, which is less than $x$. In this case, the required number of coins is $x - a_i$ to increase the strength of the hero who will kill the dragon, plus $\max(0, y - (\sum\limits_{j=1}^n a_j - a_i))$ to increase the strength of the defending heroes.

To find the heroes with strength as close to $x$ as possible, you can use binary search (don't forget to sort the heroes beforehand).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  int n;
  cin >> n;
  vector<li> a(n);
  for (auto &x : a) cin >> x;
  sort(a.begin(), a.end());
  li sum = accumulate(a.begin(), a.end(), 0LL);
  int m;
  cin >> m;
  while (m--) {
    li x, y;
    cin >> x >> y;
    int i = lower_bound(a.begin(), a.end(), x) - a.begin();
    li ans = 2e18;
    if (i > 0) ans = min(ans, (x - a[i - 1]) + max(0LL, y - sum + a[i - 1]));
    if (i < n) ans = min(ans, max(0LL, y - sum + a[i]));
    cout << ans << 'n';
  }
}
```
[1574D - The Strongest Build](../problems/D._The_Strongest_Build.md "Educational Codeforces Round 114 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1574D - The Strongest Build](../problems/D._The_Strongest_Build.md "Educational Codeforces Round 114 (Rated for Div. 2)")

Consider the bruteforce solution. You start with a build that contains the most powerful item for each slot. In one move, you swap an item in some slot for the one that is the previous one by power. If a build is not banned, update the answer with its total power (banned builds can be stored in a set, maybe hashset if you hash carefully enough).

Notice that if you reach some unbanned build in this bruteforce, it never makes sense to go further. The answer is already updated with this one, and all the lower ones have smaller power.

If you code that bruteforce in a smart way (or just add memorization), you won't visit any build twice. How many states will you visit, though? Since you can only proceed if you are standing in a banned build, you will check around $m + mn$ builds.

You can code it like that and get accepted. However, there's another way that's easier to code, in my opinion.

The optimal answer can be one of only two types. Either it contains the last item of each slot. Or it's some banned build with one item swapped with the previous one. It's easy to see from the solution above. So you can check the first type, then iterate over the banned build and try swapping each slot in it, checking if the resulting build is banned or not.

Overall complexity: $O(mn)$ or $O(mn \log m)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n;
vector<vector<int>> a;
int m;
vector<vector<int>> b;

int main() {
	scanf("%d", &n);
	a.resize(n);
	forn(i, n){
		int c;
		scanf("%d", &c);
		a[i].resize(c);
		forn(j, c) scanf("%d", &a[i][j]);
	}
	scanf("%d", &m);
	b.resize(m);
	forn(i, m){
		b[i].resize(n);
		forn(j, n){
			scanf("%d", &b[i][j]);
			--b[i][j];
		}
	}
	sort(b.begin(), b.end());
	vector<int> ult(n);
	forn(i, n) ult[i] = int(a[i].size()) - 1;
	if (!binary_search(b.begin(), b.end(), ult)){
		forn(i, n) printf("%d ", ult[i] + 1);
		puts("");
		return 0;
	}
	int mx = 0;
	vector<int> ans(n, -1);
	forn(i, m){
		vector<int> tmp = b[i];
		int sum = 0;
		forn(j, n) sum += a[j][tmp[j]];
		forn(j, n) if (tmp[j] != 0){
			--tmp[j];
			if (!binary_search(b.begin(), b.end(), tmp) && sum - a[j][tmp[j] + 1] + a[j][tmp[j]] > mx){
				mx = sum - a[j][tmp[j] + 1] + a[j][tmp[j]];
				ans = tmp;
			}
			++tmp[j];
		}
	}
	forn(i, n){
		printf("%d ", ans[i] + 1);
	}
	puts("");
}

```
[1574E - Coloring](../problems/E._Coloring.md "Educational Codeforces Round 114 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1574E - Coloring](../problems/E._Coloring.md "Educational Codeforces Round 114 (Rated for Div. 2)")

For best understanding we replace the matrix with $0$ and $1$ with the matrix with black and white cells.

At first let's consider matrix if there are two adjacent horizontal cell with same color (for example cells $(5, 5)$ and $(5, 6)$ are black). Then the cells $(4, 5)$, $(4, 6)$, $(6, 5)$ and $6, 6$ must have the opposite color (white); the cells $(3, 5)$, $(3, 6)$, $(7, 5)$ and $7, 6$ must have the same color (black) and so on. So, two adjacent horizontal cells generate the vertical strip of width two. Reciprocally two adjacent vertical cells generate the horizontal strip of width two. And if simultaneously there are horizontal strip and vertical strip then the answer is $0$ (because they contradict each other).

If there are two cells of same color in the same row with even number of cells between them (for example $(2, 2)$ and $(2, 7)$ with four cells between them) then there is the vertical strip (because there are always two adjacent cells with same color between them). The same is correct for horizontal strips. 

Now let's consider how the matrix look if there are the vertical strip. It look like a chess board of size $n \times m$, but colors of some verticals are inverted. The same is correct if there are the horizontal strips.

How we can quickly understand that there are two cells of same color in the same row with even number of cells between them? For this mentally color the matrix in a checkerboard pattern. And then one of this cells has the same color witch cells in chessboard, and the other has the opposite color witch cells in chessboard.

For calculating the answer we have maintain to the following values: 

* The color of each colored cell;
* The row and columns containing the cells of same color with even number of cells between them;
* And the number of row and columns containing at least one colored cell (for calculating the number of beautiful matrix).
 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 1'000'009;

int sum (int a, int b) {
    int res = a + b;
    if (res < 0) res += MOD;
    if (res >= MOD) res -= MOD;
    return res;
}

int n, m, k;
map <pair <int, int>, char> c;
int cntr[N][2], cntc[N][2];
int cntx[2];
set <int> badr, badc;
set<int> ur, uc;
int p2[N];

void upd2(int pos, int col, int add, int cnt[N][2], set <int> &bad, set<int> &u) {
    cnt[pos][col] += add;
    assert(cnt[pos][col] >= 0);
    
    if (cnt[pos][0] > 0 && cnt[pos][1] > 0){
        if (!bad.count(pos))
            bad.insert(pos);
    } else {
        if (bad.count(pos))
            bad.erase(pos);
    }
    
    if (cnt[pos][0] > 0 || cnt[pos][1] > 0){
        if (!u.count(pos))
            u.insert(pos);
    } else {
        if (u.count(pos))
            u.erase(pos);
    }
}

void upd(int x, int y, int t) {
    int col = (x & 1) ^ (y & 1);
    if (c.count({x, y})) {
        int ncol = col ^ c[{x, y}];
        --cntx[ncol];
        upd2(x, ncol, -1, cntr, badr, ur);
        upd2(y, ncol, -1, cntc, badc, uc);
        c.erase({x, y});
    }
    
    if (t == -1)
        return;
        
    int ncol = col ^ t;
    ++cntx[ncol];
    upd2(x, ncol, 1, cntr, badr, ur);
    upd2(y, ncol, 1, cntc, badc, uc);
    c[{x, y}] = t;
}

int main(){
    p2[0] = 1;
    for (int i = 1; i < N; ++i)
        p2[i] = sum(p2[i - 1], p2[i - 1]);
        
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        --x, --y;
        upd(x, y, t);
        
        int res = 0;
        if(badr.size() > 0 && badc.size() > 0) {
            res = 0;
        } else if (badr.size() > 0) {
            assert(m - uc.size() >= 0);
            res = p2[m - uc.size()];
        } else if (badc.size() > 0) {
            assert(n - ur.size() >= 0);
            res = p2[n - ur.size()];
        } else {
            if (ur.size() == 0 && uc.size() == 0)
                res = sum(sum(p2[n], p2[m]), -2);
            else {
                assert(m - uc.size() >= 0);
                res = sum(res, p2[m - uc.size()]);
                assert(n - ur.size() >= 0);
                res = sum(res, p2[n - ur.size()]);
                if (cntx[0] == 0 || cntx[1] == 0) {
                    assert(cntx[0] != 0 || cntx[1] != 0);
                    res = sum(res, -1);
                }
            }
        }
        
        printf("%dn", res);
    }
    return 0;
}
```
[1574F - Occurrences](../problems/F._Occurrences.md "Educational Codeforces Round 114 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1574F - Occurrences](../problems/F._Occurrences.md "Educational Codeforces Round 114 (Rated for Div. 2)")

What does the condition "the number of occurrences of $A_i$ in the array $a$ is not less than the number of occurrences of each non-empty subarray of $A_i$ in $a$" mean? First, if $A_i$ contains two (or more) equal elements, then any occurrence of $A_i$ introduces at least two occurrences of that element; so any element in $A_i$ is forbidden (it should not appear in the resulting array). Now let's consider an array $A_i$ such that every its element is unique. Every element of $A_i$ should be a part of an occurrence of $A_i$ in the array $a$. Let's rephrase this condition as follows: for each occurrence of $A_{i,j}$ in $a$, the next element in $a$ is $A_{i,j+1}$, and vice versa: for each occurrence of $A_{i,j+1}$ in $a$, the previous element in $a$ is $A_{i,j}$.

Let's build a directed graph on $k$ vertices, where an arc from vertex $x$ to vertex $y$ means that each occurrence of $x$ should be followed by $y$, and each occurrence of $y$ should be preceded by $x$ (i. e. $x$ is followed by $y$ in some array $A_i$). Let's consider the weakly connected components in this graph. If we have at least one occurrence of some element from a component in $a$, it means that all other elements from this component occur in $a$ as well. Some integers from $1$ and $k$ are "bad" in a sense that we cannot uniquely determine which element should follow/precede them (in terms of graph theory, it means that the in-degree or out-degree of a vertex is at least $2$). Since by picking one element from a component, we will have to use all elements from a component, it means that if a component contains at least one "bad" element, the whole component will be "bad" — we cannot use any element from it.

If a component is a cycle, no vertex has in-degree or out-degree greater than $1$, but the component is still "bad" since, if we include at least one element from $a$, we cannot finish the cycle — the array $a$ is not infinite, but the cycle is.

Okay, the only "good" components are chains. When we use an element from a chain in $a$, all elements from this chain will be used in exactly the same order that they were in the chain; so, $a$ should consist of some chains linked together (chains may repeat, and some chains may be absent from $a$). We can write a solution with dynamic programming: let $dp_i$ be the number of ways to construct an array of length $i$ using these chains. The transitions are as follows: $dp_i = \sum\limits_{j=1}^{c} dp_{i - len_j}$, where $c$ is the number of chains, and $len_j$ is the length of the $j$-th chain.

The number of chains is up to $k$, and the number of states in dynamic programming is $m + 1$, so the solution works in $O(mk)$, which is too slow. We can improve it with the following two facts:

* all chains of the same length are indistinguishable;
* there are $O(\sqrt{k})$ different lengths of chains.

So, instead of iterating on the chains themselves in dynamic programming, we will iterate on the lengths of the chains (considering only lengths having at least one chain), and process all chains of the same length as one by introducing a multiplier in our dynamic programming: $dp_i = \sum \limits_{j=1}^{k} dp_{i - j} \cdot cnt_j$, where $cnt_j$ is the number of chains of length $j$. That way, our dynamic programming will work in $O(m \sqrt{k})$ if we skip the values of $j$ with $cnt_j = 0$.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
 	x += y;
 	while(x >= MOD) x -= MOD;
 	while(x < 0) x += MOD;
 	return x;
}

int mul(int x, int y)
{
 	return (x * 1ll * y) % MOD;
}

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<vector<int>> A(n);
	vector<int> bad_num(k);
	for(int i = 0; i < n; i++)
	{
		int c;
		scanf("%d", &c);
		A[i].resize(c);
		for(int j = 0; j < c; j++)
		{
			scanf("%d", &A[i][j]); 	
			A[i][j]--;
		}
	}

	for(int i = 0; i < n; i++)
	{
	 	if(set<int>(A[i].begin(), A[i].end()).size() != A[i].size())
	 	{
	 	 	for(auto x : A[i])
	 	 		bad_num[x] = 1;
	 	}
	}
	vector<vector<int>> nxt(k);
	vector<vector<int>> prv(k);
	for(int i = 0; i < n; i++)
		for(int j = 0; j + 1 < A[i].size(); j++)
		{
		 	nxt[A[i][j]].push_back(A[i][j + 1]);
		 	prv[A[i][j + 1]].push_back(A[i][j]);
		}

	for(int i = 0; i < k; i++)
	{
	    sort(nxt[i].begin(), nxt[i].end());
	    sort(prv[i].begin(), prv[i].end());
	 	nxt[i].erase(unique(nxt[i].begin(), nxt[i].end()), nxt[i].end());
	 	prv[i].erase(unique(prv[i].begin(), prv[i].end()), prv[i].end());
	}

	vector<int> used(k, 0);
	vector<int> cnt(k + 1, 0);
	for(int i = 0; i < k; i++)
	{
		if(used[i]) continue;
	 	queue<int> q;
	 	vector<int> comp;
	 	q.push(i);
	 	used[i] = 1;
	 	while(!q.empty())
	 	{
	 		int z = q.front();
	 		q.pop();
	 		comp.push_back(z);
	 	 	for(auto x : nxt[z])
	 	 		if(!used[x])
	 	 		{
	 	 		 	used[x] = 1;
	 	 		 	q.push(x);
	 	 		}
	 	 	for(auto x : prv[z])
	 	 		if(!used[x])
	 	 		{
	 	 		 	used[x] = 1;
	 	 		 	q.push(x);
	 	 		}
	 	}
	 	bool bad = false;
	 	int cnt_beg = 0;
	 	for(auto x : comp)
	 	{
	 	 	if(prv[x].empty())
	 	 		cnt_beg++;
	 	 	if(prv[x].size() > 1 || nxt[x].size() > 1 || bad_num[x])
	 	 		bad = true;
	 	}
	 	bad |= (cnt_beg == 0);
	 	if(!bad)
	 		cnt[comp.size()]++;
	}
	vector<int> nonzero;
	for(int i = 1; i <= k; i++)
		if(cnt[i] > 0)
			nonzero.push_back(i);
	vector<int> dp(m + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= m; i++)
		for(auto x : nonzero)
		 	if(x <= i)
		 		dp[i] = add(dp[i], mul(cnt[x], dp[i - x]));

	printf("%dn", dp[m]);
	return 0;
}
```
