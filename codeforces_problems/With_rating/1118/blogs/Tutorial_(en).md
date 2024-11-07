# Tutorial_(en)

[1118A - Water Buying](../problems/A._Water_Buying.md "Codeforces Round 540 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1118A - Water Buying](../problems/A._Water_Buying.md "Codeforces Round 540 (Div. 3)")

The answer can be calculated by easy formula: ⌊n2⌋⋅min(2a,b)+(n % 2)⋅a, where ⌊xy⌋ is x divided by y rounded down and x % y is x modulo y.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	
	for (int i = 0; i < q; ++i) {
		long long n;
		int a, b;
		cin >> n >> a >> b;
		cout << (n / 2) * min(2 * a, b) + (n % 2) * a << endl;
	}
	
	return 0;
}
```
[1118B - Tanya and Candies](../problems/B._Tanya_and_Candies.md "Codeforces Round 540 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1118B - Tanya and Candies](../problems/B._Tanya_and_Candies.md "Codeforces Round 540 (Div. 3)")

Let's maintain four variables oddPref, evenPref, oddSuf and evenSuf, which will mean the sum of ai with odd i on prefix, even i on prefix, odd i on suffix and even i on suffix. Initially, oddPref and evenPref are 0, oddSuf equals to the sum of ai with odd i in a whole array and evenSuf equals to the sum of ai with even i in a whole array.

Let's iterate from left to right over all elements of the array. Let's consider the current element ai. If i is even, then set evenSuf:=evenSuf−ai, otherwise let's set oddSuf:=oddSuf−ai. Then let's consider we give the current candy to dad. Then we have to increase the answer if oddPref=evenSuf and evenPref=oddSuf. Then if i is even then let's set evenPref:=evenPref+ai, otherwise let's set oddPref:=oddPref+ai.

 **Solution**
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
	
	vector<int> a(n);
	
	int ePref = 0, oPref = 0, eSuf = 0, oSuf = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i & 1) eSuf += a[i];
		else oSuf += a[i];
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i & 1) eSuf -= a[i];
		else oSuf -= a[i];
		if (ePref + oSuf == oPref + eSuf) {
			++ans;
		}
		if (i & 1) ePref += a[i];
		else oPref += a[i];
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1118C - Palindromic Matrix](../problems/C._Palindromic_Matrix.md "Codeforces Round 540 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

I should mention [this](//codeforces.com/blog/entry/65383) blog because it is amazing! This is a tutorial of this problem from [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov").

 **Tutorial**
### [1118C - Palindromic Matrix](../problems/C._Palindromic_Matrix.md "Codeforces Round 540 (Div. 3)")

Basically, what does the matrix being palindromic imply? For each i,j values in cells (i,j), (i,n−j−1), (n−i−1,j) and (n−i−1,n−j−1) are equal (all zero-indexed). You can easily prove it by reversing the order of rows or columns and checking the overlapping cells in them.

Thus, all cells can be split up into equivalence classes. The even n case is simple: all classes have size 4. The odd n case has classes of sizes 1, 2 and 4.

Let's fill the classes one by one. Obviously, the order between the classes of the same size doesn't matter. I claim that filling the classes in order 4,2,1 in sizes construct the answer if any exists. The key observation is that each next size is divisible by the previous one.

The implementation can come in lots of different forms and complexities. Mine works in O(MAXVAL+n2), you can refer to it in attachment.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef pair<int, int> pt;

const int N = 1000 + 7;

int cnt[N];
int a[20][20];

int main() {
	int n;
	scanf("%d", &n);
	forn(i, n * n){
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	
	vector<pair<int, pt>> cells;
	forn(i, (n + 1) / 2) forn(j, (n + 1) / 2){
		if (i != n - i - 1 && j != n - j - 1)
			cells.push_back({4, {i, j}});
		else if ((i != n - i - 1) ^ (j != n - j - 1))
			cells.push_back({2, {i, j}});
		else
			cells.push_back({1, {i, j}});
	}
	
	for (auto cur : {4, 2, 1}){
		int lst = 1;
		for (auto it : cells){
			if (it.first != cur) continue;
			int i = it.second.first;
			int j = it.second.second;
			while (lst < N && cnt[lst] < cur)
				++lst;
			if (lst == N){
				puts("NO");
				return 0;
			}
			a[i][j] = a[n - i - 1][j] = a[i][n - j - 1] = a[n - i - 1][n - j - 1] = lst;
			cnt[lst] -= cur;
		}
	}
	
	puts("YES");
	forn(i, n){
		forn(j, n)
			printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}
```
[1118D1 - Coffee and Coursework (Easy version)](../problems/D1._Coffee_and_Coursework_(Easy_version).md "Codeforces Round 540 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1118D1 - Coffee and Coursework (Easy version)](../problems/D1._Coffee_and_Coursework_(Easy_version).md "Codeforces Round 540 (Div. 3)")

Since the number of days doesn't exceed n, let's iterate over this value (from 1 to n). So now we have to check (somehow), if the current number of days is enough to write a coursework.

Let the current number of days be k. The best way to distribute first cups of coffee for each day is to take k maximums in the array. Then we have to distribute second cups for each day. Let's also take the next k maximums in the remaining array, and so on.

How do we can calculate such a thing easily? Let's sort the array a in the reversed order (before iterating over all numbers of days), then the following formula will work fine for the current number of days k: n∑i=1max(0,ai−⌊i−1k⌋).

So if the value of the formula above is greater than or equal to m then the current number of days is enough. If there is no any suitable number of days, the answer is -1.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	
	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			sum += max(a[j] - j / i, 0);
		}
		if (sum >= m) {
			cout << i << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	
	return 0;
}
```
[1118D2 - Coffee and Coursework (Hard Version)](../problems/D2._Coffee_and_Coursework_(Hard_Version).md "Codeforces Round 540 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1118D2 - Coffee and Coursework (Hard Version)](../problems/D2._Coffee_and_Coursework_(Hard_Version).md "Codeforces Round 540 (Div. 3)")

Well, the main idea is described in the previous (D1) problem editorial. Read it firstly.

So, now we have to improve our solution somehow. How can we do it? Wait... What is it? We iterate over all numbers of days... And the number of pages Polycarp can write when we consider k+1 days instead of k is strictly increases... (because we always can drink any cup even with the minimum value of ai as a first during the new day, and the number of pages will increase). So, what is it? Oh, this is binary search!

So all we need is to replace linear search to binary search, submit the written code and get AC.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a;

bool can(int i) {
	long long sum = 0; // there can be a bug
	for (int j = 0; j < n; ++j) {
		sum += max(a[j] - j / i, 0);
	}
	return sum >= m;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m;
	
	a = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	
	int l = 1, r = n;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (can(mid)) r = mid;
		else l = mid;
	}
	
	if (can(l)) cout << l << endl;
	else if (can(r)) cout << r << endl;
	else cout << -1 << endl;
	
	return 0;
}
```
[1118E - Yet Another Ball Problem](../problems/E._Yet_Another_Ball_Problem.md "Codeforces Round 540 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**Tutorial is loading... **Solution**
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
	
	if (n > k * 1ll * (k - 1)) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			cur += (i % k == 0);
			cout << i % k + 1 << " " << (cur + i % k) % k + 1 << endl;
		}
	}
	
	return 0;
}
```
[1118F1 - Tree Cutting (Easy Version)](../problems/F1._Tree_Cutting_(Easy_Version).md "Codeforces Round 540 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1118F1 - Tree Cutting (Easy Version)](../problems/F1._Tree_Cutting_(Easy_Version).md "Codeforces Round 540 (Div. 3)")

Let's root the tree by some vertex. The edge (v,u), where v is the parent of u, is now nice if and only if the subtree of u contains either all red vertices of the tree and no blue vertices or all blue vertices of the tree and no red vertices. That's because removing that edge splits the tree into the subtree of u and the component of every other vertex.

Thus, the task is to calculate the number of red and blue vertices in each subtree with dfs and check a couple of conditions.

Overall complexity: O(n).

 **Solution**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 300 * 1000 + 13;

int n;
int a[N];
vector<int> g[N];
int red, blue;
int ans;

pair<int, int> dfs(int v, int p = -1){
	int r = (a[v] == 1), b = (a[v] == 2);
	for (auto u : g[v]) if (u != p){
		auto tmp = dfs(u, v);
		ans += (tmp.first == red && tmp.second == 0);
		ans += (tmp.first == 0 && tmp.second == blue);
		r += tmp.first;
		b += tmp.second;
	}
	return make_pair(r, b);
}

int main() {
	int n;
	scanf("%d", &n);
	
	forn(i, n){
		scanf("%d", &a[i]);
		red += (a[i] == 1);
		blue += (a[i] == 2);
	}
	
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	ans = 0;
	dfs(0);
	printf("%dn", ans);
	return 0;
}
```
[1118F2 - Tree Cutting (Hard Version)](../problems/F2._Tree_Cutting_(Hard_Version).md "Codeforces Round 540 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1118F2 - Tree Cutting (Hard Version)](../problems/F2._Tree_Cutting_(Hard_Version).md "Codeforces Round 540 (Div. 3)")

Okay, this solution is really complicated and I would like to hear nicer approaches from you in comments if you have any. However, I still feel like it's ok to have this problem in a contest specifically as a harder version of F1.

Let's start with the following thing. Root the tree by some vertex. For each color take all vertices of this color and paint their lowest common ancestor the same color as them. The purpose of that will come clear later. Why can we do this? The case with lca = some vertex of that color is trivial. Now, take a look at the edges from lca to its subtrees. At least two of them contain a vertex of that color. You can't cut the edges to these subtrees because this will make vertices of the same color belong to different components. Thus, lca will always be in the same component as these vertices. 

If lca is already painted the other color then the answer is 0. That's because lca once again make vertices of the same color belong to different components.

Now everything will be calculated in a single dfs. Let dfs(v) return one of the following values:

* 0, if there is no colored vertex in the subtree of v;
* x, if there exists some color x such that vertex v has vertices of color x in its subtree and vertex v has ancestors of color x (not necesserily direct parent);
* −1, otherwise.

I claim that if there are multiple suitable colors for some vertex v then the answer is 0. Let's take a look at any two of them and call them colors x1 and x2. For both colors take a path from arbitrary vertex of that color in subtree to arbitrary vertex of that color that is ancestor of v. You can't cut any edge on these paths because that will divide the vertices of the same color. Now, either path for color x1 contains vertex of color x2 or path for color x2 contains vertex of color x1. That vertex is the upper end of the corresponding path. That means that component of one color includes the vertex of the other color, which is impossible.

Moreover, that's the last specific check for the answer being 0. The step with lca helped us to move to the ancestor instead of any vertex in the upper subtree of v. I truly believe that you can avoid lca in this solution, however, that will make both implementation and proof harder.

Now let's do dp[v][2] — the number of ways to cut some edges in the subtree of v so that: 0 — the component with vertex v has no colored vertices in it, 1 — has some colored vertices. Generally, the color itself for 1 doesn't matter. If for some child u of v: dfs(u) returned color x then it must be color x in that component, otherwise the color doesn't matter. For −1 all vertices of each color presented in the subtree of u are contained within the subtree of u.

The transitions will be of form "do we cut the edge from v to u or not" for all children u of v. That is the most tedious part so I'm sorry if I mess up something the way I did with my author solution :D

Here from now I'll ignore the children that returned 0 (if I say all children, I will mean all non-zero returning children) as they add nothing to the answer. 

If there are no children, then the vertices with av=0 will have dp[v][0]=1, dp[v][1]=0 and the other vertices will have dp[v][0]=0, dp[v][1]=1.

Basically, there are two main cases. I would recommend to follow the code in attachment while reading this, tbh.

1. av=0 and all children dfs returned −1. Then for each edge to the child you can either cut it if there are colored vertices (take dp[u][1]) or don't cut it if it has no colored vertices (take dp[u][0]). So dp[v][0]=∏u∈g(v)(dp[u][0]+dp[u][1]). For v to have some color you'll need to push that color from exactly one of the children. You can't choose two subtrees because they are guaranteed to have different colors in them (otherwise they wouldn't return −1). So dp[v][1]=∑x∈g(v)∏u∈g(v),u≠xdp[x][1]⋅(dp[u][0]+dp[u][1]). To calculate that fast enough you'll need to precalculate prefix and suffix products of (dp[u][0]+dp[u][1]).
2. av≠0 or av=0 but some children returned the same value x≠−1. Then you are required to make v the part of component with vertices of color x. That means that dp[v][0]=0 for that case. For children, who returned x, you don't cut their edge (take dp[u][1]). For the other children you can either cut it if there are colored vertices (take dp[u][1]) or don't cut it if it has no colored vertices (take dp[u][0]). Thus, dp[v][1]=(∏u∈g(v),dfs(u)=−1(dp[u][0]+dp[u][1]))⋅(∏u∈g(v),dfs(u)≠−1dp[u][1]).

The answer will be stored in dp[root][1] after that.

Overall complexity: O(nlogn) but I'm sure this can be rewritten in such a manner that it becomes O(n).

 **Solution**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 300 * 1000 + 13;
const int LOGN = 19;
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

int a[N];
vector<int> g[N];
int up[N][LOGN];
int d[N];

void init(int v, int p = -1){
	for (auto u : g[v]) if (u != p){
		up[u][0] = v;
		for (int i = 1; i < LOGN; ++i)
			up[u][i] = up[up[u][i - 1]][i - 1];
		d[u] = d[v] + 1;
		init(u, v);
	}
}

int lca(int v, int u){
	if (d[v] < d[u]) swap(v, u);
	for (int i = LOGN - 1; i >= 0; --i)
		if (d[up[v][i]] >= d[u])
			v = up[v][i];
	if (v == u) return v;
	for (int i = LOGN - 1; i >= 0; --i)
		if (up[v][i] != up[u][i]){
			v = up[v][i];
			u = up[u][i];
		}
	return up[v][0];
}

int l[N];
int dp[N][2];

int dfs(int v, int p = -1){
	vector<pair<int, int>> cur;
	for (auto u : g[v]) if (u != p){
		int c = dfs(u, v);
		if (c != 0)
			cur.push_back(make_pair(c, u));
	}
	
	vector<int> vals;
	forn(i, cur.size()) if (cur[i].first > 0)
		vals.push_back(cur[i].first);
	
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	
	if (int(vals.size()) > 1){
		puts("0");
		exit(0);
	}
	
	if (a[v] != 0 && !vals.empty() && vals[0] != a[v]){
		puts("0");
		exit(0);
	}
	
	if (a[v] == 0 && cur.empty())
		return 0;
	
	if (a[v] == 0 && vals.empty()){		
		vector<int> pr(1, 1), su(1, 1);
		forn(i, cur.size())
			pr.push_back(mul(pr.back(), add(dp[cur[i].second][0], dp[cur[i].second][1])));
		for (int i = int(cur.size()) - 1; i >= 0; --i)
			su.push_back(mul(su.back(), add(dp[cur[i].second][0], dp[cur[i].second][1])));
		reverse(su.begin(), su.end());
		dp[v][1] = 0;
		forn(i, cur.size())
			dp[v][1] = add(dp[v][1], mul(mul(pr[i], su[i + 1]), dp[cur[i].second][1]));
		dp[v][0] = add(dp[v][0], pr[cur.size()]);
		return -1;
	}
	
	dp[v][1] = 1;
	for (auto it : cur){
		if (it.first == -1)
			dp[v][1] = mul(dp[v][1], add(dp[it.second][0], dp[it.second][1]));	
		else
			dp[v][1] = mul(dp[v][1], dp[it.second][1]);
	}
	
	if (a[v] == 0)
		return vals[0];
	
	return (l[a[v]] == v ? -1 : a[v]);
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	
	forn(i, n)
		scanf("%d", &a[i]);
	
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	init(0);
	
	memset(l, -1, sizeof(l));
	forn(i, n) if (a[i] != 0)
		l[a[i]] = (l[a[i]] == -1 ? i : lca(l[a[i]], i));
	
	for (int i = 1; i <= k; ++i){
		if (a[l[i]] != 0 && a[l[i]] != i){
			puts("0");
			exit(0);
		}
		a[l[i]] = i;
	}
	
	dfs(0);
	
	printf("%dn", dp[0][1]);
	return 0;
}
```
