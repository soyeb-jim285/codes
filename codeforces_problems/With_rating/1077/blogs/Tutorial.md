# Tutorial

[1077A - Frog Jumping](../problems/A._Frog_Jumping.md "Codeforces Round 521 (Div. 3)")

 **Tutorial**
### [1077A - Frog Jumping](../problems/A._Frog_Jumping.md "Codeforces Round 521 (Div. 3)")

With each pair of jumps of kind "to the right — to the left" the frog jumps $a - b$. So the answer is almost $(a - b) \cdot \lfloor\frac{k}{2}\rfloor$. Almost because there can be one more jump to the right. So if $k$ is odd then we have to add $a$ to the answer.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int a, b, k;
		cin >> a >> b >> k;
		cout << (a - b) * 1ll * (k / 2) + a * (k & 1) << endl;
	}
	
	return 0;
}
```
[1077B - Disturbed People](../problems/B._Disturbed_People.md "Codeforces Round 521 (Div. 3)")

 **Tutorial**
### [1077B - Disturbed People](../problems/B._Disturbed_People.md "Codeforces Round 521 (Div. 3)")

The first observation is that we are interested only in patterns of kind "101". All other patterns don't make sense at all.

So, let's build a greedy approach. Let's iterate over the given array from the left to the right and maintain that the prefix of the given answer is already correct. If now we are at some position $i$, $a_{i - 1} = a_{i + 1} = 1$ and $a_i = 0$ (and the prefix from $1$ to $i-2$ is already correct) then which one $1$ we have to replace? When we replace the left one then we cannot do better in the future, but when we replace the right one then we can fix some on the suffix of the array.

The easiest example is "1101011". If now we are at the position $3$ then we will do better if we will set $a_4 := 0$.

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
	
	int ans = 0;
	for (int i = 1; i < n - 1; ++i) {
		if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) {
			++ans;
			a[i + 1] = 0;
		}
	}
	cout << ans << endl;
	
	return 0;
}
```
[1077C - Good Array](../problems/C._Good_Array.md "Codeforces Round 521 (Div. 3)")

 **Tutorial**
### [1077C - Good Array](../problems/C._Good_Array.md "Codeforces Round 521 (Div. 3)")

The first part: calculate the sum of the whole array: $sum = \sum\limits_{i = 1}^n a_i$ (be careful, it can be $2 \cdot 10^{11}$!).

The second part: let's maintain an array $cnt$ of size $10^6 + 1$ where $cnt_i$ will be equal to the number of elements in the given array equals to $i$.

The third part: iterate over the array, let the current position be $i$. Set $sum := sum - a_i$, make $cnt_{a_i} := cnt_{a_i} - 1$. If $sum$ is even, $\frac{sum}{2} \le 10^6$ and $cnt_{\frac{sum}{2}} > 0$ then the index $i$ is nice otherwise it doesn't. And after all make $cnt_{a_i} := cnt_{a_i} + 1$ and set $sum := sum + a_i$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> cnt(MAX + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	long long sum = accumulate(a.begin(), a.end(), 0ll);
	
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		sum -= a[i];
		--cnt[a[i]];
		if (sum % 2 == 0 && sum / 2 <= MAX && cnt[sum / 2] > 0) {
			ans.push_back(i);
		}
		sum += a[i];
		++cnt[a[i]];
	}
	
	cout << ans.size() << endl;
	for (auto it : ans) cout << it + 1 << " ";
	cout << endl;
	
	return 0;
}
```
[1077D - Cutting Out](../problems/D._Cutting_Out.md "Codeforces Round 521 (Div. 3)")

 **Tutorial**
### [1077D - Cutting Out](../problems/D._Cutting_Out.md "Codeforces Round 521 (Div. 3)")

Let's solve the problem using binary search by the answer. It is easy to see that if we can construct the answer for some number of copies $val$ then we also can do it for $val - 1$. The only thing we need is to write the function $can(val)$ which will say can we cut off $val$ copies of some array $t$ from $s$ or not.

Let's imagine $val$ copies of string $t$ as a matrix of size $val \times k$. Obviously, each row of this matrix should be equal to each other row. Let's fill not rows but columns of this matrix. For some element $i$ of $s$ we can easy notice that we can take exactly $\lfloor\frac{cnt_i}{val}\rfloor$ columns containing this element where $cnt_i$ is the number of such elements in $s$. So, overall number of columns we can fill in this matrix will be $\sum\limits_{i = 1}^{2 \cdot 10^5} \lfloor\frac{cnt_i}{val}\rfloor$. If this value is greater than or equal to $k$ then $can(val)$ is true otherwise it is false.

It is easy to construct the answer using all things we described above.

Overall complexity is $O(n + |A|\log n)$ where $|A|$ is the size of the alphabet.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200 * 1000 + 1;

int n, k;
vector<int> s, t;
vector<int> cnts(MAX);

bool can(int cnt) {
	t.clear();
	for (int i = 0; i < MAX; ++i) {
		int need = min(cnts[i] / cnt, k - int(t.size()));
		for (int j = 0; j < need; ++j) {
			t.push_back(i);
		}
	}
	return int(t.size()) == k;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> k;
	s = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (auto c : s) {
		++cnts[c];
	}
	
	int l = 0, r = n;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (can(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	if (!can(r)) can(l);
	for (auto it : t) cout << it << " ";
	cout << endl;
	
	return 0;
}
```
[1077E - Thematic Contests](../problems/E._Thematic_Contests.md "Codeforces Round 521 (Div. 3)")

 **Tutorial**
### [1077E - Thematic Contests](../problems/E._Thematic_Contests.md "Codeforces Round 521 (Div. 3)")

The first thing: we don't need the problems, we need their counts. So let's calculate for each topic the number of problems with this topic and sort them in non-decreasing order. The counting can be done with std::map or another one sorting.

The second thing: the answer is not exceed $n$ (very obviously). So let's iterate over the number of problems in maximum by the number of problems thematic contest. Now we have to calculate the maximum number of problems we can take in the set of thematic contests. Let's do it greedily.

The number of contests in the set don't exceed $\log n$. Let the number of problems in the current contest be $cur$ (at the beginning of iteration the current contest is the maximum by the number of problems). Let's take the topic with the maximum number of problems for this contest. If we cannot do it, stop the iteration. Otherwise we can (maybe) continue the iteration. If $cur$ is even then divide it by $2$ and continue with the rest of topics, otherwise stop the iteration. Which topic we have to choose for the second one contest? The answer is: the topic with the maximum number of problems (which isn't chosen already). So let's carry the pointer $pos$ (initially it is at the end of the array of counts) and decrease it when we add another one contest to our set. All calculations inside the iteration are very obviously.

Let's notice that one iteration spends at most $\log n$ operations. So overall complexity of the solution is $O(n \log n)$.

The last question is: why can we take the maximum by the number of problems topic each time? Suppose we have two contests with numbers of problems $x$ and $y$, correspondingly. Let's consider the case when $x < y$. Let the number of problems of the first contest topic be $cnt_x$ and the number of problems of the second contest topic be $cnt_y$. The case $cnt_x \le cnt_y$ don't break our assumptions. The only case which can break our assumptions is $cnt_x > cnt_y$. So if it is then we can swap these topics (because $x < y$ and $cnt_x > cnt_y$) and all will be okay. So this greedy approach works.

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
	map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
	}
	
	vector<int> cnts;
	for (auto it : cnt) {
		cnts.push_back(it.second);
	}
	sort(cnts.begin(), cnts.end());
	
	int ans = 0;
	for (int i = 1; i <= cnts.back(); ++i) {
		int pos = int(cnts.size()) - 1;
		int cur = i;
		int res = cur;
		while (cur % 2 == 0 && pos > 0) {
			cur /= 2;
			--pos;
			if (cnts[pos] < cur) break;
			res += cur;
		}
		ans = max(ans, res);
	}
	cout << ans << endl;
	
	return 0;
}
```
[1077F1 - Pictures with Kittens (easy version)](../problems/F1._Pictures_with_Kittens_(easy_version).md "Codeforces Round 521 (Div. 3)")

 **Tutorial**
### [1077F1 - Pictures with Kittens (easy version)](../problems/F1._Pictures_with_Kittens_(easy_version).md "Codeforces Round 521 (Div. 3)")

Let's solve the problem using dynamic programming. Let $dp_{i, j}$ be the maximum total beauty of pictures if Vova is at the $i$-th picture now, the number of remaining reposts is $j$ and Vova reposted the $i$-th picture. Initially, $dp_{0, x} = 0$ and all other values of $dp$ are $-\infty$.

Let's learn to do some transitions to calculate this dynamic programming. What is the way to do it? Let's iterate over the position of the previously reposted picture and try to update $dp_{i, j}$ using previously calculated values. Obviously, this position can be from $i-1$ to $i-k$. So let's iterate over the position (let it be $p$) and if $dp_{p, j + 1}$ (we need one more repost to repost the $i$-th picture) is not $-\infty$ then try to update $dp_{i, j} = max(dp_{i, j}, dp_{p, j + 1} + a_i$) (pictures are $1$-indexed).

So, where can we find the answer? The answer is $\max\limits_{i = n - k + 1}^{n} dp_{i}$. If this value is $-\infty$ then the answer is -1.

Overall complexity is $O(nkx)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const long long INF64 = 1e18;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k, x;
	cin >> n >> k >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, -INF64));
	
	dp[0][x] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < x; ++j) {
			for (int p = 1; p <= k; ++p) {
				if (i - p < 0) break;
				if (dp[i - p][j + 1] == -INF64) {
					continue;
				}
				dp[i][j] = max(dp[i][j], dp[i - p][j + 1] + a[i - 1]);
			}
		}
	}
	
	long long ans = -INF64;
	for (int i = n - k + 1; i <= n; ++i) {
		ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
	}
	if (ans == -INF64) ans = -1;
	cout << ans << endl;
	
	return 0;
}
```
[1077F2 - Pictures with Kittens (hard version)](../problems/F2._Pictures_with_Kittens_(hard_version).md "Codeforces Round 521 (Div. 3)")

 **Tutorial**
### [1077F2 - Pictures with Kittens (hard version)](../problems/F2._Pictures_with_Kittens_(hard_version).md "Codeforces Round 521 (Div. 3)")

Let's use dynamic programming described in the previous tutorial to solve this problem too. But its complexity is $O(nkx)$ so we have to improve some part of the solution.

Let's see how we do transitions in this dp: for $p \in [i-k; i-1]$ $dp_{i, j} = max(dp_{i, j}, dp_{p, j + 1} + a_i)$. What can we do to optimize it? $a_i$ is the constant and we have to take the maximum value among $dp_{i - k, j + 1}, dp_{i - k + 1, j + 1}, \dots, dp_{i - 1, j + 1}$. You will say "segment tree"! I say no. Not a segment tree. Not a sparse table. Not a cartesian tree or some other logarithmic data structures. If you want to spend a lot of time to fit such solution in time and memory limits — okay, it is your choice. I prefer the queue with supporting the maximum on it.

The last part of this tutorial will be a small guide about how to write and use the queue with supporting the maximum on it.

The first part of understanding this data structure is the stack with the maximum. How do we support the stack with the maximum on it? That's pretty easy: let's maintain the stack of pairs, when the first value of pair is the value in the stack and the second one is the maximum on the stack if this element will be the topmost. Then when we push some value $val$ in it, the first element of pair will be $val$ and the second one will be $max(val, s.top().second)$ (if $s$ is our stack and $top()$ is the topmost element). When we pop the element we don't need any special hacks to do it. Just pop it. And the maximum on the stack is always $s.top().second$.

Okay, the second part of understanding this data structure is the queue on two stacks. Let's maintain two stacks $s1$ and $s2$ and try to implement the queue using it. We will push elements only to $s2$ and pop elements only from $s1$. Then how to maintain the queue using such stacks? The push is pretty easy — just push it in $s2$. The main problem is pop. If $s1$ is not empty then we have to pop it from $s1$. But what do we do if $s1$ is empty? No problems: let's just transfer elements of $s2$ to $s1$ (pop from $s2$, push to $s1$) in order from top to bottom. And don't forget to pop the element after this transfer!

Okay, if we will join these two data structures, we can see that we obtain exactly what we want! Just two stacks with maximums! That's pretty easy to understand and implement it.

The last part of the initial solution is pretty easy — just apply this data structure (in fact, $x+1$ data structures) to do transitions in our dynamic programming. The implementation of this structure can be found in the authors solution.

Total complexity of the solution is $O(nx)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair

typedef long long li;
typedef pair<li, li> pll;

const li INF64 = 1e18;

struct myQueue {
	stack<pll> s1, s2;
	
	int size() {
		return s1.size() + s2.size();
	}
	
	bool isEmpty() {
		return size() == 0;
	}
	
	long long getMax() {
		if (isEmpty()) {
			return -INF64;
		}
		if (!s1.empty() && !s2.empty()) {
			return max(s1.top().y, s2.top().y);
		}
		if (!s1.empty()) {
			return s1.top().y;
		}
		return s2.top().y;
	}
	
	void push(long long val) {
		if (s2.empty()) {
			s2.push(mp(val, val));
		} else {
			s2.push(mp(val, max(val, s2.top().y)));
		}
	}
	
	void pop() {
		if (s1.empty()) {
			while (!s2.empty()) {
				if (s1.empty()) {
					s1.push(mp(s2.top().x, s2.top().x));
				} else {
					s1.push(mp(s2.top().x, max(s2.top().x, s1.top().y)));	
				}
				s2.pop();
			}
		}
		assert(!s1.empty());
		s1.pop();
	}
};

int n, k, x;
vector<int> a;

vector<myQueue> q;
vector<queue<int>> pos;
vector<vector<long long>> dp;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> k >> x;
	a = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	q = vector<myQueue>(x + 1);
	pos = vector<queue<int>>(x + 1);
	dp = vector<vector<long long>>(n + 1, vector<long long>(x + 1, -INF64));
	
	dp[0][x] = 0;
	pos[x].push(-1);
	q[x].push(0ll);
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= x; ++j) {
			while (!pos[j].empty() && pos[j].front() < i - k - 1) {
				q[j].pop();
				pos[j].pop();
			}
		}
		for (int j = 0; j < x; ++j) {
			if (!q[j + 1].isEmpty()) {
				dp[i][j] = max(dp[i][j], q[j + 1].getMax() + a[i - 1]);
				q[j].push(dp[i][j]);
				pos[j].push(i - 1);
			}
		}
	}
	
	long long ans = -INF64;
	for (int i = n - k + 1; i <= n; ++i) {
		ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
	}
	if (ans == -INF64) ans = -1;
	cout << ans << endl;
	
	return 0;
}
```
