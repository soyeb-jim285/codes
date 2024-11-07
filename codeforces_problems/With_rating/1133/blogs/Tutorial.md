# Tutorial

[1133A - Middle of the Contest](../problems/A._Middle_of_the_Contest.md "Codeforces Round 544 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1133A - Middle of the Contest](../problems/A._Middle_of_the_Contest.md "Codeforces Round 544 (Div. 3)")

Firstly, let's parse both strings to four integers ($h_1, m_1, h_2, m_2$). Just read them and then use some standard functions to transform them into integers (or we can do it manually).

The second part is to obtain $t_1 = h_1 \cdot 60 + m_1$ and $t_2 = h_2 \cdot 60 + m_2$. Then let $t_3 = \frac{t_1 + t_2}{2}$. It is the answer.

We have to print $h_3 = \lfloor\frac{t_3}{60}\rfloor$ and $m_3 = t_3 \% 60$, where $\lfloor\frac{a}{b}\rfloor$ is $a$ divided by $b$ rounding down and $a \% b$ is $a$ modulo $b$.

The only thing we should do more carefully is to print one leading zero before $h_3$ if it is less than $10$ and do the same for $m_3$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int h1, m1;
	scanf("%d:%d", &h1, &m1);
	int h2, m2;
	scanf("%d:%d", &h2, &m2);
	int t1 = h1 * 60 + m1;
	int t2 = h2 * 60 + m2;
	int t3 = (t1 + t2) / 2;
	printf("%02d:%02dn", t3 / 60, t3 % 60);
	
	return 0;
}
```
[1133B - Preparation for International Women's Day](../problems/B._Preparation_for_International_Women's_Day.md "Codeforces Round 544 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1133B - Preparation for International Women's Day](../problems/B._Preparation_for_International_Women's_Day.md "Codeforces Round 544 (Div. 3)")

Let $cnt_i$ be the number of boxes with $i$ candies modulo $k$.

Firstly, the number of pairs of boxes we can obtain using two boxes with remainder $0$ modulo $k$ is $\lfloor\frac{cnt_0}{2}\rfloor$.

Secondly, if $k$ is even then we also can obtain pairs of boxes using two boxes with remainder $\frac{k}{2}$ modulo $k$ and its number is $\lfloor\frac{cnt_{\frac{k}{2}}}{2}\rfloor$.

And for any other remainder $i$ from $1$ to $\lfloor\frac{k}{2}\rfloor$ the number of pairs of boxes is $min(cnt_{i}, cnt_{k - i - 1})$.

So, if we sum up all these values, the answer is this sum multiplied by two (because we have to print the number of boxes, not pairs).

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
	vector<int> cnt(k);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++cnt[x % k];
	}
	int ans = cnt[0] / 2;
	if (k % 2 == 0) ans += cnt[k / 2] / 2;
	for (int i = 1; i < (k + 1) / 2; ++i) {
		int j = k - i;
		ans += min(cnt[i], cnt[j]);
	}
	
	cout << ans * 2 << endl;
	
	return 0;
}
```
[1133C - Balanced Team](../problems/C._Balanced_Team.md "Codeforces Round 544 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1133C - Balanced Team](../problems/C._Balanced_Team.md "Codeforces Round 544 (Div. 3)")

Let's sort all values in non-decreasing order. Then we can use two pointers to calculate for each student $i$ the maximum number of students $j$ such that $a_j - a_i \le 5$ ($j > i$). This is pretty standard approach. We also can use binary search to do it (or we can store for each programming skill the number of students with this skill and just iterate from some skill $x$ to $x+5$ and sum up all numbers of students).

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
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0;
	int j = 0;
	for (int i = 0; i < n; ++i) {
		while (j < n && a[j] - a[i] <= 5) {
			++j;
			ans = max(ans, j - i);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1133D - Zero Quantity Maximization](../problems/D._Zero_Quantity_Maximization.md "Codeforces Round 544 (Div. 3)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "Grandmaster BledDest")

 **Tutorial**
### [1133D - Zero Quantity Maximization](../problems/D._Zero_Quantity_Maximization.md "Codeforces Round 544 (Div. 3)")

For each index $i \in [1, n]$ let's try to find which $d$ we should use in order to make $i$-th element of $c$ equal to zero.

If $a_i = 0$, then $c_i = b_i$ no matter which $d$ we choose. So we should just ignore this index and add $1$ to the answer if $b_i = 0$.

Otherwise, we should choose $d = \frac{-b_i}{a_i}$. Let's calculate the required fraction for each index, and among all fractions find one that fits most indices (this can be done, for example, by storing all fractions in a map).

The only thing that's left to analyze is how to compare the fractions, because floating-point numbers may be not precise enough. Let's store each fraction as a pair of integers $(x, y)$, where $x$ is the numenator and $y$ is the denominator. We should normalize each fraction as follows: firstly, we reduce it by finding the greatest common divisor of $x$ and $y$, and then dividing both numbers by this divisor. Secondly, we should ensure that numenator is non-negative, and if numenator is zero, then denominator should also be non-negative (this can be achieved by multiplying both numbers by $-1$).

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second

const int N = 200043;

void norm(pair<int, int>& p)
{
	if(p.x < 0)
	{
		p.x *= -1;
		p.y *= -1;
	}
	else if (p.x == 0 && p.y < 0)
	{
		p.y *= -1;
	}
	int d = __gcd(abs(p.x), abs(p.y));
	p.x /= d;
	p.y /= d;
}

map<pair<int, int>, int> m;

int a[N];
int b[N];
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	int ans = 0;
	int cnt0 = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == 0)
		{
			if(b[i] == 0)
				cnt0++;
		}
		else
		{
			pair<int, int> p = make_pair(-b[i], a[i]);
			norm(p);
			m[p]++;
			ans = max(ans, m[p]);
		}
	}
	cout << cnt0 + ans << endl;
}
```
[1133E - K Balanced Teams](../problems/E._K_Balanced_Teams.md "Codeforces Round 544 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1133E - K Balanced Teams](../problems/E._K_Balanced_Teams.md "Codeforces Round 544 (Div. 3)")

Firstly, let's sort all students in order of non-decreasing their programming skill.

Then let's calculate the following dynamic programming: $dp_{i, j}$ is the maximum number of students in at most $j$ non-empty teams if we consider first $i$ students.

How to do transitions from $dp_{i, j}$? The first transition is pretty intuitive: just skip the $i$-th ($0$-indexed) student. Then we can set $dp_{i + 1, j + 1} := max(dp_{i + 1, j + 1}, dp_{i, j})$.

The second possible transition is to take some team starting from the $i$-th student.

The only assumption we need to do it is the following: take the maximum by number of students team starting from the $i$-th student is always optimally. Why it is so?

If we consider the student with the maximum programming skill in the team, we can take him to this team instad of forming the new team with this student because this is always not worse.

So the second transition is the following: let $cnt_i$ be the number of students in a team if the $i$-th student is the first in it. We can calculate this part in $O(n^2)$ naively or in $O(n)$ using two pointers.

We can set $dp_{i + cnt_i, j + 1} = max(dp_{i + cnt_i, j + 1}, dp_{i, j} + cnt_i)$.

Time complexity: $O(n(n+k))$.

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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> cnt(n);
	for (int i = 0; i < n; ++i) {
		while (i + cnt[i] < n && a[i + cnt[i]] - a[i] <= 5) {
			++cnt[i];
		}
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (j + 1 <= k) {
				dp[i + cnt[i]][j + 1] = max(dp[i + cnt[i]][j + 1], dp[i][j] + cnt[i]);
			}
		}
	}
	
	cout << dp[n][k] << endl;
	
	return 0;
}
```
[1133F1 - Spanning Tree with Maximum Degree](../problems/F1._Spanning_Tree_with_Maximum_Degree.md "Codeforces Round 544 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1133F1 - Spanning Tree with Maximum Degree](../problems/F1._Spanning_Tree_with_Maximum_Degree.md "Codeforces Round 544 (Div. 3)")

We can take any vertex with the maximum degree and all its neighbours. To implement it, just run bfs from any vertex with the maximum degree. See the authors solution for better understanding.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> deg, used;
vector<pair<int, int>> ans;

mt19937 rnd(time(NULL));

void bfs(int s) {
	used = vector<int>(n);
	used[s] = 1;
	queue<int> q;
	q.push(s);
	
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto to : g[v]) {
			if (used[to]) continue;
			if (rnd() & 1) ans.push_back(make_pair(v, to));
			else ans.push_back(make_pair(to, v));
			used[to] = 1;
			q.push(to);
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m;
	g = vector<vector<int>>(n);
	deg = vector<int>(n);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
		++deg[x];
		++deg[y];
	}
	
	int pos = 0;
	for (int i = 0; i < n; ++i) {
		if (deg[pos] < deg[i]) {
			pos = i;
		}
	}
	
	bfs(pos);
	shuffle(ans.begin(), ans.end(), rnd);
	for (auto it : ans) cout << it.first + 1 << " " << it.second + 1 << endl;
	
	return 0;
}
```
[1133F2 - Spanning Tree with One Fixed Degree](../problems/F2._Spanning_Tree_with_One_Fixed_Degree.md "Codeforces Round 544 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1133F2 - Spanning Tree with One Fixed Degree](../problems/F2._Spanning_Tree_with_One_Fixed_Degree.md "Codeforces Round 544 (Div. 3)")

Firstly, let's remove the vertex $1$ from the graph. Then let's calculate the number of connected components. Let it be $cnt$.

The answer is NO if and only if $cnt > D$ or $D$ is greater than the number of edges incident to the first vertex.

Otherwise let's construct the answer. Firstly, let's add into the new graph spanning trees of components in the initial graph without vertex $1$.

Then let's add into the new graph $cnt$ edges from vertex $1$ — one edge to each component.

Then let's add into the new graph any $D - cnt$ remaining edges from vertex $1$.

The last thing we need is to construct a spanning tree of a new graph such that all edges incident to the vertex $1$ are in this spanning tree (and other edges doesn't matter).

How to do it? Let's run bfs from the vertex $1$ in a new graph!

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n, m, D;
vector<vector<int>> g;

int cnt;
vector<int> p, color;
vector<pair<int, int>> ans;

mt19937 rnd(time(NULL));

void bfs(int s, int bad) {
	queue<int> q;
	q.push(s);
	color[s] = cnt;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (p[v] != -1) {
			if (rnd() & 1) ans.push_back(make_pair(p[v], v));
			else ans.push_back(make_pair(v, p[v]));
		}
		for (auto to : g[v]) {
			if (to == bad || color[to] != -1) continue;
			p[to] = v;
			color[to] = cnt;
			q.push(to);
		}
	}
	++cnt;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m >> D;
	g = vector<vector<int>>(n);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	p = color = vector<int>(n, -1);
	cnt = 0;
	for (int i = 1; i < n; ++i) {
		if (color[i] == -1) {
			bfs(i, 0);
		}
	}
	
	if (cnt > D || D > int(g[0].size())) {
		cout << "NO" << endl;
		return 0;
	}
	
	sort(g[0].begin(), g[0].end(), [](int a, int b) {
		return color[a] < color[b];
	});
	
	for (int i = 0; i < int(g[0].size()); ++i) {
		if (i == 0 || color[g[0][i]] != color[g[0][i - 1]]) {
			ans.push_back(make_pair(0, g[0][i]));
		}
	}
	D -= cnt;
	for (int i = 1; i < int(g[0].size()); ++i) {
		if (D == 0) break;
		if (color[g[0][i]] == color[g[0][i - 1]]) {
			ans.push_back(make_pair(0, g[0][i]));
			--D;
		}
	}
	
	g = vector<vector<int>>(n);
	for (auto it : ans) {
		g[it.first].push_back(it.second);
		g[it.second].push_back(it.first);
	}
	ans.clear();
	p = color = vector<int>(n, -1);
	cnt = 0;
	bfs(0, -1);
	
	shuffle(ans.begin(), ans.end(), rnd);
	cout << "YES" << endl;
	for (auto it : ans) {
		cout << it.first + 1 << " " << it.second + 1 << endl;
	}
	
	return 0;
}
```
