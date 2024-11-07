# Tutorial

[1144A - Diverse Strings](../problems/A._Diverse_Strings.md "Codeforces Round 550 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1144A - Diverse Strings](../problems/A._Diverse_Strings.md "Codeforces Round 550 (Div. 3)")

The string is diverse if it is a permutation of some substring of the Latin alphabet ("abcd ... xyz").

In other words, the string is diverse if all letters in it are distinct (we can check it using some structure like std::set or array of used elements) and if the number of letters between the letter with the maximum alphabet position and the letter with the minimum alphabet position plus one is exactly the length of the string. For example, the position in alphabet of letter 'a' is one, the position of letter 'f' is six and so on.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int n;
    cin >> n;
    forn(i, n) {
        string s;
        cin >> s;
        if (set<char>(s.begin(), s.end()).size() == s.length()
                && *max_element(s.begin(), s.end()) == char(*min_element(s.begin(), s.end()) + (s.length() - 1)))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

```
[1144B - Parity Alternated Deletions](../problems/B._Parity_Alternated_Deletions.md "Codeforces Round 550 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1144B - Parity Alternated Deletions](../problems/B._Parity_Alternated_Deletions.md "Codeforces Round 550 (Div. 3)")

Let's calculate the sum of the whole array $sum$ and then divide all its elements into two arrays $odd$ and $even$ by their parity ($odd$ for odd, $even$ for even). Sort both of them in non-increasing order. Then what can we see? We always can delete first $k = min(|odd|, |even|)$ elements from both arrays (where $|x|$ is the size of $x$). So let's decrease $sum$ by the sum of first $k$ elements of the array $odd$ and the same for the array $even$. If one the arrays has more than $k$ elements (both arrays cannot have more than $k$ elements because if it is so then $k$ should be greater) then let's decrease $sum$ by the $k+1$-th element of this array (because this is the maximum possible element we can remove). Now $sum$ is the answer for the problem.

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
	int sum = 0;
	vector<int> even, odd;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		sum += x;
		if (x & 1) odd.push_back(x);
		else even.push_back(x);
	}
	
	sort(odd.rbegin(), odd.rend());
	sort(even.rbegin(), even.rend());
	int k = min(odd.size(), even.size());
	int rem = sum;
	rem -= accumulate(odd.begin(), odd.begin() + k, 0);
	rem -= accumulate(even.begin(), even.begin() + k, 0);
	if (int(odd.size()) > k) {
		rem -= odd[k];
	}
	if (int(even.size()) > k) {
		rem -= even[k];
	}
	
	cout << rem << endl;
	
	return 0;
}
```
[1144C - Two Shuffled Sequences](../problems/C._Two_Shuffled_Sequences.md "Codeforces Round 550 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1144C - Two Shuffled Sequences](../problems/C._Two_Shuffled_Sequences.md "Codeforces Round 550 (Div. 3)")

Let's count the number of occurrences of each element in the array $cnt$. Because the maximum possible element is $2 \cdot 10^5$, it can be done without any data structures.

Then let's check if $cnt_i$ is greater than $2$ for some $i$ from $0$ to $2 \cdot 10^5$, and if it is, then the answer is "NO", because this element should occur at least twice in one of the sequences.

Now let's output the increasing sequence. The number of elements in it is the number of elements $i$ such that $cnt_i = 2$. Let's iterate from left to right, print the suitable elements and decrease their $cnt$.

The number of elements in the decreasing sequence is just the number of elements with non-zero $cnt$. So let's iterate from right to left and just print suitable elements.

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
	vector<int> cnt(200 * 1000 + 1);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
		if (cnt[x] > 2) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl << count(cnt.begin(), cnt.end(), 2) << endl;
	for (int i = 0; i <= 200 * 1000; ++i) {
		if (cnt[i] == 2) {
			cout << i << " ";
			--cnt[i];
		}
	}
	cout << endl << count(cnt.begin(), cnt.end(), 1) << endl;
	for (int i = 200 * 1000; i >= 0; --i) {
		if (cnt[i] == 1) {
			cout << i << " ";
			--cnt[i];
		}
	}
	cout << endl;
	
	assert(count(cnt.begin(), cnt.end(), 0) == 200 * 1000 + 1);
	
	return 0;
}
```
[1144D - Equalize Them All](../problems/D._Equalize_Them_All.md "Codeforces Round 550 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**
### [1144D - Equalize Them All](../problems/D._Equalize_Them_All.md "Codeforces Round 550 (Div. 3)")

Let's find the most frequent element in the array (using the array of frequencies $cnt$, of course). Let this element be $x$. If we will see the operations more carefully, we can see that the part of these operations means "set element $p$ to element $q$". if $p < q$ then this operation is $1 p q$, otherwise it is $2 p q$.

Now let's consider the number of operations in the optimal answer. It is obvious that we need at least $n - cnt_x$ operations to equalize all the elements. And it is also obvious that we can always do it with $n - cnt_x$ such operations we have.

How to restore the answer? There is an easy way to do it: find the first occurrence of $x$. Let it be $pos$. Then let's go from $pos - 1$ to $1$ and set each element to the next element (element at the position $pos - 1$ to $pos$, $pos - 2$ to $pos - 1$ and so on). And don't forget to print right type of operation. Then let's go from left to right from $1$ to $n$ and if the $i$-th element don't equal to $x$ then set it to $i-1$-th element using right operation.

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
	
	vector<int> a(n), cnt(200 * 1000 + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	
	int val = max_element(cnt.begin(), cnt.end()) - cnt.begin();
	int pos = find(a.begin(), a.end(), val) - a.begin();
	
	cout << n - cnt[val] << endl;
	int siz = 0;
	for (int i = pos - 1; i >= 0; --i) {
		cout << 1 + (a[i] > a[i + 1]) << " " << i + 1 << " " << i + 2 << " " << endl;
		a[i] = a[i + 1];
		++siz;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (a[i + 1] != val) {
			assert(a[i] == val);
			cout << 1 + (a[i + 1] > a[i]) << " " << i + 2 << " " << i + 1 << " " << endl;
			a[i + 1] = a[i];
			++siz;
		}
	}
	
	assert(siz == n - cnt[val]);
	return 0;
}
```
[1144E - Median String](../problems/E._Median_String.md "Codeforces Round 550 (Div. 3)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**
### [1144E - Median String](../problems/E._Median_String.md "Codeforces Round 550 (Div. 3)")

This problem supposed to be easy long arithmetic problem.

Let's represent our strings as huge numbers with base $26$. Let $s$ be $l$ and $t$ be $r$.

So if we will see more precisely in the problem statement, then we can see that the answer is $\frac{l + r}{2}$. The operation $l + r$ with long numbers can be done in $O(k)$ and division long number by two also can be done in $O(k)$.

All details of implementation are in the author's solution.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> get(const string &s) {
	vector<int> res(s.size() + 1);
	for (int i = 0; i < int(s.size()); ++i) {
		res[i + 1] = s[i] - 'a';
	}
	return res;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int k;
	string s, t;
	cin >> k >> s >> t;
	vector<int> a = get(s), b = get(t);
	
	for (int i = k; i >= 0; --i) {
		a[i] += b[i];
		if (i) {
			a[i - 1] += a[i] / 26;
			a[i] %= 26;
		}
	}
	
	for (int i = 0; i <= k; ++i) {
		int rem = a[i] % 2;
		a[i] /= 2;
		if (i + 1 <= k) {
			a[i + 1] += rem * 26;
		} else {
			assert(rem == 0);
		}
	}
	
	for (int i = 1; i <= k; ++i) {
		cout << char('a' + a[i]);
	}
	cout << endl;
	
	return 0;
}
```
[1144F - Graph Without Long Directed Paths](../problems/F._Graph_Without_Long_Directed_Paths.md "Codeforces Round 550 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1144F - Graph Without Long Directed Paths](../problems/F._Graph_Without_Long_Directed_Paths.md "Codeforces Round 550 (Div. 3)")

What if the given graph will contain a cycle of odd length? It will mean that some two consecutive edges of this cycle will be oriented in the same way and will form a path of length two.

What if there is no cycles of odd length in this graph? Then it is bipartite. Let's color it and see what we got. We got some vertices in the left part, some vertices in the right part and all edges connecting vertices from different parts. Let's orient all edges such that them will go from the left part to the right part. That's it.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 11;

int n, m;
vector<int> g[N];
vector<pair<int, int>> e;

bool bipartite;
vector<int> color;

void dfs(int v, int c) {
	color[v] = c;
	for (auto to : g[v]) {
		if (color[to] == -1) {
			dfs(to, c ^ 1);
		} else {
			if (color[to] == color[v]) {
				bipartite = false;
			}
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
		e.push_back(make_pair(x, y));
	}
	
	bipartite = true;
	color = vector<int>(n, -1);
	dfs(0, 0);
	
	if (!bipartite) {
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	for (int i = 0; i < m; ++i) {
		cout << (color[e[i].first] < color[e[i].second]);
	}
	cout << endl;
	
	return 0;
}
```
[1144G - Two Merged Sequences](../problems/G._Two_Merged_Sequences.md "Codeforces Round 550 (Div. 3)")

[There](//codeforces.comAnnouncement.md?#comment-503140) is different solution for the problem, it is pretty interesting! Thanks, [Roundgod](https://codeforces.com/profile/Roundgod "Grandmaster Roundgod")!

Idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh")

 **Tutorial**
### [1144G - Two Merged Sequences](../problems/G._Two_Merged_Sequences.md "Codeforces Round 550 (Div. 3)")

I know about greedy solutions and other approaches, but I'll describe my solution. This is dynamic programming. I'll consider all positions $0$-indexed.

Let $dp_{i, 0}$ be the maximum possible minimal element in the decreasing sequence, if the last element ($i-1$-th) was in the increasing sequence, and $dp_{i, 1}$ be the minimum possible maximum element in the increasing sequence, if the last element ($i-1$-th) was in the decreasing sequence.

Initially, all $dp_{i, 0}$ are $-\infty$ and all $dp_{i, 1}$ are $\infty$ (except two values: $dp_{0, 0} = \infty$ and $dp_{0, 1} = -\infty$).

What about transitions? Let's consider four cases: 

* The previous element was in the increasing sequence and we want to add the current element to the increasing sequence. We can do $dp_{i, 0} := max(dp_{i, 0}, dp_{i - 1, 0})$ if $a_i > a_{i - 1}$;
* the previous element was in the increasing sequence and we want to add the current element to the decreasing sequence. We can do $dp_{i, 1} := min(dp_{i, 1}, a_{i - 1})$ if $a_i < dp_{i - 1, 0}$;
* the previous element was in the decreasing sequence and we want to add the current element to the decreasing sequence. We can do $dp_{i, 1} := min(dp_{i, 1}, dp_{i - 1, 1})$ if $a_i < a_{i - 1}$;
* the previous element was in the decreasing sequence and we want to add the current element to the increasing sequence. We can do $dp_{i, 0} := max(dp_{i, 0}, a_{i - 1})$ if $a_i > dp_{i - 1, 1}$.

The logic behind these transitions is kinda hard but understandable.

If $dp_{n - 1, 0} = -\infty$ and $dp_{n - 1, 1} = \infty$ then the answer is "NO". Otherwise we can restore any possible answer using parents in the dynamic programming.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

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
	
	vector<vector<int>> dp(n, vector<int>({-INF, INF}));
	vector<vector<int>> p(n, vector<int>(2, -1));
	dp[0][0] = INF;
	dp[0][1] = -INF;
	
	for (int i = 1; i < n; ++i) {
		{
			if (a[i] > a[i - 1] && dp[i][0] < dp[i - 1][0]) {
				dp[i][0] = dp[i - 1][0];
				p[i][0] = 0;
			}
			if (a[i] < dp[i - 1][0] && dp[i][1] > a[i - 1]) {
				dp[i][1] = a[i - 1];
				p[i][1] = 0;
			}
		}
		{
			if (a[i] < a[i - 1] && dp[i][1] > dp[i - 1][1]) {
				dp[i][1] = dp[i - 1][1];
				p[i][1] = 1;
			}
			if (a[i] > dp[i - 1][1] && dp[i][0] < a[i - 1]) {
				dp[i][0] = a[i - 1];
				p[i][0] = 1;
			}
		}
	}
	
	int pos = -1;
	if (dp[n - 1][0] != -INF) {
		pos = 0;
	}
	if (dp[n - 1][1] != INF) {
		pos = 1;
	}
	
	if (pos == -1) {
		cout << "NO" << endl;
		return 0;
	}
	
	vector<int> inInc(n);
	for (int i = n - 1; i >= 0; --i) {
		if (pos == 0) {
			inInc[i] = 1;
		}
		pos = p[i][pos];
	}
	
	cout << "YES" << endl;
	for (int i = 0; i < n; ++i) {
		cout << !inInc[i] << " ";
	}
	cout << endl;
	
	return 0;
}
```
