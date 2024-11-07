# Tutorial

[1430A - Number of Apartments](../problems/A._Number_of_Apartments.md "Educational Codeforces Round 96 (Rated for Div. 2)")

Idea: [fcspartakm](https://codeforces.com/profile/fcspartakm "Candidate Master fcspartakm")

 **Tutorial**
### [1430A - Number of Apartments](../problems/A._Number_of_Apartments.md "Educational Codeforces Round 96 (Rated for Div. 2)")

There are many possible solutions to this problem. The simplest one is to notice that, using several flats of size $3$ and one flat of some size (possibly also $3$, possibly not), we can get any $n$ equal to $[3, 6, 9, \dots]$, $[5, 8, 11, \dots]$ or $[7, 10, 13, \dots]$. The only numbers that don't belong to these lists are $1$, $2$ and $4$, and it's easy to see that there is no answer for that numbers. So the solution is to try all possible sizes of one flat, and if the remaining number of windows is non-negative and divisible by $3$, then take the required number of three-room flats.

 **Solution (fcspartakm)**
```cpp
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>

#define forn(i, n) for(int i=0;i<n;++i)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define x first
#define y1 ________y1
#define y second
#define ft first
#define sc second
#define pt pair<int, int>

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;

using namespace std;

const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

li n;

inline void read() {	
	cin >> n;
}

inline void solve() {
	if (n == 1 || n == 2 || n == 4) {
		cout << -1 << endl;
		return;
	}
	if (n % 3 == 0) {
		cout << n / 3 << ' ' << 0 << ' ' << 0 << endl;
	} else if (n % 3 == 1) {
		cout << (n - 7) / 3 << ' ' << 0 << ' ' << 1 << endl;
	} else {
		cout << (n - 5) / 3 << ' ' << 1 << ' ' << 0 << endl;
	}
}

int main () {
#ifdef fcspartakm
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    cerr << setprecision(10) << fixed;
    
    int t; cin >> t;
    while(t--) {
    	read();
    	solve();
    }
 
    //cerr << "TIME: " << clock() << endl;
}

```
[1430B - Barrels](../problems/B._Barrels.md "Educational Codeforces Round 96 (Rated for Div. 2)")

Idea: [fcspartakm](https://codeforces.com/profile/fcspartakm "Candidate Master fcspartakm")

 **Tutorial**
### [1430B - Barrels](../problems/B._Barrels.md "Educational Codeforces Round 96 (Rated for Div. 2)")

A greedy strategy always works: take $k + 1$ largest barrels, choose one barrel among them and pour all water from those barrels to the chosen barrel. That way, we make the minimum amount equal to $0$ (it's quite obvious that we can't do anything better here), and the maximum amount as large as possible, so the difference between them will be as large as possible.

 **Solution (fcspartakm)**
```cpp
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>

#define forn(i, n) for(int i=0;i<n;++i)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define x first
#define y1 ________y1
#define y second
#define ft first
#define sc second
#define pt pair<int, int>

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;

using namespace std;

const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
const int N = 200 * 1000 + 13;

int n, k;
int a[N];

inline void read() {	
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
}

inline void solve() {
	sort(a, a + n);
	reverse(a, a + n);
	li ans = 0;
	for (int i = 0; i <= k; i++) {
		ans += a[i];
	}
	cout << ans << endl;
}

int main () {
#ifdef fcspartakm
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    cerr << setprecision(10) << fixed;
    
    int t; cin >> t;
    while(t--) {
    	read();
    	solve();
 	}
    //cerr << "TIME: " << clock() << endl;
}

```
[1430C - Numbers on Whiteboard](../problems/C._Numbers_on_Whiteboard.md "Educational Codeforces Round 96 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1430C - Numbers on Whiteboard](../problems/C._Numbers_on_Whiteboard.md "Educational Codeforces Round 96 (Rated for Div. 2)")

It's easy to see that we can't get the result less than $2$, because, if we merge two positive numbers, and at least one of them is $2$ or greater, the new number is always greater than $1$. So we can't get rid of all numbers greater than $1$.

To always achieve $2$, we can use a greedy algorithm: always merge two maximum numbers. During the first step, we merge $n$ and $n - 1$, get $n$; then we merge $n$ and $n - 2$, get $n - 1$; then we merge $n - 1$ and $n - 3$, get $n - 2$; and it's easy to see that the last operation is merging $3$ and $1$, so the result is $2$.

 **Solution (fcspartakm)**
```cpp
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>

#define forn(i, n) for(int i=0;i<n;++i)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define x first
#define y1 ________y1
#define y second
#define ft first
#define sc second
#define pt pair<int, int>

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;

using namespace std;

const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

int n;

inline void read() {	
	cin >> n;
}

inline void solve() {
	multiset<int> was;
	for (int i = 1; i <= n; i++) {
		was.insert(i);
	}
	vector<pair<int, int> > ans;
	for (int i = 0; i < n - 1; i++) {
		auto it = was.end();
		it--;
		int a = *it;
		was.erase(it);
		it = was.end();
		it--;
		int b = *it;
		was.erase(it);
		was.insert((a + b + 1) / 2);
		ans.pb(mp(a, b));
	}
	cout << *was.begin() << endl;
	for (int i = 0; i < sz(ans); i++) {
		cout << ans[i].ft << ' ' << ans[i].sc << endl;
	}	
}

int main () {
#ifdef fcspartakm
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    cerr << setprecision(10) << fixed;
    
    int t; cin >> t;
    while(t--) {
    	read();
    	solve();
    }
    //cerr << "TIME: " << clock() << endl;
}

```
[1430D - String Deletion](../problems/D._String_Deletion.md "Educational Codeforces Round 96 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1430D - String Deletion](../problems/D._String_Deletion.md "Educational Codeforces Round 96 (Rated for Div. 2)")

Suppose the string consists of $n$ characters, and each character is different from the adjacent ones (so the string looks like 01010... or 10101...). It's easy to see that we can't make more than $\lceil \frac{n}{2} \rceil$ operations (each operation deletes at least two characters, except for the case when the string consists of only one character). And there is an easy way to perform exactly $\lceil \frac{n}{2} \rceil$ operations: always choose the last character and delete it.

Okay, what about the case when some adjacent characters in the string are equal? It's never optimal to delete a character that's different from both adjacent characters: since the second part of each operation always deletes the left block of equal characters, this action merges two blocks, so they will be deleted in one second part of the operation (which decreases the total number of operations).

So, we should always delete a character from a block with at least two equal characters. From which of the blocks, if there are more than one? It's easy to see that we should choose a character from the leftmost such block, since that block is the earliest to be deleted (and if we want to make the same action later, we might be unable to do it).

So, the solution is greedy: during each action, we have to find the leftmost block consisting of at least $2$ equal characters, and delete a character from it (or the last character of the string, if there are no such blocks). Since the length of the string is up to $2 \cdot 10^5$ and the number of operations is up to $10^5$, we should do it efficiently, for example, by storing the eligible blocks in some data structure.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

char buf[200043];

int main()
{
	int t;
	scanf("%d", &t);
	for(int tc = 1; tc <= t; tc++) {
		int n;
		scanf("%d", &n);
		scanf("%s", buf);
		string s = buf;
		queue<int> q;
		int cur = 0;
		for(int i = 0; i < n; i++)
		{
		 	if(i > 0 && s[i] != s[i - 1])
		 		cur++;
		 	if(i > 0 && s[i] == s[i - 1])
		 		q.push(cur);
		}
		int deleted = 0;       
		int score = 0;
		for(int i = 0; i < n; i++)
		{
			if(q.empty())
				break;
			q.pop();
			deleted++;
			score++;
			while(!q.empty() && q.front() == i)
			{
				q.pop();
				deleted++; 	
			}
			deleted++;
			//cerr << deleted << endl;
		}
		score += (n - deleted + 1) / 2;
		printf("%dn", score);
	}
}

```
[1430E - String Reversal](../problems/E._String_Reversal.md "Educational Codeforces Round 96 (Rated for Div. 2)")

Idea: [fcspartakm](https://codeforces.com/profile/fcspartakm "Candidate Master fcspartakm")

 **Tutorial**
### [1430E - String Reversal](../problems/E._String_Reversal.md "Educational Codeforces Round 96 (Rated for Div. 2)")

First of all, let's find the resulting position for each character of the string. It's easy to see that we don't need to swap equal adjacent characters (it changes nothing), so the first character a in the original string is the first character a in the resulting string, the second character a in the original string is the second character a in the resulting string, and so on.

Now, let's build a permutation $p$ of $n$ elements, where $p_i$ is the resulting position of the element that was on position $i$ in the original string. For example, for the string abcad this permutation will be $p = [2, 4, 3, 5, 1]$. In one operation, we may swap two elements in this permutation, and our goal is to sort it (since each character of the string has its own required position, and when for every $i$ the condition $p_i = i$ holds, each character is on the position it should be). The required number of swaps of adjacent elements to sort a permutation is exactly the number of inversions in it (since each swap changes the number of inversions by $1$), and this number can be calculated using many different techniques, for example, mergesort tree or Fenwick tree.

 **Solution (fcspartakm)**
```cpp
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>

#define forn(i, n) for(int i=0;i<n;++i)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define x first
#define y1 ________y1
#define y second
#define ft first
#define sc second
#define pt pair<int, int>

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;

using namespace std;

const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
const int N = 200 * 1000 + 13;

int n;
string s;
string revS;
vector<int> posS[30];
vector<int> posT[30];
int cnt[30];
int t[N];

inline int sum (int r) {
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

inline void inc (int i, int d) {
	for (; i < n; i = (i | (i+1)))
		t[i] += d;
}

int sum (int l, int r) {
	return sum (r) - sum (l-1);
}
     
inline void read() {	
	cin >> n >> s;
}

inline void solve() {
	revS = s;
	reverse(all(revS));
	for (int i = 0; i < sz(s); i++) {
		posS[s[i] - 'a'].pb(i);
		posT[revS[i] - 'a'].pb(i);
	}
	li ans = 0;
	for (int i = 0; i < sz(revS); i++) {
		int let = revS[i] - 'a';
		int cur = posS[let][cnt[let]];
		int oldC = cur;
		cur += sum(cur, n - 1);
		int need = i;
		ans += cur - need;
		inc(oldC, 1);
		cnt[let]++;
	}
	cout << ans << endl;
}

int main () {
#ifdef fcspartakm
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    srand(time(NULL));
    cerr << setprecision(10) << fixed;
    
    read();
    solve();
 
    //cerr << "TIME: " << clock() << endl;
}

```
[1430F - Realistic Gameplay](../problems/F._Realistic_Gameplay.md "Educational Codeforces Round 96 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1430F - Realistic Gameplay](../problems/F._Realistic_Gameplay.md "Educational Codeforces Round 96 (Rated for Div. 2)")

Note some observations: if we meet a new wave and start shooting it's optimal to shoot monsters in the wave using full magazines while we can and there are no reasons to take breaks between shooting monsters from one wave. That's why we can track only moments when waves start and the number of remaining bullets in magazine we have at these moments.

Moreover, since the next wave starts not earlier than the previous ends, we can think that when we start dealing with one wave we've already dealt with the previous one. Also, instead of keeping track of the remaining bullets, let's just look only at such indices of waves when we reloaded and threw remaining bullets before reaching them.

So, we can write the next dp: $d[i]$ is the minimum number of bullets we spend dealing with the first $i$ waves and now we standing at the moment $l_i$ with full magazine. Obviously, $dp[0] = 0$.

Now, with fixed $i$ we can iterate over the index $j$ of a wave before which we'll reload throwing away remaining bullets. And for waves $[i, j)$ we need to check that we are able to exterminate all these waves without throwing away any bullets. We can check it with several formulas.

If it's possible for segment $[i, j)$ then the possibility for the segment $[i, j + 1)$ is just checking that we can exterminate the $j$-th wave having $rem \ge 0$ bullets in the start in no more than $r_j - l_j$ reloads plus checking that we have at least one unit before $l_{j + 1}$ for a reload.

As a result, the time complexity of the solution is $O(n^2)$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n, k;
vector<int> l, r, a;

inline bool read() {
	if(!(cin >> n >> k))
		return false;
	l.resize(n);
	r.resize(n);
	a.resize(n);
	
	fore(i, 0, n)
		cin >> l[i] >> r[i] >> a[i];
	
	return true;
}

inline void solve() {
	vector<li> d(n + 1, INF64);
	d[0] = 0;
	
	li ans = INF64;
	fore(i, 0, n) {
		li rem = k, total = d[i];
		for (int j = i; j < n; j++) {
			li cntReloads = (max(0LL, a[j] - rem) + k - 1) / k;
			if (cntReloads > r[j] - l[j])
				break;
			
			li newRem = (rem + cntReloads * k) - a[j];
			total += a[j];
			if (j + 1 < n) {
				if (l[j] + cntReloads < l[j + 1])
					d[j + 1] = min(d[j + 1], total + newRem);
			} else
				ans = min(ans, total);
			rem = newRem;
		}
	}
	if (ans > INF64 / 2)
		ans = -1;
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
	
	if(read()) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}

```
[1430G - Yet Another DAG Problem](../problems/G._Yet_Another_DAG_Problem.md "Educational Codeforces Round 96 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1430G - Yet Another DAG Problem](../problems/G._Yet_Another_DAG_Problem.md "Educational Codeforces Round 96 (Rated for Div. 2)")

The key observation in this problem is that the values of $a_v$ should form a contiguous segment of integers. For example, suppose there exists a value $k$ such that there is at least one $a_v < k$, there is at least one $a_v > k$, but no $a_v = k$. We can decrease all values of $a_v$ that are greater than $k$ by $1$, so the answer will still be valid, but the value of $\sum \limits_{i = 1}^{m} w_i b_i$ will decrease. So, the values of $a_v$ form a contiguous segment of integers. We can always assume that this segment is $[0, n - 1]$, since subtracting the same value from each $a_v$ does not change anything.

The other observation we need is that we can rewrite the expression we have to minimize as follows: $\sum \limits_{i = 1}^{m} w_i b_i = \sum \limits_{v = 1}^{n} a_v c_v$, where $c_v$ is the signed sum of weights of all arcs incident to the vertex $v$ (the weights of all arcs leading from $v$ are taken with positive sign, and the weights of all arcs leading to $v$ are taken with negative sign). These two observations lead us to a bitmask dynamic programming solution: let $dp_{i, mask}$ be the minimum value of $\sum \limits_{v = 1}^{n} a_v c_v$, if we assigned the values from $[0, i - 1]$ to the vertices from $mask$. A naive way to calculate this dynamic programming is to iterate on the submask of $mask$, check that choosing the integer $i - 1$ for each vertex from that submask doesn't ruin anything (for each vertex that belongs to this submask, all vertices that are reachable from it should have $a_v < i - 1$, so they should belong to $mask$, but not to the submask we iterate on), and update the dynamic programming value. But this solution is $O(n 3^n)$, and, depending on your implementation, this might be too slow.

It's possible to speed this up to $O(n^2 2^n)$ in a way similar to how profile dp can be optimized from $O(3^n)$ to $O(n 2^n)$: we won't iterate on the submask; instead, we will try to add the vertices one by one, and we should be able to add a vertex to the mask only if all vertices that are reachable from it already belong to the mask. There is a possibility that we add two vertices connected by an arc with the same value of $a_v$, so, for a fixed value of $a_v$, we should consider assigning it to vertices in topological sorting order (that way, if one vertex is reachable from another, it will be considered later, so we won't add both of those with the same value of $a_v$).

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long li;

const int N = 18;
const int M = (1 << N);
const li INF64 = li(1e18);

int n, m;
vector<int> g[N];
li sum[N];
int need_mask[N];
li dp[N + 1][N + 1][M];
bool p[N + 1][N + 1][M];

vector<int> order;       
vector<int> used;

void dfs(int x, bool build_topo)
{
    if(used[x])
    	return;
    used[x] = 1;
    for(auto y : g[x])
    	dfs(y, build_topo);
    if(build_topo)
    	order.push_back(x);
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
	 	int x, y, w;
	 	cin >> x >> y >> w;
	 	--x;
	 	--y;
	 	sum[x] += w;
	 	sum[y] -= w;
	 	g[x].push_back(y);
	}
	used.resize(n);
	for(int i = 0; i < n; i++)
		dfs(i, true);
	for(int i = 0; i < n; i++)
	{
	 	used = vector<int>(n, 0);
	 	dfs(i, false);
	 	for(int j = 0; j < n; j++)
	 		if(j != i && used[j] == 1)
	 			need_mask[i] |= (1 << j);		
	}
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			for(int k = 0; k < (1 << n); k++)
				dp[i][j][k] = INF64;
	dp[0][0][0] = 0;
	reverse(order.begin(), order.end());
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= n; j++)
			for(int k = 0; k < (1 << n); k++)
			{
			 	if(dp[i][j][k] > INF64 / 2)
			 		continue;
			 	if(j == n)
			 	{
			 	 	if(dp[i + 1][0][k] > dp[i][j][k])
			 	 	{
			 	 	 	dp[i + 1][0][k] = dp[i][j][k];
			 	 	 	p[i + 1][0][k] = false;
			 	 	}
			 	}
			 	else
			 	{
			 		int v = order[j];
			 		li add = sum[v] * i;
			 		if(dp[i][j + 1][k] > dp[i][j][k])
			 		{
			 		 	dp[i][j + 1][k] = dp[i][j][k];
			 		 	p[i][j + 1][k] = false;
			 		}
			 		if(((k & (1 << v)) == 0) && ((need_mask[v] & k) == need_mask[v]))
			 		{
			 		 	int nk = k | (1 << v);
			 		 	if(dp[i][j + 1][nk] > dp[i][j][k] + add)
			 		 	{
			 		 	 	dp[i][j + 1][nk] = dp[i][j][k] + add;
			 		 	 	p[i][j + 1][nk] = true;
			 		 	}
				 	}
				}
			}
	vector<int> ans(n);
	int i = n;
	int j = 0;
	int k = (1 << n) - 1;
	while(i > 0 || j > 0 || k > 0)
	{
	 	if(j == 0)
	 	{
	 	 	j = n;
	 	 	i--;
	 	}
	 	else
	 	{
	 	 	if(p[i][j][k])
	 	 	{
	 	 	 	int v = order[j - 1];
	 	 	 	ans[v] = i;
	 	 	 	k ^= (1 << v);
	 		}
	 		j--;
	 	}
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << " n"[i == n - 1];
}

```
