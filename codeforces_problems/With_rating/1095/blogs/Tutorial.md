# Tutorial

[1095A - Repeating Cipher](../problems/A._Repeating_Cipher.md "Codeforces Round 529 (Div. 3)")

 **Tutorial**
### [1095A - Repeating Cipher](../problems/A._Repeating_Cipher.md "Codeforces Round 529 (Div. 3)")

There are many possible approaches in this problem, I will describe one of the easiest.

Let's print the initial string by the following algorithm: firstly, init the variable $i = 1$. Then, while the encrypted string isn't empty, print the first character of this string, remove $i$ first characters from it and increase $i$ by one.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int index = 0;
    int gap = 1;
    while (index < n)
        cout << s[index], index += gap, gap++;
}

```
[1095B - Array Stabilization](../problems/B._Array_Stabilization.md "Codeforces Round 529 (Div. 3)")

 **Tutorial**
### [1095B - Array Stabilization](../problems/B._Array_Stabilization.md "Codeforces Round 529 (Div. 3)")

It is easy to see that we always have to remove either minimum or maximum of the array. So we can sort the array and the answer will be $min(a_{n - 1} - a_{1}, a_{n} - a_{2})$. We also can do it without sort because two minimal and two maximal elements of the array can be found in linear time.

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
	
	cout << min(a[n - 2] - a[0], a[n - 1] - a[1]) << endl;
	
	return 0;
}
```
[1095C - Powers Of Two](../problems/C._Powers_Of_Two.md "Codeforces Round 529 (Div. 3)")

 **Tutorial**
### [1095C - Powers Of Two](../problems/C._Powers_Of_Two.md "Codeforces Round 529 (Div. 3)")

First of all, let's analyze how can we calculate the minimum number of powers of two needed to get $n$ as the sum. We can use binary representation of $n$: each bit in it, which is equal to $1$, becomes a summand in the answer.

Firstly, if the number of summands is greater than $k$ then the answer is NO. Okay, what if we don't have enough summands? Every summand $x > 1$ can be broken down into two summands equal to $\frac{x}{2}$. Let's maintain all summands greater than $1$ somewhere (stack, array, queue, multiset, anything you want), and pick an arbitrary summand and break it into two until we have exactly $k$ summands. If $n \ge k$, then this process will terminate since we will have some summand to pick until all of them are equal to $1$.

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	map<int, int> ans;
	queue<int> q;
	for(int i = 0; i <= 30; i++)
		if(n & (1 << i))
		{
			if(i > 0) q.push(1 << i);
			ans[1 << i]++;
		}
	if(int(ans.size()) > k)
	{
		puts("NO");
		return 0;
	}
	int cnt = ans.size();
	while(cnt < k && !q.empty())
	{
		int z = q.front();
		q.pop();
		ans[z]--;
		ans[z / 2] += 2;
		if(z / 2 > 1)
		{
			q.push(z / 2);
			q.push(z / 2);
		}
		cnt++;
	}
	if(cnt < k)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(auto x : ans)
		for(int i = 0; i < x.second; i++)
			printf("%d ", x.first);
	puts("");
	return 0;
}
```
[1095D - Circular Dance](../problems/D._Circular_Dance.md "Codeforces Round 529 (Div. 3)")

 **Tutorial**
### [1095D - Circular Dance](../problems/D._Circular_Dance.md "Codeforces Round 529 (Div. 3)")

Let's write a function check(a, b) which will try to restore the circle if kid with number $b$ comes right after kid with number $a$. If $b$ comes right after $a$ then we can determine $c$ — the number of kid who is next to kid $b$. So now we have: $b$ comes right after $a$, $c$ comes right after $b$. Let's determine $d$ — kid who is next to kid $c$.

If we repeat this operation $n$ times then we can "determine" the answer if $b$ comes right after $a$. But it can be wrong so we have to check that our answer corresponds to the input.

So if we have this function, we can apply it two times to determine the correct answer. Just call check($1, a_{1, 1}$) and check($1, a_{1, 2}$).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> a;

void check(int l, int r) {
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int nxt = -1;
		if (a[l][0] == r) {
			nxt = a[l][1];
		} else if (a[l][1] == r) {
			nxt = a[l][0];
		} else {
			return;
		}
		ans.push_back(nxt);
		l = r;
		r = nxt;
	}
	for (auto it : ans) {
		cout << it + 1 << " ";
	}
	cout << endl;
	exit(0);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n;
	a = vector<vector<int>> (n, vector<int>(2));
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1];
		--a[i][0];
		--a[i][1];
	}
	
	check(0, a[0][0]);
	check(0, a[0][1]);
	
	assert(false);
	
	return 0;
}
```
[1095E - Almost Regular Bracket Sequence](../problems/E._Almost_Regular_Bracket_Sequence.md "Codeforces Round 529 (Div. 3)")

 **Tutorial**
### [1095E - Almost Regular Bracket Sequence](../problems/E._Almost_Regular_Bracket_Sequence.md "Codeforces Round 529 (Div. 3)")

In this problem we have to calculate the number (count) of positions such that if we change the type of the bracket at this position then the obtained bracket sequence will become regular.

Let's calculate the balance of each prefix of the bracket sequence and store it in the array $prefBal$. Just iterate from left to right over the string and if the current bracket is opening then increase the current balance by one, otherwise decrease it by one.

For each prefix let's also calculate whether it can be a prefix of a regular bracket sequence (RBS) and store it in the array $prefCan$. The prefix of length $i$ can be the prefix of RBS if and only if the prefix of length $i-1$ can be the prefix of RBS and $prefBal_i \ge 0$.

Let's calculate the same arrays for all suffixes (and call they $sufBal$ and $sufCan$ correspondingly), but now the closing bracket will increase the balance by one and the opening will decrease it by one and we consider the characters from right to left.

Now if we have these arrays, let's iterate over all positions in the initial bracket sequence. If we now at the position $i$ then let's do the following things: firstly, if $prefCan_{i} = false$ or $sufCan_{i} = false$ then skip this position. Otherwise if the current bracket is opening then we have to increase the answer if $prefBal_{i-1} > 0$ and $prefBal_{i - 1} - 1 + sufBal_{i + 1} = 0$ (only in this case the bracket sequence will become regular). And if the current bracket is closing then we have to increase the answer if $prefBal_{i - 1} + 1 - sufBal_{i + 1} = 0$.

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
	string s;
	cin >> n >> s;
	
	string rs(s.rbegin(), s.rend());
	for (int i = 0; i < n; ++i) {
		if (rs[i] == '(') {
			rs[i] = ')';
		} else {
			rs[i] = '(';
		}
	}
	
	vector<int> pref(n + 1), suf(n + 1);
	vector<bool> okp(n + 1), oks(n + 1);
	okp[0] = oks[n] = true;
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + (s[i] == '(' ? +1 : -1);
		okp[i + 1] = okp[i] & (pref[i + 1] >= 0);
		suf[n - i - 1] = suf[n - i] + (rs[i] == '(' ? +1 : -1);
		oks[n - i - 1] = oks[n - i] & (suf[n - i - 1] >= 0);
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!okp[i] || !oks[i + 1]) {
			continue;
		}
		if (s[i] == '(') {
			if (pref[i] > 0 && pref[i] - 1 - suf[i + 1] == 0) {
				++ans;
			}
		} else {
			if (pref[i] + 1 - suf[i + 1] == 0) {
				++ans;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1095F - Make It Connected](../problems/F._Make_It_Connected.md "Codeforces Round 529 (Div. 3)")

 **Tutorial**
### [1095F - Make It Connected](../problems/F._Make_It_Connected.md "Codeforces Round 529 (Div. 3)")

Suppose we have found all the edges of the graph explicitly, sorted them, and start running Kruskal on the sorted list of edges. Each time we add some edge to MST, it is either a special edge given in the input, or an edge which was generated with cost $a_x + a_y$ (whichever costs less). Let's try to analyze how can we find the cheapest edge of each type that connects two components. For special edges, we may just maintain the number of special edges we already added or skipped, and when choosing a new edge, we skip some more (possibly zero) special edges that don't connect anything, until we find an edge that connects something. And for the other type of edges, we may find two components having minimum numbers on the vertices in those components as small as possible, and just connect the minimum vertex in the first component with the minimum vertex in the second component. We may simulate this by maintaining a data structure (for example, a multiset), where for each component we will store the vertex having minimum $a_i$ in this component, and pick two minimums from this set. We also have to be able to check if two vertices are connected (this can be done with DSU) and merge two components.

But this solution can be made easier. Every time we add a "non-special" edge, one of the ends of this edge is the vertex with minimum $a_i$. So we may just find this vertex, generate all edges connecting this vertex to all other vertices, merge this set of edges with the set of special edges, and run any MST algorithm on the resulting set of edges. If there are multiple minimums in the array $a$, then we may pick any of them because in Kruskal algorithm it doesn't matter which of the edges with equal costs we try to add first.

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair

typedef pair<long long, pair<int, int> > edge;

const int N = 200043;

int p[N];
long long a[N];

int get_leader(int x)
{
	return (x == p[x] ? x : (p[x] = get_leader(p[x])));
}

bool merge(int x, int y)
{
	x = get_leader(x);
	y = get_leader(y);
	if(x == y) return false;
	p[x] = y;
	return true;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	vector<edge> es(m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d %lld", &es[i].y.x, &es[i].y.y, &es[i].x);
		es[i].y.x--;
		es[i].y.y--;
	}
	int z = min_element(a, a + n) - a;
	for(int i = 0; i < n; i++)
		if(i != z)
			es.push_back(mp(a[i] + a[z], mp(i, z)));
	sort(es.begin(), es.end());
	long long ans = 0;
	for(int i = 0; i < n; i++)
		p[i] = i;
	for(auto e : es)
		if(merge(e.y.x, e.y.y))
			ans += e.x;
	printf("%lldn", ans);
	return 0;		
}
```
