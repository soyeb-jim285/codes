# T_(en)

[1132A - Regular Bracket Sequence](../problems/A._Regular_Bracket_Sequence.md "Educational Codeforces Round 61 (Rated for Div. 2)")

 **Tutorial**
### [1132A - Regular Bracket Sequence](../problems/A._Regular_Bracket_Sequence.md "Educational Codeforces Round 61 (Rated for Div. 2)")

For bracket sequence to be regular, it should have equal number of opening and closing brackets. So, if cnt1≠cnt4, then it's impossible to construct any regular bracket sequence.

cnt2 is completely irrelevant to us, since inserting or removing a () substring doesn't change the status of the string we get. Almost the same applies to cnt3, but we should have at least one (( substring before it. So, if cnt3>0, but cnt1=0, there is no solution.

In all other cases it is possible to order all strings as follows: all strings ((, then all strings (), then all strings )(, then all strings )).

 **Solution (BledDest)**
```cpp
cnt = []

for i in range(4):
	cnt.append(int(input()))
	
if(cnt[0] == cnt[3] and (cnt[2] == 0 or cnt[0] > 0)):
	print(1)
else:
	print(0)
```
[1132B - Discounts](../problems/B._Discounts.md "Educational Codeforces Round 61 (Rated for Div. 2)")

 **Tutorial**
### [1132B - Discounts](../problems/B._Discounts.md "Educational Codeforces Round 61 (Rated for Div. 2)")

When using i-th coupon, the bar we get for free should have at least xi−1 bars not cheaper than it. So, if we consider a sorted in non-decreasing order, then we cannot get discount greater than an−xi+1.

On the other hand, we can always get such a discount if we pick xi most expensive bars to buy using the i-th coupon.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 300009;

int n;
int a[N];
long long res[N];

int main() {
	long long sum = 0;
	scanf("%d", &n);	
	for(int i = 0; i < n; ++i){
		scanf("%d", a + i);
		sum += a[i];	
	}
	sort(a, a + n);
	
	memset(res, -1, sizeof res);
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		int c;
		scanf("%d", &c);
		if(res[c] == -1){
			res[c] = sum - a[n - c];
		}	

		printf("%lldn", res[c]);
	}
	return 0;
}
```
[1132C - Painting the Fence](../problems/C._Painting_the_Fence.md "Educational Codeforces Round 61 (Rated for Div. 2)")

 **Tutorial**
### [1132C - Painting the Fence](../problems/C._Painting_the_Fence.md "Educational Codeforces Round 61 (Rated for Div. 2)")

Let ci be the number of painters that are painting the i-th section.

Let's fix the first painter (denote his index as x) we won't take and decrease the numbers of array c in the range which he paints.

Then we may new array d, such that di is equal to 1 if and only if ci=1, and 0 otherwise. This array corresponds to segments that are painted by only one painter 

After that we build prefix sum array p on array d: pi=i∑j=1dj. This should be done in O(n).

Now, for each remaining painter we can count the number of sections that are painted only by him. For painter i it will be equal to pri−pli−1. Let's denote it as resi.

Finally, find an painter with the minimum value of resi, denote it as MinRes. The answer (if we choose painter x as one of two that won't be hired) will be equal to cnt−MinRes, where cnt is the number of elements greater than 0 in the array c after removing the painter x. 

And, of course, we should do the same for all painters.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 5043;

int p1[N];
int p2[N];
int p3[N];
int n, q;
int l[N], r[N];

int solve(int idx)
{
	memset(p1, 0, sizeof p1);
	for(int i = 0; i < q; i++)
	{
		if(i == idx) continue;
		p1[l[i]]++;
		p1[r[i]]--;
	}
	memset(p2, 0, sizeof p2);
	int c = 0;
	for(int i = 0; i < n; i++)
	{
		c += p1[i];
		p2[i] = c;
	}	
	memset(p3, 0, sizeof p3);
	for(int i = 0; i < n; i++)
		p3[i + 1] = p3[i] + (p2[i] == 1 ? 1 : 0);
	int ans = -int(1e9);
	for(int i = 0; i < q; i++)
	{
		if(i == idx) continue;
		ans = max(ans, p3[l[i]] - p3[r[i]]);
	}
	for(int i = 0; i < n; i++)
		if(p2[i] > 0)
			ans++;
	return ans;
}

int main()
{
	cin >> n >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> l[i] >> r[i];
		l[i]--;
	}
	int ans = 0;
	for(int i = 0; i < q; i++)
		ans = max(ans, solve(i));
	cout << ans << endl;
}
```
[1132D - Stressful Training](../problems/D._Stressful_Training.md "Educational Codeforces Round 61 (Rated for Div. 2)")

 **Tutorial**
### [1132D - Stressful Training](../problems/D._Stressful_Training.md "Educational Codeforces Round 61 (Rated for Div. 2)")

The easiest part of the solution is to notice that if the charger of power $x$ works then the charger of power $x + 1$ also works. Thus, binary search is applicable to the problem.

$k$ is really small and only one laptop can be charged during some minute. It implies that check function can work in something polynomial on $k$ by searching for the right laptop to charge during every minute.

I claim that the greedy algorithm works. Find the laptop that gets his charge below zero the first. Charge it for one minute as early as possible. Repeat until you either don't have time to charge the laptop (check returns false) or the contest is over (check returns true).

Why greedy works? Well, check any case where check returns false. If some laptop runs out of power then all the minutes up to the current one are used to charge something. Moreover, you can free no minute of these as by doing greedy we charged all laptops as late as possible. Freeing some minute will lead to other laptop dying earlier.

One way to implement this is the following. Keep a heap of events ($time\\_i-th\\_laptop\\_dies$), pop its head, add $x$ to it if the time is greater than the number of charges already made and push it back to heap. That will simulate the entire process in $O((n + k) \log n)$. Unfortunately, this may be too slow on some implementations.

Let's try the following linear approach. Maintain not the heap but such an array that $i$-th its cell contains all indices of all the laptops to run out of charge on the beginning of minute $i$. Keep an iterator to the first non-empty position. Pop a single index out of this vector, charge it and push it to the new position. You'll still make $k$ steps and on each step you'll make $O(1)$ instant operations. That will make it $O(n + k)$ for this simulation.

I'm not really sure how to build the maximal answer case, however, I can estimate the upper bound of binary search. You can set $x$ in such a way that it charges every laptop in one minute so that it won't run out of power until the end of the contest. Choose the smallest $a_i$, the greatest $b_i$, the greatest $k$ and you'll end up with $1 - 2 \cdot 10^5 \cdot 10^7$ total usage. Thus, $2 \cdot 10^12$ will always be enough.

Overall complexity: $O((n + k) \cdot \log ANS)$. (or $O((n + k) \cdot \log ANS \log n)$ if you are skillful enough to squeeze it :D).

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;
const long long INF64 = 1e18;

int n, k;
long long a[N];
int b[N];
long long cur[N];

vector<int> qr[N];

bool check(long long x){
	forn(i, k) qr[i].clear();
	forn(i, n) cur[i] = a[i];
	forn(i, n){
		long long t = cur[i] / b[i] + 1;
		cur[i] %= b[i];
		if (t < k) qr[t].push_back(i);
	}
	
	int lst = 0;
	forn(t, k){
		while (lst < k && qr[lst].empty())
			++lst;
		if (lst <= t)
			return false;
		if (lst == k)
			return true;
		int i = qr[lst].back();
		if (cur[i] + x < b[i]){
			cur[i] += x;
			continue;
		}
		qr[lst].pop_back();
		long long nt = (cur[i] + x) / b[i];
		cur[i] = (cur[i] + x) % b[i];
		if (lst + nt < k)
			qr[lst + nt].push_back(i);
	}
	
	return true;
}

int main() {
	scanf("%d%d", &n, &k);
	forn(i, n) scanf("%lld", &a[i]);
	forn(i, n) scanf("%d", &b[i]);
	long long l = 0, r = INF64;
	while (l < r - 1){
		long long m = (l + r) / 2;
		if (check(m))
			r = m;
		else
			l = m;
	}
	if (!check(r))
		puts("-1");
	else
		printf("%lldn", check(l) ? l : r);
	return 0;
}
```
[1132E - Knapsack](../problems/E._Knapsack.md "Educational Codeforces Round 61 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 9;
const int L = 840;

typedef long long li;

li dp[N][L * N];
li W;
li cnt[N];

int main()
{
	cin >> W;
	for(int i = 0; i < 8; i++)
		cin >> cnt[i];
	for(int i = 0; i < N; i++) for(int j = 0; j < L * N; j++) dp[i][j] = -1;
	dp[0][0] = 0;
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < L * N; j++)
		{
			if(dp[i][j] == -1) continue;
			int b = L / (i + 1);
			if(cnt[i] < b)
				b = cnt[i];
			for(int k = 0; k <= b; k++)
			{
				li& d = dp[i + 1][j + k * (i + 1)];
				d = max(d, dp[i][j] + (cnt[i] - k) / (L / (i + 1)));
			}
		}
	}
	li ans = 0;
	for(int j = 0; j < L * N; j++)
	{
		if(j > W || dp[8][j] == -1)
			continue;
		ans = max(ans, j + L * (min(dp[8][j], (W - j) / L)));
	}
	cout << ans << endl;
}
```
[1132F - Clear the String](../problems/F._Clear_the_String.md "Educational Codeforces Round 61 (Rated for Div. 2)")

 **Tutorial**
### [1132F - Clear the String](../problems/F._Clear_the_String.md "Educational Codeforces Round 61 (Rated for Div. 2)")

We will solve the problem by dynamic programming. 

Let $dp_{l, r}$ be the answer for substring $s_{l, l + 1, \dots, r}$. Then we have two cases: 

1. The first letter of the substring is deleted separately from the rest, then $dp_{l, r} = 1 + dp_{l + 1, r}$;
2. The first letter of the substring is deleted alongside with some other letter (both letters must be equal), then $dp_{l,r} = \min \limits_{l < i \le r, s_i = s_r} dp_{l + 1, i - 1} + dp_{i, r}$.
 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n;
string s;
int dp[N][N];

int calc(int l, int r){	
	int &res = dp[l][r];
	if(res != -1) return res;
	
	if(l > r) return res = 0;
	if(l == r) return res = 1;
    
	res = 1 + calc(l + 1, r);
	for(int i = l + 1; i <= r; ++ i)
		if(s[l] == s[i])
			res = min(res, calc(l + 1, i - 1) + calc(i, r));
	return res;
}

int main(){
	cin >> n >> s;
	memset(dp, -1, sizeof dp);
	cout << calc(0, n - 1);
	return 0;
}
```
[1132G - Greedy Subsequences](../problems/G._Greedy_Subsequences.md "Educational Codeforces Round 61 (Rated for Div. 2)")

 **Tutorial**
### [1132G - Greedy Subsequences](../problems/G._Greedy_Subsequences.md "Educational Codeforces Round 61 (Rated for Div. 2)")

Let's calculate for each position i position nxti — "the closest greater from the right" element to i and add directed edge from i to nxti. Then we will get oriented forest (or tree if we'd add fictive vertex) where all edges are directed to some root.

So, we can look at current subsegment we need to calculate the answer for as at a number of marked vertices in the tree. Then, the answer itself is a longest path up to the tree consisting only from marked vertices. Key observation is next: if u and v are marked and u is an ancestor of v then any vertex y on path from v to u is also marked.

So, "the longest path up to the tree consisting only from marked vertices" has length equal to a number of marked vertices on path to the root. And we have three types of queries: mark a vertex, unmark a vertex and calculate maximum number of marked vertices among all paths to the root.

It can be done with Segment Tree on Euler Tour of the tree: if we calculate Tin and Tout for each vertex in dfs order, then marking/unmarking is just adding ±1 to a segment [Tin,Tout), and maximum among all paths is a maximum on the whole tree.

Result time complexity is O(nlogn) and space complexity is O(n).

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

int n, k;
vector<int> a;

inline bool read() {
	if(!(cin >> n >> k))
		return false;
	a.assign(n, 0);
	fore(i, 0, n)
		cin >> a[i];
	return true;
}

int T = 0;
vector< vector<int> > g;
vector<int> tin, tout;

void dfs(int v) {
	tin[v] = T++;
	for(int to : g[v])
		dfs(to);
	tout[v] = T;
}

vector<int> Tmax, Tadd;

inline void push(int v) {
	Tadd[2 * v + 1] += Tadd[v];
	Tadd[2 * v + 2] += Tadd[v];
	Tadd[v] = 0;
}
inline int getmax(int v) {
	return Tmax[v] + Tadd[v];
}

void addVal(int v, int l, int r, int lf, int rg, int val) {
	if(l == lf && r == rg) {
		Tadd[v] += val;
		return;
	}
	int mid = (l + r) >> 1;
	push(v);
	if(lf < mid) addVal(2 * v + 1, l, mid, lf, min(mid, rg), val);
	if(rg > mid) addVal(2 * v + 2, mid, r, max(lf, mid), rg, val);
	Tmax[v] = max(getmax(2 * v + 1), getmax(2 * v + 2));
}

inline void solve() {
	g.resize(n + 1);
	tin.resize(n + 1, 0);
	tout.resize(n + 1, 0);
	vector<int> st;
	for(int i = n - 1; i >= 0; i--) {
		while(!st.empty() && a[st.back()] <= a[i])
			st.pop_back();
		int nxt = st.empty() ? n : st.back();
		g[nxt].push_back(i);
		st.push_back(i);
	}
	dfs(n);
	Tmax.assign(4 * (n + 1), 0);
	Tadd.assign(4 * (n + 1), 0);
	
	fore(i, 0, k - 1)
		addVal(0, 0, n + 1, tin[i], tout[i], +1);
	
	for(int l = 0; l + k <= n; l++) {
		addVal(0, 0, n + 1, tin[l + k - 1], tout[l + k - 1], +1);
		cout << getmax(0) << " ";
		addVal(0, 0, n + 1, tin[l], tout[l], -1);
	}
	cout << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(0);
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
