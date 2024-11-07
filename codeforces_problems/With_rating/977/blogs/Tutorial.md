# Tutorial

[977A - Wrong Subtraction](../problems/A._Wrong_Subtraction.md "Codeforces Round 479 (Div. 3)")

 **Tutorial**Tutorial is loading... **Solution (Vovuh)**
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
	
	for (int i = 0; i < k; ++i) {
		if (n % 10 == 0) n /= 10;
		else n--;
	}
	
	cout << n << endl;
	
	return 0;
}
```
[977B - Two-gram](../problems/B._Two-gram.md "Codeforces Round 479 (Div. 3)")

 **Tutorial**
### [977B - Two-gram](../problems/B._Two-gram.md "Codeforces Round 479 (Div. 3)")

There are at least two different approaches to this problem:

You can iterate over all substrings of $s$ of length $2$ and calculate for each of them the number of its occurrences in $s$ (and try to update the result with the current substring).

Also you can iterate over all two-grams in the alphabet and do the same as in the aforementioned solution.

 **Solution (Vovuh)**
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
	string s;
	cin >> s;
	
	int res = 0;
	string ans;
	for (int i = 0; i < n - 1; ++i) {
		int cur = 0;
		for (int j = 0; j < n - 1; ++j)
			if (s[j] == s[i] && s[j + 1] == s[i + 1])
				++cur;
		if (res < cur) {
			res = cur;
			ans = string(1, s[i]) + string(1, s[i + 1]);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[977C - Less or Equal](../problems/C._Less_or_Equal.md "Codeforces Round 479 (Div. 3)")

 **Tutorial**
### [977C - Less or Equal](../problems/C._Less_or_Equal.md "Codeforces Round 479 (Div. 3)")

In this problem you can do the following thing: firstly, let's sort our array.

Let $ans$ will be the answer. Then you have two cases: if $k = 0$ then $ans := a_0 - 1$ otherwise $ans := a_{k - 1}$ (for 0-indexed array).

Then you need to calculate the number of the elements of the array $a$ that are less than or equal to $ans$. Let it be $cnt$. Then if $ans < 1$ or $cnt \ne k$ then print "-1" otherwise print $ans$.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	scanf("%d %d", &n, &k);
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	
	sort(a.begin(), a.end());
	
	int ans;
	
	if (k == 0) {
		ans = a[0] - 1;
	} else {
		ans = a[k - 1];
	}
	
	int cnt = 0;
	
	for (int i = 0; i < n; ++i)
		if (a[i] <= ans) ++cnt;
	
	if (cnt != k || !(1 <= ans && ans <= 1000 * 1000 * 1000)) {
		puts("-1");
		return 0;
	}
	
	printf("%dn", ans);
	
	return 0;
}
```
[977D - Divide by three, multiply by two](../problems/D._Divide_by_three,_multiply_by_two.md "Codeforces Round 479 (Div. 3)")

 **Tutorial**
### [977D - Divide by three, multiply by two](../problems/D._Divide_by_three,_multiply_by_two.md "Codeforces Round 479 (Div. 3)")

Let $deg_3(x)$ be the maximum integer $y$ such that $3^y | x$ ($x$ is divisible by $3^y$).

Our problem is to rearrange the given array in such a way that (easy to see it if we look at our operations) if it looks like $a_{i_1}, a_{i_2}, \dots, a_{i_n}$, then for each $k \in [1..n - 1]$ the next inequality will be satisfied: $deg_3(a_{i_k}) \ge deg_3(a_{i_k + 1})$. And if $deg_3(a_{i_k}) = deg_3(a_{i_k + 1})$ then numbers must be placed in increasing order (because of our operations). So we can store an array of pairs $ans$, when $ans_i = (x_i, y_i)$, $x_i = -deg_3(a_i)$, $y_i = a_i$. Then if we sort it in lexicographical order we can just print the second elements of the sorted array $ans$.

 **Solution (eddy1021)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int count3(LL x){
  int ret=0;
  while(x % 3 == 0){
    ret++;
    x /= 3;
  }
  return ret;
}
int n;
vector<pair<int,LL>> v;
int main(){
  cin>>n;
  v.resize(n);
  for(int i=0; i<n; i++){
    cin>>v[i].second;
    v[i].first=-count3(v[i].second);
  }
  sort(v.begin(), v.end());
  for(int i=0; i<n; i++)
    printf("%lld%c", v[i].second, " n"[i + 1 == n]);
}
```
[977E - Cyclic Components](../problems/E._Cyclic_Components.md "Codeforces Round 479 (Div. 3)")

 **Tutorial**
### [977E - Cyclic Components](../problems/E._Cyclic_Components.md "Codeforces Round 479 (Div. 3)")

Let's solve this problem for each connected component of the given graph separately.

It is easy to see that the connected component is a cycle iff the degree of each its vertex equals to $2$.

So the solution is to count the number of components such that every vertex in the component has degree $2$.

The connected components of the graph can be easily found by simple dfs or bfs.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 11;

int n, m;
int deg[N];
bool used[N];
vector<int> comp;
vector<int> g[N];

void dfs(int v) {
	used[v] = true;
	comp.push_back(v);
	
	for (auto to : g[v])
		if (!used[to])
			dfs(to);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
		++deg[x];
		++deg[y];
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			comp.clear();
			dfs(i);
			bool ok = true;
			for (auto v : comp) ok &= deg[v] == 2;
			if (ok) ++ans;
		}
	}
	
	printf("%dn", ans);
	
	return 0;
}
```
[977F - Consecutive Subsequence](../problems/F._Consecutive_Subsequence.md "Codeforces Round 479 (Div. 3)")

 **Tutorial**
### [977F - Consecutive Subsequence](../problems/F._Consecutive_Subsequence.md "Codeforces Round 479 (Div. 3)")

Let $dp[x]$ be the answer for our problem if the last element of our subsequence equals to $x$.

Then we have an easy solution: let's store $dp$ as a "std::map" (C++) or "HashMap" (Java). Initially for each $i \in [1..n]$ $dp[a_i] = 0$. Then let's iterate over all $a_i$ in order of input and try to update $dp[a_i]$ with a $dp[a_i - 1] + 1$ ($dp[a_i] = max(dp[a_i], dp[a_i - 1] + 1)$).

Then the maximum element of $dp$ will be our answer. Let it be $ans$. Then let's find any $a_i$ such that $dp[a_i] = ans$. Let it be $lst$. Then for restoring the answer we need to iterate over all elements of our array in reverse order and if the current element $a_k = lst$ then push $k$ to the array of positions of our subsequence and make $lst := lst - 1$.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	
	map<int, int> dp;
	
	int ans = 0;
	int lst = 0;
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		dp[x] = dp[x - 1] + 1;
		if (ans < dp[x]) {
			ans = dp[x];
			lst = x;
		}
	}
	
	vector<int> res;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == lst) {
			res.push_back(i);
			--lst;
		}
	}
	reverse(res.begin(), res.end());
	
	printf("%dn", ans);
	for (auto it : res)
		printf("%d ", it + 1);
	puts("");
	
	return 0;
}
```
