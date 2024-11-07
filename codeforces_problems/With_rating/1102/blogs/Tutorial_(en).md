# Tutorial_(en)

[1102A - Integer Sequence Dividing](../problems/A._Integer_Sequence_Dividing.md "Codeforces Round 531 (Div. 3)")

 **Tutorial**
### [1102A - Integer Sequence Dividing](../problems/A._Integer_Sequence_Dividing.md "Codeforces Round 531 (Div. 3)")

The first solution: take n modulo 4 and solve the problem manually (then for cases n=0 and n=3 the answer is 0 and for n=1 and n=2 the answer is 1).

Prove: Let's see what can we make for numbers n, n−1, n−2 and n−3. We can add n and n−3 in A and add n−1 and n−2 in B. Then the difference between sums will be 0. We can consider last four numbers this way until we have at least four numbers. And then we have a case n≤3. We can prove the solution for these four cases using bruteforce.

The second solution: if n∑i=1i is even then the answer is 0 otherwise the answer is 1. The formula above is just n(n+1)2.

Prove: if we have an integer sequence 1,2,…,n then we can obtain every number from 0 to n(n+1)2 as the sum of some elements of this sequence. How? Greedily! You can see how this greedy works (and prove, if you want) yourself. So what's next? If n(n+1)2 is even then we can obtain the sum n(n+1)4 in A and in B. Otherwise we can only obtain ⌊n(n+1)4⌋ in A and ⌈n(n+1)4⌉ in B (or vice versa).

 **Solution 1**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	n %= 4;
	if (n == 0 || n == 3) {
		cout << 0 << endl;
	} else {
		cout << 1 << endl;
	}
	
	return 0;
}
```
 **Solution 2**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	long long sum = n * 1ll * (n + 1) / 2;
	cout << (sum & 1) << endl;
	
	return 0;
}
```
[1102B - Array K-Coloring](../problems/B._Array_K-Coloring.md "Codeforces Round 531 (Div. 3)")

 **Tutorial**
### [1102B - Array K-Coloring](../problems/B._Array_K-Coloring.md "Codeforces Round 531 (Div. 3)")

How can we solve this problem easily? Firstly, let's sort the initial array (but maintain the initial order of the elements in the array to restore the answer). Then let's just distribute all the colors uniformly. Let's color the first element in the first color, the second one — in the second, the k-th element — in the k-th color, the k+1-th — in the first color, and so on. So we color the i-th element in the color (i−1)%k+1 (% is just modulo operation). We can see that the answer is "NO" if there is an element with frequency at least k+1 in the array (by pigeonhole principle). Otherwise our solution builds the correct answer. So we can try to find such element in the array naively, using counting sort or many other approaches.

Time complexity — O(nlogn) or O(n2).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;	
	}
	
	sort(a.begin(), a.end());
	
	vector<vector<int>> buckets(k);
	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		buckets[i % k].push_back(a[i].first);
		res[a[i].second] = i % k;
	}
	
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < int(buckets[i].size()) - 1; ++j) {
			if (buckets[i][j] == buckets[i][j + 1]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	
	cout << "YES" << endl;
	for (int i = 0; i < n; ++i) {
		cout << res[i] + 1 << " ";
	}
	cout << endl;
	
	return 0;
}
```
[1102C - Doors Breaking and Repairing](../problems/C._Doors_Breaking_and_Repairing.md "Codeforces Round 531 (Div. 3)")

 **Tutorial**
### [1102C - Doors Breaking and Repairing](../problems/C._Doors_Breaking_and_Repairing.md "Codeforces Round 531 (Div. 3)")

Let's consider two cases:

If x>y then the answer is n because we can make opposite moves to the Slavik's moves and it always will reduce durability of some door (so at some point we will reach the state when all doors will have durability 0).

Otherwise x≤y and we have to realize the optimal strategy for us. If we have some door with durability z≤x then let's break it immediately (why shouldn't we do this?). If we don't do it then Slavik will repair this door during his move. So what Slavik will do now? He will repair some door. Which door he has to repair? Of course the one with durability z≤x because otherwise we will break it during our next move. So we can realize that doors with durability z>x are not interesting for us because Slavik will make opposite moves to our moves. And what is the answer if the number of doors with durability z≤x equals to cnt? It is ⌈cnt2⌉.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, x, y;
	cin >> n >> x >> y;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int cur;
		cin >> cur;
		if (cur <= x) {
			++cnt;
		}
	}
	
	if (x > y) {
		cout << n << endl;
	} else {
		cout << (cnt + 1) / 2 << endl;
	}
	
	return 0;
}
```
[1102D - Balanced Ternary String](../problems/D._Balanced_Ternary_String.md "Codeforces Round 531 (Div. 3)")

 **Tutorial**
### [1102D - Balanced Ternary String](../problems/D._Balanced_Ternary_String.md "Codeforces Round 531 (Div. 3)")

Let's count how many characters '0', '1' and '2' we have in the string s and store it in the array cnt. Also let's count our "goal" array cur. Firstly, the array cur is [n3,n3,n3].

The main idea of this problem is a pretty standard lexicographically greedy approach. We go from left to right and try to place the minimum possible character at the current position in such a way that placing this character is not breaking conditions of our problem. How can we apply this approach to this problem?

Firstly, let's define a function need(cnt,cur)=|cnt0−cur0|+|cnt1−cur1|+|cnt2−cur2|2. What does the value of this function mean? It means the number of replacements we need to reach cur from cnt. Let initNeed=need(cur,cnt) at the beginning of the program. This value means the minimum number of replacements to obtain some balanced ternary string. Let's maintain the variable curRep which initially is 0 and means the number of replacements we already made.

So, we iterate over all positions i from 1 to n. Firstly, let's decrease cntsi. So the array cnt maintains the current amount of characters on suffix of the string. Now let's iterate over characters j from 0 to 2 and try to place every character. If the current character is needed (curj>0), then let's decrease curj and if the number of replacements will still be minimum possible after such replacement (curRep+need(cnt,cur)+(si≠j)=initNeed) then let's place this character, set curRep:=curRep+(si≠j) and go to the next position. This will form lexicographically minimum possible answer with minimum number of replacements.

There is another (simpler) solution from PikMike, you can call him to explain it, I just will add his code to the editorial.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n;

int needRep(const vector<int> &cnt, const vector<int> &need) {
	int res = 0;
	for (int i = 0; i < 3; ++i) {
		res += abs(cnt[i] - need[i]);
	}
	assert(res % 2 == 0);
	return res / 2;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	string s;
	cin >> n >> s;
	
	vector<int> cnt(3), cur(3, n / 3);
	for (auto c : s) {
		++cnt[c - '0'];
	}
	
	int need = needRep(cnt, cur);
		
	int curRep = 0;
	for (int i = 0; i < n; ++i) {
		--cnt[s[i] - '0'];
		for (int j = 0; j < 3; ++j) {
			if (cur[j] == 0) continue;
			int rep = j != s[i] - '0';
			--cur[j];
			if (curRep + rep + needRep(cnt, cur) == need) {
				s[i] = j + '0';
				curRep += rep;
				break;
			}
			++cur[j];
		}
	}
	
	cout << s << endl;
	
	return 0;
}
```
 **Solution (PikMike)**
```cpp
n = int(input())
s = [ord(x) - ord('0') for x in input()]
cnt = [s.count(x) for x in [0, 1, 2]]
def forw(x):
	for i in range(n):
		if (cnt[x] < n // 3 and s[i] > x and cnt[s[i]] > n // 3):
			cnt[x] += 1
			cnt[s[i]] -= 1
			s[i] = x
def back(x):
	for i in range(n - 1, -1, -1):
		if (cnt[x] < n // 3 and s[i] < x and cnt[s[i]] > n // 3):
			cnt[x] += 1
			cnt[s[i]] -= 1
			s[i] = x
forw(0)
forw(1)
back(2)
back(1)
print(''.join([str(x) for x in s]))
```
[1102E - Monotonic Renumeration](../problems/E._Monotonic_Renumeration.md "Codeforces Round 531 (Div. 3)")

 **Tutorial**
### [1102E - Monotonic Renumeration](../problems/E._Monotonic_Renumeration.md "Codeforces Round 531 (Div. 3)")

We are interested in such subsegments of the array a that for every value belonging to this segment all occurences of this value in the array are inside this segment. Let's call such segments closed segments. For example, if a=[1,2,1,2,3], then [1,2,1,2], [3] and [1,2,1,2,3] are closed segments.

We can see that the result is some partition of the given array into several closed segments — if for some value x all occurences of x in bi do not form a segment in ai, then there exists some pair bi,bi+1 such that bi>bi+1 (which contradicts the statement); and if the formed segment is not a closed segment, then for some indices i and j such that ai=aj it is not true that bi=bj (which also contradicts the statement).

Okay, let's try to partition the array into closed segments greedily: take the first prefix of the array that is a closed segment, erase it, take the next prefix, and so on. Let m be the number of closed segments we got with this procedure.

The key fact is that any valid partition can be produced from this partition by merging some adjacent segments. To prove it, suppose we partitioned the array in some other way. The intersection of two closed segments, if it exists, is also a closed segment; so there exists at least one segment in the partition we picked greedily that can be broken into two — but that contradicts the algorithm we used to construct this partition.

So we may merge some of m segments to get a valid partition. There are exactly 2m−1 ways to do so, because for every pair of adjacent segments we may choose whether we will merge it.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main()
{
 	int n;
 	scanf("%d", &n);
 	vector<int> a(n);
 	for(int i = 0; i < n; i++)
 		scanf("%d", &a[i]);
 	map<int, int> lst;
 	vector<int> last_pos(n);
 	for(int i = n - 1; i >= 0; i--)
 	{
 		if(!lst.count(a[i]))
 			lst[a[i]] = i;
 		last_pos[i] = lst[a[i]];
 	}
 	int ans = 1;
 	int cur_max = -1;
 	for(int i = 0; i < n - 1; i++)
 	{
 		cur_max = max(cur_max, last_pos[i]);
 		if(cur_max == i)
 			ans = (2 * ans) % MOD;
 	}	
 	printf("%dn", ans);
 	return 0;
}
```
[1102F - Elongated Matrix](../problems/F._Elongated_Matrix.md "Codeforces Round 531 (Div. 3)")

 **Tutorial**
### [1102F - Elongated Matrix](../problems/F._Elongated_Matrix.md "Codeforces Round 531 (Div. 3)")

Really low constraints, choosing some permutation... Surely, this will be some dp on subsets!

At first, let's get rid of m. For each two rows calculate the minimum difference between the elements of the same columns — let's call this mn1i,j for some rows i, j. This will be used to put row j right after row i. Let's also calculate mn2i,j — the minimum difference between the elements of the column k of row i and column k+1 of row j. This will be used to put row i as the last row and row j as the first one.

Now let's think of choosing the permutation as choosing the traversal of the following graph. Vertices are rows and the weights of edges between the vertices are stored in mn1. However, you can't straight up do minimum weight Hamiltonian cycle search as the edge between the first vertex and the last one should be of weight from mn2 and not mn1.

Let's fix some starting vertex and find minimum weight Hamiltonian paths from it to all vertices. Finally, update the answer with min(mn2u,v,pathv,u). That will lead to 2n⋅n3 approach (minimum weight Hamiltonian path is a well-known problem solved by dp[maskofusedvertices][lastvisitedvertex]).

That's completely fine and it's the most intended solution.

However, there exist another solution that would have worked better if the edge weight were a bit smaller.

Let's do binary search, each time checking if the answer is greater or equal to mid. The check is simple enough. Now the graph is binary (edge exists if its weight is greater or equal to mid), thus you should check for existence of Hamiltonian path, not for the minimum weight one. That can be done in O(2n⋅n2), leading to O(2n⋅n2logMAXN) solution. The key idea of that dp is storing the vertices where the path of the current mask could have ended as a mask itself. Then it becomes dp[mask] with n transitions.

Overall complexity: O(2n⋅n3) or O(2n⋅n2logMAXN).

 **Solution 1**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef long long li;

const int N = 18;
const int M = 100 * 1000 + 13;
const int INF = 1e9;

int dp[1 << N][N];

int n, m;
int a[N][M];
int mn1[N][N], mn2[N][N];

int calc(int mask, int v){
	if (dp[mask][v] != -1)
		return dp[mask][v];
	dp[mask][v] = 0;
	forn(u, n) if (v != u && ((mask >> u) & 1))
		dp[mask][v] = max(dp[mask][v], min(mn1[u][v], calc(mask ^ (1 << v), u)));
	return dp[mask][v];
}

int main() {
	scanf("%d%d", &n, &m);
	forn(i, n) forn(j, m)
		scanf("%d", &a[i][j]);
	
	forn(i, n) forn(j, n){
		int val = INF;
		forn(k, m)
			val = min(val, abs(a[i][k] - a[j][k]));
		mn1[i][j] = val;
		val = INF;
		forn(k, m - 1)
			val = min(val, abs(a[i][k] - a[j][k + 1]));
		mn2[i][j] = val;
	}
	
	int ans = 0;
	forn(i, n){
		memset(dp, -1, sizeof(dp));
		forn(j, n)
			dp[1 << j][j] = (j == i ? INF : 0);
		forn(j, n)
			ans = max(ans, min(mn2[j][i], calc((1 << n) - 1, j)));
	}
	
	printf("%dn", ans);
}
```
 **Solution 2**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 18;
const int M = 100 * 1000 + 13;
const int INF = 1e9;

int used[1 << N];
char dp[1 << N];
int g[1 << N];

int n, m;
int a[N][M];
int mn1[N][N], mn2[N][N];

bool calc(int mask){
	if (dp[mask] != -1)
		return dp[mask];
	used[mask] = 0;
	dp[mask] = 0;
	forn(i, n){
		if (!((mask >> i) & 1))
			continue;
		if (!calc(mask ^ (1 << i)))
			continue;
		if (!(used[mask ^ (1 << i)] & g[i]))
			continue;
		used[mask] |= (1 << i);
		dp[mask] = 1;
	}
	return dp[mask];
}

bool check(int k){
	forn(i, n){
		g[i] = 0;
		forn(j, n)
			g[i] |= (1 << j) * (mn1[j][i] >= k);
	}
	forn(i, n){
		memset(dp, -1, sizeof(dp));
		forn(j, n){
			dp[1 << j] = (j == i);
			used[1 << j] = (1 << j);
		}
		calc((1 << n) - 1);
		forn(j, n) if (mn2[j][i] >= k && ((used[(1 << n) - 1] >> j) & 1))
			return true;
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	forn(i, n) forn(j, m)
		scanf("%d", &a[i][j]);
	
	forn(i, n) forn(j, n){
		int val = INF;
		forn(k, m)
			val = min(val, abs(a[i][k] - a[j][k]));
		mn1[i][j] = val;
		val = INF;
		forn(k, m - 1)
			val = min(val, abs(a[i][k] - a[j][k + 1]));
		mn2[i][j] = val;
	}
	
	int l = 0, r = INF;
	while (l < r - 1){
		int m = (l + r) / 2;
		if (check(m))
			l = m;
		else
			r = m;
	}
	
	printf("%dn", check(r) ? r : l);
}
```
